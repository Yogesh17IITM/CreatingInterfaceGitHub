#pragma once

// DLL Exports
#ifdef INTERFACEDLL_EXPORTS
#  define INTERFACEDLLEXPORT __declspec(dllexport)
#else
#  define INTERFACEDLLEXPORT __declspec(dllimport)
#endif