class Solution {
  public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        // code here
        int n = r.size();


        vector<pair<int, int>> discs;

        for (int i = 0; i < n; i++) {
            discs.push_back({r[i], h[i]});
        }

        sort(discs.begin(), discs.end());

        vector<int> bit(1002, 0);

        auto query = [&](int x) {
            int res = 0;

            while (x > 0) {
                res = max(res, bit[x]);
                x -= x & (-x);
            }

            return res;
        };

        auto update = [&](int x, int value) {
            while (x <= 1000) {
                bit[x] = max(bit[x], value);
                x += x & (-x);
            }
        };

        int answer = 0;
        int i = 0;

        while (i < n) {
            int j = i;

            while (j < n && discs[j].first == discs[i].first) {
                j++;
            }

            vector<pair<int, int>> updates;

            for (int k = i; k < j; k++) {
                int height = discs[k].second;

                int bestBelow = query(height - 1);

                int current = bestBelow + height;

                answer = max(answer, current);

                updates.push_back({height, current});
            }

            for (auto &[height, value] : updates) {
                update(height, value);
            }

            i = j;
        }
           
            return answer;
    }
    
};