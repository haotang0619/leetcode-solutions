class Solution {
public:
    string clearDigits(string s) {
        while(true) {
            smatch match;
            regex digit("\\d");
            if(regex_search(s, match, digit)){
                int pos = match.position();
                s.erase(pos - 1, 2);
            } else break;
        }
        return s;
    }
};
