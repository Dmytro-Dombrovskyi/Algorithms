// Partition algorithms
// Dmytro Dombrovskyi // 26.06.2014 //
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
	//cout << endl;
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
	//cout << endl;
	if(is_partitioned(some_arr.begin(), some_arr.end(),
		[](int i)->bool { return i % 2 == 1; }))
	{
		cout << " (partitioned) \n";
	}
	else
	{
		cout << " (not partitioned) \n";
	}
	cout << endl;

	// #2. partition
	cout << "#2. partition: " << endl;
	vector<int> part_arr;
	for(int i = 0; i < 10; ++i)
	{
		part_arr.push_back(i);
	}
	vector<int>::iterator part_itr;
	part_itr = partition(part_arr.begin( ), part_arr.end( ),
								[](int i)->bool { return i % 2 == 1; });
	// print data
	cout << "Odd values:  ";
	for(auto x = part_arr.begin( ); x != part_itr; ++x)
	{
		cout << *x << " ";
	}
	cout << endl;

	cout << "Even values: ";
	for(auto x = part_itr; x != part_arr.end( ); ++x)
	{
		cout << *x << " ";
	}
    cout << endl << endl;

	// #3. stable_partition
	cout << "#3. stable_partition: " << endl;
	vector<int> stable_part_arr;
	for(int i = 0; i < 10; ++i)
	{
		stable_part_arr.push_back(i);
	}
	for(auto x : stable_part_arr)
	{
		cout << x << " ";
	}
	cout << endl;

	stable_partition(stable_part_arr.begin( ), stable_part_arr.end( ),
										[](int i)->bool { return i % 2 == 1; });

	for(auto x : stable_part_arr)
	{
		cout << x << " ";
	}
    cout << endl << endl;

	// #4. partition copy
	
	cout << "#4. partition_copy: " << endl;
	vector<int> part_copy_arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> odd, even;

	cout << "Data in array: ";
	for(auto x : part_copy_arr) cout << x << " ";
	cout << endl;

	auto n = count_if(part_copy_arr.begin( ), part_copy_arr.end( ),
							[](int i)->bool { return i % 2 == 1; });
	odd.resize(n);
	even.resize(part_copy_arr.size( ) - n);
	partition_copy(part_copy_arr.begin( ), part_copy_arr.end( ), odd.begin( ), even.begin( ),
						[](int i)->bool { return i % 2 == 1; });

	cout << "Odd numbers:  ";
	for(auto x : odd) cout << x << " ";
	cout << endl;

	cout << "Even numbers: ";
	for(auto x : even) cout << x << " ";
	cout << endl << endl;

	// 4.1 partition_copy (using string instead int)
	cout << "#4.1 partition_copy: (names): " << endl;

    vector<string> names1{"Dmytro", "Andrew", "Anechka", "Angela", "Jack", "Michael", "Daniel"};
	vector<string> names_first_latter_A;
	vector<string> names_other_latters;

	cout << "Data in array: ";
	for(auto x : names1) cout << x << ", ";
	cout << endl;

    size_t n_count = count_if(names1.begin( ), names1.end( ),
							  [](const string & some_name)->bool { return some_name[0] == 'A'; });
    names_first_latter_A.resize(n_count);
    names_other_latters.resize(names1.size( ) - n_count);
    partition_copy(names1.begin(), names1.end(),
                   names_first_latter_A.begin(), names_other_latters.begin(),
                   [](const string & some_name)->bool { return some_name[0] == 'A'; });
    cout << endl;
    cout << "Data names 1: ";
    for(auto x : names_first_latter_A) cout << x << " ";
    cout << endl;
    cout << "Data names 2: ";
    for(auto x : names_other_latters) cout << x << " ";
    cout << endl << endl;


	// #5. partition point
    cout << "#5. partition_point: " << endl;
    vector<int> par_point_arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Data in array: ";
    for(auto x = par_point_arr.begin(); x != par_point_arr.end(); ++x)
    {
        cout << *x << " ";
    } cout << endl;
    // ordered partition before using algorithm
    stable_partition(par_point_arr.begin(), par_point_arr.end(),
              [](int i)->bool{ return i % 2 == 0; });
    vector<int> par_point_arr_odd;
    auto par_point_itr = partition_point(par_point_arr.begin(), par_point_arr.end(),
                                        [](int i)->bool{ return i % 2 == 0; });
    par_point_arr_odd.assign(par_point_arr.begin(), par_point_itr);
    cout << "Odd values in array: ";
    for(auto x : par_point_arr_odd) cout << x << " ";
    cout <<endl << endl;


	//cin.get( );


	return 0;
}
