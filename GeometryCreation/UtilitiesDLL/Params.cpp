#include<iostream>

#include "Params.h"
#include "Utilities.h"

using namespace std;

void GetDataFor2DGeometry(GeometricParams2D& oGeometricParams2D)
{
	// TODO: Define a template function in utilities and move the below code to there
	int DomainType;
	DisplayMessage("Specify Domain Type: 1 (for rectangle), 2 (for triangle) and 3 (for circle)");
	cin >> DomainType;

	DisplayMessage("Specify geometric parameters");
	oGeometricParams2D.GeometricType = static_cast<GeometricParams2D::GEOMETRIC_TYPE>(DomainType);
	switch (oGeometricParams2D.GeometricType)
	{
	case GeometricParams2D::GEOMETRIC_TYPE::Rectangle:
		oGeometricParams2D.Rec.Length = GetParam("Length");
		oGeometricParams2D.Rec.Height = GetParam("Height");
		oGeometricParams2D.Rec.CentreX = GetParam("Centre X");
		oGeometricParams2D.Rec.CentreY = GetParam("Centre Y");
		break;
	case GeometricParams2D::GEOMETRIC_TYPE::Triangle:
		oGeometricParams2D.Tri.Base = GetParam("Base");
		oGeometricParams2D.Tri.Height = GetParam("Height");
		oGeometricParams2D.Tri.CentreX = GetParam("Centre X");
		oGeometricParams2D.Tri.CentreY = GetParam("Centre Y");
		break;
	case GeometricParams2D::GEOMETRIC_TYPE::Circle:
		oGeometricParams2D.Cir.Radius = GetParam("Radius");
		oGeometricParams2D.Cir.CentreX = GetParam("Centre X");
		oGeometricParams2D.Cir.CentreY = GetParam("Centre Y");
		break;
	default:
		break;
	}
}

bool CalculateGridSize(GridParams& oGridParams, const GeometricParams2D& iGeometricParams2D)
{
	bool oReturnVal = false;

	DisplayMessage("Specify number of particles along each direction");
	oGridParams.NX = GetParam("NX");	// along X Direction
	oGridParams.NY = GetParam("NY");	// along Y Direction

	// Calc. Grid size
	if (GeometricParams2D::GEOMETRIC_TYPE::Rectangle == iGeometricParams2D.GeometricType)
	{
		if ((oGridParams.NX > 1) && (oGridParams.NY > 1))
		{
			oGridParams.dx = iGeometricParams2D.Rec.Length / (oGridParams.NX - 1.0);
			oGridParams.dy = iGeometricParams2D.Rec.Height / (oGridParams.NY - 1.0);
			oReturnVal = true;
		}		
	}
	else if (GeometricParams2D::GEOMETRIC_TYPE::Triangle == iGeometricParams2D.GeometricType)
	{
	}
	else if ((GeometricParams2D::GEOMETRIC_TYPE::Circle == iGeometricParams2D.GeometricType))
	{
	}
	else
	{	// handle exceptions for INVALID_GEOMETRIC_TYPE		
	}

	return oReturnVal;
}
