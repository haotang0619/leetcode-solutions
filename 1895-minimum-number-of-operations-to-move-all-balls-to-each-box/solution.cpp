class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int n = boxes.size();
        for(int i = 0; i < n; i++) {
            int now = 0;
            for(int j = 0; j < n; j++) {
                if(boxes[j] == '1') now += abs(j - i);
            }
            ans.push_back(now);
        }
        return ans;
    }
};
