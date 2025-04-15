#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n1=nums1.size();
        for(int i=0;i<n1;i++)
        {
            mp[nums1[i]]=i;
        }

        ordered_set s;
        long long total=0,n2=nums2.size();
        for(int i=0;i<n2;i++)
        {
            int index=mp[nums2[i]];
            int left=s.order_of_key(index);
            int right=(n2-1-index)-(s.size()-left);
            total+=(long long)left*right;
            s.insert(index);
        }
        return total;
        
    }
};