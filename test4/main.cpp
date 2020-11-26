#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void MT(int t, int m)
{
    cout << "Matrix:" << endl << endl;
    
    double** ptrarr = new double* [t]; //создаем матрицу
    for(int count = 0; count < t; count++)
    {
        ptrarr[count] = new double[m];
    }



    for(int count_row = 0; count_row < t; count_row++) // заполняем матрицу случайными числами
    {
        for(int count_column = 0; count_column < m; count_column++)
        {
            ptrarr[count_row][count_column] = (rand() % 10+1)/double((rand() % 10+1));
        }
    }

    for (int count_row = 0; count_row < t; count_row++)
    {
        for (int count_column = 0; count_column < m; count_column++)
        {
            cout << setw(12) << setprecision(2) << ptrarr[count_row][count_column] << "";
        }
        cout << endl;
    }
    cout << endl << endl << endl;

    double* ptrstrmax = new double[t];
    for(int i = 0; i < t; i++)
    {
        ptrstrmax[i] = 0;
    }

    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (ptrarr[i][j] > ptrstrmax[i])
            {
                ptrstrmax[i] = ptrarr[i][j];
            }
        }
    }

    for(int i = 0; i < t; i++) //надо рассмотреть каждую строку
    {
        for(int i = 0; i < t; i++)//идем до нужной строки
        {
            for(int j = 0; j < m; j++)//ищем стоблец с максимальным значение в строке
            {
                if(ptrarr[i][j] == ptrstrmax[i])//дошли
                {
                    if((ptrarr[i][j] == ((ptrstrmax[i+1] == ptrarr[i][j])*ptrstrmax[i+1])) || (ptrstrmax[i+1] == ptrarr[i+1][j]))//сравниваем макс знч со следующим при том, что они друг под другом
                    {
                        double summ = ptrarr[i][j] = ptrarr[i][0] + ptrstrmax[i+1];//макс значение суммы станавливаем на первом элементе
                        for(int j = 0; j < m; j++)//начинаем выбирать, какое оставить, а какое перебрать для макс знч, если не получится, на след итер будет повтор
                        {
                            if(ptrstrmax[i+1] == ptrarr[i][j]) continue;//пропускаем столбец, который мы хотим поменять
                            if(summ <= (ptrarr[i][j] + ptrstrmax[i+1]))//если оно меньше суммы с первым элементом, то перебираем дальше
                            {
                                summ = ptrarr[i][j] + ptrstrmax[i+1];
                            }
                            else ptrstrmax[i] = ptrarr[i][j-1];
                        }
                    }
                    else continue;
                }
            }
        }
    }


    cout << endl << "Link matrix:" << endl;

    for(int i = 0; i < t; i++)
    {
        cout << endl << i+1 << setw(8) << ptrstrmax[i] << endl;
    }

    cout << endl << endl << endl << endl;
    double LS = 0;

    for(int i = 0; i < t; i++)
    {
        LS += ptrstrmax[i];
    }

    cout.precision(4);
    cout << "Link summ is: " << LS << endl;

    for(int count = 0; count < t; count++)
    {
        delete[] ptrarr;
    }
    delete[] ptrarr;
    delete[] ptrstrmax;

}

int main()
{
    cout << "Hello World!" << endl;
    MT(4,5);
    return 0;
}
