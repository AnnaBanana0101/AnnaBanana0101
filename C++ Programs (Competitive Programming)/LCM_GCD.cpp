//Find LCM and GCD of 2 numbers
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) 
    {
        vector <long long> list;
        int rem;
        long long gcd;
        long long lcm;
        int a=A, b=B;
        
        while(b!=0)
        {
            rem=a%b;
            a=b;
            b=rem;
        }
        
        gcd=a;
        
        lcm= (A*B)/gcd;
        
        list.push_back(lcm);
        list.push_back(gcd);
        
        return list;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends