class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int, int> mp1;
        map<char, int> mp2;
        for(auto r : ranks) mp1[r]++;
        for(auto s : suits) mp2[s]++;
        for(auto [s, cnt] : mp2) {
            if(cnt == 5) return "Flush";
        }
        int maxCnt = 0;
        for(auto [r, cnt] : mp1) maxCnt = max(maxCnt, cnt);
        return maxCnt >= 3 ? "Three of a Kind" : (maxCnt >= 2 ? "Pair" : "High Card");
    }
};
