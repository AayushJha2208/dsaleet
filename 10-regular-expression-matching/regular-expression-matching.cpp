class Solution {
public:
    bool solve(string& s, string& p, int i, int j) {
        if (j == p.size())
            return i == s.size();

        bool firstMatch = (i < s.size() && (p[j] == s[i] || p[j] == '.'));
        if (j + 1 < p.size() && p[j + 1] == '*') {
            return solve(s, p, i, j + 2) ||
                   (firstMatch && solve(s, p, i + 1, j));
        }

        return firstMatch && solve(s, p, i + 1, j + 1);
    }

    bool isMatch(string s, string p) { return solve(s, p, 0, 0); }
};

// bool func(string s, string p,int i,int j){
//     if(i>=s.size() && j>=p.size())return 1;
//     if(s[i]==p[j]) return func(s,p,i+1,j+1);
//     if(p[j]=='.'){
//         if(i==s.size()) return 0;
//         else return func(s,p,i+1,j+1);
//     }
//     if(p[j]=='*'){
//         if(i==s.size()-1) return 1;
//         bool ans=func(s,p,i+1,j+1);
//         if(ans) return ans;
//         for(int k=i+1;k<s.size();k++){
//             if(p[j]==s[k] && func(s,p,k+1,j+1)){
//                 ans=1;
//                 break;
//             }
//         }
//         return ans;
//     }
//     return 0;

// }

//    int i=0,j=0;
//     while(i<s.size() && j<p.size()){
//         if(s[i]==p[j]) {
//             i++;
//             j++;
//         }
//         else if(p[j]=='.')j++;
//         else if(p[j]=='*'){
//             if(j==p.size()-1) return 1;
//             if(p[j+1]==s[i] || p[j+1]=='.'){

//             }
//         }
//         else {
//             j++;
//         }
//     }
//     if(i==s.size()&& j==p.size()) return 1;
//     if(i==s.size() && j==p.size()-1 && p[j]=='*') return 1;
//     return 0;

// class Solution(object):
//     def isMatch(self, text: str, pattern: str) -> bool:
//         memo = {}

//         def dp(i: int, j: int) -> bool:
//             if (i, j) not in memo:
//                 if j == len(pattern):
//                     ans = i == len(text)
//                 else:
//                     first_match = i < len(text) and pattern[j] in {text[i],
//                     "."} if j + 1 < len(pattern) and pattern[j + 1] == "*":
//                         ans = dp(i, j + 2) or first_match and dp(i + 1, j)
//                     else:
//                         ans = first_match and dp(i + 1, j + 1)

//                 memo[i, j] = ans
//             return memo[i, j]

//         return dp(0, 0)

// class Solution(object):
//     def isMatch(self, text: str, pattern: str) -> bool:
//         dp = [[False] * (len(pattern) + 1) for _ in range(len(text) + 1)]

//         dp[-1][-1] = True
//         for i in range(len(text), -1, -1):
//             for j in range(len(pattern) - 1, -1, -1):
//                 first_match = i < len(text) and pattern[j] in {text[i], "."}
//                 if j + 1 < len(pattern) and pattern[j + 1] == "*":
//                     dp[i][j] = dp[i][j + 2] or first_match and dp[i + 1][j]
//                 else:
//                     dp[i][j] = first_match and dp[i + 1][j + 1]

//         return dp[0][0]