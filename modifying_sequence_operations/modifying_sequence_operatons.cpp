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
#include <ctime>
#include <random>

using namespace std;
template<typename T>
inline void print(T & widget) {cout << widget << " ";}

inline int plus_iter()
{
    static int i = 0;
    return ++i;
}

inline int get_random_value() {return rand() % 2; }

int main()
{
    srand(time(NULL));
   // #if 0
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


    // transform with lamba functions
    cout << "\n10. transform algorithm: \n" << endl;

    vector<int> tr_1;
    vector<int> tr_2;
    for(int i = 0; i < 10; ++i)
        tr_1.push_back((i* 10));

    tr_2.resize(tr_1.size());

    cout << "before transform: \n";

    cout << "tr_1 contains " << tr_1.size() << " elements: ";
    for(auto x : tr_1) cout << " [" << x << "]";
    cout << endl;

    cout << "tr_2 contains " <<tr_2.size() << " elements: ";
    for(auto x : tr_2) cout << " [" << x << "]";
    cout << endl;
    // using transform with unary operation
    transform(tr_1.begin(), tr_1.end(), tr_2.begin(),
              [] (int i) -> int { return ++i; } );

    cout << "after using transform algorithm: unary operation \n";

    cout << "tr_1 contains " << tr_1.size() << " elements: ";
    for(auto x : tr_1) cout << " [" << x << "]";
    cout << endl;

    cout << "tr_2 contains " <<tr_2.size() << " elements: ";
    for(auto x : tr_2) cout << " [" << x << "]";
    cout << endl << endl;

    // using transform with binary operation
    transform(tr_1.begin(), tr_1.end(), tr_2.begin(), tr_1.begin(),
              [] (int a, int b) -> int { return a + b; } );

    cout << "after using transform algorithm: bynary operation: \n";

    cout << "tr_1 contains " << tr_1.size() << " elements: ";
    for(auto x : tr_1) cout << " [" << x << "]";
    cout << endl;

    cout << "tr_2 contains " <<tr_2.size() << " elements: ";
    for(auto x : tr_2) cout << " [" << x << "]";
    cout << endl;

    // replace algorithm
    cout << "\n11. replace algorithm: \n" << endl;
    vector<int> rep_value {10, 20, 10, 30, 50, 10};
    cout << "Value in array: ";
    for_each(rep_value.begin(), rep_value.end(),
             [] (int val) { cout << val << " "; });
    cout << endl;
    replace(rep_value.begin(), rep_value.end(), 10, 0);
    cout << "Value in array after using replace algorithm: ";
    for(auto x : rep_value) cout << x << " ";
    cout << endl << endl;

    // replace_if
    cout << "\n12. replace_if: \n" << endl;
    vector<string> rep_if_names {"Dima", "Andrju", "Machel", "Thomas"};
    cout << "Data in array: ";
    for(auto x: rep_if_names) cout << x << " ";
    cout << endl;

    string name_for_replace("Tom");
    replace_if(rep_if_names.begin(), rep_if_names.end(),
               [](string & name) -> bool{return name == "Thomas";},
                name_for_replace);
    cout << "After using replace_if algorithm: ";
    for(auto x: rep_if_names) cout << x << " ";
    cout << endl << endl;

    // replace_copy
    cout << "\n13. replace_copy: \n" << endl;
    vector<int> rep_copy_val1 {10, 20, 30, 10, 50};
    vector<int> rep_copy_val2;
    rep_copy_val2.resize(rep_copy_val1.size());

    cout << "Data in array 1: ";
    for(auto x: rep_copy_val1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: ";
    for(auto x: rep_copy_val2) cout << x << " ";
    cout << endl;

    replace_copy(rep_copy_val1.begin(), rep_copy_val1.end(),
                 rep_copy_val2.begin(), 10, 50);

    cout << "Data after using replace_copy algorithm: " << endl;
    cout << "Data in array 1: ";
    for(auto x: rep_copy_val1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: ";
    for(auto x: rep_copy_val2) cout << x << " ";
    cout << endl << endl;

      // replace_copy_if algorithm:
    cout << "\n14. replace_copy_if: \n" << endl;
    deque<int> rep_copy_if_val1 {1, 3, 4, 5, 2, 1, 1};
    deque<int> rep_copy_if_val2(rep_copy_if_val1.size());

    cout << "Data in array 1: ";
    for(auto x: rep_copy_if_val1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: ";
    for(auto x: rep_copy_if_val2) cout << x << " ";
    cout << endl;

    replace_copy_if(rep_copy_if_val1.begin(), rep_copy_if_val1.end(),
                    rep_copy_if_val2.begin(),
                    [](int val)->bool { return val % 2; }, 0);

    cout << "Data in arrays after using replace_copy_if algorithm: ";
    cout << endl;
    cout << "Data in array 1: ";
    for(auto x: rep_copy_if_val1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: ";
    for(auto x: rep_copy_if_val2) cout << x << " ";
    cout << endl << endl;


    // fill algoritm
    //Assigns val to all the elements in the range [first,last).
    cout << "\n15. fill: \n" << endl;
    vector<double> fill_values(10);
    cout << "Data in array: ";
    for(auto x: fill_values) cout << x << " ";
    cout << endl;

    fill(fill_values.begin(), fill_values.end() - 5, 1.0);
    fill(fill_values.end() - 5, fill_values.end(), 2.0);

    cout << "After using fill algorithm: " << endl;
    cout << "Data in array: ";
    for(auto x: fill_values) cout << x << " ";
    cout << endl << endl;

    // fill_n algorithm:
    cout << "\n16. fill_n: \n" << endl;
    // Assigns val to the first n elements of the sequence pointed by first.
    vector<char> fill_n_symbol(10, '*');
    cout << "Data in array: ";
    for(auto x: fill_n_symbol) cout << x << " ";
    cout << endl;

    fill_n(fill_n_symbol.begin(), 5, '-');
    fill_n(fill_n_symbol.begin() + 5, 4, '.');

    cout << "After using fill_n algorithm: " << endl;
    cout << "Data in array: ";
    for(auto x: fill_n_symbol) cout << x << " ";
    cout << endl << endl;


    // generate algorithm
    // Assigns the value returned by successive calls
    // to gen to the elements in the range [first,last).
    cout << "\n17. Generate algorithm: \n" << endl;

    vector<int> gen_val (10, 0);
    generate(gen_val.begin(), gen_val.end(), plus_iter );
    cout << "Data in array after using generate algorithm: ";
    cout << endl;
    for(auto x: gen_val) cout << x << " ";
    cout << endl << endl;

    // generate_n
    // Assigns the value returned by successive calls to gen
    // to the first n elements of the sequence pointed by first.

    cout << "\n18. Generate_n algorithm: \n" << endl;

    vector<int> gen_n_values(10, 0);
    generate_n(gen_n_values.begin(), 10, plus_iter);

    cout << "Data in array: ";
    for(auto x: gen_n_values) cout << x << " ";
    cout << endl << endl;


    // remove
    //Remove value from range
    cout << "\n19. remove algorithm: \n" << endl;
    list<int> rem_array {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    cout << "Data in array: \n";
    for(auto x: rem_array) cout << x << " ";
    cout << endl;

    int rem_value = 2;
    rem_array.erase(remove(rem_array.begin(), rem_array.end(), rem_value),
                    rem_array.end());

    cout << "Data after using remove algorithm: \n";
    for(auto x: rem_array) cout << x << " ";
    cout << endl << endl;


    // remove_if
    cout << "\n20. remove_if algorithm: \n" << endl;
    vector<int> rem_if_val {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Data in array: " << endl;
    for(auto x: rem_if_val) cout << x << " ";
    cout << endl;

    rem_if_val.erase(remove_if(rem_if_val.begin(), rem_if_val.end(),
              [](int x)->bool{return x % 2;} ), rem_if_val.end() );

    cout << "Data after using remove_if algorithm: \n";
    for(auto x: rem_if_val) cout << x << " ";
    cout << endl << endl;


    // remove_copy
    // Copies the elements in the range [first,last) to
    // the range beginning at result, except those elements
    // that compare equal to val.

    cout << "\n21. remove_copy algorithm: \n" << endl;
    vector<int> rem_copy_arr1;
    for(int i = 0; i < 10; ++i)
        rem_copy_arr1.push_back(i);
    vector<int> rem_copy_arr2(rem_copy_arr1.size());

    cout << "Data in array 1: ";
    for(auto x: rem_copy_arr1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: ";
    for(auto x: rem_copy_arr2) cout << x << " ";
    cout << endl;

    rem_copy_arr2.erase(remove_copy(rem_copy_arr1.begin(), rem_copy_arr1.end(),
              rem_copy_arr2.begin(), 2), rem_copy_arr2.end() );

    cout << "After using remove_copy algorithm \n";
    cout << "Data in array 1: ";
    for(auto x: rem_copy_arr1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: ";
    for(auto x: rem_copy_arr2) cout << x << " ";
    cout << endl << endl;


    // remove_copy_if
    // Copies the elements in the range [first,last) to
    // the range beginning at result, except those elements
    // for which pred returns true.

    cout << "\n22. remove_copy_if algorithm: \n" << endl;
    vector<int> rem_copy_if_arr1;
    for(int i = 0; i < 20; ++i)
        rem_copy_if_arr1.push_back(i);
    vector<int> rem_copy_if_arr2(rem_copy_if_arr1.size());

    cout << "Data in array 1: ";
    for(auto x: rem_copy_if_arr1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: ";
    for(auto x: rem_copy_if_arr2) cout << x << " ";
    cout << endl;

    rem_copy_if_arr2.erase(remove_copy_if(rem_copy_if_arr1.begin(),
                           rem_copy_if_arr1.end(), rem_copy_if_arr2.begin(),
                           [](int i)->bool{return i % 2;} ),
                           rem_copy_if_arr2.end() );

    cout << "After using remove_copy algorithm \n";
    cout << "Data in array 1: ";
    for(auto x: rem_copy_if_arr1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: ";
    for(auto x: rem_copy_if_arr2) cout << x << " ";
    cout << endl << endl;


    // unique
    // Removes all but the first element from every consecutive
    // group of equivalent elements in the range [first,last).
    cout << "\n23. unique algorithm: \n" << endl;

    vector<int> unique_array1 {1, 2, 2, 3, 4, 4, 3, 2, 1, 1};
    vector<int>::iterator un_itr;

    cout << "Data in array: " << endl;
    for(auto x: unique_array1) cout << x << " ";
    cout << endl;

    un_itr = std::unique(unique_array1.begin(), unique_array1.end());
    unique_array1.resize(distance(unique_array1.begin(), un_itr));

    cout << "After using unique algorithm: " << endl;
    for(auto x: unique_array1) cout << x << " ";
    cout << endl << endl;


    // unique_copy
    // Copies the elements in the range [first,last) to the range
    // beginning at result, except consecutive duplicates
    // (elements that compare equal to the element preceding).
    cout << "\n24. unique_copy algorithm using predicate: \n" << endl;

    vector<int> unique_copy_alg1 {1, 2, 2, 3, 4, 4, 3, 2, 1, 1};
    vector<int> unique_copy_alg2(unique_copy_alg1.size());

    cout << "Data in array1: " << endl;
    for(auto x: unique_copy_alg1) cout << x << " ";
    cout << endl;
    cout << "Data in array2: " << endl;
    for(auto x: unique_copy_alg2) cout << x << " ";
    cout << endl;

    unique_copy_alg2.erase(unique_copy(unique_copy_alg1.begin(),
                                        unique_copy_alg1.end(),
                                        unique_copy_alg2.begin(),
                            [](int a, int b)->bool {return a == b;} ),
                            unique_copy_alg2.end() );

    vector<int>::iterator uni_copy_itr;
    for(uni_copy_itr = unique_copy_alg2.begin();
        *uni_copy_itr != 0; ++uni_copy_itr);

    unique_copy_alg2.resize(distance(unique_copy_alg2.begin(), uni_copy_itr));

    cout << "Data in arrays after using unique_copy algorithm: ";
    cout << endl;

    cout << "Data in array1: " << endl;
    for(auto x: unique_copy_alg1) cout << x << " ";
    cout << endl;
    cout << "Data in array2: " << endl;
    for(auto x: unique_copy_alg2) cout << x << " ";
    cout << endl << endl;


    // reverse
    // Reverses the order of the elements in the range [first,last).
    cout << "\n25. reverse algorithm: \n" << endl;

    deque<int> rev_arr1 {1, 2, 3, 4, 5, 6};

    cout << "Data in array: " << endl;
    for(auto x: rev_arr1) cout << x << " ";
    cout << endl;

    reverse(rev_arr1.begin(), rev_arr1.end());

    cout << "After using reverse algoritm: " << endl;
    for(auto x: rev_arr1) cout << x << " ";
    cout << endl << endl;

    // reverse_copy
    // Copies the elements in the range [first,last) to the range
    // beginning at result, but in reverse order.
    cout << "\n26. reverse_copy algorithm: \n" << endl;

    vector<int> rev_copy_arr1;
    for(int i = 0; i < 20; ++i)
        rev_copy_arr1.push_back(i);
    vector<int> rev_copy_arr2(rev_copy_arr1.size());

    cout << "Data in array 1: " << endl;
    for(auto x: rev_copy_arr1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: " << endl;
    for(auto x: rev_copy_arr2) cout << x << " ";
    cout << endl;

    reverse_copy(rev_copy_arr1.begin(), rev_copy_arr1.end(),
                 rev_copy_arr2.begin());
    cout << "Data in arrays after using reverse_copy algorithm: ";
    cout << endl;
    cout << "Data in array 1: " << endl;
    for(auto x: rev_copy_arr1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2: " << endl;
    for(auto x: rev_copy_arr2) cout << x << " ";
    cout << endl << endl;


    // rotate algorithm
    // Rotates the order of the elements in the range [first,last),
    // in such a way that the element pointed by middle becomes the
    // new first element.
    cout << "\n27. rotate algorithm: \n" << endl;

    vector<string> rotate_array1 {"BMW", "Mercedes", "Bentlay", "Reno", "Audi"};

    cout << "Data in array: " << endl;
    for(auto x: rotate_array1) cout << x << " ";
    cout << endl;

    rotate(rotate_array1.begin(), rotate_array1.begin() + 3,
           rotate_array1.end() );

    cout << "Data in array after using rotate algoritm: " << endl;
    for(auto x: rotate_array1) cout << x << " ";
    cout << endl << endl;

    // rotate_copy
    // Copies the elements in the range [first,last) to the
    // range beginning at result, but rotating the order of
    // the elements in such a way that the element pointed by
    // middle becomes the first element in the resulting range.
    cout << "\n28. rotate_copy algorithm: \n" << endl;

    vector<int> rot_copy_arr1;
    for(int i = 0; i < 10; ++i)
        rot_copy_arr1.push_back(i);
    vector<int> rot_copy_arr2(rot_copy_arr1.size());

    cout << "Data in array 1:" << endl;
    for(auto x: rot_copy_arr1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2:" << endl;
    for(auto x: rot_copy_arr2) cout << x << " ";
    cout << endl;

    rotate_copy(rot_copy_arr1.begin(), rot_copy_arr1.begin() + 5,
                rot_copy_arr1.end(), rot_copy_arr2.begin());


    cout << "After using rotate_copy algorithm: " << endl;
    cout << "Data in array 1:" << endl;
    for(auto x: rot_copy_arr1) cout << x << " ";
    cout << endl;
    cout << "Data in array 2:" << endl;
    for(auto x: rot_copy_arr2) cout << x << " ";
    cout << endl << endl;


    // random_shuffle algorithm
    // Rearranges the elements in the range [first,last) randomly.
    cout << "\n29. random_shuffle algorithm: \n" << endl;
    vector<int> rand_shuff_arr1;
    for(int i = 0; i < 20; ++i)
        rand_shuff_arr1.push_back(i);
    cout << "Data in array: " << endl;
    for(auto x: rand_shuff_arr1) cout << x << " ";
    cout << endl;

    random_shuffle(rand_shuff_arr1.begin(), rand_shuff_arr1.end());
    cout << "Data in array after using random_shuffle algorithm: ";
    cout << endl;
    for(auto x: rand_shuff_arr1) cout << x << " ";
    cout << endl << endl;
//#endif

    // shuffle algorithm
    // Rearranges the elements in the range [first,last) randomly,
    // using g as uniform random number generator.
    cout << "\n30. shuffle algorithm: \n" << endl;

    vector<int> shuffle_array;
    for(int i = 0; i < 10; ++i)
        shuffle_array.push_back(i);
    cout << "Data in array: " << endl;
    for(auto x: shuffle_array) cout << x << " ";
    cout << endl;

    shuffle(shuffle_array.begin(), shuffle_array.end(),
            default_random_engine(get_random_value()));
    cout << "Data in array after using shuffle alorithm: ";
    cout << endl;
    for(auto x: shuffle_array) cout << x << " ";
    cout << endl << endl;


    return 0;
}
