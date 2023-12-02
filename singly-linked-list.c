#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void addAtBeginning(struct Node **head, int num)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = num;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(struct Node **head, int num)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = num;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        printf("Linked list: ");
        while (head != NULL)
        {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
}

void freeLinkedList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    int num, choice;

    while (1)
    {
        printf("\n****** MENU ******\n");
        printf("1. Add at beginning\n2. Add at end\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &num);
            addAtBeginning(&head, num);
            break;
        case 2:
            printf("Enter the number: ");
            scanf("%d", &num);
            addAtEnd(&head, num);
            break;
        case 3:
            display(head);
            break;
        case 4:
            freeLinkedList(head);
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
