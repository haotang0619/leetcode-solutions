class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int& a, int& b) {
            return ratings[a] < ratings[b];
        });
        for(auto &i : indices) {
            if(i - 1 >= 0 && ratings[i - 1] > ratings[i]) {
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
            }
            if(i + 1 < n && ratings[i + 1] > ratings[i]) {
                candies[i + 1] = max(candies[i + 1], candies[i] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
