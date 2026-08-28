/* EX.NO: 8  APPLICATION OF GRAPHS
   AIM: To write a C program to perform Dijkstra's algorithm to find the shortest path. */

#include <stdio.h>
#define MAX_VERTICES 20
#define INFINITY 999

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        distance[i] = (graph[src][i] == 0 && i != src) ? INFINITY : graph[src][i];
        visited[i] = 0;
    }
    distance[src] = 0;
    visited[src] = 1;

    for (int count = 1; count < n; count++) {
        int min = INFINITY, u = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && distance[v] <= min) {
                min = distance[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                distance[u] != INFINITY &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("\nVertex\tDistance from Source (%d)\n", src);
    for (int i = 0; i < n; i++) {
        if (distance[i] == INFINITY)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
