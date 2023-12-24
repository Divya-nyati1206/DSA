#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> weight , vector<int> value , int index , int capacity , vector<vector<int>> dp)
{
    if(index == 0)
    {
        if(weight[index]<=capacity)
            return value[index];
        else
            return 0;
    }

    if(dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if(weight[index]<=capacity)
        include = value[index] + solve(weight , value , index-1 , capacity-weight[index]  , dp);
    int exclude = 0 + solve(weight , value , index-1 , capacity , dp);

    dp[index][capacity] = max(include , exclude);

    return dp[index][capacity];
}

int knapsack(vector<int> weight , vector<int> value , int n , int capacity)
{
    vector<vector<int>> dp(n , vector<int>(capacity+1 , -1));
    int max_value = solve(weight , value , n-1 , capacity , dp);
    return max_value;
}

int main()
{
    vector<int> weight;
    vector<int> value;
    int w , v;
    int count = 0;
    int capacity = 0;

    int i = 1;
    while(i!=0)
    {
        cout<<"Enter the weight and value of item :";
        cin>>w>>v;
        weight.push_back(w);
        value.push_back(v);
        count++;
        cout<<"Want to insert an item??(enter 0 or 1) : ";
        cin>>i;
    }

    cout<<"Enter the capacity of knapsack : ";
    cin>>capacity;

    int max_value = knapsack(weight , value , count , capacity);

    cout<<endl<<"Maximum value of items which can be put in knapsack : "<<max_value;

    return 0;
    
}