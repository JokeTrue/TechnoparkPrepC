#include "set.hpp"

#define ARRAYSIZE(a) (sizeof(a) / sizeof(*(a)))

typedef Set<double> DSet;

using std::cout;
using std::endl;
using std::cin;

int main() {
    double arr[6] = {4.8, 9.5, 8.3, 9.5, 1.2, 4.8};

//    DSet s1;
//    DSet s2(3);
    DSet s3(arr, ARRAYSIZE(arr));

    for (auto obj: s3) {
        cout << obj << endl;
    }

//    cout << "s1 = " << s1 << endl;
//    cout << "s2 = " << s2 << endl;
//    cout << "s3 = " << s3 << endl;
//
//    s2.insert(4.7);
//    s2.insert(8.2);
//    s2.insert(8.2);
//    s2.insert(9.3);
//    s2.insert(7.1);
//    cout << "s2 = " << s2 << endl;
//
//    s1 = s2;
//    cout << "s1 = " << s1 << endl;
//
//    s1 = s2 + s3;
//    cout << "s1 = " << s1 << endl;
//
//    s3 += 6.8;
//    cout << "s3 = " << s3 << endl;
//
//    DSet s4 = s3;
//    cout << "s4 = " << s4 << endl;

    return 0;
}