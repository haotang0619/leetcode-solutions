class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        for(int i = 1; i <= n; i++) {
            if(n % i != 0) continue;
            string target = "";
            for(int j = 0; j < i; j++) target += s[j];
            sort(target.begin(), target.end());
            bool flag = true;
            for(int j = i; j < n; j += i) {
                string now = "";
                for(int k = j; k < j + i; k++) now += s[k];
                sort(now.begin(), now.end());
                if(target != now) {
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};
