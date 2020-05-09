// Std libraries
#include<iostream>
#include<string>
#include<vector>

// Interfaces
#include "Particle.h"
#include "Position.h"
#include "CalculatePosition.h"

// Include dependencies
#include "Factory.h"	
#include "Utilities.h"
#include "Params.h"

// Using directives
using namespace std;

int main()
{
    // 1. Get Geometrical details
    GeometricParams2D geoParam2D;
    GetDataFor2DGeometry(geoParam2D);

    // 2. Get Grid Params
    bool bRc = false;
    GridParams gridParams;
    if (geoParam2D.GeometricType == GeometricParams2D::GEOMETRIC_TYPE::Rectangle)
    {
        bRc = CalculateGridSize(gridParams, geoParam2D);
    }

    // 3. Create Particle instances
    vector<Particle*> ListOfAirParticles;
    vector<Particle*> ListOfWaterParticles;
    int NAirParticles = 0;
    int NWaterParticles = 0;
    if (bRc)
    {
        NAirParticles = (gridParams.NX * gridParams.NY); // Total air particles
        NWaterParticles = NAirParticles;				 // Total Water Particles (currently same as air particles)

        // 3.1 Create Air Particles		
        bRc = CreateMultipleParticleInstances(ListOfAirParticles, NAirParticles, INTERFACE_ID::IID_AirParticle);

        // 3.2 Create Water Particles
        if (bRc)
            bRc = CreateMultipleParticleInstances(ListOfWaterParticles, NWaterParticles, INTERFACE_ID::IID_WaterParticle);
    }

    // 4. Initial position of particles (at time, t = 0)
    if (bRc && (NAirParticles == ListOfAirParticles.size() && (NWaterParticles == ListOfWaterParticles.size())))
    {
        CalculatePosition* pCalcPosition = NULL;
        bRc = CreateInstance((void**)&pCalcPosition, INTERFACE_ID::IID_CalculatePosition);
        if (bRc && pCalcPosition)
        {
            // 4.1: For air particles
            bRc = pCalcPosition->CalculateCurrentPosition(ListOfAirParticles, gridParams, geoParam2D);

            Position* pLastAirParticlePosition = NULL;
            if (bRc)
            {
                SmartPtr<Particle> spLastParticle;      // Life-cycle managed automatically
                spLastParticle = ListOfAirParticles[ListOfAirParticles.size() - 1];
                if (spLastParticle)
                {
                    spLastParticle->GetPosition(pLastAirParticlePosition);
                    if (pLastAirParticlePosition)
                        pLastAirParticlePosition->AddRef();
                }
            }

            // 4.2: For water particles
            if (bRc)
            {
                Position* pStartPosition = NULL;
                bRc = CreateInstance((void**)&pStartPosition, INTERFACE_ID::IID_Position);
                if (bRc && pStartPosition)
                {
                    double currX = 0.0;
                    if (pLastAirParticlePosition)
                        currX = pLastAirParticlePosition->GetX();

                    pStartPosition->SetX(currX + gridParams.dx);
                    pStartPosition->SetY(0.0);	// To extend only in X-Direction
                    bRc = pCalcPosition->CalculateCurrentPosition(ListOfWaterParticles, gridParams, geoParam2D, pStartPosition);
                }
                pStartPosition->Release();
            }
            pLastAirParticlePosition->Release();
        }
        pCalcPosition->Release();
    }

    // TODO: Create Boundary Particles using ParticleCreation algo.

    // TODO: Function to Set properties	

    // Writing Initial state of Particle(s) into .csv file (User can view it using "Paraview" application)
    if (bRc)
    {
        vector<Particle*> ListOfAllParticles;
        ListOfAllParticles.insert(ListOfAllParticles.begin(), ListOfAirParticles.begin(), ListOfAirParticles.end());
        ListOfAllParticles.insert(ListOfAllParticles.end(), ListOfWaterParticles.begin(), ListOfWaterParticles.end());
        WriteToFile(ListOfAllParticles, "InitialStateOfParticles");
    }

    // TODO: Include error library to diplay error codes/ messages
        
    return 0;
}

