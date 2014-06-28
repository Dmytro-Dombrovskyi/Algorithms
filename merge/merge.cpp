// merge algorithms
// Dmytro Dombrovskyi // 27.06.2014 //

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

typedef vector<int> vec_int;

template<typename T>
class compare
{
    public:
    bool operator () (T a, T b) { return a < b;}
};

int main()
{
#if 0
    // #1. merge
    cout << "#1. merge sorted ranges: " << endl;
    vector<int> merge_arr_1, merge_arr_2;
    for(size_t i = 0; i < 10; ++i)
        merge_arr_1.push_back(i);
    for(size_t i = merge_arr_1.size();
        i < merge_arr_1.size() * 2; ++i)
        merge_arr_2.push_back(i);

    if(!(std::is_sorted(merge_arr_1.begin(),
                      merge_arr_1.end())) )
    {
      std::sort(merge_arr_1.begin(), merge_arr_1.end());
    }

    if(!(std::is_sorted(merge_arr_2.begin(),
                        merge_arr_2.end())) )
    {
        std::sort(merge_arr_2.begin(), merge_arr_2.end());
    }

    vector<int> merge_arr_result(merge_arr_1.size() + merge_arr_2.size());
    std::merge(merge_arr_1.begin(), merge_arr_1.end(),
               merge_arr_2.begin(), merge_arr_2.end(),
               merge_arr_result.begin());
    cout << "Data in array 1: ";
    for(auto x : merge_arr_1) cout << x << " "; cout << endl;
    cout << "Data in array 1: ";
    for(auto x : merge_arr_2) cout << x << " "; cout << endl;
    cout << "Data in array 3: ";
    for(auto x : merge_arr_result) cout << x << " "; cout << endl;

    // #2. inplace_merge
    cout << "#2. inplace_merge: " << endl;
    vec_int data1, data2, data3;
    for(size_t i = 0; i < 10; ++i)
        data1.push_back(i);
    for(size_t i = 5; i < 15; ++i)
        data2.push_back(i);

    cout << "Data in array 1: ";
    for(auto x : data1) cout << x << " "; cout << endl;
    cout << "Data in array 2: ";
    for(auto x : data2) cout << x << " "; cout << endl;

    data3.resize(data1.size() + data2.size());
    std::copy(data1.begin(), data1.end(), data3.begin());
    std::copy(data2.begin(), data2.end(), data3.begin() + data1.size());

    cout << "Data in array 3: ";
    for(auto x : data3) cout << x << " "; cout << endl;


    std::inplace_merge(data3.begin(),
                       data3.begin() + (data3.size() / 2),
                       data3.end());
    cout << "using inplace_merge algorithm: " << endl;
    cout << "Data in array 3: ";
    for(auto x : data3) cout << x << " "; cout << endl;
    cout << endl;
#endif
    // #3. includes
    cout << "#3. includes: " << endl;
    vec_int data_incl_1;
    vec_int data_incl_2;

    for(int i = 0; i < 10; ++i) data_incl_1.push_back(i);
    for(int i = 5; i < 10; ++i) data_incl_2.push_back(i);

    cout << "Data 1: ";
    for(auto x : data_incl_1) cout << x << " "; cout << endl;
    cout << "Data 2: ";
    for(auto x : data_incl_2) cout << x << " "; cout << endl;

    cout << "Data2 in Data1 are ";
    compare<int> comparator_1;
    if(std::includes(data_incl_1.begin(), data_incl_1.end(),
       data_incl_2.begin(), data_incl_2.end(), comparator_1))
       {
           cout << "includ!" << endl;
       }
       else
        cout << "not includ!" << endl;
    cout << endl;

    // #4. set_union
    cout << "#4. set_union: " << endl;
    data_incl_1.clear(); data_incl_2.clear();
    for(int i = 0; i < 10; ++i)
    {
        data_incl_1.push_back(i);
        data_incl_2.push_back(i * 2);
    }
    cout << "data in array 1: ";
    for(auto x : data_incl_1) cout << x << ' '; cout << endl;
    cout << "data in array 2: ";
    for(auto x : data_incl_2) cout << x << ' '; cout << endl;

    vec_int arr_set_union(data_incl_1.size() + data_incl_2.size());
    vec_int::iterator arr_itr;
    arr_itr = std::set_union(data_incl_1.begin(), data_incl_1.end(),
                   data_incl_2.begin(), data_incl_2.end(),
                   arr_set_union.begin());
    arr_set_union.resize(arr_itr - arr_set_union.begin());

    cout << "Data in union array: ";
    for(auto x : arr_set_union) cout << x << ' '; cout << endl;
    cout << endl;


    // #5. set_intersection
    cout << "#5. set_intersection: " << endl;





    return 0;
}
