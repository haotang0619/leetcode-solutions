class Solution {
public:
    int calDays(vector<int>& weights, int cap) {
        int needed = 1, now = 0;
        for(auto& w : weights) {
            if(now + w > cap) now = 0, needed++;
            now += w;
        }
        return needed;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while(l < r) {
            int m = l + (r - l) / 2;
            if(calDays(weights, m) > days) l = m + 1;
            else r = m;
        }
        return l;
    }
};
