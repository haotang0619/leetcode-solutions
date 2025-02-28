class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        unordered_map<long long, vector<int>> mp;

        int size = nums.size();
        for(int i = 0; i < size; i++) mp[(long long)nums[i]].push_back(i);

        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                for(int k = j + 1; k < size; k++) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k];
                    long long diff = (long long)target - sum;
                    
                    bool flag = false;
                    for(auto y : mp[diff]) {
                        if(y != i && y != j && y != k) {
                            flag = true;
                            break;
                        }
                    }

                    if(flag) {
                        vector<int> tmp = {(int)diff, nums[i], nums[j], nums[k]};
                        sort(tmp.begin(), tmp.end());
                        st.insert(tmp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
