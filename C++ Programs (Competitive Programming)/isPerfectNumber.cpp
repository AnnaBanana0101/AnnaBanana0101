//Is Perfect Number

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) 
    {
        long long num;
        int rem;
        
        int sum=1;
        
        for(int i=2; i<=sqrt(N); i++)
        {
            if(N%i==0)
            {
                sum=sum+ i+ (N/i);
                //cout<<"i: "<<i<<endl;
            }
        }
        
        /*while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            sum=sum+temp;
        }*/
        
        if(sum==N&& N!=1)
        {
            return 1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends