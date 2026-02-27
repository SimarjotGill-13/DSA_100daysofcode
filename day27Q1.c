/* Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findNode(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    if (len1 > len2) {
        diff = len1 - len2;
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        diff = len2 - len1;
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);

        struct Node* intersectionNode = findNode(head1, value);

        if (intersectionNode != NULL) {
            if (head2 == NULL)
                head2 = intersectionNode;
            else
                tail2->next = intersectionNode;
            break;
        } else {
            struct Node* newNode = createNode(value);

            if (head2 == NULL) {
                head2 = newNode;
                tail2 = newNode;
            } else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection\n");
    else
        printf("Intersection Point: %d\n", result);

    return 0;
}
