class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(vector<int> &init) {
        n = init.size();
        tree.resize(4 * n);
        build(init, 1, 0, n - 1);
    }

    void build(vector<int> &init, int node, int l, int r) {
        if (l == r) {
            tree[node] = init[l];
        } else {
            int mid = (l + r) / 2;
            build(init, node * 2, l, mid);
            build(init, node * 2 + 1, mid + 1, r);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] += val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};

class Solution {
public:
    int getIdx(vector<int>& allY, int y) {
        return lower_bound(allY.begin(), allY.end(), y) - allY.begin();
    }

    // Asked GPT to learn how to use segment trees in this 2D scheme.
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        int n = xCoord.size();
        map<int, vector<int>> pointsOfX, pointsOfY; // To find adjacent points
        set<pair<int, int>> st; // To check if a point exist
        for(int i = 0; i < n; i++) {
            int x = xCoord[i], y = yCoord[i];
            pointsOfX[x].push_back(y);
            pointsOfY[y].push_back(x);
            st.insert({x, y});
        }
        vector<int> allY; // To discretize y values
        for(auto &[x, v] : pointsOfX) sort(v.begin(), v.end());
        for(auto &[y, v] : pointsOfY) {
            allY.push_back(y);
            sort(v.begin(), v.end());
        }
        vector<pair<int, int>> points; // To build segment trees
        for(auto p : st) points.push_back(p);
        
        map<int, int> idxOfX;
        vector<pair<pair<int, int>, pair<int, int>>> rect; // To save rectangles
        for(auto &[y, v] : pointsOfY) {
            for(int i = 0; i < v.size(); i++) {
                int x = v[i], idx = ++idxOfX[x];
                if(i + 1 >= v.size() || idx >= pointsOfX[x].size()) continue;
                int x1 = v[i + 1], y1 = pointsOfX[x][idx];
                pair<int, int> p1 = {x, y}, p2 = {x1, y1};
                if(st.contains(p2)) rect.push_back({p1, p2});
            }
        }
        
        map<pair<pair<int, int>, pair<int, int>>, int> ycnt;
        vector<int> init(allY.size(), 0);
        SegTree st1(init), st2(init);
        sort(rect.begin(), rect.end(), [](auto &a, auto &b) {
            return a.second.first < b.second.first;
        });
        int i = 0;
        for(auto rec : rect) {
            auto [x, y] = rec.first;
            auto [x1, y1] = rec.second;
            while(i < n && points[i].first <= x1) {
                int idx = getIdx(allY, points[i].second);
                st1.update(1, 0, st1.n - 1, idx, 1);
                i++;
            }
            ycnt[rec] = st1.query(1, 0, st1.n - 1, getIdx(allY, y), getIdx(allY, y1));
        }
        
        long long ans = -1;
        sort(rect.begin(), rect.end(), [](auto &a, auto &b) {
            return a.first.first < b.first.first;
        });
        i = 0;
        for(auto rec : rect) {
            auto [x, y] = rec.first;
            auto [x1, y1] = rec.second;
            while(i < n && points[i].first < x) {
                int idx = getIdx(allY, points[i].second);
                st2.update(1, 0, st2.n - 1, idx, 1);
                i++;
            }
            ycnt[rec] -= st2.query(1, 0, st2.n - 1, getIdx(allY, y), getIdx(allY, y1));
            if(ycnt[rec] == 4) ans = max(ans, (long long)(x1 - x) * (y1 - y));
        }
        return ans;
    }
};
