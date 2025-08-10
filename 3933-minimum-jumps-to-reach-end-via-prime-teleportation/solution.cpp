class Solution {
public:
    // MLE due to too many edges, thus checked the solution and found that we should not pre-build the whole edges vector.
    vector<bool> isPrime = vector<bool>(1e6 + 1, true);
    
    void findPrime(int maxKey) {
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= maxKey; i++) {
            if(!isPrime[i]) continue;
            for(int j = i * i; j <= maxKey; j += i) isPrime[j] = false;
        }
    }

    void bfs(int maxKey, unordered_map<int, vector<int>> &mp, vector<int> &nums, vector<int> &dist) {
        int n = nums.size();

        queue<int> q;
        dist[0] = 0;
        q.push(0);
    
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            if (u == n - 1) break;
    
            vector<int> edges;
            if(u > 0) edges.push_back(u - 1);
            if(u < n - 1) edges.push_back(u + 1);

            if(isPrime[nums[u]]) {
                for (int i = nums[u]; i <= maxKey; i += nums[u]) {
                    if(mp.contains(i)) {
                        for (int x : mp[i]) {
                            if (abs(x - u) > 1) edges.push_back(x);
                        }
                    }
                }
            }
            
            for (int v : edges) {
                if (dist[v] == INT_MAX) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    int minJumps(vector<int>& nums) {
        int n = nums.size(), maxKey = -1;
        unordered_map<int, vector<int>> mp;
        for(int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            mp[x].push_back(i);
            maxKey = max(maxKey, x);
        }

        findPrime(maxKey);
        vector<int> dist(n, INT_MAX);
        bfs(maxKey, mp, nums, dist);
        return dist[n - 1];
    }
};
