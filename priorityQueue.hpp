/**********************************************************
 * Author:      Peter Ballard
 * Assignment:  Project 2
 * Date:        10-06-2024
 * File:        priorityQueue.hpp
 * Description: A priority queue to keep track of the arrivals and departures of customers. should be implemented as a heap
 **********************************************************/

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include "customer.hpp"
using namespace std;

class PriorityQueue{
    public:
        PriorityQueue();
        bool isEmpty();
    private:
        int M;
        void percolateUp();
        void percolateDown();
        Customer custHeap[200];
};

#endif


// Notes about heap for me
// starts at 1 
// children are at i*2 and i*2+1