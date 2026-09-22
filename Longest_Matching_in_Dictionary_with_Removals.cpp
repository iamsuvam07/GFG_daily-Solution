class Solution {
  public:
  
     string findLongestWord(string &s, vector<string> &d) {
                int n = s.length();

                
 vector<vector<int>> nextPos(n + 1, vector<int>(26, -1));

     for (int c = 0; c < 26; c++)
                    nextPos[n][c] = -1;

     for (int i = n - 1; i >= 0; i--) {
      nextPos[i] = nextPos[i + 1];
     nextPos[i][s[i] - 'a'] = i;
                }

      string ans = "";

 for (string &word : d) {
      int pos = 0;
   bool ok = true;

     for (char ch : word) {
     if (pos > n || nextPos[pos][ch - 'a'] == -1) {
       ok = false;
      break;
         }

     pos = nextPos[pos][ch - 'a'] + 1;
  }

      if (ok) {
       if (word.length() > ans.length() ||
      (word.length() == ans.length() && word < ans)) {
          ans = word;
                        }
                    }
                }
                
        return ans;
        
    }
};