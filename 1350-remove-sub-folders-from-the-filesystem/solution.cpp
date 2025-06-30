class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        string curr = "";
        vector<string> ans;
        for(auto x : folder) {
            if(curr == "" || x.size() <= curr.size()) {
                ans.push_back(x);
                curr = x;
            } else {
                string sub = x.substr(0, curr.size());
                if(sub == curr && x[curr.size()] == '/') continue;
                else {
                    ans.push_back(x);
                    curr = x;
                }
            }
        }
        return ans;
    }
};
