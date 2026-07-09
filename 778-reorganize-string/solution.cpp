class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto& c : s) mp[c]++;
        priority_queue<pair<int, char>> pq;
        for(auto& [c, cnt] : mp) pq.push({cnt, c});
        string ans;
        while(ans.size() < s.size()) {
            auto [cnt1, c1] = pq.top();
            pq.pop();
            if(cnt1 == 0) return "";
            if(ans.size() > 0 && ans.back() == c1) {
                if(pq.empty()) return "";
                auto [cnt2, c2] = pq.top();
                if(cnt2 == 0) return "";
                pq.pop();
                ans += c2;
                pq.push({cnt1, c1});
                pq.push({cnt2 - 1, c2});
            } else {
                ans += c1;
                pq.push({cnt1 - 1, c1});
            }
        }
        return ans;
    }
};
