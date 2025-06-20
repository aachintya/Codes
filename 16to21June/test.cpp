class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        int lo = 0;
        int hi = 1e9;
        int ans = hi;
        auto check = [&](int mid){
            int pairs = 0;
            for(int i = 0; i < n; i++){
                if(nums[i + 1] - nums[i] <= mid){
                    pairs++;
                    i++;
                }
            }
            return pairs >= p;
        };
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(check(mid)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};