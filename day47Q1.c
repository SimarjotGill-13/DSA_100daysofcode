/* Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications 
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* buildTree(int arr[], int n){
    if(n==0 || arr[0]==-1) return NULL;

    struct node* root = createNode(arr[0]);
    struct node* queue[n];
    int front=0,rear=0;

    queue[rear++] = root;
    int i=1;

    while(i<n){
        struct node* temp = queue[front++];

        if(arr[i]!=-1){
            temp->left = createNode(arr[i]);
            queue[rear++] = temp->left;
        }
        i++;

        if(i<n && arr[i]!=-1){
            temp->right = createNode(arr[i]);
            queue[rear++] = temp->right;
        }
        i++;
    }
    return root;
}

int height(struct node* root){
    if(root==NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left>right?left:right)+1;
}

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    struct node* root = buildTree(arr,n);
    int h = height(root);

    printf("Height of Binary Tree: %d",h);

    return 0;
}
