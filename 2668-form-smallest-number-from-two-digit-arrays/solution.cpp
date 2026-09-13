class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        int ans = 1;
        while(ans <= 99) {
            string s = to_string(ans);
            bool v1 = false, v2 = false;
            for(auto& c : s) {
                if(st1.contains(c - '0')) v1 = true;
                if(st2.contains(c - '0')) v2 = true;
            }
            if(v1 && v2) break;
            ans++;
        }
        return ans;
    }
};
