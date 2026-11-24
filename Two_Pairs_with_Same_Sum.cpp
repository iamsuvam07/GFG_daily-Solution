
class Solution {
public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, pair<int, int>> mp;

        vector<int> ans = {-1, -1, -1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int sum = arr[i] + arr[j];

                if (mp.find(sum) != mp.end()) {

                    auto p = mp[sum];

                    int a = p.first;
                    int b = p.second;

                    if (a != i && a != j &&
                        b != i && b != j) {

                        vector<int> temp = {a, b, i, j};

                        if (ans[0] == -1 || temp < ans) {
                            ans = temp;
                        }
                    }
                }
                else {
                    mp[sum] = {i, j};
                }
            }
        }

        return ans;
    }
};
