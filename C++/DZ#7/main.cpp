#include "set.hpp"
#include "string.hpp"

#define ARRAYSIZE(a) (sizeof(a) / sizeof(*(a)))

using std::cout;
using std::endl;

int main() {
    String arr1[] = {"Hello", "Human", "Bye", "Wonderful", "Human", "Hello", "Bye"};
    String arr2[] = {"Bye", "Hello", "Human", "Wonderful"};

    Set<String> SSet1(arr1, ARRAYSIZE(arr1));
    Set<String> SSet2(arr1, ARRAYSIZE(arr2));
cout << SSet1;
    SSet1<< cout << 123456;
    SSet1.operator<<(cout);
    if (SSet1 == SSet2) {
        for (auto obj: SSet1) {
            cout << obj << endl;
        }
    }
    return 0;
}