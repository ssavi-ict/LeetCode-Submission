// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:

    int findParent(int stone, vector<int> & parentStone){
        if(parentStone[stone] == stone) return stone;
        return parentStone[stone] = findParent(parentStone[stone], parentStone);
    }

    void makeUnion(int stone_a, int stone_b, vector<int> & parentStone){
        int parent_a = findParent(stone_a, parentStone);
        int parent_b = findParent(stone_b, parentStone);
        if(parent_a != parent_b){
            parentStone[parent_b] = parent_a; 
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = stones.size();
        vector<int>parentStone(n);
        for(int i=0; i<n; i++) parentStone[i] = i;

        int counter = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n && i!=j; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    makeUnion(i, j, parentStone);
                }
            }
        }
        for(int i=0; i<n; i++) counter += (parentStone[i] == i);
        return n - counter;
    }
};