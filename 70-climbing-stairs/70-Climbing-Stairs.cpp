class Solution {
public:
    map<int, int> memo;
    int climbStairs(int n) {
            if (memo.count(n)) return memo[n];
            if (n == 1) return 1;
            if (n == 2) return 2;

            return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);

        //      if (n == 1) return 1;
        
        // int prev2 = 1; // Ways to climb 1 step
        // int prev1 = 2; // Ways to climb 2 steps
        
        // for (int i = 3; i <= n; i++) {
        //     int current = prev1 + prev2;
        //     prev2 = prev1;
        //     prev1 = current;
        // }
        
        // return prev1;
    }
};