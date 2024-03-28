//  *************************** find all duplicate in array **************************


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// ----------------------APPROCAH-----------------

// MAKE VISITED BASED ON VALUE OF ARRAY AT PERTICULAR INDEX LIKE NUMS[NUMS[I]-1]
class Solution
{
public:
    vector<int> checkduplicate(int *arr, int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] < 0)
            {
                 ans.push_back(abs(arr[i]));
            }
            arr[abs(arr[i]) - 1] *= -1;
        }
        return ans;
    }
};
int main()
{
    int t;
    cout<<"Enter ";
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
        vector<int> ans = obj.checkduplicate(arr, n);
        cout<<"Answer is: ";
       for(auto i:ans){
        cout<<i<<" ";
       }
    }
}