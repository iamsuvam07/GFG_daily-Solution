class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        // code here
int n = mat.size();
     int m = mat[0].size();
     
     vector<vector<int>> safe = mat;
     
     
     int dx[] = {-1, 1, 0, 0};
     int dy[] = {0, 0, -1, 1};
     
     for (int i = 0; i < n; i++) {
         for(int j = 0; j < m; j++) {
             if(mat[i][j] == 0) {
                 for (int k = 0; k < 4; k++) {
    int ni = i + dx[k];
    int nj = j + dy[k];
    
    if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
        safe[ni][nj] = 0;
        
    }
                 }
             }
         }
     }
     
     queue<pair<pair<int, int>, int>> q;
             vector<vector<int>> visited(n, vector<int>(m, 0));

             for (int i = 0; i < n; i++) {
                 if (safe[i][0] == 1) {
                     q.push({{i, 0}, 1});
                     visited[i][0] = 1;
                 }
             }

 while (!q.empty()) {
     auto cur = q.front();
q.pop();

     int x = cur.first.first;
     int y = cur.first.second;
     int dist = cur.second;
     
     if (y == m - 1) {
         return dist;
     }
     
         for (int k = 0; k < 4; k++) {
             int nx = x + dx[k];
             int ny = y + dy[k];

             if (nx >= 0 && nx < n &&
                 ny >= 0 && ny < m &&
                 safe[nx][ny] == 1 &&
                 !visited[nx][ny]) {

                 visited[nx][ny] = 1;
                 q.push({{nx, ny}, dist + 1});
             }
         }
     }

     return -1;
    }
};