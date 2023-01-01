// https://leetcode.com/problems/construct-string-from-binary-tree

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
    
    string ans;
    
    string to_str(int value){
        if(value == 0) return "0";
        int n = (value < 0) ? -value : value;
        string ret = "";
        while(n){
            ret += (n%10 + '0');
            n /= 10;
        }
        if(value < 0) ans += '-';
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    void solve(TreeNode * root){
        ans += to_str(root->val);
        if(root->left){
            ans += '(';
            solve(root->left);
            ans += ')';
        }
        if(root->right){
            if(!root->left){
                ans += '(';
                ans += ')';
            }
            ans += '(';
            solve(root->right);
            ans += ')';
        }
    }
    
    string tree2str(TreeNode* root) {
        ans = "";
        solve(root);
        return ans;
    }
};