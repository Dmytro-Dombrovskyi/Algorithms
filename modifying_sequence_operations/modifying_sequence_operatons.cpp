// Algorithms part 2:
// using modifying sequence operators:
// 29.05.2014

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <iterator>
#include <utility>

using namespace std;
template<typename T>
void print(T & widget) {cout << widget << " ";}
int main()
{
    // copy
    cout << "1. copy algorithm: \n";
    vector<string> names1 { "Dmytro", "Hanna", "Andrij" };
    vector<string> names2;
    names2.resize(names1.size());

    cout << "\nNames 1 before copy: " << endl;
    for(auto x : names1) cout << x << " ";
    cout << "\nNames 2 before copy: " << endl;
    for(auto y : names2) cout << y << " ";

    copy(names1.begin(), names1.end(), names2.begin());
    ostream_iterator<string> out_itr (cout, ", ");

    cout << "\nNames 1 after copy algorithm used: " << endl;
    copy(names1.begin(), names1.end(), out_itr);

    cout << "\nNames 2 after copy algorithm used: " << endl;
    copy(names2.begin(), names2.end(), out_itr);
    cout << endl;

    // copy using back_insert_iterator
    copy(names1.begin(), names1.end(),
         back_insert_iterator<vector<string> >(names2));
    cout << "\nNames 2 after copy algrithm used back_insert_iterator: " << endl;
    copy(names2.begin(), names2.end(), out_itr);
    cout << endl;

    // copy_n
    cout << "\n2. copy_n algorithm: \n";
    cout << "\nNames 2 before copy_n: " << endl;
    copy(names2.begin(), names2.end(), out_itr);
    names1.push_back("Alex");
    names2.resize(names1.size());

    copy_n(names1.begin(), names1.size(), names2.begin() );
    cout << "\nNames 2 after copy_n algorithm used: " << endl;
    copy(names2.begin(), names2.end(), out_itr);
    cout << endl;

    // copy_if
    cout << "\n3. copy_if algorithm: \n" << endl;
    deque<int> arr_1 = { 1, 2, 3, 4, 5, 6 };
    deque<int> arr_2;
    copy_if(arr_1.begin(), arr_1.end(),
            front_insert_iterator<deque<int> >(arr_2),
            [](int i) {return i % 2; } );
    cout << "arr_1: ";
    for(auto x : arr_1) cout << x << " ";
    cout << endl;
    cout << "arr_2(odd numbers):";
    for(auto x : arr_2) cout << x << " ";
    cout << endl;

    // copy_backward
    cout << "\n4. copy_backward algorithm: \n" << endl;
    arr_1.clear();
    for(int i = 0; i < 10; ++i) arr_1.push_back(i);
    cout << "Arr_1 before using copy_backward algorithm: " << endl;
    for(auto x : arr_1) cout << x << " ";
    cout << endl;
    arr_1.resize(arr_1.size() + 3);
    copy_backward(arr_1.begin(), arr_1.begin() + 7, arr_1.end());
    cout << "Arr_1 after using copy_backward algorithm: " << endl;
    for(auto x : arr_1) cout << x << " ";
    cout << endl;

    // move
    cout << "\n5. move algorithm: \n" << endl;
    arr_1.clear(); arr_2.clear(); // int
    for(int i = 0; i < 10; ++i) arr_1.push_back(i);


    return 0;
}
