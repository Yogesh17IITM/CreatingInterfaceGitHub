#pragma once

#include<string>
using namespace std;

// DLL Exports
#include "InterfaceDLLExport.h"

// Include headers
#include "ImplMaster.h"

// Forward declarations
class Position;
class GridParams;
class GeometricParams2D;

class INTERFACEDLLEXPORT Particle : public ImplMaster
{
public:
	Particle();
	virtual ~Particle();

	// Pure Virtual Methods
	virtual void SetPosition(const Position * iPosition) = 0;
	virtual void GetPosition(Position *& oPosition) const = 0;

	virtual void SetDensity(const double& iDensity) = 0;
	virtual void GetDensity(double& oDensity) const = 0;

	virtual void SetMass(const double& iMass) = 0;
	virtual void GetMass(double& oMass) const = 0;
		
	virtual string GetParticleType() const = 0;
};

