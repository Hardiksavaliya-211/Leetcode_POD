// ********************************** FIND MISSING POSITIVE **********************************

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//SWAPPING VALUE AT THEIR POSITION TILL ith VALUE NOT GET INT THEIR ACTUAL POSITION


class Solution{
    public:
    int missingPos(int *nums,int n){
        for (int i = 0; i < n;)
        {
            if (nums[i] <= 0 || nums[i] > n || nums[i] == i + 1 || nums[nums[i] - 1] == nums[i])
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first missing positive integer
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};
int main(){
    int t;
    cin>>t;
    cout<<endl;
    while(t--){
        int n;
        cout<<"enter size of array : ";
        cin>>n;
        int arr[n];

        cout<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            cout<<endl;
        }

        Solution obj;
        int ans=obj.missingPos(arr,n);
        cout<<"answer is : "<<abs(ans)<<endl;
    }

}