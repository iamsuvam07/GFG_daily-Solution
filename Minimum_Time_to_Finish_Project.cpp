class Solution {
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        // code here
        int n = duration.size();
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for (auto & edge : dependencies) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            indegree[v]++;
            
        }
        
        vector<long long> finish(n, 0);
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if ( indegree[i] == 0) {
                finish[i] = duration[i];
                q.push(i);
                
            }
        }
        
        int processed = 0;
        long long answer = 0;
        
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            
            processed++;
            
            answer = max(answer, finish[u]);
            
            
            for (int v : adj[u]) {
                finish[v] = max(finish[v], finish[u] + duration[v]);
                
                indegree[v]--;
                
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        if (processed != n) {
            return -1;
        }
        
        return (int) answer;
    }
};