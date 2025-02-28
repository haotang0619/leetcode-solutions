class Solution {
public:
    string answerString(string word, int numFriends) {
        unsigned long maxLen = word.length() - (numFriends - 1);
        if(numFriends == 1) return word;
        
        string ans = "";
        for(int i = 0; i < word.length(); i++) {
            unsigned long len = min(maxLen, word.length() - i);
            string_view curr{word.data() + i, len};
            ans = ans > curr ? ans : (string)curr;
        }
        return ans;
    }
};
