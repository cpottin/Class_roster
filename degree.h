//  degree.h
//  C867 Roster Project
//
//  Created by Cynthia Pottin on 2/22/22.
//

#ifndef degree_h
#define degree_h
#pragma once
#include<string>
using namespace std;

enum DegreeProgram
{
    SECURITY,
    NETWORK,
    SOFTWARE
    
};

//convert enum DegreeProgram into string for printing
static const string degreeProgramStrings[] = {"SECURITY", "NETWORK", "SOFTWARE"};

#endif /* degree_h */
