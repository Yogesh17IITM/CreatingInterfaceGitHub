#pragma once

// Base class
#include "CalculatePosition.h"

// DLL Exports
#include "ImplementationDLLExport.h"

class IMPLEMENTATIONDLLEXPORT ImplCalculatePosition : public CalculatePosition
{
public:
	virtual bool CalculateCurrentPosition(vector<Particle*>& oListOfParticles, const GridParams iGridParams, const GeometricParams2D iGeometricParams2D) override;
};

