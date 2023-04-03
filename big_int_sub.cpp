#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

template<class T>
void swap(T* a, T* b)
{
    T t = a;
    a=b;
    b=t;
}

long long pow(long long a, int b)
{
    long long x=1;
    for (int i = 0; i < b; i++)
    {
        x*=a;
    }
    return x;
}

int main()
{
    cout<<"ENTER NO 1\n";
    string s; cin>>s;
    for (int i = 0; i < s.size()/2; i++)
    {
        swap(s[i],s[s.size()-1-i]);
        // cout<<"swaping"<<endl;
    }
    long long int arr[1000];
    for (int i = 0; i < 1000; i++)
    {
        arr[i]=0;   
    }
    int x=0,sz=0;
    long long m=0;
    for (int i = 0; i < 1000; i++)
    {
        // cout<<"inhere"<<endl;
        m = 0;
        if(i*18>=s.size())break;
        while(x<18 && i*18+x<s.size())
        {
            // cout<<"storing"<<endl;
            m = (s[i*18+x]-'0')*pow(10,x)+m;
            x++;
        }
        arr[i]=m;
        x=0;
        sz++;
    }
    // for (int i = 0; i < sz; i++)
    // {
    //     cout<<arr[i]<<' ';
    // }
    cout<<"ENTER NO 2\n";
    string f; cin>>f;
    for (int i = 0; i < f.size()/2; i++)
    {
        swap(f[i],f[f.size()-1-i]);
        // cout<<"swaping"<<endl;
    }
    long long int arr2[1000];
    for (int i = 0; i < 1000; i++)
    {
        arr2[i]=0;   
    }
    x=0,sz=0;
    m=0;
    for (int i = 0; i < 1000; i++)
    {
        // cout<<"inhere"<<endl;
        m = 0;
        if(i*18>=f.size())break;
        while(x<18 && i*18+x<f.size())
        {
            // cout<<"storing"<<endl;
            m = (f[i*18+x]-'0')*pow(10,x)+m;
            x++;
        }
        arr2[i]=m;
        x=0;
        sz++;
    }
    int res[1000];
    for(int i = 0; i < 1000; i++){
        res[i] = arr[i] - arr2[i];
    }
    for(int i = 0; i < 1000; i++){
        if(res[i] < 0){
            res[i] += 1000000000000000000;
            res[i+1] -= 1;
        }
    }
    // long long carry=0,h=1000000000000000000;
    // for (int i = 0; i < 1000; i++)
    // {
    //     arr[i]=((arr[i]+arr2[i])+carry)%h;
    //     carry = arr[i]/h;
    // }
    string ans="";
    for (int i = 1000-1; i >=0; i--)
    {
        if(res[i]){
            ans=ans+to_string(res[i]);
            // cout << res[i] << "\n";
        }
    }
    cout<< ans <<endl;
    return 0;
}
