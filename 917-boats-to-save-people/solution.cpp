class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int ans = 0, i = 0, j = n - 1;
        sort(people.begin(), people.end());
        while(i <= j) {
            ans++;
            if(i == j) break;
            if(people[i] + people[j] <= limit) i++, j--;
            else j--;
        }
        return ans;
    }
};
