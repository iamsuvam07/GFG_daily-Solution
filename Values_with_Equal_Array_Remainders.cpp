class Solution {
public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();

        bool same = true;

        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                same = false;
                break;
            }
        }

        if (same)
            return -1;

        long long g = 0;

        for (int i = 1; i < n; i++) {
            g = std::gcd(g, (long long)abs(arr[i] - arr[0]));
        }

        int ans = 0;

 for (long long d = 1; d * d <= g; d++) {
            if (g % d == 0) {
         ans++;

                if (d * d != g)
         ans++;
            }
        }

        return ans;
    }
};