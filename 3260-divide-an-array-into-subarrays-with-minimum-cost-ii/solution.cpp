class MinElementsSum {
public:
    int size;
    long long sum = 0;
    multiset<int> ms1, ms2;
    
    MinElementsSum(int sz) {
        size = sz;
    }

    void insert(int num) {
        if(ms1.size() < size) ms1.insert(num), sum += num;
        else {
            int maxMin = *prev(ms1.end());
            if(num <= maxMin) {
                sum += num - maxMin;
                ms1.insert(num);
                ms1.erase(ms1.find(maxMin));
                ms2.insert(maxMin);
            } else ms2.insert(num);
        }
    }

    void remove(int num) {
        if(ms1.contains(num)) {
            sum -= num;
            ms1.erase(ms1.find(num));
            if(!ms2.empty()) {
                sum += *ms2.begin();
                ms1.insert(*ms2.begin());
                ms2.erase(ms2.begin());
            }
        } else ms2.erase(ms2.find(num));
    }
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans = LLONG_MAX;
        int n = nums.size();
        MinElementsSum mes(k - 2);
        for(int i = 1, j = 2; i < n - k + 2; i++) {
            // Get the sum of the minimum k - 2 elements in [i + 1, i + dist]
            if(i >= 2) mes.remove(nums[i]);
            while(j <= i + dist && j < n) mes.insert(nums[j++]);
            ans = min(ans, nums[0] + nums[i] + mes.sum);
        }
        return ans;
    }
};
