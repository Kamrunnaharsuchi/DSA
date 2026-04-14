#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[501];
bool vis[502];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        cout << parent << " ";

        for(auto child : adj_list[parent]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
            }
        }
    }
}

int main(){
    int node, edge;
    cin >> node >> edge;

    while(edge--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));

    bfs(1);

    return 0;
}
