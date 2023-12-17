/*
 * little program to test 2 methods of swap vector arrays
 * by std::swap_ranges
 */
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>


class MyClass {
public:
    std::vector<int> a;
};

int main() {
    MyClass my_class1;
    MyClass my_class2;
    my_class1.a.resize(10000);
    my_class2.a.resize(10000);

    //ref
    auto start = std::chrono::steady_clock::now();
    std::ranges::swap_ranges(my_class1.a.begin(), my_class1.a.end(), my_class2.a.begin(), my_class2.a.end());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_time = end - start;
    std::cout << "Elapsed time to swap by reference: " << elapsed_time.count() << " seconds" << std::endl;

    //pointer
    start = std::chrono::steady_clock::now();
    std::ranges::swap_ranges(my_class1.a.data(), my_class1.a.data() + my_class1.a.size(), my_class2.a.data(), my_class2.a.data() + my_class2.a.size());
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    std::cout << "Elapsed time to swap by pointer: " << elapsed_time.count() << " seconds" << std::endl;

    return 0;
}
