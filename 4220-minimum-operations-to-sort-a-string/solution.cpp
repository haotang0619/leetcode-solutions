class Solution {
public:
    int minOperations(string s) {
        string s1 = s;
        sort(s1.begin(), s1.end());
        if(s == s1) return 0;

        unordered_set<string> st1, st2;
        string s2 = s, s3 = s;
        int cnt = 0;
        while(true) {
            bool flag = true;
            
            cnt++;
            sort(s2.begin(), s2.end() - 1);
            sort(s3.begin() + 1, s3.end());
            if(s1 == s2 || s1 == s3) return cnt;
            if(!st1.contains(s2) || !st2.contains(s3)) flag = false;
            st1.insert(s2); st2.insert(s3);

            cnt++;
            sort(s2.begin() + 1, s2.end());
            sort(s3.begin(), s3.end() - 1);
            if(s1 == s2 || s1 == s3) return cnt;
            if(!st1.contains(s2) || !st2.contains(s3)) flag = false;
            st1.insert(s2); st2.insert(s3);

            if(flag) break;
        }

        return -1;
    }
};
