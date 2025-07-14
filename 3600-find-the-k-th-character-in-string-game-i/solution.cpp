class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size() < k) {
            int size = word.size();
            for(int i = 0; i < size; i++) {
                char c = word[i] + 1;
                c = c > 'z' ? 'a' : c;
                word += c; 
            }
        }
        return word[k - 1];
    }
};
