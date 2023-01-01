// https://leetcode.com/problems/my-calendar-iii

class MyCalendarThree {
public:

    map<int, int>mymap;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mymap[start]++;
        mymap[end]--;
        int res = 0, ans = 0;
        for(auto slice: mymap){
            // cout<<slice.first<<' '<<slice.second<<endl;
            res += slice.second;
            ans = max(ans, res);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */