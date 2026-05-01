/* Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
float data;
struct Node* next;
} Node;

void insertSorted(Node** head, float value) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = value;
newNode->next = NULL;

if (*head == NULL || (*head)->data >= value) {
newNode->next = *head;
*head = newNode;
return;
}

Node* current = *head;
while (current->next != NULL && current->next->data < value)
current = current->next;

newNode->next = current->next;
current->next = newNode;
}

void bucketSort(float arr[], int n) {
int i;
Node** buckets = (Node**)malloc(n * sizeof(Node*));

for (i = 0; i < n; i++)
buckets[i] = NULL;

for (i = 0; i < n; i++) {
int index = n * arr[i];
insertSorted(&buckets[index], arr[i]);
}

int k = 0;
for (i = 0; i < n; i++) {
Node* temp = buckets[i];
while (temp != NULL) {
arr[k++] = temp->data;
temp = temp->next;
}
}
}

void printArray(float arr[], int n) {
int i;
for (i = 0; i < n; i++)
printf("%.2f ", arr[i]);
}

int main() {
float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
int n = sizeof(arr)/sizeof(arr[0]);

bucketSort(arr, n);

printArray(arr, n);

return 0;
}
