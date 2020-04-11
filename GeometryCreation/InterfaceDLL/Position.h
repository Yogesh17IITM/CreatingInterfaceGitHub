#pragma once

// DLL Exports
#include "InterfaceDLLExport.h"

class INTERFACEDLLEXPORT Position
{	
public:
	Position();
	virtual ~Position();

	// Pure Virtual Methods
	virtual void SetX(const double& iX) = 0;
	virtual void SetY(const double& iY) = 0;
	virtual void SetZ(const double& iZ) = 0;
	virtual double GetX() const = 0;
	virtual double GetY() const = 0;
	virtual double GetZ() const = 0;
};

