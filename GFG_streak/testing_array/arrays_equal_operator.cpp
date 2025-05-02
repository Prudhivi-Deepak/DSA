#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::vector<int> arr = {1, 2, 3, 4};
    std::vector<int> arr2 = {4, 5, 6};

    // operator=
    arr = arr2;
    std::cout << "Array after operator=: ";
    for(auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Modify arr to show they are separate
    arr[0] = 1;
    std::cout << "Array arr after modification: ";
    for(auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Array arr2 remains unchanged: ";
    for(auto& elem : arr2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    cout << (arr > arr2) << endl;

    cout << arr.max_size() << endl;

    return 0;
}