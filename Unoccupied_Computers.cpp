class Solution {
  public:
    int solve(int n, string s) {
        // code here
        
        
        vector<bool> seen(26, false);
        vector<bool> usingComputer(26, false);
        
        int available = n;
        int rejected = 0;
        
        for(char c : s) {
            int x = c - 'A';
            
            if(!seen[x]) {
                seen[x] = true;
                
                if(available > 0) {
                    usingComputer[x] = true;
                    available--;
                    
                }else {
                    rejected++;
                    
                }
            }
            
            else {
                if(usingComputer[x]) {
                    usingComputer[x] = false;
                    available++;
                }
            }
        }
        
        return rejected;
    }
};
