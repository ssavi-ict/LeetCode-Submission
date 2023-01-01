// https://leetcode.com/problems/path-sum-iv

class Solution {
public:
    map<pair<int, int>, int> tree; //{level, position} - val
    int sum = 0;
    
    void DFS(int level, int pos, int pathsum = 0)
    {
        if(tree.find({level+1, pos<<1}) == tree.end() && tree.find({level+1, 1+(pos<<1)}) == tree.end()){
            sum += (pathsum + tree[{level, pos}]);
            return;
        }
        
        if(tree.find({level+1, pos<<1}) != tree.end())
            DFS(level+1, pos<<1, pathsum+tree[{level, pos}]);
        
        if(tree.find({level+1, 1+(pos<<1)}) != tree.end())
            DFS(level+1, 1+(pos<<1), pathsum+tree[{level, pos}]);
    }
    
    int pathSum(vector<int>& nums) {
        
        for(int num : nums){
            int val = num % 10;
            num /= 10;
            int pos = num % 10;
            num /= 10;
            int level = num;
            tree[{level, pos-1}] = val;
        }
        
        DFS(1, 0);
        
        return sum;
    }
};