#include <iostream>
using namespace std;

int setBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int setBittrip(int n, int pos)
{
    return (n | (1 << pos));
}

bool getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int unique(int arr[], int n)
{

    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
}

int doubleun(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    int tempxor = 0;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }

    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i], pos - 1))
        {
            newxor = newxor ^ arr[i];
        }
    }
    cout << newxor << endl;
    cout << (tempxor ^ newxor) << endl;
}

int tripun(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getBit(arr[j], i))
            {

                sum++;
            }
        }

        if (sum % 3 != 0)
        {
            result = setBittrip(result, i);
        }
    }
    return result;
}

int main()
{

    int arr[] = {1, 2, 3, 5, 2, 3};
    cout << unique(arr, 6) << endl;
    return 0;
}