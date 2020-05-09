#pragma once

// DLL Exports
#include "UtilitiesDLLExport.h"

// Std Libraries
#include<string>
#include<vector>

// Dependencies
#include "ImplMaster.h"

// Using directives
using namespace std;

// Forward Declarations
class Particle;

/* FUNCTION DECLARATIONS */

/* FUNCTION: GetParam
@Description : Function to Get input param of double type
@in          : iParam - Parameter name (string)
@out         : NA
@return      : Parameter value as specified by the user */
UTILITIESDLLEXPORT double GetParam(string iParam);

/* FUNCTION: DisplayMessage
@Description : Function to display message 
@in          : iStrMsg - Message to display
@out         : NA
@return      : NA */
UTILITIESDLLEXPORT void DisplayMessage(string iStrMsg);

/* FUNCTION: DisplayMessage
@Description : Function to write data information to a file
@in          : iListOfParticles - Contains list of Particle information 
			 : iNameOfFile - Name of the output file
@out         : <Filename>.csv will be generated in C:/Users/YOGESH/Documents/Output/
@return      : bool type 
			 : true - if file successfully created
			 : false - if unable to create file */
UTILITIESDLLEXPORT bool WriteToFile(const vector<Particle*> & iListOfParticles, const string & iNameOfFile);

/* CLASS DECLARATIONS */
template<class T>
class SmartPtr
{
	ImplMaster* _ptr;
public:
	explicit SmartPtr(ImplMaster* ip = NULL)
	{
		_ptr = ip;
		if (_ptr)
			_ptr->AddRef();
	}
	virtual ~SmartPtr()
	{
		if (NULL != _ptr)
			_ptr->Release();			
	}
	SmartPtr& operator=(ImplMaster* ip)
	{
		this->_ptr = ip;
		if (_ptr)
			_ptr->AddRef();
		return *this;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return (T*)_ptr; }	
	operator bool() const { return (_ptr) ? true : false; }
};
