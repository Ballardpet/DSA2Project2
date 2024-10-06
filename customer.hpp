#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
using namespace std;

class Customer{
    public:
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