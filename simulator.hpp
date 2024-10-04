#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
using namespace std;

// pretty sure this simulates time passing and customers coming in
class Simulator{
    public:
        Simulator();
        void getNextRandomInterval(float avg); // avg can be lmbda or mu
    private:
        int numEvents; // number of events to simulate

};

#endif




// How I assume this will work
// Simulator will make all of the random intervals
    // I feel like this is exactly what he did in the example
    // Probably needs the analytical model to figure out that numbers and shit
    // Maybe they all goo immediately into the fifo queue and then go into the priority queue
// put the first M of them into the priority queue and the rest in the fifo
// will then do all the math and shit to figure out how long it will have to wait



