#include "Factory.h"

// Include dependencies
#include "ImplPosition.h"
#include "ImplParticle.h"
#include "ImplAirParticle.h"
#include "ImplWaterParticle.h"
#include "ImplCalculatePosition.h"

bool CreateInstance(void** opp, const INTERFACE_ID iInterfaceID)
{
	bool oReturnVal = false;

	if (NULL == (*opp))
	{
		switch (iInterfaceID)
		{
		case INTERFACE_ID::IID_Position:
			(*opp) = new ImplPosition();
			break;
		case INTERFACE_ID::IID_Particle:
			(*opp) = new ImplParticle();
			break;
		case INTERFACE_ID::IID_AirParticle:
			(*opp) = new ImplAirParticle();
			break;
		case INTERFACE_ID::IID_WaterParticle:
			(*opp) = new ImplWaterParticle();
			break;
		case INTERFACE_ID::IID_CalculatePosition:
			(*opp) = new ImplCalculatePosition();
			break;
		default:
			break;
		}
	
		if (opp)	
			oReturnVal = true;		
	}
	return oReturnVal;
}

bool FACTORYDLLEXPORT CreateMultipleParticleInstances(vector<Particle*>& oListOfParticles, const int iNoOfParticles, const INTERFACE_ID iInterfaceID)
{
	bool oReturnVal = false;

	if (0 == oListOfParticles.size())
	{
		oListOfParticles.resize(iNoOfParticles);
		oReturnVal = true;
	}
	else
	{
		oReturnVal = false;		// Instance already created
	}

	if (oReturnVal)
	{
		for (int iParticle = 0; iParticle < oListOfParticles.size(); iParticle++)
		{
			Particle* pParticle = NULL;
			oReturnVal = CreateInstance((void**)&pParticle, iInterfaceID);			
			if (oReturnVal)
			{
				oListOfParticles[iParticle] = pParticle;
				pParticle->AddRef();		// Call AddRef() when a pointer is referenced.
			}
			else
			{
				break;
			}
			pParticle->Release();			// Call Release() when it scope ends.
		}
	}

	return oReturnVal;
}

