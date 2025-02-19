class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            for(auto x : nums[i]) arr.push_back({x, i});
        }
        sort(arr.begin(), arr.end());

        unordered_map<int, int> ump;
        int idx1 = 0, idx2 = 0;
        ump[arr[0].second] = 1;
        vector<int> ans = {int(-1e6), int(1e6)};

        while(idx2 < arr.size()) {
            while(ump.size() < nums.size()) {
                idx2++;
                if(idx2 >= arr.size()) break;

                if(ump.find(arr[idx2].second) != ump.end()) ump[arr[idx2].second]++;
                else ump[arr[idx2].second] = 1;
            }
            if(idx2 >= arr.size()) break;

            while(true) {
                if (ump[arr[idx1].second] > 1) {
                    ump[arr[idx1].second]--;
                    idx1++;
                } else {
                    ump.erase(arr[idx1].second);
                    vector<int> range = {arr[idx1].first, arr[idx2].first}; 
                    if(range[1] - range[0] < ans[1] - ans[0]) ans = range;
                    idx1++;
                    break;
                }
            }
        }
        return ans;
    }
};
