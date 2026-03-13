class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long l = 0, r = 1e18;
        
        while(l < r){
            long long mid = l + (r - l) / 2;
            
            long long total = 0;
            
            for(long long w : workerTimes){
                long long val = mid / w;
                
                long long x = (sqrt(1 + 8.0 * val) - 1) / 2;
                
                total += x;
                if(total >= mountainHeight) break;
            }
            
            if(total >= mountainHeight)
                r = mid;
            else
                l = mid + 1;
        }
        
        return l;
    }
};