class Solution {
  public:
    int largestSumCycle(vector<int>& edge) {


int n = edge.size();

vector<int> state(n, 0);

int ans = -1;

      for (int start = 0; start < n; start++) {
                  if (state[start] != 0)
                      continue;

                  int curr = start;

                  unordered_map<int, int> pos;
                  vector<int> path;

                  while (curr != -1 && state[curr] == 0) {
                      state[curr] = 1;
                      pos[curr] = path.size();
                      path.push_back(curr);

                      curr = edge[curr];
                  }

                  if (curr != -1 && state[curr] == 1 &&
                      pos.find(curr) != pos.end()) {

                      int sum = 0;

                      for (int i = pos[curr]; i < (int)path.size(); i++) {
                          sum += path[i];
                      }

                      ans = max(ans, sum);
                  }

                  for (int node : path) {
                      state[node] = 2;
                  }
              }

              return ans;
    }
};