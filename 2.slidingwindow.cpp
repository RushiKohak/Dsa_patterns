
//LC 209. Minimum Size SubarraySum - medium - variable window


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int sum = 0;
        int n = nums.size();
        int res = INT_MAX;

        for (int high = 0; high < n; high++)
        {
            sum = sum + nums[high];

            while (sum >= target)
            {
                res = min(res, high - low + 1);

                sum = sum - nums[low];
                low++;
            }
        }

        if (res == INT_MAX)
            return 0;

        return res;
    }
};

//#Longest Substring with K Uniques
//Difficulty: Medium

int longestkSubstring(String & s,int k){
    int low=0;
    int res=INT_MIN;
    int n =s.size();

    unordered_map<char,int>f;
    for(int high=0;high<n;high++){
        f[s[high]]++;
        int siz=f.size();
        while(f.size()>k){  //shrink
            f[s[low]]--;
            low++;
            if(f[s[low-1]]==0)
                f.erase(s[low-1]);
        }  
        //now it can be less or equal
        if(f.size()==k){
            int len=high-low+1;
            res=max(res,len);
        }

    }
    if(res==INT_MIN){
        return -1;
        
    }
    return res;
}
