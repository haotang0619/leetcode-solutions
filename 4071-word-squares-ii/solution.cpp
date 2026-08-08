class Solution {
public:
    bool check(vector<string>& now) {
        string &top = now[0], &left = now[1], &right = now[2], &bottom = now[3];
        return top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] && bottom[3] == right[3];
    }
    
    void traverse(vector<vector<string>>& ans, vector<string>& now, vector<string>& words, unordered_set<int>& st) {
        if(now.size() == 4) {
            if(check(now)) ans.push_back(now);
            return;
        }
        for(int i = 0; i < words.size(); i++) {
            if(st.contains(i)) continue;
            now.push_back(words[i]);
            st.insert(i);
            traverse(ans, now, words, st);
            st.erase(i);
            now.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        vector<string> now;
        unordered_set<int> st;
        traverse(ans, now, words, st);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
