// https://leetcode.com/problems/inorder-successor-in-bst-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node * answer = NULL;
    bool verdict = false;
    
    Node * getRoot(Node * root){
        if(!root->parent) return root;
        return getRoot(root->parent);
    }
    
    void traverse(Node *root, Node * target){
        if(!root) return;
        traverse(root->left, target);
        if(verdict){
            answer = root;
        }
        if(answer) return;
        if(target == root){
            verdict = true;
        }
        traverse(root->right, target);
    }
    
    Node* inorderSuccessor(Node* node) {
        if(!node) return nullptr;
        Node * root = getRoot(node);
        traverse(root, node);
        return answer;
    }
};