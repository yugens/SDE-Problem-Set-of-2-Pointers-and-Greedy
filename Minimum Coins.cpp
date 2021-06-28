//Greedy Approach having time complexity o(v) and space complexity o(1)
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    sort(coins,coins+M);
	    int count=0;
	    for(int i=M-1;i>=0;i--)
	    {
	        while(V>= coins[i])
	        {
	            V-=coins[i];
	             count++; 
	        }
	    }
	    return count;
	} 
	  
};
