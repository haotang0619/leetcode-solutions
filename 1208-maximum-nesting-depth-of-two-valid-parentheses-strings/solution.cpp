class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0;
        for(auto& c : seq) {
            if(c == '(') {
                if(cnt1 <= cnt2) cnt1++, ans.push_back(0);
                else cnt2++, ans.push_back(1);
            } else {
                if(cnt1 > cnt2) cnt1--, ans.push_back(0);
                else cnt2--, ans.push_back(1);
            }
        }
        return ans;
    }
};
