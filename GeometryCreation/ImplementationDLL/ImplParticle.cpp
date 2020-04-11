#include "ImplParticle.h"
#include "ImplPosition.h"
#include "Params.h"

ImplParticle::ImplParticle()
{
	_Density = 0.0;
	_Mass = 0.0;
	_pPosition = NULL;
}

ImplParticle::~ImplParticle()
{
	_pPosition = NULL;	
}

void ImplParticle::SetPosition(const Position * iPosition)
{	
	_pPosition = const_cast<Position*>(iPosition);
}

void ImplParticle::GetPosition(Position *& oPosition) const
{
	if(_pPosition)
		oPosition = _pPosition;
}

void ImplParticle::SetDensity(const double& iDensity)
{
	_Density = iDensity;
}

void ImplParticle::GetDensity(double& oDensity) const
{
	oDensity = _Density;
}

void ImplParticle::SetMass(const double& iMass)
{
	_Mass = iMass;
}

void ImplParticle::GetMass(double& oMass) const
{
	oMass = _Mass;
}

string ImplParticle::GetParticleType() const
{
	return "Unknown";
}
