class Solution {
public:
    int reflect(int x) {
        int res = 0, now = 1;
        while(x > 0) {
            res *= 2;
            if(x & 1) res += 1;
            x >>= 1;
        }
        return res;
    }
    
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](auto& a, auto& b) {
            int ra = reflect(a), rb = reflect(b);
             if(ra == rb) return a < b;
            return ra < rb;
        });
        return nums;
    }
};
