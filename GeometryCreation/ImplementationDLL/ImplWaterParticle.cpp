#include "ImplWaterParticle.h"

ImplWaterParticle::ImplWaterParticle()
{
	_Density = 1000.0;
}

ImplWaterParticle::~ImplWaterParticle()
{
}

string ImplWaterParticle::GetParticleType() const
{
	return "WATER";
}
