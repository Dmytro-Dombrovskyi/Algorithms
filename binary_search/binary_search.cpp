// binary search algorithms
// Dmytro Dombrovskyi // 27.06.2014
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main( )
{

	// #1. lower_bound and upper_bound
	cout << "#1. lower bound and upper bound algorithms: " << endl;
	vector<int> data1;
	for(int i = 0; i < 10; ++i) data1.push_back(i);
	vector<int>::iterator lw_iter;
	vector<int>::iterator up_iter;
	int lower_number = 7;	

	cout << "Data in array: ";
	for(auto x : data1) cout << x << " "; cout << endl;
	if(std::is_sorted(data1.begin( ), data1.end( )))
	{
		lw_iter = std::lower_bound(data1.begin( ), data1.end( ), lower_number);
		up_iter = std::upper_bound(data1.begin( ), data1.end( ), lower_number);
	}
	cout << "lower number is: " << lower_number << endl;
	cout << "lower number is on position: " << (lw_iter - data1.begin( )) << endl;
	cout << "upper number is on position: " << (up_iter - data1.begin( )) << endl;
	cout << endl;


	// #2. binary_search
	cout << "#2. binary_search: " << endl;

	vector<int> data_search;
	for(int i = 0; i < 10; ++i) data_search.push_back(i);

	cout << "Data in data_search array: ";
	for(auto x : data_search) cout << x << " "; cout << endl;
	int value = 5;
	cout << "Value: " << value;
	if(std::binary_search(data_search.begin( ),
			data_search.end(), value)) 
		cout << " found!";	
	else
		cout << " wasn't found!";
	cout << endl << endl;

	// #3. equal_range
	cout << "#3. equal_range: " << endl;

	vector<int> data_range{1, 2, 3, 3, 5, 6, 6, 7, 7};

	cout << "Data in data_range : ";
	for(auto x : data_range) cout << x << " "; 
	cout << endl;

	value = 5;
	std::pair<vector<int>::iterator, vector<int>::iterator> range_pair;
	range_pair = std::equal_range(data_range.begin( ), data_range.end( ), value);

	cout << "found value: " << value << endl;
	cout << "lower position: " << range_pair.first  - data_range.begin() << endl;
	cout << "upper posigion: " << range_pair.second - data_range.begin() << endl;
	cout << endl;

	// equal_range with own compare function
	//std::sort(data_range.begin( ), data_range.end( ));
	//decltype(range_pair) range_pair2;
	value = 3;
	cout << "use lambda function for compare: " << endl;
	range_pair = std::equal_range(data_range.begin( ), data_range.end( ), value,
											[](int a, int b)->bool { return a < b; });

	cout << "Data in data_range : ";
	for(auto x : data_range) cout << x << " ";
	cout << endl;
	cout << "found value: " << value << endl;
	cout << "lower position: " << range_pair.first - data_range.begin() << endl;
	cout << "upper posigion: " << range_pair.second - data_range.begin() << endl;

	return 0;
}