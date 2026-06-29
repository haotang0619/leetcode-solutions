class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for(auto& num : nums) mp[num]++;
        int ans = 1;
        for(auto& num : nums) {
            if(num == 1) {
                ans = max(ans, mp[1] % 2 == 1 ? mp[1] : mp[1] - 1);
                continue;
            };
            long long l = num;
            int cnt = 1;
            while(mp[l] >= 2) {
                if(mp[l * l] >= 1) cnt += 2;
                l = l * l;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
