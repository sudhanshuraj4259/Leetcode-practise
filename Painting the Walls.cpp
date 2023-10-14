class Solution {
private:
    int solve(vector<int>& cost, vector<int>& time, int index, int walls, vector<vector<int>> &dp){
        if(walls <= 0)
            return 0;
        if(index < 0)
            return 1e9;

        if(dp[index][walls] != -1)
            return dp[index][walls];

        int take = cost[index] + solve(cost, time, index - 1, walls - time[index] - 1, dp);
        int noTake = solve(cost, time, index - 1, walls, dp);
        return dp[index][walls] = min(take, noTake);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return solve(cost, time, n - 1, n, dp);
    }
};
