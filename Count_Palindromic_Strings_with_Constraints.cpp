 
class Solution {
    public:
      int palindromicStrings(int n, int k) {
          long long MOD = 1e9 + 7;
          long long total = 0;

          vector<vector<long long>> nPr(k + 1, vector<long long>(k + 1, 0));
          for (int i = 0; i <= k; i++) {
              nPr[i][0] = 1;
              for (int j = 1; j <= i; j++) {
                  nPr[i][j] = (nPr[i][j - 1] * (i - j + 1)) % MOD;
              }
          }

          for (int len = 1; len <= n; len++) {
              int unique_chars_needed = (len + 1) / 2;

              if (unique_chars_needed <= k) {
                  total = (total + nPr[k][unique_chars_needed]) % MOD;
              }
          }

          return total;
      }
  };