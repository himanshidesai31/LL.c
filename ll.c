#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the list
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to update a node's data
void updateNode(struct Node* head, int oldData, int newData) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            return;
        }
        current = current->next;
    }
    printf("Node with data %d not found.\n", oldData);
}

// Function to delete a node by value
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *headRef = temp->next; // Changed head
        free(temp); // Free old head
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp); // Free memory
}

int main() {
    struct Node* head = NULL;
    int choice, data, oldData, newData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Append a node\n");
        printf("2. Update a node\n");
        printf("3. Delete a node\n");
        printf("4. Print the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 2:
                printf("Enter data to update: ");
                scanf("%d", &oldData);
                printf("Enter new data: ");
                scanf("%d", &newData);
                updateNode(head, oldData, newData);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printf("Linked List: ");
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;