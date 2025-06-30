class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long max_num = 0, min_num = 0, cnt = 0;
        for(auto x : differences) {
            cnt += x;
            max_num = max(max_num, cnt);
            min_num = min(min_num, cnt);
        }
        return max((upper - lower) - (max_num - min_num) + 1, 0LL);
    }
};
