#include "event.hpp"

Event::Event(Customer* theCust, char type, float time){
    theCustomer = theCust;
    eventType = type;
    eventTime = time;
}

Customer* Event::getCust(){
    return theCustomer;
}

char Event::getType(){
    return eventType;
}

float Event::getTime(){
    return eventTime;
}