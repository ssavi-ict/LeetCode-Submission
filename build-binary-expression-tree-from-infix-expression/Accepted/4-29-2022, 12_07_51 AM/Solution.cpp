// https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression

/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<char, int> signedPrior;
    
    Node* FuN(string &s, int l, int r)
    {
        Node* curr = NULL;
        if(l == r) {
            curr = new Node(s[l]);
            return curr;
        }
        
        long long partitionIdx = 1e9, mnPrior = 1e9, openBracket = 0, num = 0;
        
        for(int i=l ; i<=r ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                continue;
            }
            else if(s[i] == '(')
                openBracket++;
            else if(s[i] == ')')
                openBracket--;
            else if(!openBracket){
                if(signedPrior[s[i]] <= mnPrior){
                    mnPrior = signedPrior[s[i]];
                    partitionIdx = i;
                }
            }
        }
        
        if(mnPrior == 1e9 && s[l] == '(' && s[r] == ')')
            return FuN(s, l+1, r-1);
        else{
            curr = new Node(s[partitionIdx]);
            curr->left = FuN(s, l, partitionIdx-1);
            curr->right = FuN(s, partitionIdx+1, r);
            return curr;
        }
    }
    
    
    Node* expTree(string s) {
        int n = s.size();
        signedPrior['+'] = 1;
        signedPrior['-'] = 2;
        signedPrior['/'] = 3;
        signedPrior['*'] = 4;
        return FuN(s, 0, n-1);
    }
};