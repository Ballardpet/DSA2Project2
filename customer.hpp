/**********************************************************
 * Author:      Peter Ballard
 * Assignment:  Project 2
 * Date:        10-06-2024
 * File:        customer.hpp
 * Description: Creates a customer to be stored in the queues and simulated in the simulator
 **********************************************************/

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
using namespace std;

class Customer{
    public:
        Customer();
        Customer(float arrivalTime);
        void setLengthForService(float serviceLength);
        void setArrivalTime(float time);
        void SetStartOfServiceTime(float time);
        void setNextCust(Customer* next);
        float getArrivalTime();
        float getServiceTime();
        Customer* getNext();
    private:
        float arrivalTime;
        float startOfServiceTime;
        float departureTime; // startOfServiceTime + timeForService
        Customer* nextCust; // linked for fifo

        float timeForService;
        float timeWaiting; // calculated from startOfServiceTime - arrivalTime
        // make copy constrtuctors and such !!!!!!!!!!!!!!!!!!!!
};

#endif