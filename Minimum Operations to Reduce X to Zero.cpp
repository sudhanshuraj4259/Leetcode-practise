class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> prefix={nums[0]};
        for(int i=1; i<n; i++){
        //    cout<<prefix[i-1]<<endl;
            if (prefix[i-1]>=x) break;
            prefix.push_back(prefix[i-1]+nums[i]);
        }
        int sz=prefix.size();
    //    cout<<"sz="<<sz<<endl;
        int idx=lower_bound(prefix.begin(), prefix.end(), x)-prefix.begin();
        int ans=INT_MAX;
        if (idx!=sz && prefix[idx]==x){
            ans=idx+1;
        //    cout<<"x="<<x<<" idx="<<idx<<" ans="<<ans<<endl;
        }
        for(int j=n-1; j>=0; j--){
            x-=nums[j];
            if (x<0) break;
            if (x==0) ans=min(ans, (n-j));
            idx=lower_bound(prefix.begin(), prefix.end(), x)-prefix.begin();
            if (idx<j && prefix[idx]==x){//idx<j very important
            //    cout<<"x="<<x<<" idx="<<idx<<" ans="<<idx+(n-j)+1<<endl;
                ans=min(ans, idx+1+(n-j));
            } 
        }
        return ans==INT_MAX?-1:ans;
    }
};
