#pragma once

#include "LinkedHeader.h"

#include <iostream>
#include <stdexcept>
#include "LinkedHeader.h"

Linked_List::Linked_List() {
    head = NULL;
    tail = NULL;
    num_items = 0;
}

void Linked_List::push_front(const int& item) {
    Node* new_node = new Node(item, head);
    if (head == NULL) {
        // This is the first node being added to the list
        tail = new_node;
    }
    head = new_node;
    ++num_items;
}

void Linked_List::push_back(const int& item) {
    Node* new_node = new Node(item, tail);

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }

    ++num_items;

}

bool Linked_List::pop_front() {
    if (head == NULL)
    {
        return false;
    }
    Node* temp = head; // Store the old head node to delete it later
    head = head->next;
    
    delete temp; // Deallocate the old head node
    --num_items; // Decrease the count of items in the list

    return true;
    
}

bool Linked_List::pop_back() {
    if (head == NULL)
    {
        return false;
    }
    Node* temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = NULL;

    --num_items;
}
    

int& Linked_List::front() {
    return head->data;
}

int& Linked_List::back() {
    return tail->data;
}

bool Linked_List::empty() const {
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Linked_List::insert(size_t index, const int& item) {
    // If the list is empty or index is 0, we can push to the front
    if (head == NULL || index == 0) {
        push_front(item);
    }

    // Index is the size of list or greater, push to tail
    else if (index >= num_items) {
        push_back(item);
    }

    // Check where the new node should be inserted
    else {
        // We start at the head/first one
        Node* current_node = head;
        // And we iterate until we reach the node right before the index
        for (size_t i = 0; i < index - 1; ++i) {
            current_node = current_node->next;
        }

        // We create a new node that points to the node currently at the index
        Node* new_node = new Node(item, current_node->next);

        // And we update the 'next' of the current node to the new node
        current_node->next = new_node;

        // Finally, we increase the number of items in the list
        ++num_items;
    }
}

bool Linked_List::remove(size_t index) {
    // Check if empty
    if (head == NULL) {
        return false;
    }

    // If index is 0
    else if (index == 0) {
        pop_front();
        return true;
    }

    // If the index is past the end of the list
    else if (index >= num_items) {
        std::cout << "Index beyond list size";
        return false;
    }
    // Check to see where to delete node
    else {
        // We start at the first one
        Node* current_node = head;
        // iterate 

        for (size_t i = 0; i < index - 1; ++i) {
            current_node = current_node->next;
        }

        Node* temp = current_node->next;
        // We update the 'next' of the current node 
        current_node->next = temp->next;

        // Check if tail
        if (temp == tail) {
            tail = current_node;
        }

        // We delete the node
        delete temp;
        --num_items;

        return true;
    }
}

size_t Linked_List::size() const {
    return num_items;
}


size_t Linked_List::find(const int& item) const {



}