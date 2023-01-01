// https://leetcode.com/problems/statistics-from-a-large-sample

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double>samples;
        int maxSample = INT_MIN, minSample = INT_MAX, sampleCount = 0, totalValue = 0;
        int maxSampleValue = 0, modeValue;
        for(int i=0; i<256; i++){
            if(count[i] > 0){
                totalValue += (i * count[i]);
                sampleCount += count[i];
                maxSample = max(maxSample, i);
                minSample = min(minSample, i);
                if(maxSampleValue < count[i]){
                    maxSampleValue = count[i];
                    modeValue = i;
                }
            }
        }
        double meanValue = totalValue / (sampleCount * 1.0);
        int last = 0, to_limit = 0;
        double medianValue;
        for(int i=0; i<256; i++){
            if(count[i] > 0){
                if(to_limit + count[i] > (sampleCount /2 )){
                    int remain = (sampleCount /2) - to_limit;
                    if(sampleCount & 1){
                        medianValue = i * 1.0;
                    }
                    else{
                        if(remain < 1){
                            medianValue = (last + i) / 2.0;
                        }
                        else{
                            medianValue = i * 1.0;
                        }
                    }
                    break;
                }
                to_limit += count[i];
                last = i;
            }
        }
        return {minSample*1.0, maxSample*1.0, meanValue, medianValue, modeValue*1.0};
    }
};