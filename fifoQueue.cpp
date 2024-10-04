#include "fifoQueue.hpp"
#include <stdlib.h>
#include <iostream>

FifoQueue::FifoQueue(){
    first = nullptr;
    last = nullptr;
}

void FifoQueue::push(Customer temp){
    if (first == nullptr){
        *first = temp;
        *last = temp;
    }
    else {
        last->setNextCust(&temp);
        *last = temp; // pretty sure this makes last point at new last
    }
}

 Customer FifoQueue::pop(){
    //if (first == nullptr){
        //return NULL; // get back to this later
    //}
    //else {
        Customer temp(first->getArrivalTime());
        temp.SetStartOfServiceTime(first->getServiceTime());
        temp.setNextCust(first->getNext());
        delete first;
        first = temp.getNext();
        if (temp.getNext() == nullptr){
            last = nullptr;
        }
        return temp;

    //}
 }

 Customer FifoQueue::peek(){
    Customer temp(first->getArrivalTime());
    temp.SetStartOfServiceTime(first->getServiceTime());
    temp.setNextCust(first->getNext());
    return temp; // wrong. should delete temp. need to find a way to dereference customers
 }