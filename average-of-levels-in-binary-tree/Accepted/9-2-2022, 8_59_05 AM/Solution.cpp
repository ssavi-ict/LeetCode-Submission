// https://leetcode.com/problems/average-of-levels-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>myQ;
        myQ.push(root);
        while(!myQ.empty()){
            long long sum = 0;
            int count = 0;
            int sz = myQ.size();
            while(sz--){
                auto top = myQ.front();
                sum += top->val;
                count++;
                if(top->left) myQ.push(top->left);
                if(top->right) myQ.push(top->right);
                myQ.pop();
            }
            ans.push_back((sum*1.0)/count);
        }
        return ans;
    }
};