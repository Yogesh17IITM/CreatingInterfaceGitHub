#pragma once

#include<vector>

#include "Particle.h"

// DLL Exports
#include "FactoryDLLExport.h"

 enum class FACTORYDLLEXPORT INTERFACE_ID
{
	IID_Position = 1,
	IID_Particle = 2,
	IID_AirParticle = 3,
	IID_WaterParticle = 4,
	IID_CalculatePosition = 5
};

// Create an Instance
bool FACTORYDLLEXPORT CreateInstance(void ** opp, const INTERFACE_ID iInterfaceID);

// Create Multiple instances of same type
bool FACTORYDLLEXPORT CreateMultipleParticleInstances(vector<Particle*>& oListOfParticles, const int iNoOfParticles, const INTERFACE_ID iInterfaceID = INTERFACE_ID::IID_Particle);


