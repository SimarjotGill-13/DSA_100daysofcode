/* Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/
#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int value)
{
    if(front == 0)
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }

    deque[front] = value;
}

void push_back(int value)
{
    if(rear == MAX-1)
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

void pop_front()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void pop_back()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

void getFront()
{
    if(front == -1)
        printf("Deque empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void getRear()
{
    if(front == -1)
        printf("Deque empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

int size()
{
    if(front == -1)
        return 0;
    return rear - front + 1;
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Front Element\n");
        printf("6. Rear Element\n");
        printf("7. Size\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                getFront();
                break;

            case 6:
                getRear();
                break;

            case 7:
                printf("Size: %d\n", size());
                break;

            case 8:
                display();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
