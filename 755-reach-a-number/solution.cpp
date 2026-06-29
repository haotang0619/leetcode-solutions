class Solution {
public:
    // 1st -1 to 1 (odd)
    // 2nd -3 to 3 (odd)
    // 3rd -6 to 6 (even)
    // 4th -10 to 10 (even)
    // 5th -15 to 15 (odd)
    // 6th -21 to 21 (odd)
    // 7th -28 to 28 (even)
    // 8th -36 to 36 (even)
    // ......
    int reachNumber(int target) {
        vector<int> range = {0};
        int now = 1;
        while(range.back() < 2e9 + 7) range.push_back(range.back() + now++);
        int idx = lower_bound(range.begin(), range.end(), abs(target)) - range.begin();
        while(range[idx] % 2 != abs(target) % 2) idx++;
        return idx;
    }
};
