class Solution {
public:
    void findPal(vector<long long>& all, map<int, int>& left, string& prev, string center) {
        bool flag = false;
        for(auto [digit, cnt] : left) {
            if(cnt > 0) {
                flag = true;
                prev.push_back('0' + digit);
                left[digit]--;
                findPal(all, left, prev, center);
                left[digit]++;
                prev.pop_back();
            }
        }
        if(!flag) {
            string res(prev), rev(prev);
            reverse(rev.begin(), rev.end());
            if(center.size() > 0) res += center;
            res += rev;
            if(res.size() > 0) all.push_back(stoll(res));
        }
    }
    
    void findOpt(vector<vector<int>>& opts, vector<int>& now, int pos, int limit) {
        if(pos == limit) {
            int sum = 0;
            for(auto x : now) sum += x;
            if(now.size() >= 1 && sum <= 16) opts.push_back(now);
            for(int i = 1; i <= 9; i += 2) {
                now.push_back(i);
                if(sum + i <= 16) opts.push_back(now);
                now.pop_back();
            }
            return;
        }
        for(int i = now.size() > 0 ? now.back() : 2; i <= 8; i += 2) {
            bool added = false;
            for(auto x : now) {
                if(x == i) {
                    added = true;
                    break;
                }
            }
            if(!added) {
                now.push_back(i);
                findOpt(opts, now, pos + 1, limit);
                now.pop_back();
            }
        }
    }
    
    long long specialPalindrome(long long n) {
        vector<int> now;
        vector<vector<int>> opts;
        for(int i = 0; i <= 4; i++) findOpt(opts, now, 0, i);
        
        vector<long long> all;
        for(auto opt : opts) {
            string prev = "";
            string center = "";
            if(opt.back() % 2 == 1) center = '0' + opt.back();
            map<int, int> left;
            for(auto x : opt) left[x] = x / 2;
            findPal(all, left, prev, center);
        }
        sort(all.begin(), all.end());
        for(auto x : all) {
            if(x > n) return x;
        }
        return -1;
    }
};
