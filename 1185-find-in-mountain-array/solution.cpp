/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(m + 1 >= n || mountainArr.get(m) >= mountainArr.get(m + 1)) r = m;
            else l = m + 1;
        }
        if(mountainArr.get(l) == target) return l;
        int l1 = 0, r1 = l;
        while(l1 < r1) {
            int m = l1 + (r1 - l1) / 2;
            if(mountainArr.get(m) >= target) r1 = m;
            else l1 = m + 1;
        }
        if(mountainArr.get(l1) == target) return l1;
        int l2 = l, r2 = n - 1;
        while(l2 < r2) {
            int m = l2 + (r2 - l2) / 2;
            if(mountainArr.get(m) <= target) r2 = m;
            else l2 = m + 1;
        }
        return mountainArr.get(l2) == target ? l2 : -1;
    }
};
