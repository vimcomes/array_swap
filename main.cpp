#include <iostream>
#include <vector>
#include <chrono>

class MyClass {
public:
    std::vector<int> a;
    std::vector<int> b;

    void swap_by_reference() {
        std::swap(a, b);
    }

    void swap_by_pointer() {
        // Get pointers to the elements of the arrays
        int* a_ptr = a.data();
        int* b_ptr = b.data();

        // Swap the pointers
        std::swap(a_ptr, b_ptr);
    }
};

int main() {
    MyClass my_class1;
    MyClass my_class2;

    my_class1.a.resize(1000000);
    my_class1.b.resize(1000000);

    // Measure the time to swap the arrays by reference
    auto start = std::chrono::steady_clock::now();
    my_class1.swap_by_reference();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_time = end - start;
    std::cout << "Elapsed time to swap by reference: " << elapsed_time.count() << " seconds" << std::endl;

    // Measure the time to swap the arrays by pointer
    start = std::chrono::steady_clock::now();
    my_class1.swap_by_pointer();
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    std::cout << "Elapsed time to swap by pointer: " << elapsed_time.count() << " seconds" << std::endl;

    return 0;
}
