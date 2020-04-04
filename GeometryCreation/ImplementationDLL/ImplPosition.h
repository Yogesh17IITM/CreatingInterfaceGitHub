#pragma once

// DLL Exports
#ifdef IMPLEMENTATIONDLL_EXPORTS
#  define IMPLEMENTATIONDLLEXPORT __declspec(dllexport)
#else
#  define IMPLEMENTATIONDLLEXPORT __declspec(dllimport)
#endif

// Base class
#include "Position.h"

// Dependencies
// <include headers here...>

class IMPLEMENTATIONDLLEXPORT ImplPosition : public Position
{
private:
	double _X, _Y, _Z;

public:
	ImplPosition();
	virtual ~ImplPosition();

	// Pure Virtual Methods
	virtual void SetX(const double& iX);
	virtual void SetY(const double& iY);
	virtual void SetZ(const double& iZ);
	virtual double GetX() const;
	virtual double GetY() const;
	virtual double GetZ() const;
};

