#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
using namespace std;

class Customer{
    public:
        Customer(float arrivalTime);
        void setArrivalTime(float time);
        void SetStartOfServiceTime(float time);
        void setNextCust(Customer* next);
        float getArrivalTime();
        float getServiceTime();
        Customer* getNext();
    private:
        float arrivalTime;
        float startOfServiceTime;
        Customer* nextCust; // linked for fifo
};

#endif