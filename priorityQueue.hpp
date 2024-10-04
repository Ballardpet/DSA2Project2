// this will be made out of a heap
// It will hold arrival events and departure events

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
using namespace std;

// pretty sure this represents the available tellers
// min heap
// cap at 200
class PriorityQueue{
    public:
    private:
        int M; // Number of channels
        void percolateUp();
        void percolateDown();
};

#endif