#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int start)
{
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty())
    {
        int top = st.top();
        printf("%d ", top);
        st.pop();

        for (int neighbor : adj[top])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;   // mark before pushing
                st.push(neighbor);
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

    dfs(adj, visited, start);

    return 0;
}
