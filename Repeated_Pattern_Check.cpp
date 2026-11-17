class Solution {
  public:
    bool findPattern(string& s) {

int i = 0;
int n = s.size();


while(i < n) {
    if (s[i] != 'x') {
        return false;
    }
    
    
    int xCount = 0;
    
    while (i < n && s[i] == 'x') {
        xCount++;
        i++;
    }
    
    int yCount = 0;
    while (i < n && s[i] == 'y') {
        yCount++;
        i++;
    }
    
    if(xCount != yCount) {
        return false;
    }
}


return true;

    }
};