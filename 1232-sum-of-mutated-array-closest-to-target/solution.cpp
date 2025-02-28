class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        pair<int, int> tmp = {INT_MAX, INT_MAX};
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int avg = target / size;
        int dist1 = abs((size * (avg + 1)) - target);
        if(dist1 <= tmp.second) tmp = {avg + 1, dist1};
        int dist2 = abs((size * avg) - target);
        if(dist2 <= tmp.second) tmp = {avg, dist2};
        
        if(arr[0] > tmp.first) return tmp.first;

        pair<int, int> p = {INT_MAX, INT_MAX};
        int sum = 0;
        for(int i = 0; i < size - 1; i++) {
            sum += arr[i];
            int diff = target - sum;
            int size1 = (size - i - 1);
            int curr = diff / size1;
            if(curr + 1 < arr[i]) break;
            
            int dist1 = abs((size1 * min((curr + 1), arr[i + 1]) + sum) - target);
            if(dist1 <= p.second) p = {min((curr + 1), arr[i + 1]), dist1};
            int dist2 = abs((size1 * min(curr, arr[i + 1]) + sum) - target);
            if(dist2 <= p.second) p = {min(curr, arr[i + 1]), dist2};
        }
        return p.first;
    }
};
