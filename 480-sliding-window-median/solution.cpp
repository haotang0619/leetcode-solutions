class SlidingMedium {
public:
    int k;
    multiset<int> s1, s2;

    SlidingMedium(int K) {
        k = K;
    }

    void insert(int& num) {
        if(s1.size() < ceil((double)k / 2)) s1.insert(num);
        else {
            auto last = *prev(s1.end());
            if(num > last) s2.insert(num);
            else {
                s1.erase(prev(s1.end()));
                s1.insert(num), s2.insert(last);
            }
        }
    }

    void erase(int& num) {
        auto last = *prev(s1.end());
        if(num <= last) {
            s1.erase(s1.find(num));
            if(s2.size() > 0) {
                auto first = *s2.begin();
                s2.erase(s2.begin());
                s1.insert(first);
            }
        } else s2.erase(s2.find(num));
    }

    double getMedium() {
        if(k % 2 == 1) return *prev(s1.end());
        return ((double)*prev(s1.end()) + *s2.begin()) / 2;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        SlidingMedium sm(k);
        vector<double> ans;
        for(int i = 0; i < nums.size(); i++) {
            sm.insert(nums[i]);
            if(i >= k) sm.erase(nums[i - k]);
            if(i >= k - 1) ans.push_back(sm.getMedium());
        }
        return ans;
    }
};
