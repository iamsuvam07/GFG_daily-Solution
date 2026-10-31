class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {

       
       
       
        int n = arr.size();

        long long normal = arr[0];
        long long squared = 1LL * arr[0] * arr[0];
        long long ans = squared;

        for (int i = 1; i < n; i++) {
            long long x = arr[i];

            long long useSquare = normal + x * x;

            long long startSquare = x * x;

            long long continueSquare = squared + x;

            squared = max({startSquare, useSquare, continueSquare});

            normal = max(x, normal + x);

            ans = max(ans, squared);
        }

        return (int)ans;

    }
};