// https://leetcode.com/problems/queue-reconstruction-by-height

class Solution {
public:
    
    struct comp{
        bool operator()(pair<int, int>&a, pair<int, int>&b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector< pair<int, int> >human, ans;
        int tall = 0;
        for(int i=0; i<n; i++){
            human.push_back(make_pair(people[i][0], people[i][1]));
        }
        sort(human.begin(), human.end(), comp());
        
        for(int i=0; i<human.size(); i++){
            int p_front = human[i].second;
            int pos = 0;
            for(int j=0; j<ans.size() && p_front>0; j++){
                if(ans[j].first>=human[i].first){
                    pos = j+1; p_front--;
                }
            }
            // cout<<pos<<' '<<ans.size()<<endl;
            ans.insert(ans.begin()+pos, make_pair(human[i].first, human[i].second));
        }
        
        
        for(int i=0, j=0; i<ans.size(); i++, j++){
            people[i][0] = ans[i].first;
            people[i][1] = ans[i].second;
        }
        
        return people;
    }
};