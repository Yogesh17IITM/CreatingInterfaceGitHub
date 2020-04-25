#pragma once

// DLL Exports
#include "MasterDLLExport.h"

class MASTERDLLEXPORT Master
{
public:
	Master();
	virtual ~Master();

	// To manage lifecycle of instance
	virtual void AddRef() = 0;
	virtual void Release() = 0;
};

