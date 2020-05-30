// Std Libraries
#include<iostream>
#include<fstream>

// User-Defined headers
#include "Params.h"
#include "Utilities.h"

// The 'Using' directives
using namespace std;

// Macro definitions
#define PATHTOOPEN(Filename) "C:/Users/YOGESH/Documents/Input/"+(Filename)+".txt"

/* FUNCTION DEFINITIONS */
void GetDataFor2DGeometry(GeometricParams2D& oGeometricParams2D)
{
    int DomainType = 1;	// Set Default to 1 (Rectangle)
    double BottomLeft_X = 0, BottomLeft_Y = 0.0;
    double TopRight_X = 0, TopRight_Y = 0;

    // Read Inputs from file
#pragma region ReadInputsFromFile
    string strFilename = "CreateGeometryInput";
    ifstream inputfile(PATHTOOPEN(strFilename));
    bool bIsReadInputFromFile = false;
    if (inputfile.is_open())
    {
        bIsReadInputFromFile = true;
        string strLine;
        int count = 0;
        while (getline(inputfile, strLine))
        {
            count++;
            // Parsing inputs		
            if (1 == count)	// Get Domain Type
            {
                if ("Rectangle" == strLine) { DomainType = 1; }
                else if ("Triangle" == strLine) { DomainType = 2; }
                else { DomainType = 3; }
            }
            else if (2 == count) { BottomLeft_X = atof(strLine.c_str()); }
            else if (3 == count) { BottomLeft_Y = atof(strLine.c_str()); }
            else if (4 == count) { TopRight_X = atof(strLine.c_str()); }
            else if (5 == count) { TopRight_Y = atof(strLine.c_str()); break; }
        }
    }
#pragma endregion

    // Read User Inputs
#pragma region ReadUserInputs
    if (!bIsReadInputFromFile)
    {
        DisplayMessage("Specify Domain Type: 1 (for rectangle), 2 (for triangle) and 3 (for circle)");
        cin >> DomainType;

        DisplayMessage("Specify geometric parameters");
        BottomLeft_X = GetParam("BottomLeft_X");
        BottomLeft_Y = GetParam("BottomLeft_Y");
        TopRight_X = GetParam("TopRight_X");
        TopRight_Y = GetParam("TopRight_Y");
    }
#pragma endregion

    oGeometricParams2D.GeometricType = static_cast<GeometricParams2D::GEOMETRIC_TYPE>(DomainType);
    switch (oGeometricParams2D.GeometricType)
    {
    case GeometricParams2D::GEOMETRIC_TYPE::Rectangle:
        oGeometricParams2D.Rec.Length = abs(TopRight_X - BottomLeft_X);
        oGeometricParams2D.Rec.Height = abs(TopRight_Y - BottomLeft_Y);
        break;
    case GeometricParams2D::GEOMETRIC_TYPE::Triangle:
        oGeometricParams2D.Tri.Base = GetParam("Base");
        oGeometricParams2D.Tri.Height = GetParam("Height");
        oGeometricParams2D.Tri.CentreX = GetParam("Centre X");
        oGeometricParams2D.Tri.CentreY = GetParam("Centre Y");
        break;
    case GeometricParams2D::GEOMETRIC_TYPE::Circle:
        oGeometricParams2D.Cir.Radius = GetParam("Radius");
        oGeometricParams2D.Cir.CentreX = GetParam("Centre X");
        oGeometricParams2D.Cir.CentreY = GetParam("Centre Y");
        break;
    default:
        break;
    }
}

bool CalculateGridSize(GridParams& oGridParams, const GeometricParams2D& iGeometricParams2D)
{
    bool oReturnVal = false;

    // Read Inputs from file
#pragma region ReadInputsFromFile
    string strFilename = "CreateGeometryInput";
    ifstream inputfile(PATHTOOPEN(strFilename));
    bool bIsReadInputFromFile = false;
    if (inputfile.is_open())
    {
        bIsReadInputFromFile = true;
        string strLine;
        int count = 0;
        while (getline(inputfile, strLine))
        {
            count++;
            // Parsing inputs
            if (6 == count) { oGridParams.NX = atoi(strLine.c_str()); }
            if (7 == count) { oGridParams.NY = atoi(strLine.c_str()); break; }
        }
    }
#pragma endregion

    // Read User Inputs
#pragma region ReadUserInputs
    if (!bIsReadInputFromFile)
    {
        DisplayMessage("Specify number of particles along each direction");
        oGridParams.NX = GetParam("NX");	// along X Direction
        oGridParams.NY = GetParam("NY");	// along Y Direction
    }
#pragma endregion

    // Calc. Grid size
    if (GeometricParams2D::GEOMETRIC_TYPE::Rectangle == iGeometricParams2D.GeometricType)
    {
        if ((oGridParams.NX > 1) && (oGridParams.NY > 1))
        {
            oGridParams.dx = iGeometricParams2D.Rec.Length / (oGridParams.NX - 1.0);
            oGridParams.dy = iGeometricParams2D.Rec.Height / (oGridParams.NY - 1.0);
            oReturnVal = true;
        }
    }
    else if (GeometricParams2D::GEOMETRIC_TYPE::Triangle == iGeometricParams2D.GeometricType)
    {
    }
    else if ((GeometricParams2D::GEOMETRIC_TYPE::Circle == iGeometricParams2D.GeometricType))
    {
    }
    else
    {	// handle exceptions for INVALID_GEOMETRIC_TYPE		
    }

    return oReturnVal;
}
