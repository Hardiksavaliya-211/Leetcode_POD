// **********************************Subarray Product Less Than K**********************************

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// sliding window concept is used for make solution to O(n) 
//slide window based on prod if product become grater than we increase our left point using ****(while loop)**** and at the end we add our subarray with (RIGHT-LEFT+1)

class Solution
{
public:
    int missingPos(int *nums, int n,int k)
    {
        if (k <= 1)
            return 0;

        int count = 0;
        int product = 1;
        int left = 0;
        for (int right = 0; right < n; ++right)
        {
            product *= nums[right];
            while (product >= k)
            {
                product /= nums[left];
                left++;
            }
            count += (right - left + 1);
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
        int arr[n];

        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            cout << endl;
        }

        Solution obj;
        int ans = obj.missingPos(arr, n,100);
        cout << "answer is : " << abs(ans) << endl;
    }
}