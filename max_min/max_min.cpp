// max_min algorithms //
// Dmytro Dombrovskyi // 29.06.2014 //
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<int> vec_int;
int main()
{
    // #1. min, max
    cout << "#1. min, max: " << endl;
    int a = 3;
    int b = 6;
    cout << "min(" << a << ", " << b << ") = " << min(a, b);
    cout << endl;
    cout << "max(" << a << ", " << b << ") = " << max(a, b);
    cout << endl;

    char a_ch = 'a';
    char b_ch = 'b';
    cout << "min(" << a_ch << ", " << b_ch << ") = " << min(a_ch, b_ch);
    cout << endl;
    cout << "max(" << a_ch << ", " << b_ch << ") = " << max(a_ch, b_ch);
    cout << endl << endl;

    //#2. minmax
    cout << "#2. minmax: " << endl;
    auto result = minmax(1, 2);
    cout << "min value in data: " << result.first << ", ";
    cout << "max value in data: " << result.second << ".";
    cout << endl;

    auto result_in_list = minmax({1, 2, 3, 4, 5});
    cout << "min value in data: " << result_in_list.first << ", ";
    cout << "max value in data: " << result_in_list.second << ".";
    cout << endl << endl;

    // #3. min_element, max_element
    cout << "#3. min_element, max_element: " << endl;
    vector<int> data1;
    for(int i = 0; i < 10; ++i) data1.push_back(i);
    random_shuffle(data1.begin(), data1.end());

    cout << "data1 content: ";
    for(auto x : data1) cout << x << ' '; cout << endl;
    cout << "min element in data1: ";
    cout << *min_element(data1.begin(), data1.end()) << endl;
    cout << "max element in data1: ";
    cout << *max_element(data1.begin(), data1.end()) << endl;
    cout << endl;

    // #4. minmax_element
    cout << "#4. minmax_element: " << endl;

    data1.clear();
    for(int i = 0; i < 10; ++i) data1.push_back(i*2);
    auto res_minmax_elem = minmax_element(data1.begin(), data1.end(),
            [](int a, int b)->bool {return a < b;});

    cout << "data1 content: ";
    for(auto x : data1) cout << x << ' '; cout << endl;
    cout << "min value in data1: " << *res_minmax_elem.first;
    cout << " at " << (res_minmax_elem.first - data1.begin());
    cout << " position." << endl;
    cout << "max value in data1: " << *res_minmax_elem.second;
    cout << " at " << (res_minmax_elem.second - data1.begin());
    cout << " position." << endl;

    return 0;
}
