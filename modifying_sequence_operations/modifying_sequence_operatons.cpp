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
    #if 0
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
    arr_1.clear(); arr_2.clear(); // vector<int>

    for(int i = 0; i < 10; ++i) arr_1.push_back(i);

    cout << "arr_1 contains: " << arr_1.size() << " elements: ";
    for(auto x: arr_1) cout << " [" << x << "]";
    cout << endl;
    cout << "arr_2 contains: " << arr_2.size() << " elements: ";
    for(auto x: arr_2) cout << " [" << x << "]";
    cout << endl;

            // moving ranges
    cout << "Moving ranges...\n";
    arr_2.resize(arr_1.size());
    move(arr_1.begin(), arr_1.end(), arr_2.begin() );
    cout << "arr_2 contains: " << arr_2.size() << " elements: ";
    for(auto x: arr_2) cout << " [" << x << "]";
    cout << endl;

            // moving container
    cout << "Moving container: " << endl;
    arr_1 = move(arr_2);
    cout << "arr_1 contains: " << arr_1.size() << " elements: ";
    for(auto x : arr_1) cout << " [" << x << "]";
    cout << endl;

    cout << "arr_2 is in an unspecified but valid state." << endl;

    // move_backward
    cout << "\n6. move_backwards algorithm: \n" << endl;
    arr_1.clear(); arr_2.clear(); // vector<int>
    for(int i = 0; i < 10; ++i) arr_1.push_back(i*2);

    cout << "arr_1 contains: " << arr_1.size() << " elements: ";
    for(auto x: arr_1) cout << " [" << x << "]";
    cout << endl;

            // insert new element at the beginning of arr_2.end()
    arr_2.resize(arr_1.size());
    move_backward(arr_1.begin(), arr_1.end(), arr_2.end());
    cout << "After using move_backwards: \n";
    cout << "arr_2 contains: " << arr_2.size() << " elements: ";
    for(auto x: arr_2) cout << " [" << x << "]";
    cout << endl;

    // swap
    cout << "\n7. swap algorithm: \n" << endl;

    int a = 10, b = 20;
    cout << "a: " << a << " , ";
    cout << "b: " << b << " . ";
    cout << endl;

    swap(a, b);
    cout << "After function swap called: \n";
    cout << "a: " << a << " , ";
    cout << "b: " << b << " .\n";
    cout << endl;

    vector<int> Alpha(2, a), Betta(3, b);
    cout << "Alpha contains: " << Alpha.size() << " elements: ";
    for(auto x : Alpha) cout << " [" << x << "]";
    cout << endl;
    cout << "Betta contains: " << Betta.size() << " elements: ";
    for(auto x : Betta) cout << " [" << x << "]";
    cout << endl;

    swap(Alpha, Betta);
    cout << "After function swap called: \n";
    cout << "Alpha contains: " << Alpha.size() << " elements: ";
    for(auto x : Alpha) cout << " [" << x << "]";
    cout << endl;
    cout << "Betta contains: " << Betta.size() << " elements: ";
    for(auto x : Betta) cout << " [" << x << "]";
    cout << endl;

    // swap_ranges
    cout << "\n8. swap_ranges algorithm: \n" << endl;
    vector<int> Sr_1(5, 10);
    vector<int> Sr_2(3, 20);
    cout << "Before function swap_ranges: \n";
    cout << "Sr_1 contains " << Sr_1.size() << " elements: ";
    for(auto x : Sr_1) cout << " [" << x << "]";
    cout << endl;
    cout << "Sr_2 contains " << Sr_2.size() << " elements: ";
    for(auto x : Sr_2) cout << " [" << x << "]";
    cout << endl;

    swap_ranges(Sr_1.begin(), Sr_1.end(), Sr_2.begin());

    cout << "After function swap_ranges: \n";
    cout << "Sr_1 contains " << Sr_1.size() << " elements: ";
    for(auto x : Sr_1) cout << " [" << x << "]";
    cout << endl;
    cout << "Sr_2 contains " << Sr_2.size() << " elements: ";
    for(auto x : Sr_2) cout << " [" << x << "]";
    cout << endl;

    // iter_swap
    cout << "\n9. iter_swap algorithm: \n" << endl;
    deque<int> itSw_1 {1, 2, 3, 4, 5};
    deque<int> itSw_2 {6, 7, 8, 9, 0};
    cout << "before function iter_swap: \n";
    for(auto x : itSw_1) cout << " [" << x << "]";
    cout << endl;
    for(auto x : itSw_2) cout << " [" << x << "]";
    cout << endl;

    cout << "after function iter_swap: \n";
    iter_swap(itSw_2.begin() + 1, itSw_1.begin() + 3);
    for(auto x : itSw_1) cout << " [" << x << "]";
    cout << endl;
    for(auto x : itSw_2) cout << " [" << x << "]";
    cout << endl;

    #endif
    // transform
    cout << "\n10. transform algorithm: \n" << endl;

    vector<int> tr_1;
    vector<int> tr_2;
    for(int i = 0; i < 10; ++i) tr_1.push_back((i* 10));
    tr_2.resize(tr_1.size());

    cout << "before transform: \n";
    cout << "tr_1 contains " << tr_1.size() << " elementrs: ";
    for(auto x : tr_1) cout << " [" << x << "]";
    cout << endl;

   // transform(tr_1.begin(), tr_1.end(), tr_2.begin(),
    //          tr_2.end(), plus<int>());
    cout << "After transform: \n";
    cout << "tr_1 contains " << tr_1.size() << " elementrs: ";
    for(auto x : tr_1) cout << " [" << x << "]";
    cout << endl;





    return 0;
}
