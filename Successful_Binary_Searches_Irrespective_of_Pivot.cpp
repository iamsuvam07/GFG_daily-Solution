class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        vector<int> suffixMin(n);
        
        suffixMin[n - 1] = arr[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(arr[i], suffixMin[i + 1]);
        }
        
        int ans = 0;
        int prefixMax = INT_MIN;
        
        
        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, arr[i]);
            
            if (arr[i] == prefixMax && arr[i] == suffixMin[i]) {
                ans++;
                
            }
        }
        
        
    return ans;
        
    }
};