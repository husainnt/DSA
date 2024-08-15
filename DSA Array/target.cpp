#include <iostream>
using namespace std;

const int max_size = 100;

void input(int nums[], int &length)
{
    cout << "Enter length of array: ";
    cin >> length;
    cout << "Enter elements of array: ";
    for (int i = 0; i < length; ++i)
    {
        cin >> nums[i];
    }
}

void target_sum(int nums[], int length, int ts)
{
    bool found = false;
    cout << "Pairs that add up to the target sum are:" << endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (nums[i] + nums[j] == ts)
            {
                cout << "[" << nums[i] << "," << nums[j] << "]" << endl;
                found = true;
            }
        }
    }
    if (!found)
    {
        cout << "No pairs found." << endl;
    }
}

int main()
{
    int nums[max_size];
    int length, ts;

    input(nums, length);

    cout << "Enter target sum: ";
    cin >> ts;

    target_sum(nums, length, ts);

    return 0;
}
