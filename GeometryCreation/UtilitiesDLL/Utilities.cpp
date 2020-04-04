#include "Utilities.h"

#include<iostream>

// The 'Using' directives
using namespace std;

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