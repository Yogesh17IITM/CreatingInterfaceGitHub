#pragma once

// DLL Exports
#include "UtilitiesDLLExport.h"

// Struct Definitions
struct UTILITIESDLLEXPORT GeometricParams2D
{
	enum class GEOMETRIC_TYPE { Rectangle = 1, Triangle, Circle };
	GEOMETRIC_TYPE GeometricType;

	union
	{
		struct Rectangle { double Length, Height; } Rec;
		struct Triangle { double CentreX, CentreY, Base, Height; } Tri;
		struct Circle { double CentreX, CentreY, Radius; } Cir;
	};	
};

struct UTILITIESDLLEXPORT GridParams
{
	int nDim;
	int NX, NY, NZ;
	double dx, dy, dz;
};

// Functions
UTILITIESDLLEXPORT void GetDataFor2DGeometry(GeometricParams2D& oGeometricParamS2D);
UTILITIESDLLEXPORT bool CalculateGridSize(GridParams & oGridParams, const GeometricParams2D & iGeometricParams2D);