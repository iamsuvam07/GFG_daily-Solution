class Solution {
  public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        // code here
        
        int n = arr.size() + 1;
        vector<vector<int>> ans;
        
        for (int i = 2; i  <= n; i++) {
            vector<int> dist(n + 1, -1);
            
            int current = i;
            
            int d = 0;
            
            while (current != 1) {
                current = (current == i) ? arr[i - 2] : arr[current - 2];
                d++;
                
                dist[current] = d;
                
            }
            
            for (int j = 1; j < i; j++) {
                if(dist[j] != -1) {
                    ans.push_back({i, j, dist[j]});
                    
                }
            }
        }
        
        return ans;
        
    }
};