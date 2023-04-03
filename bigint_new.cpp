#include<bits/stdc++.h>
using namespace std;
#define MM 100000000000000000
class BigInt{
private:
public:
    string s="";
    vector<long long> num;
    bool sign=0;
    void getnum(string &nums){
        s = nums;
        string temp=s;
        reverse(temp.begin(),temp.end());
        for(int i = 0; i < temp.length(); i+=17){
            string s_17=temp.substr(i,17);
            reverse(s_17.begin(), s_17.end());
            num.push_back(stoll(s_17));          
        }
    }
    void printnum(){
        cout << s << "\n";
    }
    BigInt operator+(BigInt &b){
        BigInt c;
        int carry = 0,i;
        for(i = 0; (i < num.size() && i < b.num.size()); i++){
            long long x = num[i] + b.num[i] + carry;
            carry = x/MM;
            x = x%MM;
            c.num.push_back(x);
        }
        while(i < num.size()){
            c.num.push_back(num[i]+carry);
            if(carry) carry = 0;
        }
        while(i < b.num.size()){
            c.num.push_back(b.num[i]+carry);
            if(carry) carry = 0;
        }
        for (int i = 0; i < c.num.size(); i++)
        {
            string cc=to_string(c.num[i]);
            if(i==c.num.size()-1)
            {
                c.s=cc+c.s; break;
            }
            while(cc.size()<17)cc="0"+cc;
            c.s=cc+c.s;
        }
        return c;
    }
    bool lesser(string &x, string &y)
    {
        if(x.size()<y.size())return 1;
        else if(x.size()==y.size())
        {
            for (int i = 0; i < x.size(); i++)
            {
                if(x[i]<y[i])return 1;
                if(x[i]>y[i])return 0;
            }
            return 0;
        }
        return 0;
    }
    BigInt operator-(BigInt &b)
    {
        BigInt c;
        if(lesser(s, b.s))
        {   
            swap(num,b.num);
            c.sign = 1;
        }
        int borrow=0,i;
        for (i = 0; i < b.num.size(); i++)
        {
            if(num[i]>=borrow){num[i]-=borrow; borrow=0;}
            else{
                borrow-=num[i];
                num[i]=0;
            }
            if(num[i]<b.num[i]){num[i]=1e18*1ll+num[i]; borrow++;}
            c.num.push_back(num[i]-b.num[i]);
        }
        while(i<num.size())
        {
            if(num[i]>=borrow){num[i]-=borrow; borrow=0;}
            else{
                borrow-=num[i];
                num[i]=0;
            }
            c.num.push_back(num[i]-b.num[i]);
            i++;
        }
        for (int i = 0; i < c.num.size(); i++)
        {
            string cc=to_string(c.num[i]);
            if(i==c.num.size()-1)
            {
                c.s=cc+c.s; break;
            }
            while(cc.size()<17)cc="0"+cc;
            c.s=cc+c.s;
        }
        return c;
    }
};

int main()
{
    BigInt a,b,c;
    string tmp; 
    cout<<"Enter no 1: ";
    cin>>tmp;
    a.getnum(tmp);
    cout<<"Enter no 2: ";
    cin>>tmp;
    b.getnum(tmp);
    c=a+b;
    cout<<"The sum is: ";
    c.printnum();
    c=a-b;
    // for(int i = 0; i < a.num.size(); i++){
    //     cout << a.num[i];
    // }
    // cout << "\n";
    // for(int i = 0; i < b.num.size(); i++){
    //     cout << b.num[i];
    // }
    // cout << "\n";
    // for(int i = 0; i < c.num.size(); i++){
    //     cout << c.num[i];
    // }
    cout<<"The dif is: ";
    if(c.sign)cout<<'-';
    c.printnum();
}