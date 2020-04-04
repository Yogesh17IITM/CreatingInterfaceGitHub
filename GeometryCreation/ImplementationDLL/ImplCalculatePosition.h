#pragma once

// Base class
#include "CalculatePosition.h"

// DLL Exports
#ifdef IMPLEMENTATIONDLL_EXPORTS
#  define IMPLEMENTATIONDLLEXPORT __declspec(dllexport)
#else
#  define IMPLEMENTATIONDLLEXPORT __declspec(dllimport)
#endif

class IMPLEMENTATIONDLLEXPORT ImplCalculatePosition : public CalculatePosition
{
public:
	virtual bool CalculateCurrentPosition(vector<Particle*>& oListOfParticles, const GridParams iGridParams, const GeometricParams2D iGeometricParams2D) override;
};

