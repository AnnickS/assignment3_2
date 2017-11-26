/*
 * LinkedStack.h
 *
 *  Created on: Nov 24, 2017
 *      Author: annic
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
using namespace std;

//LinkedStack.h

template <class T>
struct node{
    T data;
    node<T>* next;
};

template <class T>
class LinkedStack{
      node<T> *top;
   public:
      LinkedStack() { top = NULL; };
      void push(T item);
      T pop();
      T stop();
      bool isEmpty();
      void destroy();
      ~LinkedStack();
};

template<class T>
void LinkedStack<T>::push(T item){
	node<T>* adding = new node<T>();
	adding->data = item;

	if(isEmpty()){
		top = adding;
	}
	else{
		adding->next = top;
		top = adding;
	}
}

template<class T>
T LinkedStack<T>::pop(){
	T item = top->data;
	node<T>* popped = top;
	top = top->next;
	delete popped;
	return item;
}

template<class T>
T LinkedStack<T>::stop(){
	if(!isEmpty()){
		return top->data;
	}
}

template<class T>
bool LinkedStack<T>::isEmpty(){
	if(top == NULL){
		return true;
	}
	else
		return false;
}

template<class T>
void LinkedStack<T>::destroy(){
	node<T>* next;
	node<T>* remove;
	next = top;

	while(next != NULL){
		remove = next;
		next = next->next;
		delete remove;
	}

	delete next;
}

template<class T>
LinkedStack<T>::~LinkedStack(){
	destroy();
}


#endif /* LINKEDSTACK_H_ */
