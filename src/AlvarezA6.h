/*
 * AlvarezA6.h
 *
 *  Created on: Mar 11, 2020
 *      Author: Enrique Alvarez412-1
 */

#ifndef ALVAREZA6_H_
#define ALVAREZA6_H_
using namespace std;
#include <iostream>
#include <list>
#include <cassert>



template <class T>
class Queue
{
private:
	int maxQsize;
	int count;
	int Qfront;
	int Qback;
	T * list;

public:

void initializeQ();
void addQ(T);				//adds a transaction to the end of the queue
void removeQ();				//removes the transaction at the front of the queue
void displayQ();		//prints all transactions in queue
bool isEmptyQ();			//
bool isFull();				//
T QFront();				//
T QBack();				//
int getCount();



Queue(int d)
{
	maxQsize = d;
	list = new T[maxQsize];
	initializeQ();

}

};

template <class T>
void Queue<T>::initializeQ(){
	count = 0;
	Qfront = 0;
	Qback = maxQsize-1;
}

template <class T>
void Queue<T>::addQ(T elem){
	if(isFull() == false){
		Qback = (Qback + 1 ) % maxQsize;
		list[Qback] = elem;
		count++;
	}
	else{
		cout << "error adding" << endl;
	}
}

template <class T>
void Queue<T>::removeQ(){
	if(isEmptyQ()==false){
		Qfront = (Qfront+1) %maxQsize;
		count--;
	}
	else{
		cout<< "error removing" << endl;
	}
}


template <class T>
void Queue<T>::displayQ(){
	for(int i = Qfront ;i<=Qback;i++){
		cout<< "spot: " << i << "  contains " << list[i] << endl;
	}
	cout << "elements in Queue : " << count << endl;
	cout << "Q front value is " << Qfront << endl;
	cout << "Q back value is " << Qback << endl;
	cout << " should be front" << list[Qfront] <<endl;
}

template <class T>
bool Queue<T>::isEmptyQ(){
	if(count == 0){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
bool Queue<T>::isFull(){
	if(count == maxQsize){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
T Queue<T>::QFront(){
	if(!isEmptyQ()){
		return list[Qfront];
	}
	else{
		cout << " here " << Qfront << endl;
		throw domain_error("error in Qfront function ");
	}


}

template <class T>
T Queue<T>::QBack(){
	if(isEmptyQ()==false){
		return list[Qback];
	}
	else{
		throw domain_error("error in Qback function ");
	}
}

template <class T>
int Queue<T>::getCount(){
	return count;
}

//
#endif /* ALVAREZA6_H_ */
