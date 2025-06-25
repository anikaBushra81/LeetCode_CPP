class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums2.begin(),nums2.end());
        long long low=-1e10,high=1e10;
        while(low<high)
        {
            long long mid=low+(high-low)/2;
            if(countPairs(nums1,nums2,mid)<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
        
    }

    long long countPairs(vector<int>&A,vector<int>&B,long long x)
    {
        long long count=0;
        int m=A.size(),n=B.size();

        for(int i=0;i<m;i++)
        {
            long a=A[i];

            if(a>0)
            {
                long long target=floor_div(x,a);

                count+=upper_bound(B.begin(),B.end(),target)-B.begin();

            }
            else if(a<0)
            {
                long long target=ceil_div(x,a);
                
                count+=B.end()-lower_bound(B.begin(),B.end(),target);
            }
            else
            {
                if(x>=0)
                {
                    count+=n;
                }
            }
        }
        return count;
    }

    long long ceil_div(long long a,long long b)
    {
        if(b>0)
        {
            return a/b+((a%b)>0);
        }
        else
        {
            return a/b+((a%b)<0);
        }
    }

    long long floor_div(long long a,long long b)
    {
        if(b>0)
        {
            return a/b-((a%b)<0);
        }
        else
        {
            return a/b-((a%b)>0);
        }
    }
};
