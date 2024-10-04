#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
using namespace std;

// pretty sure this is the line the customers are waiting in
// make a seperate customer class !!!!
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