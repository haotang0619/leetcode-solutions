class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minCap = INT_MAX, idx = -1, n = capacity.size();
        for(int i = 0; i < n; i++) {
            if(capacity[i] < itemSize) continue;
            if(minCap > capacity[i]) minCap = capacity[i], idx = i;
        }
        return idx;
    }
};
