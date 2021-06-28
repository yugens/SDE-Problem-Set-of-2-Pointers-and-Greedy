//Best Aproach having time complexity o(2nlogn)+o(2n) and space complexity o(1)
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int plat=1,maxi=1;
    	int i=1,j=0;
    	while(i<n and j<n)
    	{
    	  if(arr[i]<=dep[j])
    	  {
    	      plat++;
    	      i++;
    	  }
    	  else
    	  {
    	       plat--;
    	       j++;
    	  }
    	  maxi=max(maxi,plat);
    	}
    	return maxi;
    }
};
