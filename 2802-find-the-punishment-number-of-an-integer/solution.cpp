class Solution {
public:
    bool checkAns(int target, string num, int idx, int curr) {
        if(idx == num.length()) return curr == target;
        int left = target - curr;
        bool flag = false;

        for(int i = idx + 1; i <= num.length(); i++) {
            int val = stoi(num.substr(idx, i - idx));
            if(val <= left) {
                flag = checkAns(target, num, i, curr + val);
                if(flag) break;
            } else break;
        }
        return flag;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(checkAns(i, to_string(i * i), 0, 0)) ans += i * i;
        }
        return ans;
    }
};
