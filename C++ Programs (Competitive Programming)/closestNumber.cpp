//Find the closest number to N such that it is divisible by M. If 2 such numbers exist, return the one with the higher absolute value. 
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int closestNumber(int N , int M) {
        
        int q;
        int num1, num2;
        int result;
        
        q=N/M;
        
        num1=q*M;
        
        if(N*M>0)
        {
            num2=M*(q+1);
        }
        else
        {
            num2=M*(q-1);
        }
        
        
        if(abs(N-num1)<abs(N-num2))
        {
            result=num1;
        }
        else
        {
            result=num2;
        }
        
        
        return result;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends