class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0, p2 = height.size() - 1;
        int ans = -1;
        while (p1 < p2) {
            ans = max(ans, (p2 - p1) * min(height[p1], height[p2]));
            if (height[p1] < height[p2]) p1++;
            else if (height[p1] > height[p2]) p2--;
            else p1++, p2--;
        }
        return ans;
    }
};
