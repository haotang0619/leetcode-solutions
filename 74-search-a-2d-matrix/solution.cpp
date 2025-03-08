class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> v;
        for(auto &x : matrix) v.push_back(x[0]);
        int pos1 = lower_bound(v.begin(), v.end(), target) - v.begin();
        if(pos1 == matrix.size() || v[pos1] > target) pos1--;
        if(pos1 == -1) return false;
        int pos2 = lower_bound(matrix[pos1].begin(), matrix[pos1].end(), target) - matrix[pos1].begin();
        return pos2 < matrix[pos1].size() && matrix[pos1][pos2] == target;
    }
};
