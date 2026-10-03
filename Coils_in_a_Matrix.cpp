class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        // code here
        
        
        
                int N = 4 * n;
                int total = N * N;
                int half = total / 2;

                vector<vector<int>> mat(N, vector<int>(N));

                int x = 1;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        mat[i][j] = x++;
                    }
                }

                vector<int> coil1, coil2;

                int top = 0, bottom = N - 1;
                int left = 0, right = N - 1;

                while ((int)coil1.size() < half) {

                    for (int i = top; i <= bottom && coil1.size() < half; i++)
                        coil1.push_back(mat[i][left]);

                    for (int j = left + 1; j <= right - 1 && coil1.size() < half; j++)
                        coil1.push_back(mat[bottom][j]);

                    for (int i = bottom - 1; i >= top + 1 && coil1.size() < half; i--)
                        coil1.push_back(mat[i][right - 1]);

                    for (int j = right - 2; j >= left + 2 && coil1.size() < half; j--)
                        coil1.push_back(mat[top + 1][j]);

                    top += 2;
                    bottom -= 2;
                    left += 2;
                    right -= 2;
                }

                top = 0;
                bottom = N - 1;
                left = 0;
                right = N - 1;

                while ((int)coil2.size() < half) {

                    for (int i = bottom; i >= top && coil2.size() < half; i--)
                        coil2.push_back(mat[i][right]);

                    for (int j = right - 1; j >= left + 1 && coil2.size() < half; j--)
                        coil2.push_back(mat[top][j]);

                    for (int i = top + 1; i <= bottom - 1 && coil2.size() < half; i++)
                        coil2.push_back(mat[i][left + 1]);

                    for (int j = left + 2; j <= right - 2 && coil2.size() < half; j++)
                        coil2.push_back(mat[bottom - 1][j]);

                    top += 2;
                    bottom -= 2;
                    left += 2;
                    right -= 2;
                }

                return {coil1, coil2};
       
    }
};