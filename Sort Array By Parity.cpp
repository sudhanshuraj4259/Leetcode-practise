class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result(nums.size());

       for(int num: nums){
           if(num % 2 == 0) {
               result[left] = num;
               left++;
           }
           else {
               result[right] = num;
               right --;
           }
       }
        return result;
    }
};
