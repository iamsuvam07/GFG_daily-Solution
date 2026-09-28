class Solution {
    

        int gcd(int a, int b) {
            while (b != 0) {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

        void build(vector<int>& arr, vector<int>& tree,
                   int node, int l, int r) {

            if (l == r) {
                tree[node] = arr[l];
                return;
            }

            int mid = (l + r) / 2;

            build(arr, tree, 2 * node + 1, l, mid);
            build(arr, tree, 2 * node + 2, mid + 1, r);

            tree[node] = gcd(tree[2 * node + 1],
                              tree[2 * node + 2]);
        }

        void update(vector<int>& tree, int node,
                    int l, int r, int pos, int value) {

            if (l == r) {
                tree[node] = value;
                return;
            }

            int mid = (l + r) / 2;

            if (pos <= mid)
                update(tree, 2 * node + 1, l, mid, pos, value);
            else
                update(tree, 2 * node + 2, mid + 1, r, pos, value);

            tree[node] = gcd(tree[2 * node + 1],
                              tree[2 * node + 2]);
        }

        int query(vector<int>& tree, int node,
                  int l, int r, int ql, int qr) {

            if (r < ql || l > qr)
                return 0;

            if (ql <= l && r <= qr)
                return tree[node];

            int mid = (l + r) / 2;

            int left = query(tree, 2 * node + 1,
                             l, mid, ql, qr);

            int right = query(tree, 2 * node + 2,
                              mid + 1, r, ql, qr);

            return gcd(left, right);
        }

    public:
        vector<int> processQueries(vector<int>& arr,
                                   vector<vector<int>>& queries) {

            int n = arr.size();

            vector<int> tree(4 * n);

            build(arr, tree, 0, 0, n - 1);

            vector<int> ans;

            for (auto &q : queries) {

                if (q[0] == 0) {
                    int l = q[1];
                    int r = q[2];

                    ans.push_back(
                        query(tree, 0, 0, n - 1, l, r)
                    );
                }
                else {
                    int index = q[1];
                    int value = q[2];

                    arr[index] = value;

                    update(tree, 0, 0, n - 1,
                           index, value);
                }
            }

            return ans;
     
        
    }
};