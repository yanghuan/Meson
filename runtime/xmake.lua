set_project("runtime")
set_languages("c++20")
add_requires("boost 1.72.0")
add_rules("mode.debug", "mode.release", "mode.minsizerel")

if is_mode("debug") then 
  add_defines("DEBUG")
  set_symbols("debug")
  set_optimize("none")
elseif is_mode("release") then
  set_symbols("hidden")
  set_optimize("smallest")
  set_strip("all")
end

includes("outcpp")
includes("test")