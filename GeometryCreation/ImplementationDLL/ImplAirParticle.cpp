#include "ImplAirParticle.h"

ImplAirParticle::ImplAirParticle()
{
	_Density = 1.14;
}

ImplAirParticle::~ImplAirParticle()
{
}

string ImplAirParticle::GetParticleType() const
{
	return "AIR";
}
