class NumberContainers {
public:
    unordered_map<int, int> mp1;
    unordered_map<int, set<int>> mp2;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int old_num = mp1[index];
        mp1[index] = number;
        if (old_num > 0) mp2[old_num].erase(index);
        mp2[number].insert(index);
    }
    
    int find(int number) {
        int index = *(mp2[number].begin());
        return index == 0 ? -1 : index;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
