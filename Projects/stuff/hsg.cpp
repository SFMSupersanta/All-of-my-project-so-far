#include <bits/stdc++.h>
#include <string.h>

using namespace std;
// file in
ifstream fin("NUMSET.INP");
// file out
ofstream fout("NUMSET.OUT");

int devisable_by_3(unsigned long long n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    if (sum % 3 == 0)
        return 1;
    return 0;
}

int truncate_zero(unsigned long long n)
{
    if (!n)
        return 0;
    while (n % 10 == 0)
    {
        n /= 10;
    }
    return n;
}

int existedInsideArray(unsigned long long n, unsigned long long arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (arr[i] == n)
            return 1;
    }
    return 0;
}

int getCombinationNumberFromDecimal(unsigned long long dec, int k, unsigned long long arr[])
{
    int n = 0;
    string str = string(to_string(dec).c_str());
    for (int i = 1; i <= k; i++)
    {
        cout << "i = " << i << "\n";
        int start = 0;
        while (start < k)
        {
            string tmp = str.substr(start, i);
            cout << tmp;
            unsigned long long num = stoull(tmp);
            if (devisable_by_3(num) && !existedInsideArray(num, arr, n))
            {
                arr[n++] = num;
            }
            cout << "(" << start << ")\t";
            start += i;
        }
        cout << endl;
    }

    return n;
}

int main()
{

    unsigned long long n;
    fin >> n;
    cout << n << endl;
    unsigned long long tmp = n;
    int digits = 0;
    while (tmp > 0)
    {
        digits++;
        tmp /= 10;
    }
    cout << digits << endl;
    unsigned long long arr[(int)floor((digits + digits * digits) / 2)];
    int k = getCombinationNumberFromDecimal(n, digits, arr);
    for (int i; i < k; i++)
    {
        cout << arr[i] << "\t";
    }
}
