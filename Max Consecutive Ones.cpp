//Best Aproach having time complexity o(n) and space complexity o(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,maxum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                cnt++;
                maxum=max(maxum,cnt);
            }
            else
                cnt=0;
        }
        return maxum;
        
    }
};
