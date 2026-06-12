class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans, kept(3, "");
        string now;
        text += ' ';
        for(auto c : text) {
            if(c != ' ') now += c;
            else {
                kept[0] = kept[1];
                kept[1] = kept[2];
                kept[2] = now;
                if(kept[0] == first && kept[1] == second) ans.push_back(kept[2]);
                now = "";
            }
        }
        return ans;
    }
};
