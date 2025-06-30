class Solution {
public:
    // Saw discussion
    int integerReplacement(int n) {
        int cnt = 0;
        long long nll = n;
        while(nll != 1) {
            if(nll % 4 == 1 || nll == 3) nll -= 1;
            else if(nll % 4 == 3) nll += 1;
            else nll /= 2;
            ++cnt;
        }
        return cnt;
    }
};
