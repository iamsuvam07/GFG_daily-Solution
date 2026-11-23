class Solution {
  public:
    char posInfinite(string &s, int pos) {





        long long p = pos;
        long long len = s.size();

        vector<long long> lengths;
        lengths.push_back(len);

        long long step = 1;

        while (len < p) {
            len = 2 * len + step;
            lengths.push_back(len);
            step++;
        }

        while (lengths.size() > 1) {
            long long prev = lengths[lengths.size() - 2];
            long long added = lengths.back() - 2 * prev;

            if (p <= prev) {
            } 
            else if (p <= prev + added) {
                return '$';
            } 
            else {
                p = 2 * prev + added - p + 1;
            }

            lengths.pop_back();
        }

        return s[p - 1];
   
    }
};
