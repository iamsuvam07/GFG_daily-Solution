class Solution {
  public:
    int minimumStep(int n) {

                if (n == 1) return 0;

                queue<pair<int, int>> q;
                q.push({1, 0});

                vector<bool> visited(n + 1, false);
                visited[1] = true;

                while (!q.empty()) {
                    int node = q.front().first;
                    int steps = q.front().second;
                    q.pop();

                    if (node + 1 <= n && !visited[node + 1]) {
                        if (node + 1 == n)
                            return steps + 1;

                        visited[node + 1] = true;
                        q.push({node + 1, steps + 1});
                    }

                    if (3 * node <= n && !visited[3 * node]) {
                        if (3 * node == n)
                            return steps + 1;

                        visited[3 * node] = true;
                        q.push({3 * node, steps + 1});
                    }
                }

                return -1;
        
    }
};