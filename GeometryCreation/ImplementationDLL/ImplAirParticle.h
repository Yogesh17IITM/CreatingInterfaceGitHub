#pragma once
#include "ImplParticle.h"
class IMPLEMENTATIONDLLEXPORT ImplAirParticle :	public ImplParticle
{
public:
	ImplAirParticle();
	virtual ~ImplAirParticle();

	virtual string GetParticleType() const override final;
};

