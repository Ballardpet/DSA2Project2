/**********************************************************
 * Author:      Peter Ballard
 * Assignment:  Project 2
 * Date:        10-06-2024
 * File:        analyticalModel.cpp
 * Description: Implements the AnalyticalModel methods
 **********************************************************/

#include "analyticalModel.hpp"

AnalyticalModel::AnalyticalModel(string filePath){
    this->filePath = filePath;
    readFromFile();
    runModel();
}

bool AnalyticalModel::readFromFile(){
    ifstream infile;
    infile.open(filePath);
    if(infile.fail()){
        std::cout << "The file could not be found";
        infile.close();
        infile.clear();
        return false;
    }
    else{
        string i;
        int j = 0;
        int inputArray[5];
        while (getline(infile,i)){
            inputArray[j] = stoi(i);
            j++;
        }
        lambda = inputArray[0];
        mu = inputArray[1];
        m = inputArray[2];
    }
    infile.close();
    infile.clear();
    return true;
}

void AnalyticalModel::runModel(){
    
    computeP0();
    computeL();
    computeW();
    computeLq();
    computeWq();
    computeRho();
    std::cout << toString();
}

void AnalyticalModel::computeP0(){
    double bottomLeft = 0;
    double bottomRight = 0;
    for (int i = 0; i < m; i++) { 
        bottomLeft +=  ((1/factorial(i)) * (pow((lambda / mu), i)));
    }
    bottomRight = (pow((lambda/mu),m)/factorial(m));
    bottomRight *= ((m * mu)/((m *mu)-lambda));
    p0 = (1 / (bottomLeft + bottomRight));
}

void AnalyticalModel::computeL(){
    double leftTop = 0;
    double leftBottom = 0;
    leftTop = lambda * mu * pow((lambda/mu),m);
    leftBottom = factorial(m - 1) * pow((m * mu) - lambda,2);
    l = leftTop / leftBottom;
    l *= p0;
    l += (lambda / mu);
}

void AnalyticalModel::computeW(){
    w = (l/lambda);
}

void AnalyticalModel::computeLq(){
    lq = l -(lambda/mu);
}

void AnalyticalModel::computeWq(){
    wq = (lq/lambda);
}

void AnalyticalModel::computeRho(){
    rho = (lambda/(m*mu));
}

string AnalyticalModel::toString(){
    string results = "Analytical model results from " + filePath + "\n";
    results += "P0 = " + to_string(p0) + "\n";
    results += "L = " + to_string(l) + "\n";
    results += "W = " + to_string(w) + "\n";
    results += "Lq = " + to_string(lq) + "\n";
    results += "Wq = " + to_string(wq) + "\n";
    results += "Rho = " + to_string(rho) + "\n\n";

    return results;
}

int AnalyticalModel::factorial(int theNum){
    if (theNum == 0 || theNum == 1){
        return 1;
    }
    int temp = 1;
    for (int i = 1; i <= theNum; i++){
        temp *= i;
    }
    return temp;
}