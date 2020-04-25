#include "ImplMaster.h"

ImplMaster::ImplMaster()
{
	m_RefCount = 0;
}

ImplMaster::~ImplMaster()
{
}

void ImplMaster::AddRef()
{
	m_RefCount++;
}

void ImplMaster::Release()
{
	if (0 == m_RefCount)
	{
		delete this;
	}
	else
	{
		m_RefCount--;		
	}
}
