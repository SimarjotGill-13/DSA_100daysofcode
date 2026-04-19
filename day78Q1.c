/* Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/
#include <stdio.h>
#define MAX 100
#define INF 999999

int cost[MAX][MAX];
int visited[MAX];
int n,m;

int main(){
int u,v,w;

scanf("%d %d",&n,&m);

for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
cost[i][j]=INF;
}
visited[i]=0;
}

for(int i=0;i<m;i++){
scanf("%d %d %d",&u,&v,&w);
cost[u][v]=w;
cost[v][u]=w;
}

visited[1]=1;
int edges=0,mincost=0;

while(edges<n-1){
int min=INF,a=-1,b=-1;

for(int i=1;i<=n;i++){
if(visited[i]){
for(int j=1;j<=n;j++){
if(!visited[j] && cost[i][j]<min){
min=cost[i][j];
a=i;
b=j;
}
}
}
}

if(a!=-1 && b!=-1){
visited[b]=1;
mincost+=min;
edges++;
}
}

printf("%d\n",mincost);

return 0;
}
