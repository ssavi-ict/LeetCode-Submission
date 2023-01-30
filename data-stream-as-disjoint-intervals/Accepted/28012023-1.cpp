class SummaryRanges {
public:
    set<int>myset;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        myset.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        int preValue = -1, curValue = -1;
        for(auto it=myset.begin(); it!=myset.end(); ++it){
            if(preValue == -1){
                preValue = curValue = *it; continue;
            }
            if((curValue + 1) == *it){
                curValue = *it;
            }
            else{
                ans.push_back({preValue, curValue});
                preValue = curValue = *it;
            }
        }
        ans.push_back({preValue, curValue});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */