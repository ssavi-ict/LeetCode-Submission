// https://leetcode.com/problems/dot-product-of-two-sparse-vectors

class SparseVector {
public:
    unordered_map<int, int>sparse;
    SparseVector(vector<int> &nums) {
        for(int i=0; i<size(nums); i++){
            if(nums[i]) sparse[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int num = 0;
        for(auto it:this->sparse){
            if(vec.sparse.count(it.first)){
                num += (this->sparse[it.first] * vec.sparse[it.first]);
            }
        }
        return num;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);