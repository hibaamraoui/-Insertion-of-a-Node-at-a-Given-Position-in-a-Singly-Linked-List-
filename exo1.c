#include <stdio.h>
#include "list.h"

// Function to initialize the list with values 1 to 5
Node* initializeList() {
    Node* head = createNode(1);
    Node* current = head;

    for (int i = 2; i <= 5; i++) {
        Node* newNode = createNode(i);
        setNext(current, newNode);
        current = newNode;
    }
    return head;
}

// Function to insert a node at a given position
void insertAtPosition(Node** head, int value, int k) {
    Node* newNode = createNode(value);

    // Special case: Insert at the beginning
    if (k == 0) {
        setNext(newNode, *head);
        *head = newNode;
        return;
    }

    Node* current = *head;
    Node* prev = NULL;
    int pos = 0;

    // Traverse to (k-1)th position
    while (current != NULL && pos < k) {
        prev = current;
        current = getNext(current);
        pos++;
    }

    // If position is out of bounds
    if (pos < k) {
        printf("Position out of bounds\n");
        deleteNode(newNode);
        return;
    }

    // Insert between prev and current
    setNext(newNode, current);
    setNext(prev, newNode);
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    printf("Current List: ");
    while (current != NULL) {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

int main() {
    // Initialize list with values 1 to 5
    Node* head = initializeList();

    printf("Initial linked list:\n");
    printList(head);

    int value, position;

    while (1) {
        printf("\nEnter a number to insert (-1 to exit): ");
        scanf("%d", &value);

        if (value == -1) {
            break; // Exit if user enters -1
        }

        printf("Enter the position to insert: ");
        scanf("%d", &position);

        insertAtPosition(&head, value, position);

        printf("\nUpdated linked list:\n");
        printList(head);
    }

    printf("\nFinal linked list:\n");
    printList(head);

    return 0;
}

