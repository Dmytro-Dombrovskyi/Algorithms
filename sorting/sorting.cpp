#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;

template<typename T>
class compare
{
public:
    bool operator () (T i, T j) {return i < j;}
};

int main()
{

    // #1. sort
    cout << "#1. sort: " << endl;
    cout << "1.1 using default compare: " << endl;

    vector<int> sort_val1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::random_shuffle(sort_val1.begin(), sort_val1.end());

    cout << "Data in array 1 before sorting: ";
    for(auto x : sort_val1) cout << x << " ";
    cout << endl;

    sort(sort_val1.begin(), sort_val1.end());

    cout << "Data in array 1 after sorting:  ";
    for(auto x : sort_val1) cout << x << " ";
    cout << endl << endl;

    cout << "1.2 using function compare: " << endl;

    std::random_shuffle(sort_val1.begin(), sort_val1.end());

    cout << "Data in array 2 before sorting: ";
    for(auto x : sort_val1) cout << x << " ";
    cout << endl;

    sort(sort_val1.begin(), sort_val1.end(),
         [](int i, int j)->bool{return i < j; });

    cout << "Data in array 2 after sorting:  ";
    for(auto x : sort_val1) cout << x << " ";
    cout << endl << endl;

    cout << "1.3 using class compare: " << endl;
    std::random_shuffle(sort_val1.begin(), sort_val1.end());
    cout << "Data in array 3 before sorting: ";
    for(auto x : sort_val1) cout << x << " ";
    cout << endl;

    compare<int> sort_class_compare;
    sort(sort_val1.begin(), sort_val1.end(), sort_class_compare);
    cout << "Data in array 3 after sorting:  ";
    for(auto x : sort_val1) cout << x << " ";
    cout << endl << endl;


    // #2. stable_sort
	 // Sort elements preserving order of equivalents
	 cout << "#2. stable_sort: " << endl;
	 cout << "#2.1 using default comapare: " << endl;
	 
	 vector<string> name_arr_2{"Jack", "Michael", "Deniel", "Joseph", "Annet"};
	 cout << "Data in array before sorting: ";
	 for(auto x : name_arr_2) cout << x << " "; cout << endl;

	 // sort array 
	 std::stable_sort(name_arr_2.begin( ), name_arr_2.end( ));
	 cout << "Data in stable sorted array:  ";
	 for(auto x : name_arr_2) cout << x << " "; cout << endl << endl;

	 cout << "#2.2 using own compare function: " << endl;
	 std::random_shuffle(name_arr_2.begin( ), name_arr_2.end( ));
	 cout << "Data in array before sorting: ";
	 for(auto x : name_arr_2) cout << x << " "; cout << endl;

	 // sort array (compare second letter in the words)
	 std::stable_sort(name_arr_2.begin( ), name_arr_2.end( ),
							[](const string & value_1, const string & value_2)->bool
							{ return value_1[1] < value_2[1]/* || (value_1 < value_2)*/; });

	 cout << "Data in stable sorted array:  ";
	 for(auto x : name_arr_2) cout << x << " "; cout << endl << endl;

	 // sort array using class compare
	 cout << "2.3 using own class compare: " << endl;
	 std::random_shuffle(name_arr_2.begin(), name_arr_2.end());
	 cout << "Data in array before sorting: ";
	 for(auto x : name_arr_2) cout << x << " "; cout << endl;

	 compare<string> class_compare_stable_sort;
	 std::stable_sort(name_arr_2.begin( ), name_arr_2.end( ), class_compare_stable_sort);

	 cout << "Data in stable sorted array:  ";
	 for(auto x : name_arr_2) cout << x << " "; cout << endl << endl;


	 // #3. partial_sort
	 cout << "#3. partial_sort: " << endl;

	 vector<int> value_arr_part_sort;
	 for(int i = 0; i < 20; ++i) value_arr_part_sort.push_back(i);
	 std::random_shuffle(value_arr_part_sort.begin( ), value_arr_part_sort.end( ));

	 cout << "Data in array:        ";
	 for(auto x : value_arr_part_sort) cout << x << " "; cout << endl;
	 // sorting using default function
	 std::partial_sort(value_arr_part_sort.begin( ), 
							 value_arr_part_sort.begin() + (value_arr_part_sort.size( ) / 2),
							 value_arr_part_sort.end( ));

	 cout << "Data in sorted array: ";
	 for(auto x : value_arr_part_sort) cout << x << " "; cout << endl << endl;


	 // sorting using own class compare
	 cout << "3.1 partial_sort array with own class compare: " << endl;
	 compare<int> class_part_sort_compare_int;
	 std::partial_sort(value_arr_part_sort.begin( ) + (value_arr_part_sort.size( ) / 2),
							 value_arr_part_sort.end( ) - 1, value_arr_part_sort.end( ),
							 class_part_sort_compare_int);
	 cout << "Data in sorted array: ";
	 for(auto x : value_arr_part_sort) cout << x << " "; cout << endl << endl;


	 // #4. partial_sort_copy
	 cout << "4 partial_sort_copy: \n" << endl;
	 vector<int> data1, data2;
	 for(int i = 20; i > 0; --i) data1.push_back(i);
	 std::random_shuffle(data1.begin( ), data1.end( ));

	 cout << "data 1: ";
	 for(auto x : data1) cout << x << " "; cout << endl;

	 // using default function
	 data2.resize(data1.size( ) / 2);
	 std::partial_sort_copy(data1.begin( ), data1.end( ),
									data2.begin( ), data2.end( ));
	 cout << "data 2: ";
	 for(auto x : data2) cout << x << " "; cout << endl << endl;

	 // using own lambda function
	 cout << "4.1 partial_sort_copy(using own function): " << endl;
	 data2.clear( );
	 data2.resize(data1.size( ) / 3);
	 std::partial_sort_copy(data1.begin( ), data1.end( ),
									data2.begin( ), data2.end( ),
									[](const int a, const int b)->bool { return a < b; });
	 cout << "data 2: ";
	 for(auto x : data2) cout << x << " "; cout << endl << endl;


	 // #5. is_sorted
	 cout << "5. is_sorted: " << endl;

	 vector<int> data_3;
	 for(int i = 0; i < 15; ++i) data_3.push_back(i);
	 std::random_shuffle(data_3.begin( ), data_3.end( ));

	 cout << "data in array: ";
	 for(int & x : data_3) cout << x << " "; cout << endl;

	 if(std::is_sorted(data_3.begin( ), data_3.end( )))
	 {
		 cout << "Array is sorted!" << endl;
	 }
	 else	 { cout << "Array isn't sorted!" << endl; }
	 cout << endl;

 
	 // #6. is_sorted_until
	 cout << "6. is_sorted_until: " << endl;
	 vector<int> data_4;
	 vector<int>::iterator data_4_itr;
	 for(auto i = 0; i < 10; ++i) data_4.push_back(i);
	 std::random_shuffle(data_4.begin( ), data_4.end( ));
	 cout << "Data in array: ";
	 for(auto x : data_4) cout << x << " "; cout << endl;

	 std::partial_sort(data_4.begin( ),data_4.begin() + (data_4.size( ) / 2), data_4.end());
	 data_4_itr = std::is_sorted_until(data_4.begin( ), data_4.end( ));

	 cout << "Data in sorted array: ";
	 for(auto x : data_4) cout << x << " ";
	 cout << " - " << (data_4_itr - data_4.begin()) << " sorted elements in array; " << endl;
	 cout << endl;
	

	 // #7. nth_element
	 cout << "#7. nth_element: " << endl;
	 vector<int> data4;
	 for(int i = 0; i < 16; ++i) data4.push_back(i);
	 std::random_shuffle(data4.begin( ), data4.end( ));

	 cout << "data in array: ";
	 for(auto x : data4) cout << x << " ";
	 cout << endl;

	 std::nth_element(data4.begin( ), data4.begin( ) + 5, data4.end( ));
	 cout << "data in array after using 'nth_element' algorithm. " << endl;
	 for(auto x : data4) cout << x << " ";
	 cout << endl << endl;

    return 0;
}
