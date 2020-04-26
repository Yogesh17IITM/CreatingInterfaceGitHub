#include "ImplCalculatePosition.h"

#include "Params.h"
#include "ImplPosition.h"
#include "Particle.h"

bool ImplCalculatePosition::CalculateCurrentPosition(vector<Particle*>& oListOfParticles, const GridParams & iGridParams, const GeometricParams2D & iGeometricParams2D, const Position* ipStartPosition)
{
	bool oRc = false;

	double Start_X = 0.0;
	double Start_Y = 0.0;
		
	if (ipStartPosition)
	{
		Start_X = ipStartPosition->GetX();	// To extend in X-Direction
		Start_Y = ipStartPosition->GetY();	// To extend in Y-Direction
	}

	int iCurrParticle = 0;
	for (int iIdx = 0; iIdx < iGridParams.NX; iIdx++)
	{
		for (int jIdx = 0; jIdx < iGridParams.NY; jIdx++)
		{
			// Get current particle pointer and update its position
			Particle* pCurrentParticle = NULL;
			pCurrentParticle = oListOfParticles[iCurrParticle];

			if (pCurrentParticle)
			{
				pCurrentParticle->AddRef();
				Position* pPosOfCurrParticle = new ImplPosition();	// TODO: Instantiate using FactoryDLL
				if (pPosOfCurrParticle)
				{
					// Assuming cartesian Coordinate system [2D]
					pPosOfCurrParticle->SetX(Start_X + (iIdx * iGridParams.dx * iGeometricParams2D.Rec.Length));	// Set 'X' Coordinate
					pPosOfCurrParticle->SetY(Start_Y + (jIdx * iGridParams.dy * iGeometricParams2D.Rec.Height));	// Set 'Y' Coordinate 
					pCurrentParticle->SetPosition(pPosOfCurrParticle);	// TODO: Copy obj if required. Manage lifecycle of pPosOfCurrParticle.
					pPosOfCurrParticle->AddRef();
				}
				pPosOfCurrParticle->Release();	
				iCurrParticle++;
			}
			pCurrentParticle->Release();
		}
	}

	int nTotalParticles = (iGridParams.NX * iGridParams.NY); 
	if (oListOfParticles.size() == nTotalParticles)
	{
		oRc = true;
	}

	return oRc;
}
