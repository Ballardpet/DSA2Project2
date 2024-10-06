/**********************************************************
 * Author:      Peter Ballard
 * Assignment:  Project 2
 * Date:        10-06-2024
 * File:        fifoQueue.hpp
 * Description: A first-in, first-out queue to represent a line of customers waiting
 **********************************************************/

#ifndef FIFOQUEUE_HPP
#define FIFOQUEUE_HPP
#include "customer.hpp"
using namespace std;

class FifoQueue{
    public:
        FifoQueue();
        void push(Customer temp);
        Customer pop();
        Customer peek();
        bool isEmpty();
    private:
        Customer* first;
        Customer* last;
};

#endif