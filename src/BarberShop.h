//BarberShop.cpp
#include <iostream>
#include "LinkedStack.h"
using namespace std;

struct Customer{
private:
	string first;
	string last;
public:
	Customer() { }
	Customer(string fir, string las) {
		first = fir;
		last = las;
	}
	string getName(){
		return first + " " + last;
	}
};

class BarberShop{
     LinkedStack<Customer> s1;
     LinkedStack<Customer> s2;
     public:
          void addCustomer(Customer&);
          Customer nextCustomer();
};

void BarberShop::addCustomer(Customer& customer){
	s1.push(customer);
}

Customer BarberShop::nextCustomer(){
	Customer next;

	while (!s1.isEmpty()){
		s2.push(s1.pop());
	}
	next = s2.pop();

	while(!s2.isEmpty()){
		s1.push(s2.pop());
	}

	return next;
}
