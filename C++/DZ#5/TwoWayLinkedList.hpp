#ifndef DZ_5_TWOWAYLINKEDLIST_HPP
#define DZ_5_TWOWAYLINKEDLIST_HPP

typedef struct node {
    int index;
    int number;
    struct node *prev;
    struct node *next;
} Node;

class TwoWayLinkedList {
public:
    TwoWayLinkedList();

    ~TwoWayLinkedList();

    TwoWayLinkedList(const TwoWayLinkedList &rhs);

    TwoWayLinkedList &operator=(const TwoWayLinkedList &rhs);

    friend TwoWayLinkedList operator+(const TwoWayLinkedList &a, const TwoWayLinkedList &b);

    void add(int element);

    void append(int element);

    void display();

    void delete_by_index(int index);

    Node *find_by_index(int index);

    void sort();


private:
    int size;
    Node *head;
    Node *tail;

    void _decrementIndexes(Node *start);
};


#endif //DZ_5_TWOWAYLINKEDLIST_HPP
