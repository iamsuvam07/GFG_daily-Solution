class Solution {
  public:
    int countBT(int h) {

        const long long MOD = 1000000007;

        if (h == 0 || h == 1)
            return 1;

        long long a = 1;
        long long b = 1; 

        for (int i = 2; i <= h; i++) {
            long long c = (b * b + 2 * b * a) % MOD;

            a = b;
            b = c;
        }



return (int)b;

    }
};