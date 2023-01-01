// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    priority_queue<int>first_half;
    priority_queue<int, vector<int>, greater<int>>second_half;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        first_half.push(num);
        int fqsize = first_half.size(), sqsize = second_half.size();
        int total = fqsize + sqsize;
        // cout<<"L "<<fqsize<<' '<<sqsize<<endl;
        while((fqsize - sqsize) != ((total) & 1) && fqsize >= sqsize){
            second_half.push(first_half.top()); first_half.pop();
            fqsize = first_half.size(), sqsize = second_half.size();
        }
        // cout<<"E "<<fqsize<<' '<<sqsize<<endl;
        if(fqsize && sqsize){
            int ftop = first_half.top(), stop = second_half.top();
            // cout<<ftop<<' '<<stop<<endl;
            if(ftop > stop){
                first_half.pop(), second_half.pop();
                first_half.push(stop), second_half.push(ftop);
            }
        }
    }
    
    double findMedian() {
        int fqsize = first_half.size(), sqsize = second_half.size();
        if((fqsize + sqsize) & 1) return first_half.top() * 1.0;
        else{
            double sum = first_half.top() * 1.0 + second_half.top() * 1.0;
            return sum / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */