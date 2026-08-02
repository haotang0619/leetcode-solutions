class MovieRentingSystem {
public:
    int maxMv = 1e4;
    vector<unordered_map<int, int>> prices; // movie => shop => price
    vector<set<pair<int, int>>> rented, unrented; // movie => [price, shop]
    set<tuple<int, int, int>> allRented; // [price, shop, movie]
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        prices.resize(maxMv + 1), rented.resize(maxMv + 1), unrented.resize(maxMv + 1);
        for(auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            prices[movie][shop] = price;
            unrented[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        auto it = unrented[movie].begin();
        while(ans.size() < 5 && it != unrented[movie].end()) {
            ans.push_back((*it).second);
            it++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = prices[movie][shop];
        unrented[movie].erase({price, shop});
        rented[movie].insert({price, shop});
        allRented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = prices[movie][shop];
        rented[movie].erase({price, shop});
        unrented[movie].insert({price, shop});
        allRented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        auto it = allRented.begin();
        while(ans.size() < 5 && it != allRented.end()) {
            auto& [price, shop, movie] = *it;
            ans.push_back({shop, movie});
            it++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
