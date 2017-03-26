#include "TwoWayLinkedList.hpp"

int main() {
    TwoWayLinkedList a;
    for (int i = 0; i < 10; i++) {
        a.append(i);
    }
//    TwoWayLinkedList b;
//    b = a;
//    b.display();
    TwoWayLinkedList b;
    for (int i = 10; i < 20; i++) {
        b.append(i);
    }
    TwoWayLinkedList merged = a + b;
    merged.sort();
    merged.delete_by_index(5);
    merged.display();
    return 0;
}