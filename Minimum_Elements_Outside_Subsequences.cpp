class Solution {
  public:

            int solve(int pos, int inc, int dec, vector<int>& arr,
                      vector<vector<vector<int>>>& dp) {

                int n = arr.size();

                if (pos == n)
                    return 0;

                if (dp[pos][inc + 1][dec + 1] != -1)
                    return dp[pos][inc + 1][dec + 1];

                int ans = solve(pos + 1, inc, dec, arr, dp);

                if (inc == -1 || arr[pos] > arr[inc]) {
                    ans = max(ans,
                              1 + solve(pos + 1, pos, dec, arr, dp));
                }

                if (dec == -1 || arr[pos] < arr[dec]) {
                    ans = max(ans,
                              1 + solve(pos + 1, inc, pos, arr, dp));
                }

                return dp[pos][inc + 1][dec + 1] = ans;
            }

            int minCount(vector<int>& arr) {
                int n = arr.size();

                vector<vector<vector<int>>> dp(
                    n,
                    vector<vector<int>>(n + 1,
                                        vector<int>(n + 1, -1))
                );

                int maximumUsed = solve(0, -1, -1, arr, dp);

                return n - maximumUsed;
    
    }
};