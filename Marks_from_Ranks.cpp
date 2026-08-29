class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        
        int n = l.size();
        
       vector<int> prefix(n);

         prefix[0] = r[0] - l[0] + 1;

         for (int i = 1; i < n; i++) {
             prefix[i] = prefix[i - 1] + (r[i] - l[i] + 1);
         }

         vector<int> ans;

         for (int x : rank) {

             int low = 0, high = n - 1;

             while (low < high) {
                 int mid = low + (high - low) / 2;

                 if (prefix[mid] >= x)
                     high = mid;
                 else
                     low = mid + 1;
             }

             int idx = low;

             int diff = prefix[idx] - x;

             int mark = r[idx] - diff;

             ans.push_back(mark);
         }

         return ans;
    }
};