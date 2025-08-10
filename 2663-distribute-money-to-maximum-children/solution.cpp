class Solution {
public:
    int distMoney(int money, int children) {
        int maxNum = min(money / 8, children);
        while(maxNum >= 0) {
            int left = money - maxNum * 8;
            int leftChild = children - maxNum;
            cout << left << " " << leftChild << endl;
            if(left < leftChild) {
                maxNum--;
                continue;
            }
            left -= leftChild;
            if(left == 3 && leftChild == 1) {
                maxNum--;
                continue;
            }
            if(left > 0 && leftChild == 0) {
                maxNum--;
                continue;
            }
            return maxNum;
        }
        return -1;
    }
};
