
// ############_____________________________ LEETCODE 621 TASK SCHEDULAR _____________________################

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    Solution()
    {
    }
    int schedular(vector<char> tasks, int n)
    {

        int freq[26] = {0};
        for (char task : tasks)
        {
            freq[task - 'A']++;
        }

        sort(begin(freq), end(freq));
        int chunk = freq[25] - 1;
        int idel = chunk * n;

        for (int i = 24; i >= 0; i--)
        {
            idel -= min(chunk, freq[i]);
        }
        cout << idel;

        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};

int main()
{

    Solution obj;
    vector<char> tasks = {'A', 'A', 'B', 'B', 'C', 'A'};
    int n = 2;
    int ans = obj.schedular(tasks, n);
    cout << ans;
}