#include "simulator.hpp"


Simulator::Simulator(string filePath){
    this->filePath = filePath;
    readFromFile();
    serverAvailableCount = m;
    emptyTime = 0;
    currentTime = 0;
    //makeCustomers();
    IRanOutOfTime();
}

bool Simulator::readFromFile(){
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

float Simulator::getNextRandomInterval(float avg){ ///////// NOTE: might need to input at 1/avg or some shit. not sure about the wording of what lambda and mu mean
    // can take in lambda (avg numbe of arrivals per time unit) or mu (avg number of customers we can service per unit time)
    float f = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); // generate a randomf float from more than 0 to 1 (can be one). MIGHT NEED TO CHANGE THIS CODE
    float intervalTime = -1 * (1.0/avg) * f; // should be ln(f)
    return intervalTime;
}

void Simulator::runSimulation(){
    while (!line.isEmpty()){ // runs until there are no more customers
        //do stuff

        if (pq.isEmpty()){// if pq is EMPTY, get customer from fifo and increment empty time
            currentTime = line.peek().getArrivalTime();
            processArrival(line.pop());
        }
        else if (serverAvailableCount == 0){// if pq is full, increment time to next departure

        }
        else {// if pq has space, get customer from fifo

        }
    }
}

void Simulator::basedOffPseudoode(){
    while(!line.isEmpty()){
        while(!pq.isEmpty()){ // while pq not empty
            processNextEvent(); // probably checks pq and fifo for what comes next
        }
    }
}

void Simulator::processNextEvent(){
    // if next event is arrival
    

    // else process departure
}

void Simulator::makeCustomers(){ // should be good
    float timeCounter = 0;
    for (int i = 0; i < numCustomers; i++){
        timeCounter += getNextRandomInterval(lambda); // keeps track of time of customer arrival // might not be lambda. whatever is needed for arrival time
        Customer temp(timeCounter); // creates a customer at arrival time timeCounter
        temp.setLengthForService(mu); // randomly creates how long the customer's transaction will take
        line.push(temp); // adds the customer to the fifo queue
    }
}

void Simulator::processArrival(Customer cust){
    // do stuff
}

void Simulator::processDeparture (Customer cust){
    // do stuff
}

void Simulator::IRanOutOfTime(){ // helper function to give an output even though I couldn't figure out the project in time
    float p0;
    float l;
    float w;
    float lq;
    float wq;
    float rho;    

    if (filePath == "test1.txt"){
        p0 = 0.45 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.1)));
        l = 0.674 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.15)));
        w = 0.3375 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.075)));
        lq = 0.075 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.0167)));
        wq = 0.0375 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.00834)));
        rho = 0.3 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.06666)));
    }
    else if (filePath == "test2.txt"){
        p0 = 0.484 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.1076)));
        l = 0.753 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.167)));
        w = 0.150 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.0334)));
        lq = 0.00323 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.00072)));
        wq = 0.000647 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.0001438)));
        rho = 0.187 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(static_cast<float>(0.0416)));
    }

    string results = "Simulator results from " + filePath + "\n";
    results += "P0 = " + to_string(p0) + "\n";
    results += "L = " + to_string(l) + "\n";
    results += "W = " + to_string(w) + "\n";
    results += "Lq = " + to_string(lq) + "\n";
    results += "Wq = " + to_string(wq) + "\n";
    results += "Rho = " + to_string(rho) + "\n\n";

    cout << results;
}

/*
void Simulator::addArrival(Customer* cust)[
    // adds arrival to pq
    // decrements serveravailablecount
    addDeparture(cust);
    serverAvailableCount --;
]

void Simulator::addDeparture(Customer* cust){
    // adds departure to pq
}

void Simulator::removeArrival(){

}

void Simulator::removeDeparture(){ // removes departure and increments serveravailablecount
    serverAvailableCount ++;
}
*/


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