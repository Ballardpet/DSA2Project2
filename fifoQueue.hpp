// will hold arrivals wating for service

#ifndef FIFOQUEUE_HPP
#define FIFOQUEUE_HPP
#include "customer.hpp"
using namespace std;

// pretty sure this is the line the customers are waiting in
// make a seperate customer class !!!!
class FifoQueue{
    public:
        void push();
        Customer pop();
    private:
};

#endif