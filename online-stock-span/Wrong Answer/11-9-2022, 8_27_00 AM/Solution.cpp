// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    multiset<int>prices;
    StockSpanner() {
        prices.clear();
    }
    
    int next(int price) {
        prices.insert(price);
        return distance(prices.begin(), prices.lower_bound(price)) + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */