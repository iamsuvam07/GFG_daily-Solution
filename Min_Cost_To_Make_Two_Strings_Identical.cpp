class Solution {
  public:
      int findMinCost(string &s1, string &s2, int costS1, int costS2) {

          int n = s1.length();
          int m = s2.length();

          vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

          for (int i = 1; i <= n; i++) {
              for (int j = 1; j <= m; j++) {

                  if (s1[i - 1] == s2[j - 1]) {
                      dp[i][j] = dp[i - 1][j - 1] + 1;
                  }
                  else {
                      int a = dp[i - 1][j];
                      int b = dp[i][j - 1];
                      dp[i][j] = (a > b) ? a : b;
                  }
              }
          }

          int lcs = dp[n][m];

          int removeS1 = n - lcs;
          int removeS2 = m - lcs;

          return removeS1 * costS1 + removeS2 * costS2;
        
    }
};