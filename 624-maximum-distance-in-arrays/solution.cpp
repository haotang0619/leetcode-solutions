class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min1 = 1e6, min2 = 1e5, max1 = -1e5, max2 = -1e6;
        int idx_min1 = -1, idx_max1 = -1;
        for(int i = 0; i < arrays.size(); i++) {
            auto x = arrays[i];
            if(x[0] < min2) {
                min2 = x[0];
                if(min2 < min1) {
                    swap(min1, min2);
                    idx_min1 = i;
                }
            }
            if(x.back() > max2) {
                max2 = x.back();
                if(max2 > max1) {
                    swap(max1, max2);
                    idx_max1 = i;
                }
            }
        }
        return idx_min1 != idx_max1 ? abs(max1 - min1) : max(abs(max2 - min1), abs(max1 - min2));
    }
};
