class Solution {
  public:
  

    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    long long unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return 0;

        if (sz[a] < sz[b])
            swap(a, b);

        long long newPaths = 1LL * sz[a] * sz[b];

        parent[b] = a;
        sz[a] += sz[b];

        return newPaths;
    }

    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {

        sort(edges.begin(), edges.end(), [](const vector<int>& a,
                                            const vector<int>& b) {
            return a[2] < b[2];
        });

        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        vector<int> ans(queries.size());

        long long totalPaths = 0;
        int edgeIndex = 0;

        for (auto &query : q) {

            int limit = query.first;
            int originalIndex = query.second;

            while (edgeIndex < edges.size() &&
                   edges[edgeIndex][2] <= limit) {

                int u = edges[edgeIndex][0];
                int v = edges[edgeIndex][1];

                totalPaths += unite(u, v);

                edgeIndex++;
            }

            ans[originalIndex] = (int)totalPaths;
        }

        return ans;
  
        
    }
};