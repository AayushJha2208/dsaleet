class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=0,k=n-1;
            while(j<k){
                if(j==i){
                    j++;
                    continue;
                }
                if(k==i){
                    k--;
                    continue;
                }
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    if(i<j) s.insert({nums[i],nums[j],nums[k]});
                    else if(i>k) s.insert({nums[j],nums[k],nums[i]});
                    else s.insert({nums[j],nums[i],nums[k]});
                    j++;
                    k--;
                    continue;
                }
                if(sum<0) j++;
                else k--;
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};