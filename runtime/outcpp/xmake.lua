target("outcpp")
  set_kind("binary")
  add_packages("boost")
  add_includedirs("..", {public = true})
  add_includedirs(".")
  add_files("../rt/**.cpp", "**.cpp")

