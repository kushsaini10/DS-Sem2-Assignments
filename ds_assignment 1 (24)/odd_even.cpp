#include <iostream>
using namespace std;

// recursive function to rearrange odd and even numbers in an array
void odd_even(int ar[], int len, int i = 0, int odd = 0)
{
    if (i == len)
    {
        return;
    }
    if (ar[i]%2 == 1)
    {
        int temp = ar[odd];
        ar[odd] = ar[i];
        ar[i] = temp;
        odd++;
    }
    odd_even(ar, len, i + 1, odd);
}

 
int main()
{
    int len;
    cout << "Enter the size of array: ";
    cin >> len;
    int ar[len];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < len; i++)
    {
        cin >> ar[i];
    }
    odd_even(ar, len);
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}