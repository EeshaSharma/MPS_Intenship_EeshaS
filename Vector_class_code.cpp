/*
MPS Task 1 file.
@author: Eesha Sharma
@when: 2018/07/02
*/

//

#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;

vector<int> myVector;
vector<int> myVector2;
//these are the modifiers
void testPushBack(){
	myVector.push_back(0);
}

void testPopBack(){
	myVector.pop_back();
}


void testInsert(){
	vector<int>::iterator it = myVector.begin();
	myVector.insert(it, 1);
}

void printVector(){ 
	cout << "printing the vector" << endl;
	for (int i = 0; i < myVector.size(); i++){
		cout << myVector[i];
	}
	cout << endl;
}

void testAssign(){
	myVector.assign(0, 1);
}

void testCreateVector(){
	vector<int> vec{ 1 };
}

void testInsertErase(){ 
	vector<int>::iterator it = myVector.begin();
	myVector.insert(it, 1);
	myVector.erase(myVector.begin());
}

void testErase(){
	myVector.erase(myVector.begin());
}

void testSwap(){//u will have to subtract the time it takes to create the vectors, by running fun7 beforehand
	myVector.swap(myVector2);
}
void testClear(){//u will have to subtract the time it takes to create the vector, by running fun5 beforehand
	myVector.clear();
}

void populateVector(int num){
	for (int i = 0; i < num; i++){
		myVector.push_back(0);
	}

}
//basic code for finding time
double testRun(int numOfIterations, void fun()){
	if (fun == testErase || fun == testPopBack){
		populateVector(numOfIterations);
	}
	//printVector();
	clock_t begin = clock();
	for (int i = 0; i < numOfIterations; i++){
		if (fun == testClear){
			populateVector(1);
		}
		fun();//or fun2 or fun3 or wtvr
	}
	clock_t end = clock();
	double timeElapsed = double(end - begin) / CLOCKS_PER_SEC;

	//printVector();
	
	myVector.clear();
	return timeElapsed;
}

int main()
{
	int times = 100000;
	cout << " times = " << times << endl;

	cout << "testErase time " << testRun(times, testErase) << " seconds" << endl;
	cout << "testPopBack time " << testRun(times, testPopBack) << " seconds" << endl;
	cout << "testPushBack time " << testRun(times, testPushBack) << " seconds" << endl;
	cout << "testCreateVector time " << testRun(times, testCreateVector) << " seconds" << endl;
	cout << "testClear time " << testRun(times, testClear) << " seconds" << endl;
	cout << "testInsertErase time " << testRun(times, testInsertErase) << " seconds" << endl;
	cout << "testSwap time " << testRun(times, testSwap) << " seconds" << endl;
	cout << "testAssign time " << testRun(times, testAssign) << " seconds" << endl;

	times = 10000;
	cout << " times = " << times << endl;
	cout << "testInsert time " << testRun(times, testInsert) << " seconds" << endl;
	return 0;
}