#include <iostream>
using namespace std;

// bool sorted(int arr[], int n)

// {

//     if (n == 1)
//     {
//         return true;
//     }

//     bool restArray = sorted(arr + 1, n - 1);
//     return (arr[0] < arr[1] && restArray);
// }

// void dec(int n)
// {
//     if (n == 0)
//     {
//         return;
//     }
//     cout << n << endl;
//     dec(n - 1);
// }
// int main()
// {
//     int arr[] = {1,
//                  2,
//                  53,
//                  343};
//     cout << sorted(arr, 5) << endl;

//     return 0;
// }

int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] = key)
    {
        return i;
    }
    return firstocc(arr, n, i + 1, key);
}

int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restArray = lastocc(arr, n, i + 1, key);
    if (restArray != -1)
    {
        return restArray;
    }
    if (arr[i] == key)
    {
        return i;
    }

    return -1;
}

int main()
{
    int arr[] = {4,
                 2,
                 1,
                 2,
                 5,
                 2,
                 7};
    return 0;
}