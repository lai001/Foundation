set_xmakever("2.6.3")

target("Foundation")
    set_kind("$(kind)")
    add_files("src/**.cpp")
    add_headerfiles("include/**.hpp", "include/**.h")
    add_includedirs("include/Foundation")
    add_includedirs("include", {interface = true})
    set_languages("c++17")
    add_rules("mode.debug", "mode.release")
    if is_kind("shared") and is_plat("windows") then
        add_defines("Foundation_BUILD_DLL_EXPORT")
    end
    on_config(function (target)
        import("core.project.project")
        for _targetname, _target in pairs(project.targets()) do
            local depsType = type(_target:get("deps"))
            local deps = nil;
            if depsType == "table" then
                deps = _target:get("deps")
            elseif depsType == "string" then
                deps = {_target:get("deps")}
            end
            if deps and table.contains(deps, "Foundation") and target:kind() == "shared" and target:is_plat("windows") then
                _target:add("defines", "Foundation_DLL")
            end
        end
    end)