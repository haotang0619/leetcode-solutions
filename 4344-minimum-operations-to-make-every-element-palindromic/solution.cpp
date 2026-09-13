class Solution {
public:
    long long minOperations(vector<int>& nums) {
        vector<long long> p1, p2;
        int mx = *max_element(nums.begin(), nums.end());
        long long idx = 1;
        while(true) {
            long long num1 = idx, num2 = idx, tmp1 = idx / 10, tmp2 = idx;
            
            while(tmp1 > 0) {
                num1 = num1 * 10 + (tmp1 % 10);
                tmp1 /= 10;
            }

            while(tmp2 > 0) {
                num2 = num2 * 10 + (tmp2 % 10);
                tmp2 /= 10;
            }
            
            if(num1 % 2) p1.push_back(num1);
            else p2.push_back(num1);
            if(num2 % 2) p1.push_back(num2);
            else p2.push_back(num2);
            
            if(num1 >= mx * 2) break;
            idx++;
        }
        vector<long long> v1(p1.begin(), p1.end()), v2(p2.begin(), p2.end());
        v1.erase(unique(v1.begin(), v1.end()), v1.end());
        v2.erase(unique(v2.begin(), v2.end()), v2.end());
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        long long ans = 0;
        for(auto& num : nums) {
            auto& v = (num % 2 == 1 ? v1 : v2);
            int idxHi = upper_bound(v.begin(), v.end(), num) - v.begin();
            int idxLo = idxHi - 1;
            long long diff1 = LLONG_MAX, diff2 = LLONG_MAX;
            if(idxLo >= 0) diff1 = num - v[idxLo];
            if(idxHi < v.size()) diff2 = v[idxHi] - num;
            ans += min(diff1, diff2) / 2;
        }
        return ans;
    }
};
