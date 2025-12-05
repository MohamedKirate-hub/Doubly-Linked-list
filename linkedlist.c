#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *ft_CreateNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return (newNode);
}

void ft_add_front(Node **head, int data)
{
    Node *newNode = ft_CreateNode(data);
    if (!*head)
    {
        (*head) = newNode;
        return;
    }
    (*head) -> prev = newNode;
    newNode -> next = (*head);
    (*head) = newNode;
}

void ft_add_back(Node **head, int data)
{
    Node *newNode = ft_CreateNode(data);
    Node *temp = NULL;
    if (!*head)
    {
        *head = newNode;
        return;
    }
    temp = *head;
    while (temp -> next != NULL)
        temp = temp -> next;
    newNode -> prev = temp;
    temp -> next = newNode;
}

void ft_print_list(Node *head)
{
    Node *temp = head;
    Node *tail = NULL;
    printf("\tthe next steps: \n");
    while (temp != NULL)
    {
        printf("\t%d\n", temp -> data);
        if (temp -> next == NULL)
            tail = temp;
        temp = temp -> next;
    }
    // printf("\tthe prev steps: \n");
    // while (tail != NULL)
    // {
    //     printf("\t%d\n", tail -> data);
    //     tail = tail -> prev;
    // }
}

void ft_swap_list(Node **head)
{
    int temp = 0;
    if (!*head || (*head) -> next == NULL)
        return;
    temp = (*head) -> data;
    (*head) -> data = (*head) -> next -> data;
    (*head) -> next -> data = temp;
}

int main()
{
    Node *head = NULL;
    ft_add_front(&head, 50);
    ft_add_front(&head, 40);
    ft_add_front(&head, 30);
    ft_add_front(&head, 20);
    ft_add_front(&head, 10);
    ft_swap_list(&head);
    ft_swap_list(&head);

    ft_print_list(head);

}