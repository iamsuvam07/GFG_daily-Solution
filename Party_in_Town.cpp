class Solution {
  public:
 pair<int, int> bfs(int start, vector<vector<int>> &adj) {
                int n = adj.size();

                vector<int> dist(n, -1);
                queue<int> q;

                dist[start] = 0;
                q.push(start);

                int farNode = start;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

     for (int v : adj[u]) {
      v--;  
        if (dist[v] == -1) {
     dist[v] = dist[u] + 1;
      q.push(v);

     if (dist[v] > dist[farNode])
    farNode = v;
                        }
                    }
                }

                return {farNode, dist[farNode]};
            }

            int partyHouse(vector<vector<int>> &adj) {
                int n = adj.size();

                auto p1 = bfs(0, adj);

                auto p2 = bfs(p1.first, adj);

                int diameter = p2.second;
        return (diameter + 1) / 2;
    }
};