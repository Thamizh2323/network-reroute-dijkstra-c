/*
Network Reroute Amidst Communication Outages
--------------------------------------------

Author: Thamizh
Algorithm: Dijkstra Shortest Path
Language: C

Description:
This program calculates the minimum communication delay between
two nodes in a weighted network while avoiding failed nodes.

If no path exists, the program outputs "inaccessible".
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAXN 1005

typedef struct {
    int to;
    int weight;
} Edge;

Edge graph[MAXN][MAXN];
int edgeCount[MAXN];

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Invalid input");
        return 0;
    }

    int pos = 1;

    int n = atoi(argv[pos++]);
    int m = atoi(argv[pos++]);

    for (int i = 0; i < n; i++)
        edgeCount[i] = 0;

    for (int i = 0; i < m; i++) {

        int u = atoi(argv[pos++]);
        int v = atoi(argv[pos++]);
        int w = atoi(argv[pos++]);

        graph[u][edgeCount[u]].to = v;
        graph[u][edgeCount[u]].weight = w;
        edgeCount[u]++;

        graph[v][edgeCount[v]].to = u;
        graph[v][edgeCount[v]].weight = w;
        edgeCount[v]++;
    }

    int failedCount = atoi(argv[pos++]);

    bool failed[MAXN] = {false};

    for (int i = 0; i < failedCount; i++) {
        int f = atoi(argv[pos++]);
        failed[f] = true;
    }

    int source = atoi(argv[pos++]);
    int dest = atoi(argv[pos++]);

    if (failed[source] || failed[dest]) {
        printf("inaccessible");
        return 0;
    }

    int dist[MAXN];
    bool visited[MAXN];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int i = 0; i < n; i++) {

        int u = minDistance(dist, visited, n);
        if (u == -1) break;

        visited[u] = true;

        for (int j = 0; j < edgeCount[u]; j++) {

            int v = graph[u][j].to;
            int w = graph[u][j].weight;

            if (!visited[v] && !failed[v] && dist[u] != INT_MAX
                && dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    if (dist[dest] == INT_MAX)
        printf("inaccessible");
    else
        printf("%d", dist[dest]);

    return 0;
}
