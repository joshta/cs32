#include<iostream>
using namespace std;

double foo (int n)
{
    int i;
    double sum;
    if (n == 0) return 1.0;
    else
    {
        sum = 0.0;
        for (i = 0; i < n; i++)
            sum += foo (i);
        return sum;
    }
}

int main() {
    double val=foo(5);
    cout<<"value="<<val<<endl;
    return 0;
}
