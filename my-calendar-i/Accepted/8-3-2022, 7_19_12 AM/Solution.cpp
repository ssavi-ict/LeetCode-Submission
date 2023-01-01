// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    set<pair<int, int>>bookings;
    MyCalendar() {
        bookings.clear();
    }
    
    bool book(int start, int end) {
        auto range = bookings.lower_bound(make_pair(start, end));
        if((range!=bookings.end() && end>range->first) ||(range!=bookings.begin() && start<prev(range)->second))
            return false;
        bookings.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */