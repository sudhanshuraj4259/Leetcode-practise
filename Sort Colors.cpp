class Solution {
public:
    void sortColors(vector<int>& nums) {
        //using counting sort
        int maxm = *max_element(nums.begin(),nums.end());//o(n)
        vector<int>frequency(maxm+1 , 0);
        for(int i = 0 ; i < nums.size() ; i++){      //O(n)
            frequency[nums[i]]++;
        }
        int i = 0 ; int j = 0;
        while( i < maxm+1) {                 //O(m) m=n in this case
            if(frequency[i]>0){
                nums[j++]=i;
                frequency[i]--;
            }
            else
            i++;
        }
    }
};
