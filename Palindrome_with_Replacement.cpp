class Solution {
  public:
    int minimumSum(string &s) {
    
    
            int n = s.size();
            const int INF = 1e9;

            vector<vector<int>> allowed(n);

            for (int i = 0; i < n; i++) {
                int j = n - 1 - i;

                if (s[i] != '?' && s[j] != '?' && s[i] != s[j])
                    return -1;

                if (s[i] != '?') {
                    allowed[i].push_back(s[i] - 'a');
                } 
                else if (s[j] != '?') {
                    allowed[i].push_back(s[j] - 'a');
                } 
                else {
                    for (int c = 0; c < 26; c++)
                        allowed[i].push_back(c);
                }
            }

            vector<int> dp(26, INF), ndp(26, INF);

            for (int c : allowed[0])
                dp[c] = 0;

            for (int i = 1; i < n; i++) {
                fill(ndp.begin(), ndp.end(), INF);

                for (int cur : allowed[i]) {
                    for (int prev = 0; prev < 26; prev++) {
                        if (dp[prev] != INF) {
                            ndp[cur] = min(
                                ndp[cur],
                                dp[prev] + abs(cur - prev)
                            );
                        }
                    }
                }

                dp = ndp;
            }

            return *min_element(dp.begin(), dp.end());
        
    }
};