#include <iostream>
using namespace std;

int arr[1000001];

void quickSort(int *arr, int start, int end)
{
   
   int pivot = arr[start];
   int i = start;
   int j = end;

   cout << endl;
   
   while(i <= j)
   {
      while (pivot > arr[i]) { i++; }
      while (pivot < arr[j]) { j--; }


      if (i <= j)
      {
         for (int i = 0; i < 10; i++)
         {
            cout << arr[i] << " ";
         }
         cout << endl;

         swap(arr[i], arr[j]);
         i++;
         j--;
      }


   }

   if (start < j)
      quickSort(arr, start ,j);
   if (i < end)
      quickSort(arr, i, end);

}

int main()
{
   int size;
    cin >> size;
    
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
 
   quickSort(arr, 0, size-1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
  
    return 0;
}
