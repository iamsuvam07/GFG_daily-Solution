class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        // code here

int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> height(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            height[0][j] = mat[0][j];

            for (int i = 1; i < n; i++) {
                if (mat[i][j] == 1)
                    height[i][j] = height[i - 1][j] + 1;
                else
                    height[i][j] = 0;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> row = height[i];

            sort(row.rbegin(), row.rend());

            for (int j = 0; j < m; j++) {
                ans = max(ans, row[j] * (j + 1));
            }
        }

        return ans;
    }
};