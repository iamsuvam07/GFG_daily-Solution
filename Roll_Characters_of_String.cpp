class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
       
       
       int n = s.size();
       
       vector<int> diff(n + 1, 0);
       
       for (int x : roll) {
           diff[0]++;
           diff[x]--;
           
       }
       int current = 0;
       
       for (int i = 0; i < n; i++) {
           current += diff[i];
           
           s[i] = 'a' + (s[i] - 'a' + current) % 26;
       }
       
       return s;
        
    }
};
