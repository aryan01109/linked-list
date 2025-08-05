#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter the value to insert into linked list: ");
    scanf("%d", &x);

    (*newnode).data = x;
    (*newnode).next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while ((*temp).next != NULL) {
            temp = (*temp).next;
        }
        (*temp).next = newnode;
    }

    printf("%d is inserted! \n", x);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", (*temp).data);
        temp = (*temp).next;
    }
    printf("NULL\n");
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    head = (*head).next;
    free(temp);
    printf("Front node deleted!\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head).next == NULL) {
        free(head);
        head = NULL;
        printf("Only node deleted (now list is empty).\n");
        return;
    }

    struct node *temp = head;
    struct node*prev = NULL;
    while ((*temp).next != NULL) {
        prev = temp;
        temp = (*temp).next;
    }

    (*prev).next = NULL;
    free(temp);
    printf("Last node deleted!\n");
}

void deleteFromPos() {
    int pos, i = 1;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        struct node* temp = head;
        head = (*head).next;
        free(temp);
        printf("Node at position 1 deleted!\n");
        return;
    }

    struct node* temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = (*temp).next;
        i++;
    }

    if (temp == NULL || (*temp).next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct node* delNode = (*temp).next;
    temp->next = (*delNode).next;
    free(delNode);
    printf("Node at position %d deleted!\n", pos);
}

int main() {
    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Position\n");
        printf("5. Delete from End\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); 
            break;
            case 2: display(); 
            break;
            case 3: deleteFront(); 
            break;
            case 4: deleteFromPos(); 
            break;
            case 5: deleteFromEnd(); 
            break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
