class Solution {
public:
    long long findCnt(vector<int>& candies, int n) {
        long long cnt = 0;
        for(auto &x : candies) cnt += (x / n);
        return cnt;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int maxC = *max_element(candies.begin(), candies.end());
        int left = 1, right = maxC + 1;
        while(left < right) {
            int mid = (left + right) / 2;
            long long cnt1 = findCnt(candies, mid);
            long long cnt2 = findCnt(candies, mid + 1);
            if(cnt1 >= k && (cnt2 < k || mid == maxC)) return mid;
            if(cnt1 >= k) left = mid + 1;
            else if(mid == 1) return 0;
            else right = mid;
        }
        return left;
    }
};
