class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        map<string, int> mp;
        string now;
        char prev = '\0';
        chunks.push_back(" ");
        for(auto s : chunks) {
            for(auto c : s) {
                if(c == ' ' || (c == '-' && (prev < 'a' || prev > 'z'))) {
                    while(now.size() > 0 && now[now.size() - 1] == '-') {
                        now.pop_back();
                    }
                    if(now.size() > 0) mp[now]++;
                    now = "";
                } else now += c;
                prev = c;
            }
        }
        vector<int> ans;
        for(auto s : queries) ans.push_back(mp[s]);
        return ans;
    }
};
