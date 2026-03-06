/* Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = top;
    top = temp;

    printf("Pushed %d into stack\n", x);
}

int pop()
{
    struct node *temp;
    int value;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);

    printf("Popped %d from stack\n", value);

    return value;
}

int main()
{
    char exp[100];
    int i = 0;
    int op1, op2, result;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }

        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
        {
            op2 = pop();
            op1 = pop();

            if(exp[i]=='+')
                result = op1 + op2;

            else if(exp[i]=='-')
                result = op1 - op2;

            else if(exp[i]=='*')
                result = op1 * op2;

            else if(exp[i]=='/')
                result = op1 / op2;

            printf("Applying operator %c on %d and %d = %d\n", exp[i], op1, op2, result);

            push(result);
        }

        i++;
    }

    printf("Final Result = %d\n", pop());

    return 0;
}
