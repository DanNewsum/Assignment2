#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>

class Linked_List {
private:
    // Node class
    struct Node {
        int data;
        Node* next;
        Node(const int& data_item, Node* next_val = NULL) :
            data(data_item), next(next_val) {}
    };

    // Data members
    Node* head;
    Node* tail;
    size_t num_items;

public:
    Linked_List();

    void push_front(const int& item);
    void push_back(const int& item);
    bool pop_front();
    bool pop_back();
    int& front();
    int& back();
    bool empty() const;
    void insert(size_t index, const int& item);
    bool remove(size_t index);
    size_t find(const int& item) const;
    size_t size() const;
};

#endif // LINKED_LIST_H
