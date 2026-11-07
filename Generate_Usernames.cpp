class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {



        unordered_set<string> reserved;
        unordered_set<string> assigned;
        unordered_map<string, int> nextSuffix;

        for (auto &s : arr) {
            reserved.insert(s);
        }

        vector<string> ans;

        for (auto &s : arr) {

            if (!assigned.count(s)) {
                assigned.insert(s);
                ans.push_back(s);
            }
            else {
                int &k = nextSuffix[s];
                if (k == 0) k = 1;

                string candidate;

                while (true) {
                    candidate = s + to_string(k);
                    k++;

                    if (!reserved.count(candidate)) {
                        break;
                    }
                }

                reserved.insert(candidate);
                assigned.insert(candidate);
                ans.push_back(candidate);
            }
        }

        return ans;

    }
};