/*
Objective:
    To develop an API to create a geometry with given user inputs (Coordinates)

Input: 
    Coordinates/Points
    Note: User may use the interface (Github: /WPF-Application)

Output:
    Points representing domain of interests

Visualize:
    User can input the given points to Paraview for visualization

Author:
    Yogeshwaran R
*/

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

// The 'Using' directive
using namespace std;

/* MAIN PROGRAM */
int main()
{
    bool bRc = false;
    vector<Particle*> ListOfParticles;

    // 1. Get Geometry and Grid Details
    GeometricParams2D GeoParam2D;
    bRc = GetDataFor2DGeometry(GeoParam2D);
    
    // 4. Initial position of particles (at time, t = 0)
#pragma region InitialPosition    
    CalculatePosition* pCalcPosition = NULL;
    bRc = CreateInstance((void**)&pCalcPosition, INTERFACE_ID::IID_CalculatePosition);
    if (bRc && pCalcPosition)
    {    
        // Calculating Position for Particles

        // Region #1 - Bottom Left (Water)
        vector<Particle*> ListOfWaterParticles;    
        int NWaterParticles = (GeoParam2D.GridParams.NX * GeoParam2D.GridParams.NX);
        bRc = CreateMultipleParticleInstances(ListOfWaterParticles, NWaterParticles, INTERFACE_ID::IID_WaterParticle);
        if(bRc)
            bRc = pCalcPosition->CalculateCurrentPosition(ListOfWaterParticles, GeoParam2D);

        // Region #2 - Bottom Right (Air)
        vector<Particle*> ListOfAirParticlesBottom;       // Air Particles
        if (bRc)
        {
            GeometricParams2D GeoParam2D_AirBottom;
            GeoParam2D_AirBottom.GeometricType = GeoParam2D.GeometricType;
            GeoParam2D_AirBottom.Rec.Length = GeoParam2D.Rec.Length * 2;
            GeoParam2D_AirBottom.Rec.Height = GeoParam2D.Rec.Height;
            GeoParam2D_AirBottom.GridParams.dx = GeoParam2D.GridParams.dx;
            GeoParam2D_AirBottom.GridParams.dy = GeoParam2D.GridParams.dy;
            GeoParam2D_AirBottom.ComputeGridSize();
            
            int NAirParticlesBottom = (GeoParam2D_AirBottom.GridParams.NX * GeoParam2D_AirBottom.GridParams.NY);
            bRc = CreateMultipleParticleInstances(ListOfAirParticlesBottom, NAirParticlesBottom, INTERFACE_ID::IID_AirParticle);

            Position* pStartPosition = NULL;
            if (bRc && (0 < ListOfAirParticlesBottom.size()))
                bRc = CreateInstance((void**)&pStartPosition, INTERFACE_ID::IID_Position);

            if (bRc && pStartPosition)
            {
                SmartPtr<Particle> spLastParticle;      // Life-cycle managed automatically
                spLastParticle = ListOfWaterParticles[ListOfWaterParticles.size() - 1];
                if (spLastParticle)
                {
                    Position * pLastComputedPosition;
                    spLastParticle->GetPosition(pLastComputedPosition);
                    if (pLastComputedPosition)
                    {
                        pStartPosition->SetX(pLastComputedPosition->GetX() + GeoParam2D_AirBottom.GridParams.dx);
                        pStartPosition->SetY(0.0);
                    }
                }
            }

            if (bRc && pStartPosition)  
            { 
                bRc = pCalcPosition->CalculateCurrentPosition(ListOfAirParticlesBottom, GeoParam2D_AirBottom, pStartPosition);
                pStartPosition->Release();
            }
        }

        // Region #3 - Top Region
        vector<Particle*> ListOfAirParticlesTop;       // Air Particles
        if (bRc)
        {
            GeometricParams2D GeoParam2D_AirTop;
            GeoParam2D_AirTop.GeometricType = GeoParam2D.GeometricType;
            GeoParam2D_AirTop.Rec.Length = GeoParam2D.Rec.Length * 3;
            GeoParam2D_AirTop.Rec.Height = GeoParam2D.Rec.Height;
            GeoParam2D_AirTop.GridParams.dx = GeoParam2D.GridParams.dx;
            GeoParam2D_AirTop.GridParams.dy = GeoParam2D.GridParams.dy;
            GeoParam2D_AirTop.ComputeGridSize();

            int NAirParticlesTop = (GeoParam2D_AirTop.GridParams.NX * GeoParam2D_AirTop.GridParams.NY);
            bRc = CreateMultipleParticleInstances(ListOfAirParticlesTop, NAirParticlesTop, INTERFACE_ID::IID_AirParticle);

            Position* pStartPosition = NULL;
            if (bRc && (0 < ListOfAirParticlesTop.size()))
                bRc = CreateInstance((void**)&pStartPosition, INTERFACE_ID::IID_Position);

            if (bRc && pStartPosition)
            {
                SmartPtr<Particle> spLastParticle;      // Life-cycle managed automatically
                spLastParticle = ListOfWaterParticles[ListOfWaterParticles.size() - 1];
                if (spLastParticle)
                {
                    Position* pLastComputedPosition;
                    spLastParticle->GetPosition(pLastComputedPosition);
                    if (pLastComputedPosition)
                    {
                        pStartPosition->SetX(0.0);
                        pStartPosition->SetY(pLastComputedPosition->GetY() + GeoParam2D_AirTop.GridParams.dy);
                    }
                }
            }

            if (bRc && pStartPosition)
            {
                bRc = pCalcPosition->CalculateCurrentPosition(ListOfAirParticlesTop, GeoParam2D_AirTop, pStartPosition);
                pStartPosition->Release();
            }
        }

        
        // Merge Overall Particles List
        ListOfParticles.insert(ListOfParticles.begin(), ListOfWaterParticles.begin(), ListOfWaterParticles.end());
        ListOfParticles.insert(ListOfParticles.end(), ListOfAirParticlesBottom.begin(), ListOfAirParticlesBottom.end());
        ListOfParticles.insert(ListOfParticles.end(), ListOfAirParticlesTop.begin(), ListOfAirParticlesTop.end());

        pCalcPosition->Release();
    }
#pragma endregion

    // TODO: Create Boundary Particles using ParticleCreation algo.

    // TODO: Function to Set properties	

    // Writing Initial state of Particle(s) into .csv file (User can view it using "Paraview" application)
#pragma region WritingInitialStateToaFile
    if (bRc)
    {        
        WriteToFile(ListOfParticles, "InitialStateOfParticles");
    }
#pragma endregion

    // TODO: Include error library to diplay error codes/ messages
        
    return 0;
}

