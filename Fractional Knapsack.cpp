//Greedy Approach having time complexity o(nlogn) + o(n) and space complexity o(1)


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comparator(Item a,Item b)
    {
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comparator);
        double curr=0,final=0.0;
        for(int i=0;i<n;i++)
        {
        if(curr+arr[i].weight<=W)
        {
            curr+=arr[i].weight;
            final+=arr[i].value;
        }
        else
        {
            int remain=W-curr;
            final+=((double)arr[i].value/(double)arr[i].weight)*(double)remain;
            break;
        }
        }
        return final;
    }
        
};
