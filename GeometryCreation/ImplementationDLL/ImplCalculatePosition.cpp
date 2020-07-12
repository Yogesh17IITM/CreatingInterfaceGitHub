#include "ImplCalculatePosition.h"

#include "ImplPosition.h"
#include "Particle.h"
#include "Params.h"
#include "Utilities.h"

bool ImplCalculatePosition::CalculateCurrentPosition(vector<Particle*>& ioListOfParticles, const GeometricParams2D & iGeometricParams2D, const Position* ipStartPosition)
{
	bool oRc = false;

	double Start_X = 0.0;
	double Start_Y = 0.0;
		
	if (ipStartPosition)
	{
		Start_X = ipStartPosition->GetX();	// To extend in X-Direction
		Start_Y = ipStartPosition->GetY();	// To extend in Y-Direction
	}	
	
	int nParticles = (iGeometricParams2D.GridParams.NX * iGeometricParams2D.GridParams.NY);
	if (ioListOfParticles.size() == nParticles)
	{
		int iCurrParticle = 0;
		for (int iIdx = 0; iIdx < iGeometricParams2D.GridParams.NX; iIdx++)
		{
			for (int jIdx = 0; jIdx < iGeometricParams2D.GridParams.NY; jIdx++)
			{
				// Get current particle pointer and update its position
				SmartPtr<Particle> spCurrentParticle;
				spCurrentParticle = ioListOfParticles[iCurrParticle];

				if (spCurrentParticle)
				{
					Position* pPosOfCurrParticle = new ImplPosition();	// TODO: Instantiate using FactoryDLL
					if (pPosOfCurrParticle)
					{
						// Compute and Set Coordinates (assuming cartesian Coordinate system [2D])
						pPosOfCurrParticle->SetX(Start_X + (iIdx * iGeometricParams2D.GridParams.dx));
						pPosOfCurrParticle->SetY(Start_Y + (jIdx * iGeometricParams2D.GridParams.dy));
						spCurrentParticle->SetPosition(pPosOfCurrParticle);
					}
					iCurrParticle++;
				}
			}
		}
		oRc = true;
	}
		
	return oRc;
}
