class Solution {
public:
    // Saw discussion, just use brute force
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> st = {0};
        set<int> ansSet;
        int idx = 0;
        for(auto x : arr) {
            set<int> newSt;
            for(auto y : st) {
                newSt.insert(x | y);
                ansSet.insert(x | y);
            }
            newSt.insert(x);
            ansSet.insert(x);
            st = newSt;
        }
        return ansSet.size();
    }
};
