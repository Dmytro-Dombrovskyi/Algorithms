// 28.05.2014.
// Using different non-modifying algorithms with conteiners.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
inline void print_fruits (string name_of_fruit)
{ cout << name_of_fruit << " "; }
bool Is_apples (string fruit) { return fruit == "apples";}
bool equal_value(int i, int j) { return i == j; }
bool equal_names(string name1, string name2) {return name1 == name2; }
bool odd_value(int val) { return val % 2; }

template<typename T>
void print(T & widget) { cout << widget << " "; }


int main()
{
    // Non-modifying sequence operations:
    // all_of
	vector<string> fruits { "apples", "cherry"};
	cout << "1. Using all_of: " << endl;
	if( all_of(fruits.begin(), fruits.end(),
			[](string i) -> int {return i.size() == 6;}) )
		cout << "All fruits have 6 letters." << endl;
	// any_of
	cout << "\n2. Using any_of: " << endl;
	fruits.push_back("bananas");
	if( any_of(fruits.begin(), fruits.end(),
				[](string word) { return word.size() == 7; }) )
					cout << "Some element(s) has 7 letters." << endl;
	// none_of
	cout << "\n3. Using none_of: " << endl;
	if( none_of(fruits.begin(), fruits.end(),
				[](string word) { return word == "oranges"; }) )
					cout << "Fruits don't include any oranges." << endl;
	// for_each
	cout << "\n4. Using for_each: " << endl;
	cout << "Using with class: ";

    struct print_fruit {
		void operator() (string name_of_fruit) {
			cout << name_of_fruit << " ";
		}
    } my_fruit;
    cout << "Fruit: ";
    for_each(fruits.begin(), fruits.end(), my_fruit);
    cout << endl;

    cout << "Using with function: " << endl;
    cout << "Fruit: ";
    for_each(fruits.begin(), fruits.end(), print_fruits);
    cout << endl;

    // find
    cout << "\n5. Using find: " << endl;
	vector<string>::iterator ban_itr;
	ban_itr = find(fruits.begin(), fruits.end(), "bananas");
	if(ban_itr != fruits.end())
		cout << "Fruit: " << *ban_itr << " was founded!" << endl;
	else
		cout << "Fruit wasn't found!" << endl;

	// find_if
	cout << "\n6. Using find_if: " << endl;
	ban_itr = find_if(fruits.begin(), fruits.end(), Is_apples );
	if(ban_itr != fruits.end())
		cout << "Apples was found" << endl;
	else
		cout << "Apples wasn't found!" << endl;

	// find_if_not
	cout << "\n7. Using find_if_not: " << endl;
	ban_itr = find_if_not(fruits.begin(), fruits.end(), Is_apples );
	cout << "The first fruit apple is: " << *ban_itr << endl;

	//find_end
	cout << "\n8. find_end: " << endl;
    vector<int> num1 {1, 2, 3, 4, 5, 6};
    vector<int> num2 {1, 2, 3};
    vector<int>::iterator itr;
    itr = find_end(num1.begin(), num1.end(),
					num2.begin(), num2.end());
	if(itr != num1.end())
	{
		cout << "num2 last found at position: "
			 << (itr - num1.begin()) << endl;
	}
	int num3[] {4, 5, 6};
	itr = find_end(num1.begin(), num1.end(),
					num3, num3 + 3, equal_value );
	if(itr != num1.end())
	{
		cout << "num3 last found at position: "
			 << (itr - num1.begin()) << endl;
	}

	//find_first_of
	cout << "\n9. find_first_of: " << endl;
	itr = find_first_of(num1.begin(), num1.end(), num3, num3 + 3);
	if(itr != num1.end())
	{
		cout << "The first match is: " << *itr << endl;
	}

	// adjacent_find
	cout << "\n10. adjacent_find: " << endl;
	vector<string> names1 { "Dmytro", "Mark", "Mark", "Steeve", "Andrij",
							"Andrij"};
	vector<string>::iterator it_name;
	// #1
	it_name = adjacent_find(names1.begin(), names1.end(), equal_names);
	if(it_name != names1.end())
	{
		cout << "The first pairs of repeated elements are: "
			 << *it_name << endl;
	}
	else
		cout << "Equal adjacent elements wasn't found!" << endl;
	// #2
	it_name = adjacent_find(++it_name, names1.end());
	if(it_name != names1.end())
	{
		cout << "The first pairs of repeated elements are: "
			 << *it_name << endl;
	}

	// count
	cout << "\n11. count: " << endl;
	string compared("Dmytro");
	int mycount = count(names1.begin(), names1.end(), compared);
	cout << "Counter: " << mycount << endl;

	// count_if
	cout << "\n12. count_if: " << endl;
	vector <int> num4 {1, 2, 3, 5, 6};
	mycount = count_if(num4.begin(), num4.end(), odd_value);
	cout << "Num4 has: " << mycount << " odd values!" << endl;

	// mismatch
	cout << "\n13. mismatch: " << endl;
	vector<int> num5;
	for(size_t i = 0; i < num4.size(); ++i)
		num5.push_back(num4[i] * 2);
	cout << "Numbers in num5: ";
	for_each(num5.begin(), num5.end(), print<int>);
	cout << endl;
	num5[0] = num4[0];

	pair<vector<int>::iterator, vector<int>::iterator > mypair;
	mypair = mismatch(num4.begin(), num4.end(), num5.begin() );
	cout << "First mismatching elements: " << *mypair.first
		 << " and " << *mypair.second << endl;

	// equal
	cout << "\n14. equal: " << endl;
	// #1
	cout << "Numbers in num5: ";
    for_each(num5.begin(), num5.end(), print<int>);
    cout << endl;
    cout << "Numbers in num4: ";
    for_each(num4.begin(), num4.end(), print<int>);
    cout << endl;
	if( equal(num4.begin(), num4.end(), num5.begin()) )
		cout << "num4 is equal to num5" << endl;
	else
		cout << "arrays num5 and num 5 are different!" << endl;
	// #2
	num5 = num4;
	cout << "Numbers in num5: ";
    for_each(num5.begin(), num5.end(), print<int>);
    cout << endl;
    cout << "Numbers in num4: ";
    for_each(num4.begin(), num4.end(), print<int>);
    cout << endl;
    if(equal(num4.begin(), num4.end(), num5.begin(), equal_value))
		cout << "num4 is equal to num5" << endl;
	else
		cout << "arrays num5 and num 5 are different!" << endl;

	// is_permutation
	cout << "\n15. is_permutation: " << endl;
	cout << "Numbers in num5: ";
    for_each(num5.begin(), num5.end(), print<int>);
    cout << endl;
    cout << "Numbers in num4: ";
    for_each(num4.begin(), num4.end(), print<int>);
    cout << endl;
	if(is_permutation(num4.begin(), num4.end(), num5.begin()) )
		cout << "num4 and num5 contain the same elements." << endl;
	num4.push_back(10);
	cout << "Numbers in num5: ";
    for_each(num5.begin(), num5.end(), print<int>);
    cout << endl;
    cout << "Numbers in num4: ";
    for_each(num4.begin(), num4.end(), print<int>);
    cout << endl;
	if(is_permutation(num4.begin(), num4.end(), num5.begin()) )
		cout << "num4 and num5 contain the same elements." << endl;
	else
		cout << "num4 and num5 contain different elements." << endl;

	// search
	// #1
	cout << "\n16. search: " << endl;
	num4 = num5;

	vector<int>::iterator itr_num;
	itr_num = search(num4.begin(), num4.end(), num5.begin(), num5.end());
	if(itr_num != num4.end())
		cout << "num4 found at position: " << *itr_num << endl;
	else
		cout << "num4 wasn't found!" << endl;
	// #2
	num4.clear();
	for(int i = 0; i < 10; ++i)
		num4.push_back(i*3);
	num5.clear();
	num5 = num4;
	for(size_t i = 0; i < num4.size(); ++i)
		num5.push_back(num4[i] * 2);
	cout << "Numbers in num4: ";
    for_each(num4.begin(), num4.end(), print<int>);
    cout << endl;
    cout << "Numbers in num5: ";
    for_each(num5.begin(), num5.end(), print<int>);
    cout << endl;
    itr_num = search(num5.begin(), num5.end(),
					 num4.begin(), num4.end(), equal_value);
	if(itr_num != num4.end())
		cout << "num4 found at position: " << *itr_num << endl;
	else
		cout << "num4 wasn't found!" << endl;

	// search_n
	cout << "\n17. search_n: " << endl;
	// #1
	cout << "Numbers in num4: ";
    for_each(num4.begin(), num4.end(), print<int>);
    cout << endl;
    cout << "Numbers in num5: ";
    for_each(num5.begin(), num5.end(), print<int>);
    cout << endl;
	itr_num = search_n(num5.begin(), num5.end(), 2, 4);
	if(itr_num != num5.end())
		cout << "number 4 was found at a position: "
			 << (itr_num - num5.begin()) << endl;
	else
		cout << "number 4 wasn't found!" << endl;
	// #2
	num4.clear(); num5.clear();
	for(int i = 0; i < 10; ++i)
		num4.push_back(i);
	// special creating num5 with equals values
	for(size_t i = 0; i < num4.size(); ++i)
	{
		if(i % 2)
			num5.push_back(num4[i - 1]);
		num5.push_back(num4[i]);
	}
	cout << "Numbers in num4: ";
    for_each(num4.begin(), num4.end(), print<int>);
    cout << endl;
    cout << "Numbers in num5: ";
    for_each(num5.begin(), num5.end(), print<int>);
    cout << endl;
	itr_num = search_n(num5.begin(), num5.end(), 2, 4, equal_value);
	if(itr_num != num5.end())
		cout << "number 4 was found at a position: "
			 << (itr_num - num5.begin()) << endl;
	else
		cout << "number 4 wasn't found!" << endl;
	// add for commit

    return 0;
}
