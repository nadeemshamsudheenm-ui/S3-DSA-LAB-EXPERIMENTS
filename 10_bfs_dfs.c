/* Experiment 10: Implementation of BFS and DFS algorithms
   (graph stored as an adjacency matrix) */
#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0, v, i;

    queue[rear++] = start;                 /* add start vertex to queue */
    visited[start] = 1;                    /* and mark it as visited    */

    while (front < rear) {                 /* repeat until queue is empty */
        v = queue[front++];                /* remove first vertex */
        printf("%d ", v);                  /* visit the vertex    */
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;         /* add unvisited neighbours */
                visited[i] = 1;
            }
        }
    }
}

void dfs(int start) {
    int stack[MAX * MAX], top = -1, v, i;

    stack[++top] = start;                  /* push start vertex */

    while (top != -1) {                    /* until stack is empty */
        v = stack[top--];                  /* pop a vertex */
        if (visited[v] == 0) {
            visited[v] = 1;                /* mark when popped */
            printf("%d ", v);
            for (i = n - 1; i >= 0; i--)   /* reverse order so smallest vertex is popped first */
                if (adj[v][i] == 1 && visited[i] == 0)
                    stack[++top] = i;
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    for (i = 0; i < n; i++) visited[i] = 0;
    printf("BFS traversal: ");
    bfs(start);
    for (i = 0; i < n; i++)                /* disconnected parts */
        if (visited[i] == 0)
            bfs(i);
    printf("\n");

    for (i = 0; i < n; i++) visited[i] = 0;
    printf("DFS traversal: ");
    dfs(start);
    for (i = 0; i < n; i++)
        if (visited[i] == 0)
            dfs(i);
    printf("\n");

    return 0;
}
