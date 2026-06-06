class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = n - 1; i >= 0; i--) {
            vector<int> nums;
            for(int j = 0, k = i; j < n && k < n; j++, k++) {
                nums.push_back(grid[k][j]);
            }
            sort(nums.begin(), nums.end(), greater<int>());
            for(int j = 0, k = i, l = 0; j < n && k < n; j++, k++, l++) {
                grid[k][j] = nums[l];
            }
        }
        for(int j = 1; j < n; j++) {
            vector<int> nums;
            for(int i = 0, k = j; i < n && k < n; i++, k++) {
                nums.push_back(grid[i][k]);
            }
            sort(nums.begin(), nums.end());
            for(int i = 0, k = j, l = 0; i < n && k < n; i++, k++, l++) {
                grid[i][k] = nums[l];
            }
        }
        return grid;
    }
};
