class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int>::iterator it = nums.begin();
        int index = *it;
        int len = 1;
        if(it != nums.end()){
            ++it;
            while(it != nums.end()) {
                if(*it == index) {
                    it = nums.erase(it);
                } else {
                    ++len;
                    index = *it;
                    ++it;
                }
            }
        }
        return len;
    }
};
