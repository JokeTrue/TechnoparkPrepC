#include "set.hpp"
#include "string.hpp"

#define ARRAYSIZE(a) (sizeof(a) / sizeof(*(a)))

using std::cout;
using std::endl;

int main() {
    String arr[] = {"Hello", "Human", "Bye", "Wonderful", "Human", "Hello"};
    Set<String> SSet(arr, ARRAYSIZE(arr));

    for (auto obj: SSet) {
        cout << obj << endl;
    }
    return 0;
}