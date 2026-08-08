class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true) {
            string s = to_string(n);
            int p = 1;
            for(auto& c : s) p *= (c - '0');
            if(p % t == 0) break;
            n++;
        }
        return n;
    }
};
