#pragma once

// DLL Exports
#ifdef UTILITIESDLL_EXPORTS
#  define UTILITIESDLLEXPORT __declspec(dllexport)
#else
#  define UTILITIESDLLEXPORT __declspec(dllimport)
#endif

#include<string>
using namespace std;

/* FUNCTION: GetParam
@Description : Function to Get input param of double type
@in          : iParam - Parameter name (string)
@out         : NA
@return      : Parameter value as specified by the user */
UTILITIESDLLEXPORT double GetParam(string iParam);

UTILITIESDLLEXPORT void DisplayMessage(string iStrMsg);