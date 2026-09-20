class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        // code here
        
        
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        
vector<vector<int>> right(n, vector<int>(m, 0));
vector<vector<int>> down(n, vector<int>(m ,0));

for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
        
        if (mat[i][j] == 'X') {
            right[i][j] = 1;
            down[i][j] = 1;
            
            if (j + 1 < m)
            right[i][j] += right[i][j + 1];
if ( i + 1 < n)
down[i][j] += down[i + 1][j];

        }
    }
}


   int ans = 0;
   
   for (int i = 0; i < n; i++) {
       for ( int j = 0; j < m; j++) {
           int possible = min(right[i][j], down[i][j]);
           
           for (int len = possible; len > ans; len--) {
               int bottom = i + len - 1;
               int rightCol = j + len - 1;
               
               if (bottom < n && rightCol < m) {
                   
                   if (right[bottom][j] >= len && down[i][rightCol] >= len) {
                       ans = len;
                       break;
                       
                   }
               }
           }
       }
   }
   
   return ans;
        
    }
};