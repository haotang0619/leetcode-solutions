class Solution {
public:
    void solve(unordered_map<int, vector<int>>& ump, vector<int>& ans, vector<int>& curr, set<int>& st, int now) {
        if(ump.find(now) != ump.end()) {
            vector<int> tmp = curr;
            tmp.insert(tmp.end(), ump[now].begin(), ump[now].end());
            if(ans.size() < tmp.size()) ans = tmp;
            return;
        }

        curr.push_back(now);
        if(ans.size() < curr.size()) ans = curr;
        vector<int> divs;
        for(int i = 1; i <= floor(sqrt(now)); i++) {
            if(now % i == 0) {
                if(i < now && st.find(i) != st.end()) divs.push_back(i);
                int j = now / i;
                if(j < now && j != i && st.find(j) != st.end()) divs.push_back(j);
            }
        }
        sort(divs.begin(), divs.end());
        for(auto x : divs) solve(ump, ans, curr, st, x);
        curr.pop_back();
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans, ans_of_now, curr;
        unordered_map<int, vector<int>> ump;
        set<int> st;
        sort(nums.begin(), nums.end());
        for(auto x : nums) st.insert(x);
        for(auto x : nums) {
            solve(ump, ans_of_now, curr, st, x);
            if(ans.size() < ans_of_now.size()) ans = ans_of_now;
            ump[x] = ans_of_now;
            ans_of_now = {};
        }
        return ans;
    }
};
