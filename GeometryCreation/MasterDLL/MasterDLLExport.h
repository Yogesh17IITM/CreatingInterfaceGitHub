#pragma once

// DLL Exports
#ifdef MASTERDLL_EXPORTS
#  define MASTERDLLEXPORT __declspec(dllexport)
#else
#  define MASTERDLLEXPORT __declspec(dllimport)
#endif