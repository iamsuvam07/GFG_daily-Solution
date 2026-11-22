class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {

unordered_map<int, int> mp;
mp[0] = -1;


int sum = 0;
int maxLen = 0;

for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    
    int rem = sum % k;
    
    
    if (rem < 0)
    rem += k;
    
    
    if (mp.find(rem) != mp.end()) {
        maxLen = max(maxLen, i - mp[rem]);
    }
    else {
        mp[rem] = i;
    }
}

return maxLen;


    }
};