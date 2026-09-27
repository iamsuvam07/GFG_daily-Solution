class Solution {
  public:
    void root(vector<vector<int>>& adj, string& s, vector<vector<int>>& sa,
              int node = 0, int par = -1) {
        int ra = 0, ba = 0;
        for (auto& it : adj[node]) {
            if (it == par)
                continue;
            root(adj, s, sa, it, node);
            ra = max(ra, sa[it][0]);
            ra = max(ra, sa[it][1]);
            ba = max(ba, sa[it][1]);
        }
        if (s[node] == 'R') {
            sa[node][0] = ra + 1;
            sa[node][1] = 0;
        } else {
            sa[node][0] = ba + 1;
            sa[node][1] = ba + 1;
        }
    }

    void reroot(vector<vector<int>>& adj, string& s, vector<vector<int>>& ans,
                vector<vector<int>>& sa, int node = 0, int par = -1, int red_par = 0,
                int blue_par = 0) {
        if (s[node] == 'R') {
            ans[node][0] = max(sa[node][0], 1 + red_par);
            ans[node][1] = 0;
        } else {
            ans[node][0] = max(sa[node][0], 1 + blue_par);
            ans[node][1] = max(sa[node][1], 1 + blue_par);
        }
        int fr = red_par, sr = red_par;
        int fb = blue_par, sb = blue_par;
        for (auto& it : adj[node]) {
            if (it == par)
                continue;
            if (sa[it][0] > fr) {
                sr = fr;
                fr = sa[it][0];
            } else if (sa[it][0] > sr) {
                sr = sa[it][0];
            }
            if (sa[it][1] > fb) {
                sb = fb;
                fb = sa[it][1];
            } else if (sa[it][1] > sb) {
                sb = sa[it][1];
            }
        }
        for (auto& it : adj[node]) {
            if (it == par)
                continue;
            int new_red = 0, new_blue = 0;
            if (s[node] == 'R') {
                new_red = 1;
                if (sa[it][0] == fr)
                    new_red += sr;
                else
                    new_red += fr;
                new_blue = 0;
            } else {
                new_red = 1;
                if (sa[it][1] == fb)
                    new_red += sb;
                else
                    new_red += fb;
                new_blue = new_red;
            }
            reroot(adj, s, ans, sa, it, node, new_red, new_blue);
        }
    }

    int longestPath(string& s, vector<vector<int>>& edges) {
int n = s.size();
vector<vector<int>> adj(n);
for (auto& e : edges) {
    adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
             }
vector<vector<int>> subTreeAns(n, vector<int>(2));
root(adj, s, subTreeAns);
vector<vector<int>> ans(n, vector<int>(2));
reroot(adj, s, ans, subTreeAns);
        int res = 0;
        for (int i = 0; i < n; i++)
            res = max({res, ans[i][0], ans[i][1]});
        return res;
        
        
        
        
    }
};


