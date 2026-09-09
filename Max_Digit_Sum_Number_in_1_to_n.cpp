class Solution {
  private:
    int getDigitSum(long long num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

  public:
    int findMax(int n) {
        string s = to_string(n);
        int len = s.length();

        long long bestNum = n;
        int maxSum = getDigitSum(n);

        for (int i = 0; i < len; i++) {
            if (s[i] == '0') continue;

            string candidate = s;
            candidate[i]--;
            for (int j = i + 1; j < len; j++) {
                candidate[j] = '9';
            }

            long long val = stoll(candidate);
            int currentSum = getDigitSum(val);

            if (currentSum > maxSum || (currentSum == maxSum && val > bestNum)) {
                maxSum = currentSum;
                bestNum = val;
            }
        }

        return bestNum;
    }
};