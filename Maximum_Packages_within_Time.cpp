class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {

int n = arr.size();

totalTime = min(totalTime, n);

int windowSum = 0;
for (int i = 0; i < totalTime; i++) {
    windowSum += arr[i];
}

int maxSum = windowSum;

for (int i = totalTime; i < n; i++) {
    windowSum += arr[i];
    windowSum -= arr[i - totalTime];
    
    
    maxSum = max(maxSum, windowSum);
    
}

return maxSum;

        
    }
};