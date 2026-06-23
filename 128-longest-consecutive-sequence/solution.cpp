class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st1, st2;
        for(auto x : nums) st1.insert(x);
        int ans = 0;
        for(auto x : st1) {
            if(st2.contains(x)) continue;
            int cnt = 1, y = x + 1;
            while(st1.contains(y)) {
                st2.insert(y);
                y++, cnt++;
            }
            y = x - 1;
            while(st1.contains(y)) {
                st2.insert(y);
                y--, cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
