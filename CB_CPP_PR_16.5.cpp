#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    struct tm buf;
    time_t t = time(NULL);
    localtime_s(&buf, &t);



    const int ROWS = 5;                  //количество строк массива
    const int COLS = 6;                 //количество колон массива

    int arr[ROWS][COLS];                //собсна массив


    int choseRow;                       //переменная для выбора строки
    choseRow = buf.tm_mday % ROWS;      //получение остатка от деления, как выбор строки для суммы

    int sum = 0;                        //для вывода суммы строки
    int sum2 = 0;

    cout << "Массив " << ROWS << " x " << COLS << endl << endl;

    for (int i = 0; i < ROWS; i++)                  //забиваем массив
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = i + j;
        }


    }
    for (int i = 0; i < ROWS; i++)                  //выводим массив
    {

        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << "\t";

        }
        cout << endl;
    }

    cout << endl;


    for (int i = 0; i < COLS; i++)              //считаем сумму всех элементов строки
    {
        sum += arr[choseRow][i];
    }
    cout << endl;

    for (int j = 0; j < ROWS; j++)              //еще и элементов столбца
    {
        sum2 += arr[j][choseRow];
    }


    cout << "Сумма " << choseRow + 1 << " строки: " << sum << endl;
    cout << "Сумма " << choseRow + 1 << " столба: " << sum2 << endl;


    return 0;
}
