// https://leetcode.com/problems/symmetric-tree

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
    vector<pair<int, char>>store[1001];  // Left = 'l', Right = 'r'
int mxlvl;

void solve(TreeNode * root, int lvl, char direction){
  if(!root){
    store[lvl].push_back(make_pair(1001, 'n'));
    return;
  }
  mxlvl = max(mxlvl, lvl);
  if(direction == 'l' || direction=='r'){
    store[lvl].push_back(make_pair(root->val, direction));
  }
solve(root->left, lvl+1, 'l');
solve(root->right, lvl+1, 'r');
  
}

bool isSymmetric(TreeNode* root) {
  mxlvl = 0;
  solve(root, 0, 'a');
  for(int i=1; i<=mxlvl; i++){
    int size = store[i].size();
    if(size%2) return false;
    for(int j=0; j<size/2; j++){
      int val = store[i][j].first, rev = store[i][size-j-1].first;
      char ore1 = store[i][j].second, ore2 = store[i][size-j-1].second;
      if(ore1 == 'n' && ore2=='n'){
        ;
      }
      else if(ore1=='l' && ore2=='r' && val==rev){
        ;
      }
      else if(ore1=='r' && ore2=='l' && val==rev){
        ;
      }
      else return false;
    }
  }
  return true;
}
};