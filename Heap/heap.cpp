#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {

        size = size + 1;
        int indx = size;
        arr[indx] = val;

        while (indx > 1)
        {
            int parent = indx / 2;
            if (arr[parent] < arr[indx])
            {
                swap(arr[parent], arr[indx]);
                indx = parent;
            }
            else
            {
                return;
            }
        }
    }
    void delete_fromheap()
    {
        if (size == 0)
        {
            cout << "Nothing to delte" << endl;
            return;
        }
        // put last element into 1st index
        arr[1] = arr[size];
        // remove last element
        size--;
        // take root node to correct pos
        int i = 1;
        while (i < size)
        {
            int leftidx = 2 * i;
            int rightidx = (2 * i) + 1;
            if (leftidx < size && arr[i] < arr[leftidx])
            {
                swap(arr[i], arr[leftidx]);
                i = leftidx;
            }
            else if (rightidx < size && arr[i] < arr[rightidx])
            {
                swap(arr[i], arr[rightidx]);
                i = rightidx;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.delete_fromheap();
    h.print();
    return 0;
}
