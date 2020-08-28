#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include <vector>

using namespace std;
using namespace chrono;

const int PREMATURE = 0;
const int ONGOING = 1;
const int STOPPED = 2;

class Stopwatch {
	private:
	vector<high_resolution_clock::time_point> start_points;
	vector<high_resolution_clock::time_point> stop_points;
	milliseconds elapsed_time;
	int state;
	int num_pre_calc;
	
	private:
	void calcElapsedTime();

	public:
	Stopwatch();
	void start();
	void stop();
	milliseconds getElapsedTime();
	void dump();

};

Stopwatch::Stopwatch() 
{
	state = PREMATURE;
	elapsed_time = duration_values<milliseconds>::zero();
}

void Stopwatch::start() 
{
	if(state != ONGOING)
	{
		start_points.push_back(high_resolution_clock::now());
		state = ONGOING;
	}
}

void Stopwatch::stop() 
{
	if(state == ONGOING)
	{
		stop_points.push_back(high_resolution_clock::now());
		state = STOPPED;
	}
}

void Stopwatch::calcElapsedTime() 
{
	milliseconds interval = duration_values<milliseconds>::zero();
	milliseconds total = duration_values<milliseconds>::zero();
	int saved_state = state;
	int i = 0;	

	if(saved_state == ONGOING)
	{
		stop();
	}

	for(i = num_pre_calc; i < (int)start_points.size(); i++) 
	{
		interval = duration_cast<milliseconds>(stop_points[i] - start_points[i]);
		total += interval;
	}
	
	num_pre_calc = i;
	elapsed_time = total;

	if(saved_state == ONGOING)
	{
		start();
	}
}

milliseconds Stopwatch::getElapsedTime() 
{
	calcElapsedTime();
	return elapsed_time;
}

void Stopwatch::dump() 
{
	cout << "State: " << state << endl;
	cout << "elapsed_time:" << elapsed_time.count() << endl;
	cout << "Num starts: " << start_points.size() << endl;
	cout << "Num stops: " << stop_points.size() << endl;
}

#endif
