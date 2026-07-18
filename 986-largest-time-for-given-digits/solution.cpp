class Solution {
public:
    void recursive(pair<int, int>& result, pair<int, int>& now, vector<int>& arr, unordered_set<int>& used) {
        int idx = used.size();
        if(idx == 4) {
            result = max(result, now);
            return;
        }
        for(int i = 0; i < 4; i++) {
            if(used.contains(i)) continue;
            auto& num = (idx < 2) ? now.first : now.second;
            num = num * 10 + arr[i];
            if(idx < 2 && num < 24 || idx >= 2 && num < 60) {
                used.insert(i);
                recursive(result, now, arr, used);
                used.erase(i);
            }
            num = (num - arr[i]) / 10;
        }
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        pair<int, int> result = {-1, -1}, now = {0, 0};
        unordered_set<int> used;
        recursive(result, now, arr, used);
        auto& [h, m] = result;
        if(h == -1) return "";
        string H = (h < 10) ? string({'0', (char)('0' + h)}) : to_string(h);
        string M = (m < 10) ? string({'0', (char)('0' + m)}) : to_string(m);
        return H + ':' + M;
    }
};
