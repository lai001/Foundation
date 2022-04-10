set_xmakever("2.6.3")

target("Foundation")
    set_kind("static")
    add_files("src/**.cpp")
    add_headerfiles("include/**.hpp", "include/**.h")
    add_includedirs("include/Foundation")
    set_languages("c++17")
    add_rules("mode.debug", "mode.release")