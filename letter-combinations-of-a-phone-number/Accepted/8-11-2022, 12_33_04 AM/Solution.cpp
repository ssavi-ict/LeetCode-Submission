// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    void assignment(vector<string> & mapped){
  mapped.push_back("");  // 0
  mapped.push_back("");  // 1
  mapped.push_back("abc"); // 2
  mapped.push_back("def");
  mapped.push_back("ghi");
  mapped.push_back("jkl");
  mapped.push_back("mno");
  mapped.push_back("pqrs");
  mapped.push_back("tuv");
  mapped.push_back("wxyz"); // 9
}

vector<string> letterCombinations(string digits) {
  vector<string>mapped;
  assignment(mapped);
  
  vector<string>ans, tmp;
  
  bool first = true;
  for(int i=size(digits)-1; i>=0; i--){
    int idx = digits[i] - '0';
    string key = mapped[idx];
    
    ans.clear();
    if(first){
      first = false;
      for(int j=0; j<key.size(); j++){
          string in = "";
        in = in + key[j];
        ans.push_back(in);
      }
    }
    else{
      for(int j=0; j<size(key); j++){
        for(int k=0; k<tmp.size(); k++){
          string in = key[j] + tmp[k];
          ans.push_back(in);
        }
      }
    }
    tmp.clear();
    tmp = ans;
  }
  return ans;
}
};