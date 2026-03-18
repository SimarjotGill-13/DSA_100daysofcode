/* Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n){
    if(n==0) return NULL;
    struct Node* nodes[n];
    for(int i=0;i<n;i++){
        if(arr[i]==-1)
            nodes[i]=NULL;
        else
            nodes[i]=createNode(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1;
            int r=2*i+2;
            if(l<n) nodes[i]->left = nodes[l];
            if(r<n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

void levelOrder(struct Node* root){
    if(root==NULL) return;
    struct Node* queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct Node* temp = queue[front++];
        printf("%d ",temp->data);
        if(temp->left!=NULL)
            queue[rear++]=temp->left;
        if(temp->right!=NULL)
            queue[rear++]=temp->right;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    struct Node* root = buildTree(arr,n);
    levelOrder(root);
    return 0;
}
