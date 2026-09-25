class Solution {
  public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // code here
        
        int n = height.size();
    vector<vector<int>> boxes;

                for (int i = 0; i < n; i++) {
                    int h = height[i];
                    int w = width[i];
                    int l = length[i];

                    boxes.push_back({max(w, l), min(w, l), h});

                    boxes.push_back({max(h, l), min(h, l), w});

                    boxes.push_back({max(h, w), min(h, w), l});
                }

                sort(boxes.begin(), boxes.end(), [](const vector<int>& a,
                                                    const vector<int>& b) {
                    if (a[0] != b[0])
                        return a[0] > b[0];

                    return a[1] > b[1];
                });

                int m = boxes.size();

                vector<int> dp(m);
                int ans = 0;

                for (int i = m - 1; i >= 0; i--) {
                    dp[i] = boxes[i][2];

                    for (int j = i + 1; j < m; j++) {
                        if (boxes[i][0] > boxes[j][0] &&
                            boxes[i][1] > boxes[j][1]) {

                            dp[i] = max(dp[i],
                                        boxes[i][2] + dp[j]);
                        }
                    }

                    ans = max(ans, dp[i]);
                }

                return ans;
      
    }
};