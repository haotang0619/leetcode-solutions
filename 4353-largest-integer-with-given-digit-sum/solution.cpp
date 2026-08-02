class Solution {
public:
    int largestInteger(int n, int s) {
        int i = 0, ans = -1;
        while(true) {
            string s1 = to_string(i);
            if(s1.size() > n) break;
            int sum = 0;
            for(auto& c : s1) sum += (c - '0');
            if(sum == s) ans = max(ans, i);
            i++;
        }
        return ans;
    }
};
