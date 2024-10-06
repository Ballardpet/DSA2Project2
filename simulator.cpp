#include "simulator.hpp"


Simulator::Simulator(string filePath){
    readFromFile(filePath);
    makeCustomers();
}

bool Simulator::readFromFile(string filePath){
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
        numCustomers = inputArray[3];
    }
    infile.close();
    infile.clear();
    return true;
}

float getNextRandomInterval(float avg){ ///////// NOTE: might need to input at 1/avg or some shit. not sure about the wording of what lambda and mu mean
    // can take in lambda (avg numbe of arrivals per time unit) or mu (avg number of customers we can service per unit time)
    float f = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); // generate a randomf float from more than 0 to 1 (can be one). MIGHT NEED TO CHANGE THIS CODE
    float intervalTime = -1 * (1.0/avg) * ln(f);
    return intervalTime;
}

void Simulator::runSimulation(){
    makeCustomers(); // makes customers and fills fifo
}

void Simulator::makeCustomers(){ // should be good
    float timeCounter = 0;
    for (int i = 0; i < numEvents; i++){
        timeCounter += getNextRandomInterval(lambda); // keeps track of time of customer arrival // might not be lambda. whatever is needed for arrival time
        Customer temp(timeCounter); // creates a customer at arrival time timeCounter
        temp.setLengthForService(mu); // randomly creates how long the customer's transaction will take
        line.push(temp); // adds the customer to the fifo queue
    }
}

void Simulator::addArrival(Customer* cust)[
    // adds arrival to pq
    addDeparture(cust);
]

void Simulator::addDeparture(Customer* cust){
    // adds departure to pq
}

void Simulator::removeArrival(){

}

void Simulator::removeDeparture(){

}


/**
 * start by generating all customers and putting them in the fifo
 * 
 * populate pq with arrival events as they come
 *      with each arrival, also auto generate a departure event
 * 
 * when the departure event happens check the pq for an arrival event. ALso put the departure in an array of finished customers for math
 *      if there is an event, put it in the pq
 *      if not, wait fot the next event (increment the idle time)
 *              for p0, increment idle time and total time as the program runs and do the math at the end
 *      *continue this until there are no more events
 */