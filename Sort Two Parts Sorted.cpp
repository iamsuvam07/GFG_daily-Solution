class Solution {
  public:
    void mergeTwoParts(vector<int>& arr) {
        // code here
        
            int n = arr.size();

            int i = 0;

            while (i + 1 < n && arr[i] <= arr[i + 1]) {
                i++;
            }

            if (i == n - 1) {
                return;
            }

            int j = i + 1;

            vector<int> temp;

            int left = 0;
            int right = j;

            while (left <= i && right < n) {
                if (arr[left] <= arr[right]) {
                    temp.push_back(arr[left]);
                    left++;
                } else {
                    temp.push_back(arr[right]);
                    right++;
                }
            }

            while (left <= i) {
                temp.push_back(arr[left]);
                left++;
            }

            while (right < n) {
                temp.push_back(arr[right]);
                right++;
            }

            arr = temp;
    }
};