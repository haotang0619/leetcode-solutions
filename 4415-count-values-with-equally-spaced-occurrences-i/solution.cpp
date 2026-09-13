class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 1; i <= 100; i++) {
            vector<int> v;
            for(int j = 0; j < n; j++) {
                if(nums[j] == i) v.push_back(j);
            }
            if(v.size() != 3) continue;
            if(v[1] - v[0] == v[2] - v[1]) ans++;
        }
        return ans;
    }
};
