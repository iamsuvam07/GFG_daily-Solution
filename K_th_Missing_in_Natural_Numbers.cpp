class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {


sort(arr.begin(), arr.end());


for (int i = 0; i < arr.size(); i++) {
    
    
    if (arr[i] <= k) {
        k++;
    }
    else {
        break;
    }
}
    
    return k;
    
    }
};