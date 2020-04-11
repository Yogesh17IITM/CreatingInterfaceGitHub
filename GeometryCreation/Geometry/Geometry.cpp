// Std libraries
#include<iostream>
#include<string>
#include<vector>

// Interfaces
#include "Particle.h"
#include "CalculatePosition.h"

// Include dependencies
#include "Factory.h"	
#include "Utilities.h"
#include "Params.h"

// Using directives
using namespace std;

int main()
{		
	// Get Geometry details
	GeometricParams2D geoParam2D;	
	GetDataFor2DGeometry(geoParam2D);
		
	// Get Grid Params
	bool bRc = false;
	GridParams gridParams;
	if (geoParam2D.GeometricType == GeometricParams2D::GEOMETRIC_TYPE::Rectangle)
	{		
		bRc = CalculateGridSize(gridParams, geoParam2D);
	}
	
	// Create Particle instances
	vector<Particle*> ListOfAirParticles;
	if (bRc)
	{
		int NAirParticles = (gridParams.NX * gridParams.NY); // Total air particles

		// Create Air Particles		
		bRc = CreateMultipleParticleInstances(ListOfAirParticles, NAirParticles, INTERFACE_ID::IID_AirParticle);
	}

	// Calculate current position of particles	
	if (bRc)
	{			
		CalculatePosition* pCalcPosition = NULL;
		bRc = CreateInstance((void**)&pCalcPosition, INTERFACE_ID::IID_CalculatePosition);
		if (bRc && pCalcPosition)
		{
			bRc = pCalcPosition->CalculateCurrentPosition(ListOfAirParticles, gridParams, geoParam2D);
		}
		delete pCalcPosition;
	}
	
	// TODO: Function to Set properties
	
	// TODO: Create Boundary Particles using ParticleCreation algo.

	// TODO: Print Particle info to a file and view it
	WriteToFile(ListOfAirParticles);

	// TODO: Include error library to diplay error codes/ messages
	return 0;
}

