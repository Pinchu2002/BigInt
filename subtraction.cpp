#include<assert.h>
#include<bits/stdc++.h>
using namespace std;


class BigInt {
public:
    int sign;
    string s;

    BigInt()
        : s("")
    {
    }

    BigInt(string x)
    {
        *this = x;
    }

    BigInt(int x)
    {
        *this = to_string(x);
    }

    BigInt negative()
    {
        BigInt x = *this;

        x.sign *= -1;

        return x;
    }

    BigInt normalize(int newSign)
    {
        for (int a = s.size() - 1; a > 0 && s[a] == '0'; a--)
            s.erase(s.begin() + a);

        sign = (s.size() == 1 && s[0] == '0' ? 1 : newSign);

        return *this;
    } 
    bool operator<(const BigInt& x) const
    {
        if (sign != x.sign)
            return sign < x.sign;

        if (s.size() != x.s.size())
            return (sign == 1 ? s.size() < x.s.size() : s.size() > x.s.size());

        for (int a = s.size() - 1; a >= 0; a--)
            if (s[a] != x.s[a])
                return (sign == 1 ? s[a] < x.s[a] : s[a] > x.s[a]);

        return false;
    }  
    BigInt operator+(BigInt x)
    {
        BigInt curr = *this;

        if (curr.sign != x.sign)
            return curr - x.negative();

        BigInt res;

        for (int a = 0, carry = 0; a < s.size() || a < x.s.size() || carry; a++) {
            carry += (a < curr.s.size() ? curr.s[a] - '0' : 0) + (a < x.s.size() ? x.s[a] - '0' : 0);

            res.s += (carry % 10 + '0');

            carry /= 10;
        }

        return res.normalize(sign);
    }
    BigInt operator-(BigInt x)
{
        BigInt curr = *this;

        if (curr.sign != x.sign)
            return curr + x.negative();

        int realSign = curr.sign;

        curr.sign = x.sign = 1;

        if (curr < x)
            return ((x - curr).negative()).normalize(-realSign);

        BigInt res;

        for (int a = 0, borrow = 0; a < s.size(); a++) {
            borrow = (curr.s[a] - borrow - (a < x.s.size() ? x.s[a] : '0'));

            res.s += (borrow >= 0 ? borrow + '0' : borrow + '0' + 10);

            borrow = (borrow >= 0 ? 0 : 1);
        }

        return res.normalize(realSign);
    }

    string toString() const
    {
        string ret = s;

        reverse(ret.begin(), ret.end());

        return (sign == -1 ? "-" : "") + ret;
    }
};

bool intTest(int x, int y){
    BigInt A(x), B(y);
    assert((A-B).toString() == to_string(x-y));
    // cout << x << " - " << y << " = " << A - B << "\n";
}

bool test(){
    assert((BigInt("616512316543123165465416545405640645") -
    BigInt("616512316543123165465636565231654065565654065405640645")).toString()
     == "-616512316543123164849124248688530900100237520000000000");
    cout << "616512316543123165465416545405640645 - 616512316543123165465636565231654065565654065405640645 = -616512316543123164849124248688530900100237520000000000\n";
}

int main(){
    test();

}