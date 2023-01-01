// https://leetcode.com/problems/stamping-the-sequence

class Solution {
public:
   vector<int> movesToStamp(string stamp, string target) {
	int NS = stamp.size(), NT = target.size(), totChange = 0;
    if(set<char>{stamp.begin(),stamp.end()} != set<char>{target.begin(),target.end()}) return {};
	vector<int> ans;
	bool has_match = true;
	while(has_match) {
		has_match = false;
		for(int i=0;i<=NT-NS;i++) {
			bool ok = true;
			int num_dot = 0;
            int changeable = 0 ;
			for(int j=0;j<NS;j++) { 
				if(target[i+j]=='.')num_dot++; 
				else{
                    if(stamp[j]!=target[i+j]){
                        ok=false;
                        break;
                    }
                    else changeable++;
				}
			}
			if(ok && num_dot<NS) {
				has_match = true;
				ans.push_back(i);
				for(int j=0;j<NS;j++) target[i+j]='.';
                totChange += changeable;
			}
		}

	}
	for(char a:target)if(totChange != NT)return {};
	reverse(ans.begin(),ans.end());
	return ans;
}
};