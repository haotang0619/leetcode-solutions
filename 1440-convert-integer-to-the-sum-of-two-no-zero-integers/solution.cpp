class Solution {
public:
    bool noZero(int x) {
        while(x > 0) {
            if(x % 10 == 0) return false;
            x /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++) {
            int j = n - i;
            if(noZero(i) && noZero(j)) return {i, j};
        }
        return {1, n - 1};
    }
};
