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
    int bs(int target, MountainArray &mountainArr, int l, int r, bool rev) {
        while(l < r) {
            int m = l + (r - l) / 2;
            if(mountainArr.get(m) == target) return m;
            if(rev) {
                if(mountainArr.get(m) > target) l = m + 1;
                else r = m;
            } else {
                if(mountainArr.get(m) < target) l = m + 1;
                else r = m;
            }
        }
        return l;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(m + 1 < n && mountainArr.get(m) < mountainArr.get(m + 1)) {
                l = m + 1;
            } else r = m;
        }
        int mid = l;
        int i1 = bs(target, mountainArr, 0, mid, false);
        if(mountainArr.get(i1) == target) return i1;
        int i2 = bs(target, mountainArr, mid + 1, n - 1, true);
        if(mountainArr.get(i2) == target) return i2;
        return -1;
    }
};
