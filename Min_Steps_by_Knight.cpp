class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        
        if (knightPos == targetPos) 
        return 0;
        
        int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
        
        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
        
        queue<pair<pair<int, int>, int>> q;
        
        int sx = knightPos[0];
        int sy = knightPos[1];
        int tx = targetPos[0];
        int ty = targetPos[1];
        
        q.push({{sx, sy}, 0});
        
        visited[sx][sy] =true;
        
        while (!q.empty()) {
            
            
    auto current = q.front();
                q.pop();

    int x = current.first.first;
                int y = current.first.second;
                int steps = current.second;

     if (x == tx && y == ty)
         return steps;

     for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n &&
                        !visited[nx][ny]) {

      visited[nx][ny] = true;
         q.push({{nx, ny}, steps + 1});
                    }
                }
            }

            return -1;

    }
};