#pragma once

#include<vector>
using namespace std;

// DLL Exports
#include "InterfaceDLLExport.h"

class Particle;
class GridParams;
class GeometricParams2D;
class Position;

class INTERFACEDLLEXPORT CalculatePosition
{
public:
	virtual bool CalculateCurrentPosition(vector<Particle*>& oListOfParticles, const GridParams & iGridParams, const GeometricParams2D & iGeometricParams2D, const Position * ipStartPosition = NULL) = 0;	

	// TODO: Create function for calculating updated position.	
};

