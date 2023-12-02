#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    int data;
    struct DLL *prev, *next;
};

void addbeg(struct DLL **head, int num)
{
    struct DLL *newnode = (struct DLL *)malloc(sizeof(struct DLL));
    if (newnode == NULL)
    {
        printf("Memory allocation failed. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }
    newnode->data = num;
    newnode->prev = NULL;
    newnode->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = newnode;
    }

    *head = newnode;
}

void addend(struct DLL **head, int num)
{
    struct DLL *newnode = (struct DLL *)malloc(sizeof(struct DLL));
    if (newnode == NULL)
    {
        printf("Memory allocation failed. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }

    newnode->data = num;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct DLL *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }
}

void display(struct DLL *head)
{
    if (head == NULL)
    {
        printf("\n Linked list does not exist\n");
    }
    else
    {
        printf("\n Linked list is\n");
        while (head != NULL)
        {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
}

void delbeg(struct DLL **head)
{
    if (*head == NULL)
    {
        printf("\n Linked list does not exist\n");
    }
    else
    {
        struct DLL *temp = *head;
        *head = (*head)->next;

        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }

        printf("\n Deleted item is %d\n", temp->data);
        free(temp);
    }
}

void delend(struct DLL **head)
{
    if (*head == NULL)
    {
        printf("\n Linked list does not exist\n");
    }
    else
    {
        struct DLL *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp->prev != NULL)
        {
            temp->prev->next = NULL;
        }

        printf("\n Deleted item is %d\n", temp->data);
        free(temp);
    }
}

int main()
{
    struct DLL *head = NULL;
    int num, choice;

    printf("\n1. Add at beginning\n2. Add at end\n3. Display\n4. Delete from beginning\n5. Delete from end\n6. Exit");

    while (1)
    {
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter the number: ");
            scanf("%d", &num);
            addbeg(&head, num);
            break;
        case 2:
            printf("\n Enter the number: ");
            scanf("%d", &num);
            addend(&head, num);
            break;
        case 3:
            display(head);
            break;
        case 4:
            delbeg(&head);
            break;
        case 5:
            delend(&head);
            break;
        case 6:
            free(head); // Free the entire linked list before exiting
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
