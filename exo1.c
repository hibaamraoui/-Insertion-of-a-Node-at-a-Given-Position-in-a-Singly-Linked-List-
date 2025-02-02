#include<stdio.h>
#include "list.h"

void insertAtPosition(Node** head, int value, int k) {
    // Create a new node with the given value to insert
    Node* newNode = createNode(value);

    // Special case: Insert at the beginning of the list (position 0)
    if (k == 0) {
        // Insert the new node at the start by making it point to the current head
        setNext(newNode, *head);
        // Update the head to point to the new node
        *head = newNode;
        return; // Exit after inserting
    }

    // Start at the beginning of the list
    Node* current = *head;
    int pos = 0; // Track the current position in the list

    // Move through the list to find the node just before the insertion point
    while (current != NULL && pos < k - 1) {
        current = getNext(current); // Move to the next node
        pos++; // Update the position
    }

    // If we reach the end of the list before finding the insertion point, it's invalid
    if (current == NULL) {
        printf("Position out of bounds\n");
        deleteNode(newNode); // Clean up the new node since we can't insert it
        return; // Exit the function
    }

    // Insert the new node at the correct position (middle or end)
    setNext(newNode, getNext(current)); // Make the new node point to the next node
    setNext(current, newNode); // Make the current node point to the new node
}