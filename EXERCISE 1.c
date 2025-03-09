#include <stdio.h>
#include <stdlib.h>

struct cell {
    int value;
    struct cell *next;
};

struct cell* createNode(int value) {
    struct cell* newNode = (struct cell*)malloc(sizeof(struct cell));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void addAtBeginning(struct cell** head, int value) {
    struct cell* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(struct cell** head, int value) {
    struct cell* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct cell* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct cell* head) {
    struct cell* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void deleteFirst(struct cell** head) {
    if (*head == NULL) return;
    struct cell* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct cell** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct cell* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteValue(struct cell** head, int value) {
    if (*head == NULL) return;
    if ((*head)->value == value) {
        struct cell* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct cell* temp = *head;
    while (temp->next != NULL && temp->next->value != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) return;
    struct cell* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

int main() {
    struct cell* head = NULL;

    addAtEnd(&head, 10);
    addAtEnd(&head, 20);
    addAtBeginning(&head, 5);
    displayList(head);

    deleteFirst(&head);
    displayList(head);

    deleteLast(&head);
    displayList(head);

    addAtEnd(&head, 30);
    addAtEnd(&head, 40);
    displayList(head);

    deleteValue(&head, 30);
    displayList(head);

    return 0;
}