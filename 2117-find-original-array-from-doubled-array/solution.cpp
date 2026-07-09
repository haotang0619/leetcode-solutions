class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n % 2 == 1) return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp1, mp2;
        for(auto& x : changed) mp1[x]++;
        vector<int> ans;
        for(auto& x : changed) {
            if(mp2[x] > 0) {
                mp2[x]--;
                continue;
            }
            if(mp1[x * 2] == 0) return {};
            mp1[x * 2]--, mp2[x * 2]++;
            ans.push_back(x);
        }
        return ans;
    }
};
