
class Solution {
        public:
          int minCost(int n, int i, int d, int c) {
              vector<long long> dp(n + 1, 0);

              for (int j = 1; j <= n; j++) {
                  dp[j] = dp[j - 1] + i;

                  if (j % 2 == 0) {
                      dp[j] = min(dp[j], dp[j / 2] + c);
                  } else {
                      dp[j] = min(dp[j], dp[(j + 1) / 2] + c + d);
                  }
              }

              return dp[n];
          }
      };