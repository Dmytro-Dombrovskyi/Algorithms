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
    cout << "#2. stable_sort: " << endl;


    return 0;
}
