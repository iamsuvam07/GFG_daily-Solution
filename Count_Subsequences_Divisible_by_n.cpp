class Solution {
  public:
    int countSubsequences(string& s, int n) {
        // code here
        
        const long long MOD = 1000000007LL;
        vector <long long> dp(n,0);
        
        for(char c : s) {
            int x = c - '0';
            
            vector <long long> ndp=dp;
            
            ndp[x % n] = (ndp[x % n] + 1) % MOD;
            
            for(int r = 0; r < n; r++) {
                int nr = ( r* 10 + x) % n;
                ndp[nr] = (ndp[nr] + dp[r]) % MOD;
            }
            
            dp = ndp;
        }
        return dp[0];
    }
};