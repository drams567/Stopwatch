#include <iostream>
#include <string>
#include <unistd.h>

#include "Stopwatch.h"

using namespace std;

int main() {
	Stopwatch testWatch;
	Stopwatch watch;
	milliseconds ret;

	testWatch.start();

	watch.start();
	for(int i = 0; i < 10000; i++)
	{
		ret = watch.getElapsedTime();
	}
	
	cout << "Total time according to test watch: " << testWatch.getElapsedTime().count() <<endl;	

	return 0;
}
