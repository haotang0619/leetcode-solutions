class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        for(int i = 0; i < str.length() - 1; i++) {
            char maxChar = str[i] + 1;
            int maxPos = -1;
            for(int j = i + 1; j < str.length(); j++) {
                if(str[j] >= maxChar) {
                    maxChar = str[j];
                    maxPos = j;
                }
            }
            if(maxPos != -1) {
                swap(str[i], str[maxPos]);
                break;
            }
        }
        return stoi(str);
    }
};
