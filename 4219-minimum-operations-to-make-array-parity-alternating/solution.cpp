class Solution {
public:
    int getDiff(vector<int>& changed, vector<int>& kept) {
        if(changed.size() == 0) return kept.back() - kept[0];
        if(kept.size() == 0) {
            if(changed.size() <= 1) return 0;
            return abs((changed.back() - 1) - (changed[0] + 1));
        }
        if(changed.size() == 1 || changed[0] == changed.back()) {
            return min(
                max(kept.back(), changed[0] - 1) - min(kept[0], changed[0] - 1),
                max(kept.back(), changed[0] + 1) - min(kept[0], changed[0] + 1)
            );
        }
        
        return max(kept.back(), changed.back() - 1) - min(kept[0], changed[0] + 1);
    }
    
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        vector<int> nums1, nums2;
        for(int i = 0; i < n; i++) {
            if((i % 2) == abs(nums[i] % 2)) cnt2++, nums2.push_back(nums[i]);
            else cnt1++, nums1.push_back(nums[i]);
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int diff1 = getDiff(nums1, nums2), diff2 = getDiff(nums2, nums1);
        if(cnt1 < cnt2) return {cnt1, diff1};
        if(cnt1 > cnt2) return {cnt2, diff2};
        return {cnt1, min(diff1, diff2)};
    }
};
