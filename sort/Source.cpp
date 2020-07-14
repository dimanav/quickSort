#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void zapic(int* arr, int n, string name, int j)
{
    ofstream f(name.c_str());
    if (f.is_open())     
    {
        if (j == 1)
            f << "»сходный массив : " << endl << endl;
        else f << "ќтсортированный массив : " << endl << endl;
        for (int i = 0; i < n; i++)
            f << setw(5) << arr[i];
        f.close();     
    }
    else cout << "ќшибка записи в файл " << name.c_str() << endl;
    return;
}



void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };


    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);

}
int main()
{
    SetConsoleCP(1251);     
    SetConsoleOutputCP(1251);

    int size;
    cout << "¬ведите размер массива : " << endl;
    do
    {
        cin >> size;
        if ((!(cin.good())) || (size < 2))
        {
            cout << "Ќеверно введен размер массива size " << endl;
            cin.clear();
            cin.get();
        }
    } while ((!(cin.good())) || (size < 2));

    int* arr = new int[size];                            
    string filename1 = "numbers.txt";       
    string filename2 = "sort numbers.txt"; 

    for (int i = 0; i < size; i++)
        arr[i] = ((rand() % 2001) - 1000);
    zapic(arr, size, filename1, 1);     
    cout << endl << "—генерированный массив Ц файл numbers.txt" << endl;

    quickSort(arr, 0, size - 1);

    zapic(arr, size, filename2, 2);
    cout << "ќтсортированный по возрастанию массив Ц файл sort numbers.txt" << endl;

    return 0;
}

