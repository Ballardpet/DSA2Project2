// customer pointer
// event type, arrival or departure

#ifndef EVENT_HPP
#define EVENT_HPP
#include "customer.hpp"
using namespace std;

// holds a customer and event type
class Event{
    public:
        Event(Customer* theCust, char type, float time);
        Customer* getCust();
        char getType();
        float getTime();
    private:
        Customer* theCustomer;
        char eventType; // either (a)rrival or (d)eparture
        float eventTime;
};

#endif