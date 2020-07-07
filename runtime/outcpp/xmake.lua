rule("cxxsha1")
  set_extensions(".cpp")
  before_load(function (target)
    target:data_set("cxxsha1.files_hash", {})
  end)
  on_build_file(function (target, sourcefile, opt)
    import("core.base.option")
    import("core.project.config")
    import("core.project.depend")
    import("core.tool.compiler")
    import("private.utils.progress")
    import("cxxsha1")

    local files_hash = target:data("cxxsha1.files_hash")
    local objectfile = target:objectfile(sourcefile)
    local compinst = compiler.load("cxx", {target = target})
    local compflags = compinst:compflags({target = target, sourcefile = sourcefile})

    table.insert(target:objectfiles(), objectfile)
    local dependfile = target:dependfile(objectfile)
    local dependinfo = option.get("rebuild") and {} or (depend.load(dependfile) or {})
    local depvalues = {compinst:program(), compflags}
    if depend.is_changed(dependinfo, {lastmtime = 9223372036854775807, values = depvalues}) then
    elseif cxxsha1.is_hash_changed(dependinfo, files_hash) then
    else
      return
    end

    progress.show(opt.progress, "compiling.%s %s", config.get("mode"), sourcefile)
    assert(compinst:compile(sourcefile, objectfile, {dependinfo = dependinfo, compflags = compflags}))
    dependinfo.values = depvalues
    cxxsha1.update_hash(dependinfo, files_hash)
    depend.save(dependinfo, dependfile)
  end)
  
target("outcpp")
  set_kind("binary")
  add_rules("cxxsha1")
  add_packages("boost")
  add_includedirs("..", {public = true})
  add_includedirs(".")
  add_files("../rt/**.cpp", "**.cpp", { rules = { "cxxsha1", override = true }})
