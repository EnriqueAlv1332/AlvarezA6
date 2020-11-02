//============================================================================
// Name        : AlvarezA6.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "AlvarezA6.h"
#include "Transaction.h"
#include "Server.h"
#include <fstream>
using namespace std;


int main() {
	Queue<Transaction>q(50);
//
//	cout << "main: start of part 1" << endl;
//	cout << "main: pushing 6 elements" << endl;
//	q.addQ(10);
//	q.addQ(20);
//	q.addQ(30);
//	q.addQ(40);
//	q.addQ(50);
//	q.addQ(60);

//	q.displayQ();
//
//	cout << "main: start of part 2" << endl;
//	cout << "main: removing 3 elements"<< endl;
//	q.removeQ();
//	q.removeQ();
//	q.removeQ();
//
//	cout << "main: display of list after removes" << endl;
//	q.displayQ();
//	cout << "front element: " << q.QFront() << endl;
//	cout << "back element: " << q.QBack() << endl;
//
//	q.displayQ();

//START OF SIMULATION\

	//setting up my log file
//
	ofstream log;
	log.open("A6log.txt");

	//Retrieving user values
	cout << "How clock ticks will be simulated?" << endl;
	int clockTicks;
	cin >> clockTicks;

	cout << "What would you like the probability of a transaction arriving to be? (0-100)" << endl;
	int transProb;
	cin >> transProb;

	cout << "what would you like the lower end of the required work per transaction to be?" << endl;
	int workLow;
	cin >> workLow;

	cout << "what would you like the higher end of the required work per transaction to be?" << endl;
	int workHigh;
	cin >> workHigh;

	cout << "How many units of work do you want the server to process per turn?" << endl;
	int servSpeed;
	cin >> servSpeed;
	int transComp = 0;

	Server server;
	int clock = 0;
	int totUnits;
	server.inUse = false;
	server.sID = "Server1_";
	server.sSpeed = servSpeed;
	server.timeLeft = 0;

	int ID = 1;

	Transaction working;
	while(clock<clockTicks){
		int possibleTrans = rand() % 100;

		if(possibleTrans < transProb){
			Transaction trans;
			trans.tID = "Transaction # " + to_string(ID);
			trans.workUnits = (rand() % (workHigh-workLow)) + workLow;
			trans.workUnitsTotal = trans.workUnits;
			server.timeLeft = trans.workUnits / server.sSpeed;
			ID++;
			q.addQ(trans);
			//log << trans.tID << "did i get here" <<endl;
		}
		if(server.inUse == false && q.isEmptyQ()==false){
			working = q.QFront();
			//log << working.tID << "did i get here by working line" <<endl;
			q.removeQ();
			server.inUse = true;
		}
		if(server.inUse ==true){
			if(working.workUnits > server.sSpeed){
					working.workUnits -= server.sSpeed;
			}
			else{
				server.inUse = false;
				int foo = working.workUnitsTotal / server.sSpeed;
				int bar = clock - foo;
				totUnits += working.workUnitsTotal;
				log << working.tID << endl;
				log << "Started @ tick: " << bar << endl;
				log << "ended @ tick: " << clock << endl;
				log << "Consumed " << working.workUnitsTotal << " units of work." << endl;
				log << endl;

				transComp++;
			}
		}
		clock++;
	}

	//log<< "test"<<endl;
	//log << "tested again" << endl;
	log << "The simulation has ended after completing " << transComp << " Transactions" << endl;
	log.close();

	cout << " Number of completed transactions: " << transComp << endl;
	cout << " Total units used: " << totUnits<< endl;
	if(server.inUse){
		cout << " Finished with a transaction in progress." << endl;
	}
	else{
		cout << " Finished with no transactions in progress." << endl;
	}
	cout << " Number of transactions still in queue: " << q.getCount() << endl;

	return 0;
}
