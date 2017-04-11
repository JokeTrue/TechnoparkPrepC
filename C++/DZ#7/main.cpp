#include "set.hpp"
#include "string.hpp"

#define ARRAYSIZE(a) (sizeof(a) / sizeof(*(a)))

using std::cout;
using std::endl;

int main() {
    String arr1[] = {"Hello", "Human", "Bye", "Wonderful", "Human", "Hello"};
    String arr2[] = {"Bye", "Hello", "Human", "Wonderful"};

    Set<String> SSet1(arr1, ARRAYSIZE(arr1));
    Set<String> SSet2(arr1, ARRAYSIZE(arr2));

    if (SSet1 == SSet2) {
        for (auto obj: SSet1) {
            cout << obj << endl;
        }
    }
    return 0;
}