#pragma once

// Base class
#include "CalculatePosition.h"

// DLL Exports
#include "ImplementationDLLExport.h"

class IMPLEMENTATIONDLLEXPORT ImplCalculatePosition : public CalculatePosition
{
public:
	virtual bool CalculateCurrentPosition(vector<Particle*>& ioListOfParticles, const GeometricParams2D & iGeometricParams2D, const Position* ipStartPosition = NULL) override;
};

