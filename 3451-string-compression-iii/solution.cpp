class Solution {
public:
    string compressedString(string word) {
        int cnt = 1;
        char curr = word[0];
        string ans;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == curr && cnt < 9) cnt++;
            else {
                ans += '0' + cnt;
                ans += curr;
                cnt = 1;
                curr = word[i];
            }
        }
        ans += '0' + cnt;
        ans += curr;
        return ans;
    }
};
