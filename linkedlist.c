#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *ft_create_node(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return (newNode);
}
void    ft_add_front(Node **head, int data)
{
    Node *newNode = ft_create_node(data);
    if (*head == NULL)
    {
        (*head) = newNode;
        return;
    }
    newNode -> next = (*head);
    (*head) -> prev = newNode;
    (*head) = newNode;
}
void    ft_add_back(Node **head, int data)
{
    Node *newNode = ft_create_node(data);
    Node *temp = NULL;
    if (*head == NULL)
    {
        (*head) = newNode;
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
    Node *tail = NULL;
    if (head == NULL)
        return;
    printf("\nnext data\n");
    while (head != NULL)
    {
        printf("%d\n", head -> data);
        if (head -> next == NULL)
            tail = head;
        head = head -> next;
    }
    // printf("\nprev data\n");
    // while (tail != NULL)
    // {
    //     printf("%d\n", tail -> data);
    //     tail = tail -> prev;
    // }
}
void    ft_swap_two(Node **head)
{
    int temp = 0;
    if (head == NULL || *head == NULL || (*head) -> next == NULL)
        return;
    temp = (*head) -> data;
    (*head) -> data = (*head) -> next -> data;
    (*head) -> next -> data = temp;
}

void ft_delete_front(Node **head)
{
    Node *temp = NULL;
    if (head == NULL || *head == NULL)
        return;
    temp = (*head);
    (*head) = (*head) -> next;
    if (*head != NULL)
        (*head) -> prev = NULL;
    free(temp);
}

void ft_push_a(Node **a, Node **b)
{
    ft_add_front(a, (*b) -> data);
    ft_delete_front(b);
}
void ft_push_b(Node **a, Node **b)
{
    ft_add_front(b, (*a) -> data);
    ft_delete_front(a);
}

void ft_rotate(Node **head)
{
    int int_temp = 0;
    Node *struct_temp = NULL;
    struct_temp = (*head);
    if (head == NULL || *head == NULL)
        return;
    struct_temp = (*head);
    while (struct_temp -> next != NULL)
    {
        int_temp = struct_temp -> data;
        struct_temp -> data = struct_temp -> next -> data;
        struct_temp -> next -> data = int_temp;
        struct_temp = struct_temp -> next;
    }
}

int main()
{
    Node *head = NULL;
    ft_add_front(&head, 40);
    ft_add_front(&head, 30);
    ft_add_front(&head, 20);
    ft_add_front(&head, 10);
    ft_print_list(head);
    ft_rotate(&head);
    ft_print_list(head);
}