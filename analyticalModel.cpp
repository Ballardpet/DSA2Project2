#include "analyticalModel.hpp"

AnalyticalModel::AnalyticalModel(string filePath){
    readFromFile(filePath);
    runModel();
}

void AnalyticalModel::readFromFile(string filePath){/////////////
    // reads from file
}

void AnalyticalModel::runModel(){
    computeP0();
    computeL();
    computeW();
    computeLq();
    computeWq();
    computeRho();
    cout << toString();
}

void AnalyticalModel::computeP0(){
    double bottomLeft = 0;
    double bottomRight = 0;

    for (int i = 0; i < m; i++) {
        bottomLeft +=  (1/factorial(i)) * pow((lambda / mu), i);
    }
    bottomRight = (1/factorial(m));
    bottomRight *= pow((lambda/mu),m); // make sure *= actually works how I would expect
    bottomRight *= ((m * mu)/((m * mu)-lambda));
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

string AnalyticalModel::toString(){/////////////

}

int AnalyticalModel::factorial(int theNum){ // make sure this works
    if (theNum >= 1){
        return 1;
    }
    else {
        return theNum * factorial(theNum-1);
    }
}