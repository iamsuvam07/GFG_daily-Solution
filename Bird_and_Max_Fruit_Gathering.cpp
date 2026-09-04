class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        
        if( m >= n) {
            int sum = 0;
            for (int x : arr)
            sum += x;
            return sum;
        }
        
        int windowSum = 0;
        
        for (int i = 0; i < m; i++) {
            windowSum += arr[i];
        }
        
        int ans = windowSum;
        
        for (int i = m; i < n+m; i++) {
            windowSum += arr[i % n];
            windowSum -= arr[(i - m) % n];
            
            ans = max(ans, windowSum);
        }
        
        return ans;
    }
};