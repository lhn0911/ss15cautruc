#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V, E;
int adj[MAX][MAX];
int visited[MAX];
int inStack[MAX];

int dfs(int u)
{
    visited[u] = 1;
    inStack[u] = 1;
    for (int v = 0; v < V; v++)
    {
        if (adj[u][v])
        {
            if (!visited[v] && dfs(v))
            {
                return 1;
            }
            if (inStack[v])
            {
                return 1;
            }
        }
    }

    inStack[u] = 0;
    return 0;
}

int main()
{
    printf("nhap so dinh: ");
    scanf("%d", &V);
    printf("nhap so canh: ");
    scanf("%d", &E);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("nhap cac canh (u, v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        inStack[i] = 0;
    }

    int hasCycle = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
    {
        printf("do thi co chu trinh\n");
    }
    else
    {
        printf("do thi khong co chu trình\n");
    }

    return 0;
}