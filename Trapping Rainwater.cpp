//Brute force approach having time complexity o(n^2) and space complexity o(1)
class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
      int ans=0;
        for(int i=0;i<n;i++)
        {
            int maxleft=0,maxright=0;
            for(int j=i;j>=0;j--)
                 maxleft=max(maxleft,height[j]);
            for(int j=i;j<n;j++)
                 maxright=max(maxright,height[j]);
            int level=min(maxleft,maxright);
            ans+=level-height[i];  
        }
        return ans;
    }
};

//Better approach having time complexity o(3n) and space complexity o(2n)
class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
      if(n==0)
          return 0;
      int pre[n];
      int suf[n];
      int ans=0;
      pre[0]=height[0];
      suf[n-1]=height[n-1];
      for(int i=1;i<n;i++)
      {
          pre[i]=max(height[i],pre[i-1]);
      }
      for(int i=n-2;i>=0;i--)
      {
          suf[i]=max(height[i],suf[i+1]);
      }
      for(int i=0;i<n;i++)
      {
          int level=min(pre[i],suf[i]);
          ans+=level-height[i];
      }
       return ans;
    }
};

//Optimed approach having time complexity o(n) and space complexity o(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,leftmax=0,rightmax=0,ans=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
              if(height[l]>=leftmax)
                  leftmax=height[l];
              else
                  ans+=leftmax-height[l];
              l++;
            }
            else
            {
                if(height[r]>=rightmax)
                  rightmax=height[r];
                else
                  ans+= rightmax-height[r];
              r--;
            }
        }
        return ans;
        
    }
};
