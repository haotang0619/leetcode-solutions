class KthLargest {
public:
    int sz;
    multiset<int> st;

    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(auto& num : nums) {
            st.insert(num);
            if(st.size() > sz) st.erase(st.begin());
        }
    }
    
    int add(int val) {
        st.insert(val);
        if(st.size() > sz) st.erase(st.begin());
        return *st.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
