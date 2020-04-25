#pragma once

// DLL Exports
#include "MasterDLLExport.h"

// Base class
#include "Master.h"

class MASTERDLLEXPORT ImplMaster :	public Master
{
public:
	ImplMaster();
	virtual ~ImplMaster();

	// To manage lifecycle of instance(s)
	virtual void AddRef() override;
	virtual void Release() override;

private:
	int m_RefCount;		// representing number of references made.
};

