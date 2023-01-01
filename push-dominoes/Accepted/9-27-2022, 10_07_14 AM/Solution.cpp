// https://leetcode.com/problems/push-dominoes

class Solution {
public:
    string pushDominoes(string dominoes) {
        int pidx = 0;
        int start = 0, end = 0;
        int n = dominoes.size();
        for(int i=0; i<n; i++){
            end = i;
            if(dominoes[i] != '.'){
                start = pidx;
                // cout<<dominoes<<' '<<start<<' '<<end<<endl;
                
                if(start<n && end>=0 && dominoes[start] == 'L' && dominoes[end] == 'L'){
                    while(end>=0 && start <= end){
                        dominoes[end--] = 'L';
                    }
                }
                else if(start<n && end>=0 && dominoes[start] == 'R' && dominoes[end] == 'R'){
                    while(start < n && start < end){
                        dominoes[start++] = 'R';
                    }
                }
                else if(start<n && end>=0 && dominoes[start] == 'R' && dominoes[end] == 'L'){
                    while(start < end){
                        dominoes[start++] = 'R';
                        dominoes[end--] = 'L';
                    }
                }
                else if(start<n && end>=0 && dominoes[start] == '.' && dominoes[end] == 'L'){
                    while(end>=0 && start <= end){
                        dominoes[end--] = 'L';
                    }
                }
                else if(start<n && end>= 0 && dominoes[end] == '.' && dominoes[start] == 'R'){
                    while(start<n && start <= end){
                        dominoes[start++] = 'R';
                    }
                }
                pidx = i;
            }
        }
        // cout<<"p "<<dominoes<<endl;
        // cout<<start<<' '<<end<<endl;
        start = pidx;
        if(start<n && end>= 0 && dominoes[end] == '.' && dominoes[start] == 'R'){
            while(start<n && start <= end){
                dominoes[start++] = 'R';
            }
        }
        // cout<<"q "<<dominoes<<endl;
        return dominoes;
    }
};