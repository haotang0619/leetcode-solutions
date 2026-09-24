class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        string now;
        auto dfs = [&](auto&& self, int idx) {
            if(idx == arr.size()) {
                ans = max(ans, (int)now.size());
                return;
            }
            bool valid = true;
            vector<char> exist(26, false);
            for(auto& c : now) exist[c - 'a'] = true;
            for(auto& c : arr[idx]) {
                if(exist[c - 'a']) {
                    valid = false;
                    break;
                }
                exist[c - 'a'] = true;
            }
            if(valid) {
                now += arr[idx];
                self(self, idx + 1);
                for(int i = 0; i < arr[idx].size(); i++) now.pop_back();
            }
            self(self, idx + 1);
        };
        dfs(dfs, 0);
        return ans;
    }
};
