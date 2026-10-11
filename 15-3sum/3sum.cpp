class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> s;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1, k = n - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum == 0) {
                s.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
            else if (sum < 0) {
                j++;
            }
            else {
                k--;
            }
        }
    }
    return s;
}
};

// vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> s;
//         int n=nums.size();
//         for(int i=1;i<n-1;i++){
//             if(i>1 && i<n-2 && nums[i]==nums[i-1])continue;
//             int j=0,k=n-1;
//             while(j<i && i<k){
//                 int sum=nums[i]+nums[j]+nums[k];
//                 if(sum==0){
//                     if(s.empty() || !(s.back()[0]==nums[j] && 
//                     s.back()[1]==nums[i] &&
//                     s.back()[2]==nums[k])){
//                         s.push_back({nums[j],nums[i],nums[k]});
//                     }
//                     j++;
//                     k--;
//                     continue;
//                 }
//                 if(sum<0) j++;
//                 else k--;
//             }
//         }
//         return s;
//     }