class AuctionSystem {
public:
    unordered_map<int, unordered_map<int, int>> mp1; // itemId => [userId, amount]
    unordered_map<int, set<pair<int, int>>> mp2; // itemId => [-amount, -userId]

    AuctionSystem() {}
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(mp1[itemId].contains(userId)) {
            mp2[itemId].erase({-mp1[itemId][userId], -userId});
        }
        mp1[itemId][userId] = bidAmount;
        mp2[itemId].insert({-mp1[itemId][userId], -userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        mp2[itemId].erase({-mp1[itemId][userId], -userId});
        mp1[itemId][userId] = newAmount;
        mp2[itemId].insert({-mp1[itemId][userId], -userId});
    }
    
    void removeBid(int userId, int itemId) {
        mp2[itemId].erase({-mp1[itemId][userId], -userId});
        mp1[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if(mp2[itemId].size() == 0) return -1;
        return -(*mp2[itemId].begin()).second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
