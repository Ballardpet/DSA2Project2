#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
using namespace std;
#include "fifoQueue.hpp"
#include "priorityQueue.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

// pretty sure this simulates time passing and customers coming in
class Simulator{
    public:
        Simulator(string filePath);
        bool readFromFile(string filePath);
        float getNextRandomInterval(float avg); // avg can be lmbda or mu
        void processNextEvent();
        void runSimulation();
        void processStatistics();

        void makeCustomers();
    private:
        int numEvents; // number of events to simulate
        FifoQueue line; // customers in line
        PriorityQueue pq;
        double lambda;
        double mu;
        int m;
        int numCustomers;

        void addArrival(Customer* cust);
        void addDeparture(Customer* cust);
        void removeArrival(); // might need a customer?
        void removeDeparture();

        //FifoQueue completed; // stores customers when they finish so their data can be collected
        vector<Customer> completed; // stores customers when they finish so their data can be collected
        float emptyTime; // keeps track of how long the line is empty


};

#endif




// How I assume this will work
// Simulator will make all of the random intervals
    // I feel like this is exactly what he did in the example
    // Probably needs the analytical model to figure out that numbers and shit
    // Maybe they all goo immediately into the fifo queue and then go into the priority queue
// put the first M of them into the priority queue and the rest in the fifo
// will then do all the math and shit to figure out how long it will have to wait



