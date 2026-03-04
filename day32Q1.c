/* Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    if(top == NULL)
        return;

    temp = top;
    top = top->next;
    free(temp);
}

void display()
{
    struct node *temp = top;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, m, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements to push: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        pop();
    }

    printf("Remaining stack elements from top to bottom: ");
    display();

    return 0;
}
