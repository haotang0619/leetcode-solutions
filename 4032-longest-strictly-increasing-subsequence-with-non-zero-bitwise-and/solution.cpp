struct BIT {
    int n;
    vector<int> bit;

    BIT(int n): n(n), bit(n + 1, 0) {}

    void update(int x, int v){
        for(++x; x <= n; x += x & -x)
            bit[x] = max(bit[x], v);
    }

    int query(int x){
        int res = 0;
        for(++x; x > 0; x -= x & -x)
            res = max(res, bit[x]);
        return res;
    }
};

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int idx = 0;
        unordered_map<int, int> mp;
        for(auto& num : tmp) {
            if(mp.contains(num)) continue;
            mp[num] = idx++;
        }
        
        int ans = 0, n = nums.size();
        vector<BIT> trees(32, BIT(idx));
        for(auto& num : nums) {
            for(int idx = 0, i = 1; i <= num; idx++, i <<= 1) {
                if((num & i) == 0) continue;
                int mx = trees[idx].query(mp[num] - 1);
                ans = max(ans, mx + 1);
                trees[idx].update(mp[num], mx + 1);
            }
        }
        return ans;
    }
};
