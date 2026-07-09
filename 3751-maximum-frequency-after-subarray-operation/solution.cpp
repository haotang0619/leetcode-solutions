// Solved first and then modified according to a solution
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int totK = 0;
        for(auto& x : nums) {
            if(x == k) totK++;
        }
        int ans = totK;
        for(int i = 1; i <= 50; i++) {
            if(i == k) continue;
            int ansI = 0, now = 0;
            for(auto& x : nums) {
                if(x == i) now++;
                else if(x == k) now--;
                if(now < 0) now = 0;
                ansI = max(ansI, now);
            }
            ans = max(ans, totK + ansI);
        }
        return ans;
    }
};
