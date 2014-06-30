// others algorithms
// Dmitrij Dombrovskyi // 30.06.2014

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
class compare
{
    public:
    bool operator()(const T a, const T b)
    {
        return a < b;
    }
};

template <>
class compare <char>
{
    public:
    bool operator()(char a, char b)
    {
        return std::tolower(a) < std::tolower(b);
        //return a < b;
    }
};

template<typename T>
void next_perm_func(T & data);

template<typename T>
void prev_perm_func(T & data_permutation);

template<typename T>
void print_data(const T & data);

int main()
{
    // #1. lexicographical_compare
    cout << "#1. lexicographical_compare: " << endl;
    string name1("anna");
    string name2("Annet");

    // 1.1. comparison by default
    if(std::lexicographical_compare(name1.begin(), name1.end(),
                                    name2.begin(), name2.end()) )
        cout << name1 << " is less than " << name2 << "\n";
    else
        cout << name1 << " is bigger than " << name2 << "\n";
    cout << endl;
    // 1.2. comparison using my own template class compare:
    char name_arr_1[] = "anna";
    char name_arr_2[] = "Annet";

    compare<char> my_comparison;
    if(std::lexicographical_compare(name_arr_1, name_arr_1 + 5,
                                    name_arr_2, name_arr_2 + 4,
                                    my_comparison))
    cout << name_arr_1 << " is less than " << name_arr_2 << "\n";
    else
        cout << name_arr_1 << " is bigger than " << name_arr_2 << "\n";
    cout << endl;

    // 1.3. array of names
    vector<string> name_str1 { "Anna", "Annet"};
    vector<string> name_str2 { "Alex", "Anton", "Bob"};

    cout << std::boolalpha;
    cout << "name_str1 content: ";
    for(auto x : name_str1) cout << x << ' '; cout << endl;
    cout << "name_str2 content: ";
    for(auto x : name_str2) cout << x << ' '; cout << endl;
    cout << "name_str1 < name_str2: ";
    cout << (std::lexicographical_compare(name_str1.begin(), name_str1.end(),
                                          name_str2.begin(), name_str2.end()));
    cout << "\n" << endl;


    // #2. next_permutation
    cout << "#2. next_permutation: " << endl;
    // 2.1
    vector<int> data_arr1 { 2, 11, 5};

    cout << "Data in array: ";
    print_data(data_arr1);

    cout << "Possible permutation: \n";
    next_perm_func(data_arr1);

    cout << "After permutation data is: ";
    print_data(data_arr1);

    // 2.2 string
    vector<string> names {"Alex", "Michael", "Bob"};

    cout << "Data in array: ";
    print_data(names);

    cout << "Possible permutation: \n";
    next_perm_func(names);

    cout << "After permutation data is: ";
    print_data(names);
    cout << endl;

    // #3. prev_permutation
    // Transform range to previous permutation
    cout << "#3. prev_permutation: " << endl;
    data_arr1.clear();
    for(int i = 0; i < 3; ++i) data_arr1.push_back(i);
    std::reverse(data_arr1.begin(), data_arr1.end());

    names.clear();
    names.push_back("Hanna");
    names.push_back("Hans");
    names.push_back("Adolf");
    std::sort(names.begin(), names.end());
    std::reverse(names.begin(), names.end());

    cout << "array data_arr1 content:   ";
    print_data(data_arr1);
    cout << "array names content:       ";
    print_data(names);

    cout << "Possible permutation for data_arr1: " << endl;
    prev_perm_func(data_arr1);
    cout << "After permutation data is: ";
    print_data(data_arr1);
    cout << endl;

    cout << "Possible permutation for names: " << endl;
    prev_perm_func(names);
    cout << "After permutation data is: ";
    print_data(names);
    cout << endl;


    return 0;
}
// print each element of data array
template<typename T>
void print_data(const T & data)
{
    for(auto x : data) cout << x << ' ';
    cout << endl;
}
// next_permutation for data
template<typename T>
void next_perm_func(T & data_permutation)
{
    do {
        print_data(data_permutation);
    }while(std::next_permutation(data_permutation.begin(),
                                 data_permutation.end()));
}
// prev_permutation for data
template<typename T>
void prev_perm_func(T & data_permutation)
{
    do {
        print_data(data_permutation);
    }while(std::prev_permutation(data_permutation.begin(),
                                 data_permutation.end()));

}

