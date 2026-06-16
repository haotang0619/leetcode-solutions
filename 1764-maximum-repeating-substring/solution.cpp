class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        int m = sequence.size(), n = word.size(), maxAns = m / n;
        while(ans < maxAns) {
            string now = word;
            bool valid = false;
            for(int i = 2; i <= ans + 1; i++) now += word;
            for(int i = 0; i <= m - n * (ans + 1); i++) {
                if(sequence.substr(i, n * (ans + 1)) == now) {
                    valid = true;
                    break;
                }
            }
            if(!valid) break;
            ans++;
        }
        return ans;
    }
};
