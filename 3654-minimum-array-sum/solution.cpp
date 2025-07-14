class Solution {
public:
    // Saw solutions
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        sort(nums.begin(), nums.end());
        int ans = 0, j = nums.size();
        // num >= 2 * k - 1
        // 1. Greedily apply all
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] >= 2 * k - 1) {
                if(op1 > 0) {
                    nums[i] = nums[i] / 2 + nums[i] % 2;
                    op1--;
                }
                if(op2 > 0) {
                    nums[i] -= k;
                    op2--;
                }
                ans += nums[i];
                j--;
            } else break;
        }

        // k <= num < 2 * k - 1
        // 2. Subtract k, and record the possible swappable indices
        set<int> candidates;
        int pos = j, swapCnt = 0;
        for(int i = 0; i < j; i++, pos = i) {
            if(op2 <= 0) break;
            if(nums[i] >= k) {
                if(k % 2 == 1 && nums[i] % 2 == 0) candidates.insert(i);
                nums[i] -= k;
                op2--;
            }
        }
        
        // 3. Greedily apply op1 in the middle
        for(int i = j - 1; i >= pos; i--) {
            if(op1 <= 0) break;
            if(nums[i] >= k) {
                if(k % 2 == 1 && nums[i] % 2 == 1) swapCnt++;
                nums[i] = nums[i] / 2 + nums[i] % 2;
                op1--;
            }
        }

        // 4. Greedily apply op1
        vector<pair<int, int>> v;
        for(int i = 0; i < pos; i++) v.push_back({nums[i], i});
        sort(v.begin(), v.begin() + pos, greater<pair<int, int>>());
        for(auto [num, i] : v) {
            if(op1 <= 0) break;
            nums[i] = nums[i] / 2 + nums[i] % 2;
            op1--;

            if(candidates.count(i) > 0 && swapCnt > 0) {
                swapCnt--;
                nums[i]--;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
