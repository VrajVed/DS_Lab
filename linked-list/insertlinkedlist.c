#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert_beg(struct node *start)
{

    struct node *new_node;
    int num;

    printf("\nEnter the data");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(new_node));
    new_node->data = num;
    new_node->next = start;

    start = new_node;

    return start;
};

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;

    while (ptr != NULL)
    {
    }
}

struct node *insert_end(struct node *SOMETHNIG)
{

    struct node *new_node;
    int num;

    new_node = (struct node *)malloc(sizeof(new_node));
    new_node->data = num;
    new_node->next = DATA OF NEW NODE;

    return SOMETHING;
}

int main()
{

    return 0;
}