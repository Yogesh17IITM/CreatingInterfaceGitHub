#pragma once

// DLL Exports
#ifdef UTILITIESDLL_EXPORTS
#  define UTILITIESDLLEXPORT __declspec(dllexport)
#else
#  define UTILITIESDLLEXPORT __declspec(dllimport)
#endif