class Solution {
public:
    int longestSubsequence(string s, int k) {
        int size = s.size();
        int ans = size;
        int k_len = floor(log2(k)) + 1;
        for(int i = 0; i < size; i++) {
            if(s[i] == '1') {
                if(size - i <= k_len) {
                    int num = stoi(s.substr(i), NULL, 2);
                    if(num <= k) break;
                    else ans--;
                } else ans--;
            }
        }
        return ans;
    }
};
