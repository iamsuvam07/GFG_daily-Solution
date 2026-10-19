class Solution {
  public:
    int goodIndices(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        vector<int> state(n, 0);

        function<bool(int)> dfs = [&](int i) {
            if (i < 0 || i >= n)
                return true;

            if (state[i] == 1)
                return false;

            if (state[i] == 2)
                return true;

            if (state[i] == 3 || arr[i] == 0) {
                state[i] = 3;
                return false;
            }

            state[i] = 1;

            long long next = (long long)i + arr[i];

            bool good = dfs(next);

            state[i] = good ? 2 : 3;

            return good;
        };

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (dfs(i))
                ans++;
        }

        return ans;
  
    }
};