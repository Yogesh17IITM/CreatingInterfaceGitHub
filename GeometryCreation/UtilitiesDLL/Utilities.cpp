#include "Utilities.h"

// Std libraries
#include<iostream>
#include<fstream>

// Interfaces
#include "Particle.h"
#include "Position.h"

// Include the 'Using' directives
using namespace std;

// Macro definitions
#define PATHTOWRITE(Filename) "C:/Users/YOGESH/Documents/Output/"+(Filename)+".csv"

/* FUNCTION DEFINITIONS */

// TODO: Use template functions instead of specfic datatype in the below case
double GetParam(string iParam)
{
	double oParam;
	cout << "Specify " << iParam << endl;
	cin >> oParam;
	return  oParam;
}

void DisplayMessage(string iStrMsg)
{
	cout << iStrMsg << endl;
}

bool WriteToFile(const vector<Particle*>& iListOfParticles, const string& iNameOfFile)
{
	bool oReturnVal = false;
	ofstream file;	
		
	file.open(PATHTOWRITE(iNameOfFile));	
	if (file.is_open())
	{
		oReturnVal = true;	// File opened Successfully		
		file << "X,Y,Density" << endl;
				
		for (int iParticle = 0; iParticle < iListOfParticles.size(); iParticle++)
		{
			Particle* pParticle = iListOfParticles[iParticle];

			// Get Position of current particle
			Position* pPosition = NULL;
			pParticle->GetPosition(pPosition);

			// Get Density of current particle
			double density;
			pParticle->GetDensity(density);

			// TODO: Print other properties such as mass, velocity, etc
			file << pPosition->GetX() << "," << pPosition->GetY() << "," << density << endl;
		}
		file.close();
	}
	else
	{
		// TODO: Throw error message with return code for indicating "Unable to open file"
		cout << "Unable to open file" << endl;
	}
	
	return oReturnVal;
}

