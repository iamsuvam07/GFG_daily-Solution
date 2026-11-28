class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {

int n = adj.size();
vector<bool> visited(n, false);

return dfs(adj, u, v, visited);
}

bool dfs(vector<vector<int>> & adj, int u, int v, vector<bool> &visited) {
    if(u == v)
    return true;
    
    visited[u] = true;
    
    for (int neighbour : adj[u]) {
        if (!visited[neighbour]) {
            if (dfs(adj, neighbour, v, visited))
            return true;
        }
    }
return false;

    }
};