// Written by myself
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        long long now = 0;
        int gap = k - 1, n = coins.size();
        int i = 0, j = 0, l = coins[0][0], r = l;
        
        // Find the 1st range
        while(j + 1 < n && l + gap >= coins[j + 1][0]) {
            now += (long long)coins[j][2] * (coins[j][1] - coins[j][0] + 1);
            j++;
        }
        r = min(l + gap, coins[j][1]);
        now += (long long)coins[j][2] * (r - coins[j][0] + 1);
        long long ans = now;

        while(j < n) {
            int diff1 = coins[i][1] - l, diff2 = coins[j][1] - r;
            if(diff1 > 0 && diff2 > 0) {
                // Move both ends
                int minDiff = min(diff1, diff2);
                now -= (long long)coins[i][2] * minDiff;
                now += (long long)coins[j][2] * minDiff;
                l += minDiff, r += minDiff;
                ans = max(ans, now);
            } else if(diff2 == 0) {
                // Move the right side to the next
                j++;
                if(j >= n) break;
                now += coins[j][2];
                r = coins[j][0];
                // Find the next valid left side
                if(coins[i][1] < r - gap) {
                    while(coins[i][1] < r - gap) {
                        now -= (long long)coins[i][2] * (coins[i][1] - l + 1);
                        l = coins[++i][0];
                    }
                    l = max(r - gap, coins[i][0]);
                    now -= (long long)coins[i][2] * (l - coins[i][0]);
                } else {
                    now -= (long long)coins[i][2] * (r - gap - l);
                    l = r - gap;
                }
                // Expand the right side according to the new left side
                if(j + 1 < n && l + gap >= coins[j + 1][0]) {
                    while(j + 1 < n && l + gap >= coins[j + 1][0]) {
                        now += (long long)coins[j][2] * (coins[j][1] - r);
                        r = coins[++j][0] - 1;
                    }
                    r = min(l + gap, coins[j][1]);
                    now += (long long)coins[j][2] * (r - coins[j][0] + 1);
                } else {
                    int nextR = min(l + gap, coins[j][1]);
                    now += (long long)coins[j][2] * (nextR - r);
                    r = nextR;
                }
                ans = max(ans, now);
            } else {
                // Move the left side to the next
                now -= coins[i][2];
                i++;
                if(i >= n) break;
                l = coins[i][0];
                // Expand the right side according to the new left side
                if(j + 1 < n && l + gap >= coins[j + 1][0]) {
                    while(j + 1 < n && l + gap >= coins[j + 1][0]) {
                        now += (long long)coins[j][2] * (coins[j][1] - r);
                        r = coins[++j][0] - 1;
                    }
                    r = min(l + gap, coins[j][1]);
                    now += (long long)coins[j][2] * (r - coins[j][0] + 1);
                } else {
                    int nextR = min(l + gap, coins[j][1]);
                    now += (long long)coins[j][2] * (nextR - r);
                    r = nextR;
                }
                ans = max(ans, now);
            }
        }
        return ans;
    }
};

// *From Discussions:*
//  One of the key part to understand is that the solution would either start at first element of some interval or end at last element of some interval. There won't be a case where solution would start in middle of some interval & also end in middle of some interval.
