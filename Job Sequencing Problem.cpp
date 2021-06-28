//Best Approach having time complexity o(nlogn)+o(n*m) and space complexity o(m)
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job a,Job b)
    {
        return (a.profit>b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comparator);
        int maxi=arr[0].dead;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        vector<int> v(maxi+1,-1);
        //memset(v,-1,sizeof(v));
        int jobcount=0,jobprofit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(v[j]==-1)
                {
                v[j]=i;
                jobcount++;
                jobprofit+=arr[i].profit;
                break;
                }
            }
        }
        return {jobcount,jobprofit};
    } 
};

