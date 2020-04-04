#pragma once

// DLL Exports
#ifdef IMPLEMENTATIONDLL_EXPORTS
#  define IMPLEMENTATIONDLLEXPORT __declspec(dllexport)
#else
#  define IMPLEMENTATIONDLLEXPORT __declspec(dllimport)
#endif

#include<string>
#include<vector>
using namespace std;

// Base Class
#include "Particle.h"

// Dependencies
// <include headers here...>

// Forward declarations
class GridParams;
class GeometricParams2D;

class IMPLEMENTATIONDLLEXPORT ImplParticle : public Particle
{	
public:
	ImplParticle();
	virtual ~ImplParticle();

	virtual void SetPosition(const Position * iPosition) override;
	virtual void GetPosition(Position *& oPosition) const override;

	virtual void SetDensity(const double& iDensity) override;
	virtual void GetDensity(double& oDensity) const override;

	virtual void SetMass(const double& iMass) override;
	virtual void GetMass(double& oMass) const override;
		
	virtual string GetParticleType() const override;

protected:
	Position* _pPosition;
	double _Density, _Mass;	
};

