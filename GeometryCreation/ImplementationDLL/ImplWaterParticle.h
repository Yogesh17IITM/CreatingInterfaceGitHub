#pragma once
#include "ImplParticle.h"
class IMPLEMENTATIONDLLEXPORT ImplWaterParticle : public ImplParticle
{
public:
	ImplWaterParticle();
	virtual ~ImplWaterParticle();

	virtual string GetParticleType() const override final;
};

