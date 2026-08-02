class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st1(nums.begin(), nums.end()), st2;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) st2.insert(nums[i] ^ nums[j]);
        }
        int ans = st1.size();
        int mx = *max_element(nums.begin(), nums.end());
        int l = floor(log2(mx));
        int limit = pow(2, l + 1);
        for(int i = 0; i < limit; i++) {
            if(st1.contains(i)) continue;
            for(auto& num : nums) {
                if(st2.contains(i ^ num)) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
