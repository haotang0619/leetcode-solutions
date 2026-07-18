class Solution {
public:
    void recursive(vector<int>& ans, int& low, int& high, int now, int prev) {
        if(now >= low && now <= high) ans.push_back(now);
        if(now > high || prev == 9) return;
        recursive(ans, low, high, now * 10 + prev + 1, prev + 1);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 0; i < 9; i++) recursive(ans, low, high, 0, i);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
