// https://leetcode.com/problems/logger-rate-limiter

class Logger {
public:
    unordered_map<string, int>mymap;
    Logger() {
        mymap.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mymap.find(message)==mymap.end()){
            mymap[message] = timestamp;
            return true;
        }
        if(timestamp - mymap[message] >= 10){
            mymap[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */