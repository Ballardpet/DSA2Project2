#include "customer.hpp"
#include <stdlib.h>
#include <iostream>

Customer::Customer(float arrivalTime){
    this->arrivalTime = arrivalTime;
    nextCust = nullptr;
}

void Customer::setArrivalTime(float time){
    arrivalTime = time;
}

void Customer::SetStartOfServiceTime(float time){
    startOfServiceTime = time;
}

void Customer::setNextCust(Customer* next){
    nextCust = next;
}

float Customer::getArrivalTime(){
    return arrivalTime;
}

float Customer::getServiceTime(){
    return startOfServiceTime;
}

Customer* Customer::getNext(){
    return nextCust;
}