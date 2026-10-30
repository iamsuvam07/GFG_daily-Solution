class Solution {
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
       
       
       
       
    
               const long long MOD = 1000000007;
               int n = arr.size();

               vector<int> cnt(n + 1, 0);

               for (int x : arr) {
                   if (x <= n)
                       cnt[x]++;
               }

               vector<long long> pow2(n + 1, 1);
               for (int i = 1; i <= n; i++) {
                   pow2[i] = (pow2[i - 1] * 2) % MOD;
               }

             
               long long remaining = n - cnt[0];

               long long prod = 1;

               long long ans = 0;

               for (int mex = 0; mex <= r; mex++) {

                   long long ways = (prod * pow2[remaining]) % MOD;

                   if (mex >= l) {
                       ans = (ans + ways) % MOD;
                   }

                   if (mex < r) {
                       
                       long long choices =
                           (pow2[cnt[mex]] - 1 + MOD) % MOD;

                       prod = (prod * choices) % MOD;

                     
                       remaining -= cnt[mex + 1];
                   }
               }

               return (int)ans;
       
    }
};
