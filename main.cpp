/**********************************************************
 * Author:      Peter Ballard
 * Assignment:  Project 2
 * Date:        10-06-2024
 * File:        main.cpp
 * Description: Runs the analytical models and simulators for test1 and test2
 **********************************************************/

#include <iostream>
#include "simulator.hpp"
#include "analyticalModel.hpp"

using namespace std;

int main(){
    AnalyticalModel test1("test1.txt");
    Simulator simTest1("test1.txt");
    AnalyticalModel test2("test2.txt");
    Simulator simtest2("test2.txt");
}
