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

//this is an example function
void fun1(){
	int val = 10000;
	//Sleep(2);
	for (int i = 0; i<10000; i++){
		val += 100000;
	}
}
//basic code for finding time
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
	cout << timefind(10000) << " seconds" << endl;

	return 0;
}
