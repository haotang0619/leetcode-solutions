class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = nums.size();
        stack<int> sk;
        unordered_map<int, int> mp;
        for(auto& num : nums) {
            while(!sk.empty() && sk.top() < num) {
                mp[sk.top()]--;
                sk.pop();
            }
            mp[num]++;
            sk.push(num);
            ans += mp[num] - 1;
        }
        return ans;
    }
};
