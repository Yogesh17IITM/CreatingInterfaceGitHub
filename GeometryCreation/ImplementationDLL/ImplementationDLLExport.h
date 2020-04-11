#pragma once

// DLL Exports
#ifdef IMPLEMENTATIONDLL_EXPORTS
#  define IMPLEMENTATIONDLLEXPORT __declspec(dllexport)
#else
#  define IMPLEMENTATIONDLLEXPORT __declspec(dllimport)
#endif