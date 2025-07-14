class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = n; i >= 1; i--) {
            int cnt = 0;
            for(auto x : nums) {
                if(x >= i) cnt++;
                if(cnt > i) break;
            }
            if(cnt == i) return i;
        }
        return -1;
    }
};
