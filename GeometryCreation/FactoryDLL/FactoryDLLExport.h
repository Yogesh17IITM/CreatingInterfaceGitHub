#pragma once

// DLL Exports
#ifdef FACTORYDLL_EXPORTS
#  define FACTORYDLLEXPORT __declspec(dllexport)
#else
#  define FACTORYDLLEXPORT __declspec(dllimport)
#endif