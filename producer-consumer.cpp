//ilan finkelstein
//project 1
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <tchar.h>
#include <strsafe.h>

#define MAX_THREADS 2 // # of threads

//needed to create global variables to assign cmd line input to functions
int argOne;
int argTwo;

using namespace std;

// function prototypes
DWORD WINAPI producer(LPVOID);
DWORD WINAPI consumer(LPVOID);
HANDLE hThreads[MAX_THREADS]; // # of threads
DWORD id[MAX_THREADS]; // array of thread ids


// main function
int main(int argc, char* argv[]){
	
	int arg1 = atoi(argv[1]); //cast string cmd line arg into int type
	int argOne=arg1; //assignment of local var to global variable
	int arg2 = atoi(argv[2]); //cast string cmd line arg into int type
	int argTwo=arg2; //assignment of local var to global variable
	int *argOne;
	DWORD waiter; //as per ms documentation
	
	  
srand(time(NULL)); //Seed Random Number Generator

// allocate memory fo the buffer
argOne = (int*) malloc(arg1 * sizeof(int));

 
hThreads[0] = CreateThread(NULL, NULL, 0, producer, (LPVOID)0, NULL, &id[0]);         
hThreads[1] = CreateThread(NULL, NULL, 0, consumer, (LPVOID)0, NULL, &id[1]);

//found on ms documentation - https://docs.microsoft.com/en-us/windows/win32/procthread/creating-threads
waiter = WaitForMultipleObjects(MAX_THREADS, hThreads, TRUE, INFINITE);

	for(int i = 0; i < MAX_THREADS; i++)
	{
	CloseHandle(hThreads[i]);
	}


cout<< "Producer thread finished"<<"\n";
cout<< "Consumer thread finished"<<"\n";

system("pause");
return 0;
}


// producer thread
DWORD WINAPI producer(LPVOID y, int argOne, int argTwo){

int buffer[argOne];

cout<<"Producer thread has begun:"<<"\n";

while(argOne < argTwo || argTwo < argOne)
	{
	while(((prod + 1) % argOne) == out); //solution to buffer-1
	int next = rand() % 100 + 1; //random generation of 
	Sleep(next * 50);
	buffer[prod] = next;
	cout << "Produced: " << next <<"\n"
	prod = (prod + 1) % argOne;
	argTwo++;
	}

return *((DWORD*)y); //As from StackOverflow (didnt know how to convert the pointer to int type)
}

// consumer thread
DWORD WINAPI consumer(LPVOID x, int argOne, int argTwo)
{
cout<<"Consumer thread has begun: "<<"\n";

int buffer[argOne];
int counter = 0;

while (argOne < argTwo || argTwo < argOne)
	{
	while(prod == cons);
	Sleep(next * 50);
	int next = buffer[cons];
	cout << "Consumed: "<<next<<"\n";
	cons = (cons + 1) % argOne;
	argTwo++;
	}

if (argTwo > argOne){
	{
	cout << "Buffer is now full"<<"\n";
	}

return *((DWORD*)x); //As from StackOverflow (didnt know how to convert the pointer to int type)
}}


