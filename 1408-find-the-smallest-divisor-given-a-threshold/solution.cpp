class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = INT_MAX;
        while(l < r) {
            int m = l + (r - l) / 2;
            int sum = 0;
            for(auto& num : nums) sum += ceil((double)num / m);
            if(sum <= threshold) r = m;
            else l = m + 1;
        }
        return l;
    }
};
