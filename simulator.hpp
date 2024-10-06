/**********************************************************
 * Author:      Peter Ballard
 * Assignment:  Project 2
 * Date:        10-06-2024
 * File:        simulator.hpp
 * Description: This class will simulate the random arrival of customers and keep track of 
 *              various statistics based on their vist
 * Note: This is an unfinished class. I created the "IRanOutOfTime" method to give the program
 *       an acutal output, but the simulator class does not work.
 **********************************************************/

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
        bool readFromFile();
        float getNextRandomInterval(float avg); // avg can be lmbda or mu
        void processNextEvent();
        void runSimulation();
        void processStatistics();
        void basedOffPseudoode();
        void makeCustomers();
    private:
        FifoQueue line; // customer storage. should only hold arrival times
        PriorityQueue pq; // event storage. should only hold departure times
        double lambda;
        double mu;
        int m;
        int numCustomers;
        int serverAvailableCount;

        void processArrival(Customer cust);
        void processDeparture (Customer cust);

        vector<Customer> completed; // stores customers when they finish so their data can be collected
        float currentTime; // keeps track of the current time in the program
        float emptyTime; // keeps track of how long the line is empty
        string filePath;

        void IRanOutOfTime(); // function to give me some output because I ran out of time on the project
};

#endif




// How I assume this will work
// Simulator will make all of the random intervals
    // I feel like this is exactly what he did in the example
    // Probably needs the analytical model to figure out that numbers and shit
    // Maybe they all goo immediately into the fifo queue and then go into the priority queue
// put the first M of them into the priority queue and the rest in the fifo
// will then do all the math and shit to figure out how long it will have to wait



