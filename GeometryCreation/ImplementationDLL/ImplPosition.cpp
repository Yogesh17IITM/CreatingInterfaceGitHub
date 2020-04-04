#include "ImplPosition.h"

#include <iostream>
using namespace std;

ImplPosition::ImplPosition()
{
	_X = _Y = _Z = 0;
}

ImplPosition::~ImplPosition()
{
}

void ImplPosition::SetX(const double& iX)
{
	_X = iX;
}

void ImplPosition::SetY(const double& iY)
{
	_Y = iY;
}

void ImplPosition::SetZ(const double& iZ)
{
	_Z = iZ;
}

double ImplPosition::GetX() const
{
	return _X;
}

double ImplPosition::GetY() const
{
	return _Y;
}

double ImplPosition::GetZ() const
{
	return _Z;
}

