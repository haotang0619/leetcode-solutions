class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, tuple<int, int, int>> mp; // [last, gap, cnt]
        for(auto& num : nums) mp[num] = {-1, 0, 0};
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            if(!mp.contains(num)) continue;
            auto [last, gap, cnt] = mp[num];
            if(cnt == 0) mp[num] = {i, 0, 1};
            else if(cnt == 1) {
                int gap1 = i - last;
                mp[num] = {i, gap1, 2};
            } else {
                int gap1 = i - last;
                if(gap != gap1) mp.erase(num);
                else mp[num] = {i, gap1, cnt + 1};
            }
        }
        int ans = 0;
        for(auto& [num, tup] : mp) {
            if(get<2>(tup) >= 3) ans++;
        }
        return ans;
    }
};
