class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> even, odds;
        for(auto& num : nums1) {
            if(num % 2 == 0) even.push_back(num);
            else odds.push_back(num);
        }
        if(even.empty() || odds.empty()) return true;
        int minEven = *min_element(even.begin(), even.end());
        int minOdd = *min_element(odds.begin(), odds.end());
        return minEven > minOdd;
    }
};
