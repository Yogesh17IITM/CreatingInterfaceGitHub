#pragma once

// DLL Exports
#include "UtilitiesDLLExport.h"

#include<string>
#include<vector>
using namespace std;

// Forward Declarations
class Particle;

/* FUNCTION DECLARATIONS */

/* FUNCTION: GetParam
@Description : Function to Get input param of double type
@in          : iParam - Parameter name (string)
@out         : NA
@return      : Parameter value as specified by the user */
UTILITIESDLLEXPORT double GetParam(string iParam);

UTILITIESDLLEXPORT void DisplayMessage(string iStrMsg);

UTILITIESDLLEXPORT bool WriteToFile(const vector<Particle*> & iListOfParticles);