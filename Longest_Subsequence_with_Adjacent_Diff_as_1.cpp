class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 0) return 0;
        
        unordered_map<int, int> dp;
        int ans = 1;
        
        for (int x : arr) {
            dp[x] = max(dp[x], 1 + max(dp[x - 1], dp[x + 1]));
            ans = max(ans, dp[x]);
        }
        
        return ans;
    }
};