class Solution {
public:
    int maxProduct(vector<int>& arr, int k) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        long long product = 1;
        int i = 0, j = n - 1;

        if (k % 2 != 0) {
            if (arr[n - 1] <= 0) {
                long long prod = 1;
                for (int idx = n - 1; idx >= n - k; --idx) {
                    prod *= arr[idx];
                }
                return prod;
            }
            product = arr[n - 1];
            j = n - 2;
            k--;
        }

        while (k > 0) {
            long long left_product = 1LL * arr[i] * arr[i + 1];
            long long right_product = 1LL * arr[j] * arr[j - 1];

            if (left_product > right_product) {
                product *= left_product;
                i += 2;
            } else {
                product *= right_product;
                j -= 2;
            }
            k -= 2;
        }

        return product;
    }
};