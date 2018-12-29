class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> index(26,0);
        int psize = p.size();
        int maxi = 0,count = 0;
        for(int i = psize - 1; i >= 0;i--) {
            if(i < psize -1 && p[i + 1] - p[i] ==1 || p[i] - p[i + 1] == 25)
                maxi++;
            else
                maxi = 1;
            index[p[i] - 'a'] = max(index[p[i] - 'a'], maxi);
        }
        for(int i = 0; i < 26; i++) {
            count+=index[i];
        }
        return count;
    }
};
