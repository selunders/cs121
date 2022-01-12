/* queues.h
*
* CS 121.Bolden.........Compiler version.........Seth Lunders
* 3/9/20..MSI Apache Pro with Intel i7 7th Gen CPU...lund4272@vandals.uidaho.edu
*
* The program will take in a maze data file and output a path to the exit
*
* ---------------------------------------------------------------------
*/
#include<iostream>
using namespace std;

// -----------------------------------------
// Code for nodes & queue
// -----------------------------------------


struct qNode // node for the queue
{
	int row;
	int column;
	struct qNode* next;
	qNode(int r, int c){ //initialize
		row = r;
		column = c;
		next = NULL;
	}
};

typedef struct qNode* qNodePtr;

struct queue //stores the next coordinates to visit
{
	qNodePtr start;
	qNodePtr end;
	queue(){ // queue constructor
		start = NULL;
		end = NULL;
	}
	void Enqueue(int row, int col){
		qNodePtr n = new qNode(row,col);
	
		if( start == NULL ) // Check if empty queue
		{
			start = n;
			end = n;
			return;
		}
		end->next = n; // point the old end to the new end
		end = n;	   // make the new node the end of the list
	}
	
	void Dequeue(){
		if(start == NULL)
			return;
		qNodePtr n = start;
		start = start->next;
		if(start == NULL)
			end = NULL;
		return;
	}
};