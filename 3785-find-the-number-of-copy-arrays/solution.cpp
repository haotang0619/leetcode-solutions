class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        vector<int> bound = bounds[0];
        for(int i = 1; i < original.size(); i++) {
            vector<int> b1 = bounds[i];
            int diff = original[i] - original[i - 1];
            vector<int> b2 = {bound[0] + diff, bound[1] + diff};
            bound = {max(b1[0], b2[0]), min(b1[1], b2[1])};
            if(bound[1] - bound[0] + 1 <= 0) break;
        }
        return max(bound[1] - bound[0] + 1, 0);
    }
};
