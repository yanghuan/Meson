rule("cxxfilehash")
  set_extensions(".cpp")
  before_load(function (target)
    local hashscache = {}

    local function getfiledata(file)
      local data = hashscache[file] or {}
      hashscache[file] = data
      return data
    end

    local function getfilesize(file)
      local data = getfiledata(file)
      local size = data[1] or os.filesize(file)
      data[1] = size
      return size
    end

    local function filehash(file)
      return try {
        function ()
          return hash.sha256(file)
        end
      }
    end

    local function getfilehash(file)
      local data = getfiledata(file)
      local hashcode = data[2] or filehash(file)
      data[2] = hashcode
      return hashcode
    end

    local function ishashchanged(dependinfo)
      local hashs = dependinfo.hashs or {}
      for _, file in ipairs(dependinfo.files) do
        local data = hashs[file] or {}
        local size = getfilesize(file)
        if data[1] ~= size then
          print(file, data[1], size)
          return true
        end
        local hashcode = getfilehash(file)
        if hashcode and data[2] ~= hashcode then
          print(file, data[2], hashcode)
          return true
        end
      end
      return false
    end

    local function updatehash(dependinfo)
      local hashs = {}
      dependinfo.hashs = hashs
      for _, file in ipairs(dependinfo.files) do
        hashs[file] = {
          getfilesize(file),
          getfilehash(file)
        }
      end
    end

    target:data_set("cxxfilehash.filehash", {
      ishashchanged = ishashchanged,
      updatehash = updatehash,
    })
  end)
  on_build_file(function (target, sourcefile, opt)
    import("core.base.option")
    import("core.project.config")
    import("core.project.depend")
    import("core.tool.compiler")
    import("private.utils.progress")

    local filehash = target:data("cxxfilehash.filehash")

    local objectfile = target:objectfile(sourcefile)
    local compinst = compiler.load("cxx", {target = target})
    local compflags = compinst:compflags({target = target, sourcefile = sourcefile})

    table.insert(target:objectfiles(), objectfile)
    local dependfile = target:dependfile(objectfile)
    local dependinfo = option.get("rebuild") and {} or (depend.load(dependfile) or {})
    local depvalues = {compinst:program(), compflags}
    if depend.is_changed(dependinfo, {lastmtime = 9223372036854775807, values = depvalues}) then
    elseif filehash.ishashchanged(dependinfo) then
    else
      return
    end

    progress.show(opt.progress, "compiling.%s %s", config.get("mode"), sourcefile)
    assert(compinst:compile(sourcefile, objectfile, {dependinfo = dependinfo, compflags = compflags}))
    dependinfo.values = depvalues
    filehash.updatehash(dependinfo)
    depend.save(dependinfo, dependfile)
  end)
  
target("outcpp")
  set_kind("binary")
  add_rules("cxxfilehash")
  add_packages("boost")
  add_includedirs("..", {public = true})
  add_includedirs(".")
  add_files("../rt/**.cpp", "**.cpp", { rules = { "cxxfilehash", override = true }})

