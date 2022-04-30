#ifndef Foundation_defs_hpp
#define Foundation_defs_hpp

#ifdef _WIN32
#ifdef Foundation_BUILD_DLL_EXPORT
#define Foundation_API __declspec(dllexport)
#elif (defined Foundation_DLL)
#define Foundation_API __declspec(dllimport)
#else
#define Foundation_API
#endif // Foundation_BUILD_DLL_EXPORT
#else
#define Foundation_API
#endif // _WIN32

#endif // !Foundation_defs_hpp