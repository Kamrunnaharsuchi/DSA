#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, int n)
{
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        cout << top << " ";

        for (int node : adj[top])
        {
            if (!visited[node])
            {
                visited[node] = true;
                q.push(node);
            }
        }
    }
}

int main()
{
    int n, edges;
    cin >> n >> edges;

    vector<vector<int>> adj(n);

    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);   // undirected graph
    }

    int start;
    cin >> start;

    bfs(start, adj, n);

    return 0;
}
