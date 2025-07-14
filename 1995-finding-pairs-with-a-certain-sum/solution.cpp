class FindSumPairs {
public:
    vector<int> v1, v2;
    map<int, int> mp1, mp2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto x : nums1) mp1[x]++;
        for(auto x : nums2) mp2[x]++;
        v1 = nums1;
        v2 = nums2;
    }
    
    void add(int index, int val) {
        int old = v2[index];
        mp2[old]--;
        int new_val = old + val;
        v2[index] = new_val;
        mp2[new_val]++;
    }
    
    int count(int tot) {
        int sum = 0;
        for(auto [x, cnt1] : mp1) {
            int left = tot - x;
            int cnt2 = mp2[left];
            sum += cnt1 * cnt2;
        }
        return sum;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
