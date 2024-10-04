// will hold arrivals wating for service

#ifndef FIFOQUEUE_HPP
#define FIFOQUEUE_HPP
#include "customer.hpp"
using namespace std;

// pretty sure this is the line the customers are waiting in
// make a seperate customer class !!!!
class FifoQueue{
    public:
        FifoQueue();
        void push(Customer temp);
        Customer pop();
        Customer peek();
    private:
        Customer* first;
        Customer* last;
};

#endif