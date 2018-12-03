class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size();
        vector<int> index(len,0);
        int count = 0;
        for(int i = 0; i < len; i++) {
            if(!index[i]){
                searchCircle(M, index, i);
                count++;
            }
        }
        return count;
    }
    
    void searchCircle(vector<vector<int>>& M, vector<int>& index, int node) {
        int len = M.size();
        index[node] = 1;
        for(int i = 0; i < len; i++) {
            if(i != node && !index[i] && M[node][i])
                searchCircle(M, index, i);
        }
    }
};
