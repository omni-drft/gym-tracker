workspace "GymTracker"
   configurations { "Debug", "Release" }
   architecture "x86_64"

project "GymTrackerApp"
   kind "WindowedApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   includedirs { 
       "dependencies/wxWidgets/include/msvc",
       "dependencies/wxWidgets/include",
       "dependencies/SQLiteCpp/include"
   }
   libdirs { 
       "dependencies/wxWidgets/lib/vc_x64_lib",
       "dependencies/SQLiteCpp/build/Release"
    
   }

   files { "src/**.cpp", "src/**.hpp", "src/**.c"}

   links {
      "wxbase32u",
      "wxmsw32u_core",
      "SQLiteCpp"
   }

    filter "configurations:Debug"
        defines { 
            "_DEBUG", 
            "__WXMSW__", 
            "WX_STATIC_BUILD", 
            "_ITERATOR_DEBUG_LEVEL=2",
            "SQLITE_ENABLE_COLUMN_METADATA"
        }
        symbols "On"

    filter "configurations:Release"
        defines { 
            "NDEBUG", 
            "__WXMSW__", 
            "WX_STATIC_BUILD", 
            "_ITERATOR_DEBUG_LEVEL=0",
            "SQLITE_ENABLE_COLUMN_METADATA"
        }
        optimize "On"

    filter "system:windows"
        systemversion "latest"