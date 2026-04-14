#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<bool> &visited, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        printf("%d\t", node);
        q.pop();

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int nodes, edges, u, v;

    printf("Enter the no of nodes: ");
    scanf("%d", &nodes);

    vector<vector<int>> adj(nodes);
    vector<bool> visited(nodes, false);

    printf("Enter the no of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges\n");
    for (int i = 1; i <= edges; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    printf("Enter starting node: ");
    scanf("%d", &start);

    bfs(adj, visited, start);

    return 0;
}
