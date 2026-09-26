class Solution {
  public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        
        int ans = INT_MAX;
        
 
          for (int L = 0; L <= (x + l - 1) / l; L++) {
              
              for (int M = 0; M <= (x + m - 1) / m; M++) {

                  int covered = L * l + M * m;

                  if (covered >= x) {
                      ans = min(ans, L * cl + M * cm);
                  } else {
                      int remaining = x - covered;
                      int S = (remaining + s - 1) / s;

                      ans = min(ans, L * cl + M * cm + S * cs);
                  }
              }
          }
        
        return ans;
    }
};