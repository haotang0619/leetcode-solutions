class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<int> pos;
        for(int i = 0; i < words.size(); i++) {
            if(words[i] == target) pos.push_back(i);
        }
        if(pos.size() == 0) return -1;
        int ans = INT_MAX;
        for(auto p : pos) {
            cout << p << " ";
            int p1 = p - words.size(), p2 = p + words.size();
            int now = min(abs(p - startIndex), abs(p1 - startIndex));
            now = min(now, abs(p2 - startIndex));
            ans = min(ans, now);
        }
        return ans;
    }
};
