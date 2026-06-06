class Solution {
public:
    bool isSymmetric(int num) {
        vector<int> digits;
        while(num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        if(digits.size() % 2 == 1) return false;
        int sum = 0;
        for(int i = 0; i < digits.size(); i++) {
            sum += digits[i] * (i < digits.size() / 2 ? -1 : 1);
        }
        return sum == 0;
    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++) ans += isSymmetric(i) ? 1 : 0;
        return ans;
    }
};
