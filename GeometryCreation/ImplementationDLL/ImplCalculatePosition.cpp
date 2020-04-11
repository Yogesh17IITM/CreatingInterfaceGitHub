#include "ImplCalculatePosition.h"

#include "Params.h"
#include "ImplPosition.h"
#include "Particle.h"

bool ImplCalculatePosition::CalculateCurrentPosition(vector<Particle*>& oListOfParticles, const GridParams iGridParams, const GeometricParams2D iGeometricParams2D)
{
	Particle* pCurrentParticle = NULL;

	int iCurrParticle = 0;
	for (int iIdx = 0; iIdx < iGridParams.NX; iIdx++)
	{
		for (int jIdx = 0; jIdx < iGridParams.NY; jIdx++)
		{
			Position* pPosOfCurrParticle = new ImplPosition();

			// Assuming cartesian Coordinate system [2D]
			pPosOfCurrParticle->SetX(iIdx * iGridParams.dx * iGeometricParams2D.Rec.Length);	// Set 'X' Coordinate
			pPosOfCurrParticle->SetY(jIdx * iGridParams.dy * iGeometricParams2D.Rec.Height);	// Set 'Y' Coordinate

			// Get current particle pointer and update its position
			pCurrentParticle = oListOfParticles[iCurrParticle];
			pCurrentParticle->SetPosition(pPosOfCurrParticle);	// TODO: Copy obj if required
			iCurrParticle++;
			//delete pPosOfCurrParticle;  // TODO: Check if life cycle manages propertly
										  // Addref and release must be added.
		}
	}

	return false;
}
