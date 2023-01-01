// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    stack<pair<int, int>>stockPrices;
    StockSpanner() {
        // while(!stockPrices.empty()) stockPrices.pop();
    }
    
    int next(int price) {
        int counter = 0;
        while(!stockPrices.empty() && stockPrices.top().first <= price){
            counter += stockPrices.top().second;
            // cout<<price<<' '<<counter<<endl;
            stockPrices.pop();
        }
        stockPrices.push(make_pair(price, counter + 1));
        return counter + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */