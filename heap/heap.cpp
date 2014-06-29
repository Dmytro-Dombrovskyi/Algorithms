#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    // #1. is_heap, make_heap, push_heap, pop_heap, sort_heap, is_heap_until

    cout << "#1. is_heap, make_heap, push_heap, pop_heap, sort_heap,";
    cout << " is_heap_until: " << endl;

    vector<int> data_arr;
    for(int i = 1; i < 11; ++i) data_arr.push_back(i);
    random_shuffle(data_arr.begin(), data_arr.end());

    // test if range is heap // c++11
    if(!(is_heap(data_arr.begin(), data_arr.end())))
    {
        // make_heap
        make_heap(data_arr.begin(), data_arr.end());
    }
    cout << "initial max_heap: " << data_arr.front() << endl;

    // pop_heap
    pop_heap(data_arr.begin(), data_arr.end());
    cout << "max heap after pop: " << data_arr.front() << endl;
    data_arr.pop_back();

    //push_heap
    data_arr.push_back(10);
    push_heap(data_arr.begin(), data_arr.end());
    cout << "max heap after push: " << data_arr.front() << endl;

    cout << "Data in array before sort_heap: ";
    for(auto x : data_arr) cout << x << ' '; cout << endl;

    // sort_heap
    sort_heap(data_arr.begin(), data_arr.end());
    cout << "Data in array after sorting: ";
    for(auto x : data_arr) cout << x << ' '; cout << endl;
    cout << endl;

    // is_heap_until
    if(!(is_sorted(data_arr.begin(), data_arr.end())) )
    {
       sort(data_arr.begin(), data_arr.end());
    }
    reverse(data_arr.begin(), data_arr.end());

    auto it_last = is_heap_until(data_arr.begin(), data_arr.end());
    cout << "Data in array: ";

    for(auto x : data_arr) cout << x << ' '; cout << endl;
    cout << (it_last - data_arr.begin()) << " Data is valid heap: ";
    cout << endl;

    return 0;
}

