/* Experiment 10: BFS and DFS using adjacency matrix */
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX], visited[MAX], n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0, i, v;
    for (i = 0; i < n; i++) visited[i] = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS traversal: ");
    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++)
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
    }
    printf("\n");
}

void dfsVisit(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfsVisit(i);
}

void dfs(int start) {
    int i;
    for (i = 0; i < n; i++) visited[i] = 0;
    printf("DFS traversal: ");
    dfsVisit(start);
    printf("\n");
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(start);
    dfs(start);
    return 0;
}
