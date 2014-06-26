#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include <iterator>
using namespace std;

int main( )
{
	// #1: is_partitioned
	cout << "#1. is_partitioned: " << endl;
	array<int, 5> some_arr { 1, 2, 3, 4, 5};

	for(int & x : some_arr) cout << x << " ";
	cout << endl;
	if(is_partitioned(some_arr.begin( ), some_arr.end( ),
		[](int i)->bool { return i % 2 == 1; }))
	{
		cout << " (partitioned)" << endl;
	}
	else
	{
		cout << " (not partitioned)" << endl;
	}

	partition(some_arr.begin( ), some_arr.end( ),
				 [](int i)->bool { return i % 2 == 1; });
	// prints contents again:
	for(int & x : some_arr) cout << x << " ";
	cout << endl;
	if(is_partitioned(some_arr.begin(), some_arr.end(),
		[](int i)->bool { return i % 2 == 1; }))
	{
		cout << " (partitioned)" << endl;
	}
	else
	{
		cout << " (not partitioned)" << endl;
	}


	//cin.get( );


	return 0;
}