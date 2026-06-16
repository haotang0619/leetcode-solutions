class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto w : words) {
            int sum = 0;
            for(auto c : w) sum += weights[c - 'a'];
            ans += 'z' - (sum % 26);
        }
        return ans;
    }
};
