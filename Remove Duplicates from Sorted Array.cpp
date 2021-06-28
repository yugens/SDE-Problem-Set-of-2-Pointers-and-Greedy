//Brute force Aproach having time complexity o(nlogn)+o(n) and space complexity o(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++)
            st.insert(nums[i]);
        int i=0;
        int k=st.size();
        for(auto it:st)
        {
           nums[i]=it;
            i++;
        }
        return k;
        
    }
};

//Optimed Aproach having time complexity o(n) and space complexity o(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return n;
        int i=0;
        int j=i+1;
        while(j<n)
        {
            if(nums[i]==nums[j])
                j++;
            else
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
