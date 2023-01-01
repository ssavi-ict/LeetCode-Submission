// https://leetcode.com/problems/erect-the-fence

class Solution {
public:

    int distance(pair<int, int>A, pair<int, int>B, pair<int, int>C){
        int x1 = A.first - B.first;
        int x2 = A.first - C.first;
        int y1 = A.second - B.second;
        int y2 = A.second - C.second;
        int distAB = (x1 * x1) + (y1 * y1);
        int distAC = (x2 * x2) + (y2 * y2);
        return distAB - distAC;
    }

    int crossProduct(pair<int, int>A, pair<int, int>B, pair<int, int>C){
        int x1 = A.first - B.first;
        int x2 = A.first - C.first;
        int y1 = A.second - B.second;
        int y2 = A.second - C.second;
        int crossProductValue = (x1 * y2) - (x2 * y1);
        return crossProductValue;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int startPoint = 0, n = trees.size();
        for(int i=1; i<n; i++){
            if(trees[i][0] < trees[startPoint][0]){
                startPoint = i;
            }
        }

        set<pair<int, int>>ans;
        vector<pair<int, int>>co_linear(n);
        ans.insert({trees[startPoint][0], trees[startPoint][1]});
        
        int currentPoint = startPoint;
        int count =  n;
        while(count--){
            int nextPoint = 0, cl_index = 0;
            // cout<<currentPoint<<endl;
            for(int i=1; i<n; i++){
                if(currentPoint == i) continue;
                int cpValue = crossProduct({trees[currentPoint][0], trees[currentPoint][1]}, {trees[nextPoint][0], trees[nextPoint][1]}, {trees[i][0], trees[i][1]});
                if(cpValue > 0){
                    nextPoint = i;
                    cl_index = 0;
                }
                else if(cpValue == 0){
                    int col_next = distance({trees[currentPoint][0], trees[currentPoint][1]}, {trees[nextPoint][0], trees[nextPoint][1]}, {trees[i][0], trees[i][1]});
                    if(col_next < 0){
                        co_linear[cl_index++] = {trees[nextPoint][0], trees[nextPoint][1]};
                        nextPoint = i;
                    }
                    else{
                        co_linear[cl_index++] = {trees[i][0], trees[i][1]};
                    }
                }
            }
            for(int j=0; j<cl_index; j++){
                ans.insert({co_linear[j].first, co_linear[j].second});
            }
            if(nextPoint == startPoint) break;
            ans.insert({trees[nextPoint][0], trees[nextPoint][1]});
            currentPoint = nextPoint;
        }
        trees.clear();
        for(auto it : ans){
            trees.push_back({it.first, it.second});
        }
        return trees;
    }
};












