#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solve(string a , string b , int i , int j , vector<vector<int>> dp)
{
    if(i == a.length())
        return 0;
    if(j == b.length())
        return 0;

    int ans = 0;

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(a[i] == b[j])
    {
        ans = 1 + solve(a,b,i+1,j+1,dp);
    }
    else
        ans = max(solve(a,b,i,j+1,dp),solve(a,b,i+1,j,dp));

    return dp[i][j] = ans;

}

int LCS(string a , string b)
{
    vector<vector<int>> dp(a.length() , vector<int>(b.length() , -1));
    return solve(a,b,0,0,dp);
}

int main()
{
    vector<char> subsequence;
    string a , b;
    cout<<"Enter two sequences : ";
    getline(cin , a);
    getline(cin , b);

    int l = LCS(a,b);

    cout<<"Length of longest common subsequence is : "<<l<<endl;

}