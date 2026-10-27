class Solution {
  public:
    int getMaxWeight(string &s) {

int n = s.size();

vector<int> dp(n + 1, 0);

dp[0] = 0;
dp[1] = 1;

for(int i = 2; i <=n; i++) {
    dp[i] = dp[i - 1] + 1;
    
    int pairWeight;
    
    if(s[i - 2] != s[i - 1]) {
        pairWeight = 4;
    } else {
        pairWeight = 4 - 1;
    }
    
    dp[i] = max(dp[i], dp[i - 2] + pairWeight);
    
}

return dp[n];

    }
};
