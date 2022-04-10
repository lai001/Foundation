set_xmakever("2.6.3")

includes("../Foundation")
add_requires("spdlog")

target("Example")
    set_kind("binary")
    add_files("main.cpp")
    add_includedirs("../Foundation/include")
    set_languages("c++17")
    add_rules("mode.debug", "mode.release")
    add_packages("spdlog")
    add_deps("Foundation")