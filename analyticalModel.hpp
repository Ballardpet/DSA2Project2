/**********************************************************
 * Author:      Peter Ballard
 * Assignment:  Project 2
 * Date:        10-06-2024
 * File:        analyticalModel.hpp
 * Description: takes in input from a test file and uses formulas to calculate statistical information
 **********************************************************/

#ifndef ANALYTICALMODEL_HPP
#define ANALYTICALmODEL_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

// Pretty sure this just does all of the math at the end
// Maybe it does the math at the start to figure out how long to randomize shit !!!!!!!!!
class AnalyticalModel{
    public:
        AnalyticalModel(string filePath);
        void computeP0(); // percent idle time. amount of time that no one is in the system
        void computeL(); // avg number of people in the system (number in line plus being served)
        void computeW(); // avg time a customer spends in the system. time in line plus time getting service
        void computeLq();
        void computeWq(); // avg time a customer spends waiting in the queue
        void computeRho(); // utilization factor for the system. proproton of the sustems resources
        string toString();
        bool readFromFile(); // will take necessary data from the file
        void runModel(); // runs all necessary functions;
        int factorial(int theNum); // returns a factorial

    private:
        string filePath;
        // These will be read from the file and initialized in the constructor
        double lambda;
        double mu;
        int m;
        // These will be calculated by the program
        double p0;
        double l;
        double w;
        double lq;
        double wq;
        double rho;
};

#endif

// When the program runs, it will compute and display all size values from the analytical Model
