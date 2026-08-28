/* EX.NO: 7.2  DEPTH FIRST SEARCH
   AIM: To write a C program to implement graph traversal using DFS. */

#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int curr) {
    visited[curr] = 1;
    printf("%d ", curr);
    for (int i = 0; i < n; i++) {
        if (adj[curr][i] == 1 && !visited[i])
            dfs(i);
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v) [0-indexed]:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; /* undirected graph */
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}
