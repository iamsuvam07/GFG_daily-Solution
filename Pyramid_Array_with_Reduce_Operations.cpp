class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        // code here
int  n = arr.size();
vector<int> left(n), right(n);

left[0] = min(arr[0], 1);

for (int i = 1; i< n; i++) {
    left[i] = min(arr[i], left[i - 1] + 1);
    
}

right[n - 1] = min(arr[n - 1], 1);

for(int i = n - 2; i >=0; i--) {
    right[i] =min(arr[i], right[i + 1] + 1);
    
}

long long maxKept = 0;

for (int i = 0; i < n; i++) {
    long long peak = min(left[i], right[i]);
    maxKept += peak;
    
}
maxKept = 0;

for (int i = 0; i< n; i++) {
    long long h = min(left[i], right[i]);
    long long pyramidSum = h * h;
    
    maxKept = max(maxKept, pyramidSum);
    
}

long long total = 0;
for(int x : arr)
{
    total += x;
    
}

return (int) (total - maxKept);
    }
};