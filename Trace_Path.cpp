class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
       int row = 0, col = 0;
       
       int minRow = 0, maxRow = 0;
       int minCol = 0, maxCol = 0;
       
       for (char ch : s) {
           if ( ch == 'L')
           col--;
           
           else if (ch == 'R')
           col++;
           
           else if (ch =='D')
           row++;
           
           else if (ch =='U')
           row--;
           
           
           minRow = min(minRow, row);
           maxRow = max(maxRow, row);
           minCol = min(minCol, col);
           maxCol = max(maxCol, col);
       }
       
       return (maxRow - minRow < n) && (maxCol - minCol < m);
        
        
    }
};