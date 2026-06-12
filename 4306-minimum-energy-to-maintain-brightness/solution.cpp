class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        long long sum = 0;
        int prevI1 = intervals[0][0], prevI2 = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            int i1 = intervals[i][0], i2 = intervals[i][1];
            if(i1 <= prevI2) prevI2 = max(i2, prevI2);
            else {
                sum += prevI2 - prevI1 + 1;
                prevI1 = i1;
                prevI2 = i2;
            }
        }
        sum += prevI2 - prevI1 + 1;
        return sum * (brightness % 3 == 0 ? brightness / 3 : brightness / 3 + 1);
    }
};
