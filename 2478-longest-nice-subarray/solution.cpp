class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        unordered_map<int, int> mp;
        int idx1 = 0, idx2 = 1;
        processOneCount(nums[0], true, mp);
        while(idx2 < nums.size()) {
            processOneCount(nums[idx2], true, mp);
            while(!check(mp) && idx1 < idx2) {
                processOneCount(nums[idx1], false, mp);
                idx1++;
            }
            if(check(mp)) ans = max(ans, idx2 - idx1 + 1);
            idx2++;
        }
        return ans;
    }

private:
    void processOneCount(int num, bool toAdd, unordered_map<int, int>& mp) {
        int i = 0;
        while(num > 0) {
            mp[i++] += (toAdd ? (num & 1) : -(num & 1));
            num >>= 1;
        }
    }

    bool check(unordered_map<int, int>& mp) {
        for(auto &x : mp) if(x.second > 1) return false;
        return true;
    }
};
