class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        // code here
        
        
        vector<int> freq( n + 2, 0);
        
        for (int j : updates) {
            freq[j]++;
            
        }
        
        vector<int> arr(n);
        
        int count = 0;
        
        
        for (int i = 1; i <= n; i++) {
            count += freq[i];
            arr[i - 1] = count;
        }
        
        return arr;
    }
};