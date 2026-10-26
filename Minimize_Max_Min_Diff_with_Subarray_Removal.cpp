class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        
    
              int n = arr.size();

              vector<int> preMin(n), preMax(n);
              preMin[0] = preMax[0] = arr[0];

              for (int i = 1; i < n; i++) {
                  preMin[i] = min(preMin[i - 1], arr[i]);
                  preMax[i] = max(preMax[i - 1], arr[i]);
              }

              vector<int> sufMin(n), sufMax(n);
              sufMin[n - 1] = sufMax[n - 1] = arr[n - 1];

              for (int i = n - 2; i >= 0; i--) {
                  sufMin[i] = min(sufMin[i + 1], arr[i]);
                  sufMax[i] = max(sufMax[i + 1], arr[i]);
              }

              int ans = INT_MAX;

              for (int i = 0; i + k <= n; i++) {
                  int left = i - 1;
                  int right = i + k;

                  int mn = INT_MAX;
                  int mx = INT_MIN;

                  if (left >= 0) {
                      mn = min(mn, preMin[left]);
                      mx = max(mx, preMax[left]);
                  }

                  if (right < n) {
                      mn = min(mn, sufMin[right]);
                      mx = max(mx, sufMax[right]);
                  }

                  ans = min(ans, mx - mn);
              }

              return ans;
       
        
        
    }
};
