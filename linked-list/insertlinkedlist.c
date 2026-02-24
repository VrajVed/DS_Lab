#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

static struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;

    printf("Enter the data: ");
    if (scanf("%d", &num) != 1)
    {
        return start;
    }

    new_node = (struct node *)malloc(sizeof(*new_node));
    if (new_node == NULL)
    {
        return start;
    }

    new_node->data = num;
    new_node->next = start;
    return new_node;
}

static struct node *insert_end(struct node *start)
{
    struct node *new_node;
    struct node *ptr;
    int num;

    printf("Enter the data: ");
    if (scanf("%d", &num) != 1)
    {
        return start;
    }

    new_node = (struct node *)malloc(sizeof(*new_node));
    if (new_node == NULL)
    {
        return start;
    }

    new_node->data = num;
    new_node->next = NULL;

    if (start == NULL)
    {
        return new_node;
    }

    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return start;
}

static void display(const struct node *start)
{
    const struct node *ptr = start;
    printf("List: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

static void free_list(struct node *start)
{
    while (start != NULL)
    {
        struct node *next = start->next;
        free(start);
        start = next;
    }
}

int main(void)
{
    struct node *start = NULL;
    int choice;

    for (;;)
    {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Display\n0. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1)
        {
            break;
        }

        if (choice == 1)
        {
            start = insert_beg(start);
        }
        else if (choice == 2)
        {
            start = insert_end(start);
        }
        else if (choice == 3)
        {
            display(start);
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    free_list(start);
    return 0;
}