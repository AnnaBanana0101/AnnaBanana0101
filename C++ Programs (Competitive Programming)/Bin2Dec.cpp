//Convert Binary string to decimal integer
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string str) 
    {
        
        long long int bin_num=0, dec_num=0;
        int rem;
        long long int temp=0;
        int i=0;
        
        for(int j=0; j<str.length(); j++)
        {
            temp= temp*10 + (str[j]-'0');
            //cout<<"Temp: "<<temp<<endl;
        }
        
        //cout<<"Binary: "<<temp<<endl;
        
        bin_num=temp;
        
        while(bin_num>0)
        {
            rem=bin_num%10;
            //cout<<rem<<endl;
            dec_num= dec_num + rem*pow(2,i);
            //cout<<"Dec: "<<dec_num<<endl;
            bin_num=bin_num/10;
            i++;
            
        }
        return dec_num;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends