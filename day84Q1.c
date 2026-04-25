/* Problem: Implement Insertion Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/

#include <stdio.h>

int main() {
int n;

printf("Enter number of elements: ");
scanf("%d", &n);

int arr[n];

printf("Enter %d elements:\n", n);
for(int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}

printf("\nInitial array:\n");
for(int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}

for(int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;

printf("\n\nPass %d: Inserting %d into sorted part", i, key);

while(j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}

arr[j + 1] = key;

printf("\nArray after pass %d:\n", i);
for(int k = 0; k < n; k++) {
printf("%d ", arr[k]);
}
}

printf("\n\nFinal Sorted Array:\n");
for(int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}

printf("\n");

return 0;
}
