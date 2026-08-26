class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
vector<int> dist(V, 0);

for(int i = 1; i <= V-1; i++) {
    bool updated = false;
    
    for(auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        
        if(dist[v] > dist[u] + wt) {
            dist[v] = dist[u] + wt;
            
            updated = true;
        }
    }
    
    if(!updated)
    break;
    
}

for(auto &edge : edges) {
    int u = edge[0];
    int v = edge[1];
    int wt = edge[2];
    if(dist[v] > dist[u] + wt) {
        return true;
    }
}

return false;
    }
};