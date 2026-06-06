class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num2 = (m + n / m * m) * (n / m) / 2;
        int num1 = (1 + n) * n / 2 - num2;
        return num1 - num2;
    }
};
