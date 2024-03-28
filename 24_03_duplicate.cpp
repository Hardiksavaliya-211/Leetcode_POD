#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



class Solution{
    public:
    int checkduplicate(int *arr,int n){
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]<0){
                return abs(arr[i]);
            }
            arr[abs(arr[i]) - 1]*=-1;
        }
        return 0;
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
        int ans=obj.checkduplicate(arr,n);
        cout<<"answer is : "<<abs(ans)<<endl;
    }

}