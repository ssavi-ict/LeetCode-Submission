// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    int tree[30000*3];
    
    void update(int node, int b, int e, int pos, int val){
        if(pos>e || pos<b) return;
        if(b>=pos && e<=pos){
            tree[node] = val;
            return;
        }
        int left = node * 2;
        int right = node * 2 + 1;
        int mid = (b + e) / 2 ;
        update(left, b, mid, pos, val);
        update(right, mid+1, e, pos, val);
        tree[node] = tree[left] + tree[right];
    }
    
    int query(int node, int b, int e, int l, int r){
        if(r<b || l>e) return 0;
        if(b>=l && e<=r) return tree[node];
        int left = node * 2;
        int right = node * 2 + 1;
        int mid = (b + e) / 2;
        int sum = query(left, b, mid, l, r) + query(right, mid+1, e, l, r);
        return sum;
    }
    
    int N;
    
    NumArray(vector<int>& nums) {
        memset(tree, 0, sizeof(tree));
        N = size(nums);
        for(int i=0; i<N; i++){
            update(1, 1, N, i+1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        update(1, 1, N, index+1, val);
    }
    
    int sumRange(int left, int right) {
        return query(1, 1, N, left+1, right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */