//Best Approach having time complexity o(nlogn) and space complexity o(n)
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting 
    {
        int s;
        int e;
        int pos;
    };
    static bool comparator(struct meeting m1,meeting m2)
    {
        if(m1.e<m2.e)
        return true;
        else if(m1.e>m2.e)
        return false;
        else if(m1.pos<m2.pos)
        return true;
        else
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        for(int i=0;i<n;i++)
        meet[i].s=start[i],meet[i].e=end[i],meet[i].pos=i+1;
        
        sort(meet,meet+n,comparator);
        
        vector<int> ans;
        int limit=meet[0].e;
        ans.push_back(meet[0].pos);
        for(int i=1;i<n;i++)
        {
            if(meet[i].s>limit)
            {
                limit=meet[i].e;
                ans.push_back(meet[i].pos);
            }
        }
        return ans.size();
        // Your code here
    }
};
