/*
	MPS Task 1 file.
	@author: Eesha Sharma
	@when: 2018/07/02
*/


#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;


void fun1(){
	int val = 10000;
	//Sleep(2);
	for (int i = 0; i<10000; i++){
		val += 100000;
	}
}

double timefind(int NumOfIterations){
	clock_t begin = clock();
	for (int i = 0; i < NumOfIterations; i++){
		fun1();
	}
	clock_t end = clock();
	double timeElapsed = double(end - begin) / CLOCKS_PER_SEC;
	return timeElapsed;
}

int main()
{
	cout << "Hello World\n";

	cout << timefind(10000000) << " seconds" << endl;

	// double result = timesRun(times, &fun1);
	return 0;
}
