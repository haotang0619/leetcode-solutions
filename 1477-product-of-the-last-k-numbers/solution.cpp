class ProductOfNumbers {
public:
    vector<int> vi;
    ProductOfNumbers() {
        this->vi = {1};
    }
    
    void add(int num) {
        int size = this->vi.size();
        if(num == 0) this->vi = {1};
        else this->vi.push_back(num * this->vi[size - 1]);
    }
    
    int getProduct(int k) {
        int size = vi.size();
        if(k >= size) return 0;
        return this->vi[size - 1] / this->vi[size - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
