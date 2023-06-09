// N09_HW01_Task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include<thread>
#include <Windows.h>
#include <stdlib.h>
#include <chrono>
//#include "Timer.h" ---- где взять???? не работает
//#include <Timer.h>

using namespace std;


//thread_local int max_clients_number;
//thread_local int clients_count;
int max_clients_number;
int clients_count=0;
bool stop = false;

void clients()
{

	while (stop != true) {
		if (clients_count < max_clients_number) {
			this_thread::sleep_for(1000ms);
			clients_count += 1;

			cout << clients_count << " ";
		}
		
	}
}


void window() {
	
	while (clients_count >= 0) {
		this_thread::sleep_for(2000ms);
		clients_count -= 1;
		if (clients_count > -1) {
			//consol_color::SetColor(15, 0); - не работает - как починить?
			cout << " !" << clients_count << " ";
		}
		
	 }
}



int main()
{
    cout << "max_clients_number is ";
	cin >> max_clients_number;
	cout << std::endl;

	thread t1(clients);
	thread t2(window);
	this_thread::sleep_for(30000ms);
	//cout << "\n working day stops ";

	stop = true;
	t1.join();
	t2.join();
}
