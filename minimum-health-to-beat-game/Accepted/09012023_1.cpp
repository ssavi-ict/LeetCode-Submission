long long minimumHealth(vector<int>& A, int armor) {
    long long sum = 0, maxVal = 0;
    int n = A.size();
    for(int i=0; i<n; i++){
        sum += A[i];
        if(A[i] <= armor){
            maxVal = max(maxVal, (long long)A[i]);
        }
    }
    return (sum - maxVal + 1);
}