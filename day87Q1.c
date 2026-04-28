/* Problem: Implement Binary Search Iterative - Implement the algorithm.

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

void sort(int arr[], int n){
int i,j,temp;
for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(arr[j]>arr[j+1]){
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}

int binarySearch(int arr[], int n, int key){
int low=0,high=n-1;
while(low<=high){
int mid=(low+high)/2;
if(arr[mid]==key) return mid;
else if(arr[mid]<key) low=mid+1;
else high=mid-1;
}
return -1;
}

int main(){
int n,i;
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++) scanf("%d",&arr[i]);
sort(arr,n);
for(i=0;i<n;i++) printf("%d ",arr[i]);
return 0;
}
