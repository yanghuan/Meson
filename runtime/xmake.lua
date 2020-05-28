set_project("runtime")
set_languages("c++20")
add_requires("boost")

add_rules("mode.debug", "mode.release")

if is_mode("debug") then 
  add_defines("DEBUG")
  --set_symbols("debug")
  --set_optimize("none")
end

includes("outcpp")
includes("test")