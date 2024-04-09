#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

struct Node {
    struct Node *next;
    struct Node *prev;
    int data;
};
typedef struct Node Node_t;

static Node_t *head = NULL;
static Node_t *tail = NULL;

void insertAtHead(int data) {
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
}

void insertAtTail(int data) {
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;
    tail = newNode;
}

void deleteAtHead() {
    Node_t *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void deleteAtTail() {
    Node_t *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}

void printList() {
    Node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    insertAtHead(4);
    insertAtHead(5);
    printList();
    deleteAtHead();
    deleteAtHead();
    printList();
    return 0;
}

