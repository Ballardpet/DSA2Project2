CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o analyticalModel.o customer.o fifoQueue.o priorityQueue.o simulator.o

main :  ${OBJS}
		${CXX} ${CXXFLAGS} -o $@ ${OBJS}

main.o : analyticalModel.hpp customer.hpp fifoQueue.hpp priorityQueue.hpp simulator.hpp
simulator.o : priorityQueue.hpp fifoQueue.hpp customer.hpp
priorityQueue.o : priorityQueue.hpp customer.hpp
fifoQueue.o : fifoQueue.hpp customer.hpp
analyticalModel.o : analyticalModel.hpp
customer.o : customer.hpp

clean : 
		rm ${OBJS} main