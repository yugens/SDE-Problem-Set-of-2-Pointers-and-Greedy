//Brute force approach having time complexity o(n^3logm) and space complexity o(m)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> v;
        int n=nums.size();
        if(n<3)
        return ans;
       
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        sort(v.begin(),v.end());
                        st.insert(v);
                        v.clear();
                    }
                }
            }
        }
        for(auto it: st)
            ans.push_back(it);
        return ans;
    }
};

//Better Approach having time complexity o(n^2logm) and space complexity o(m)+o(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        if(n<3)
            return ans;
        set<vector<int>> st;
        map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]--;
            for(int j=i+1;j<n;j++)
            {
               mp[nums[j]]--;
               int ele=-(nums[i]+nums[j]);
               auto it=mp.find(ele);
               if(it!=mp.end() and it->second>0)
               {
                   v.push_back(nums[i]);
                   v.push_back(nums[j]);
                   v.push_back(ele);
                   sort(v.begin(),v.end());
                   st.insert(v);
                   v.clear();
               }
               mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        for(auto it:st)
            ans.push_back(it);
        return ans;
        
    }
};

//Optimes aproach having time complexity o(n^2) and space complexity o(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(n<3)
            return ans;
        for(int i=0;i<n-2;i++)
        {
            if(i==0 or (i>0 and nums[i]!=nums[i-1]))
            {
                int l=i+1,h=n-1,sum=0-nums[i];
                while(l<h)
                {
                    if(nums[l]+nums[h]==sum)
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[l]);
                        v.push_back(nums[h]);
                        ans.push_back(v);
                    
                        while(l<h and nums[l]==nums[l+1])
                            l++;
                        while(l<h and nums[h]==nums[h-1])
                            h--;
                        l++;
                        h--;
                    }
                    else if(nums[l]+nums[h]<sum)
                        l++;
                    else
                        h--;
                }
            }
        }
        return ans;
    }
};
