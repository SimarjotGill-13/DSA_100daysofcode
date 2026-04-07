/* Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/

#include <stdio.h>

#define MAX 100

int visited[MAX];
int recStack[MAX];

int dfs(int v, int n, int adj[MAX][MAX]) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1) {
            if (!visited[i]) {
                if (dfs(i, n, adj))
                    return 1;
            }
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[v] = 0;
    return 0;
}

int hasCycle(int n, int adj[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n, adj))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (hasCycle(n, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
