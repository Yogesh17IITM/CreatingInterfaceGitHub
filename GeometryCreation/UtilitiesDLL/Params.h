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

	struct Grid {
		int nDim; 
		int NX, NY, NZ;		
		double dx, dy, dz;
	} GridParams;

	bool ComputeGridSize();
};

// Functions
UTILITIESDLLEXPORT bool GetDataFor2DGeometry(GeometricParams2D& oGeometricParamS2D);