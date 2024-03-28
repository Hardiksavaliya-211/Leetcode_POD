// **********************************Subarray Product Less Than K**********************************
#include<bits/stdc++.h>
#include <map>
using namespace std;

// sliding window concept is used for make solution to O(n)
// slide window based on prod if product become grater than we increase our left point  and at the end we add our subarray with (RIGHT-LEFT+1)

class Solution
{
public:
    int maxSubarrayLength(int *nums, int n, int k)
    {
        int i = 0;
        map<int, int> mp;
        int count = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            mp[nums[j]]++;
            while (mp[nums[j]] > k)
            {
                mp[nums[i]]--;
                i++;
            }
            count = max(count, j - i + 1);
        }
        return count;
    }
};
int main()
{
    int t;
    cin >> t;
    cout << endl;
    while (t--)
    {
        int n;
        cout << "enter size of array : ";
        cin >> n;
        int nums[n];

        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            cout << endl;
        }

        Solution obj;
        int ans = obj.maxSubarrayLength(nums, n, 2);
        cout << "answer is : " << ans << endl;
    }
}