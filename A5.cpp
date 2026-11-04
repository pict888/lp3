#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int partition(int a[], int low, int high, int &comp){
    int pivot = a[low];
    int p = low+1;
    int q = high;
    while(p<=q){
        while(p <= high){
            comp++;
            if(a[p] > pivot)
                break;
            p++;
        }
        while(q > low){
            comp++;
            if(a[q] <= pivot)
                break;
            q--;
        }
        if(p < q){
            swap(a[p], a[q]);
            p++;
            q--;
        }
    }
    swap(a[low], a[q]);
    return q;
}

int randomParition(int a[], int low, int high, int &comp){
    int r = low + rand() % (high-low+1);
    swap(a[low], a[r]);
    cout << "Random Pivot: " << a[low] << " \n";
    return partition(a, low, high, comp);
}

void quicksort(int a[], int low, int high, int &comp, bool random){
    if(low < high) {
        int pos;
        if(random)
            pos = randomParition(a, low, high, comp);
        else
            pos = partition(a, low, high, comp);
        quicksort(a, low, pos-1, comp, random);
        quicksort(a, pos+1, high, comp, random);
    }
}

int main()
{
        int n, a[100], b[100];
    int compD = 0, compR = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid input";
        return 0;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    srand(time(0));

    quicksort(a, 0, n - 1, compD, false);
    quicksort(b, 0, n - 1, compR, true);

    cout << "\nDeterministic Quick Sort: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nComparisons: " << compD;

    cout << "\n\nRandomized Quick Sort: ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    cout << "\nComparisons: " << compR;

    return 0;
}
