class Solution {
public:
    using pii = pair<int, int>;
    using vpii = vector<pii>;
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vpii intervals1(26, {-1, -1}), intervals2, intervals3;
        
        // Find the interval of each letter
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            auto& [l, r] = intervals1[idx];
            if(l == -1) l = i;
            r = i;
        }

        // Extend intervals based on others
        for(int i = 0; i < n; i++) {
            for(int idx = 0; idx < 26; idx++) {
                auto& [l1, r1] = intervals1[idx];
                auto& [l2, r2] = intervals1[s[i] - 'a'];
                if(l1 < i && r1 > i) l1 = min(l1, l2), r1 = max(r1, r2);
            }
        }

        // Remove those intervals that completely cover one another
        for(auto& x1 : intervals1) {
            bool valid = true;
            for(auto& x2 : intervals1) {
                auto& [l1, r1] = x1;
                auto& [l2, r2] = x2;
                if(l1 < l2 && r1 > r2) {
                    valid = false;
                    break;
                }
            }
            if(valid) intervals2.push_back(x1);
        }
        
        // Merge intervals
        sort(intervals2.begin(), intervals2.end());
        pii curr = intervals2[0];
        for(int i = 1; i < intervals2.size(); i++) {
            auto& [l1, r1] = curr;
            auto& [l2, r2] = intervals2[i];
            if(l2 <= r1) r1 = r2;
            else {
                intervals3.push_back(curr);
                curr = {l2, r2};
            }
        }
        intervals3.push_back(curr);

        // Build answer
        vector<string> ans;
        for(auto& [l, r] : intervals3) {
            if(l == -1) continue;
            ans.push_back(s.substr(l, r - l + 1));
        }
        return ans;
    }
};
