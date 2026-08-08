class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> v(2, 0);
        for(auto& num : nums1) v[num % 2]++;
        if(v.size() == 1) return true; 
        if(v[0] == 0 || v[1] == 0) return true;
        return v[1] >= 1;
    }
};
