class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for(auto x : word) {
            if(mp.find(x) == mp.end()) mp[x] = 0;
            mp[x]++;
        }
        vector<int> v;
        for(auto x : mp) v.push_back(x.second);
        sort(v.begin(), v.end());
        int ans = INT_MAX, size = word.size();
        int i = 0, j = 0, sum = 0, pre_sum = 0;
        while(j < v.size()) {
            int target = v[i] + k;
            while(j < v.size() && v[j] <= target) {
                sum += v[j];
                j++;
            }
            int suffix_sum = size - sum;
            int left_cnt = v.size() - j;
            int curr_ans = suffix_sum - target * left_cnt;
            ans = min(ans, curr_ans + pre_sum);
            pre_sum += v[i++];
        }
        return ans;
    }
};
