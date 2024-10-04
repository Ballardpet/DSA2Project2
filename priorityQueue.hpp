// this will be made out of a heap
// It will hold arrival events and departure events

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include "customer.hpp"
using namespace std;

// pretty sure this represents the available tellers
// min heap
// cap at 200
class PriorityQueue{
    public:
    private:
        int M; // Number of channels. IDK if this even goes here
        void percolateUp();
        void percolateDown();
        Customer custHeap[200];
};

#endif


// Notes about heap for me
// starts at 1 
// children are at i*2 and i*2+1