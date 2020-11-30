#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void vengalg(int t, int m)
{
    int t1 = t;
    if (t < m) t = t + (m - t);
    double** ptrarr = new double* [t]; //создаем матрицу
    for(int count = 0; count < t; count++)
    {
        ptrarr[count] = new double[m];
    }

    double** ptrarr2 = new double* [t]; //создаем матрицу, с которой будет работать алгоритм
    for(int count = 0; count < t; count++)
    {
        ptrarr2[count] = new double[m];
    }

    /*for(int count_row = 0; count_row < t; count_row++) // заполняем матрицу случайными числами
    {
        for(int count_column = 0; count_column < m; count_column++)
        {
            ptrarr[count_row][count_column] = (rand() % 10+1)/double((rand() % 10+1));
            ptrarr2[count_row][count_column] = ptrarr[count_row][count_column];
        }
    }*/
    ptrarr[0][0] = 0.57;
    ptrarr[0][1] = 0.67;
    ptrarr[0][2] = 5;
    ptrarr[0][3] = 0.1;
    ptrarr[0][4] = 0.14;
    ptrarr[1][0] = 0.22;
    ptrarr[1][1] = 3;
    ptrarr[1][2] = 1.3;
    ptrarr[1][3] = 0.33;
    ptrarr[1][4] = 0.57;
    ptrarr[2][0] = 2.5;
    ptrarr[2][1] = 0.62;
    ptrarr[2][2] = 6;
    ptrarr[2][3] = 2;
    ptrarr[2][4] = 3;
    ptrarr[3][0] = 1;
    ptrarr[3][1] = 1.2;
    ptrarr[3][2] = 0.5;
    ptrarr[3][3] = 0.5;
    ptrarr[3][4] = 1;

    if(t1 != m)
    {
        for (int i = (t - (t-t1)); i < t; i++)
        {
            for (int j = 0; j < m; j++)
                {
                    ptrarr[i][j] = 0;
                }
        }
    }

    for (int i = 0; i < t; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ptrarr2[i][j] = ptrarr[i][j];
        }
    }

    double* ptrstrmax = new double [t];
    double* ptrstrmin = new double [t];
    for (int i = 0; i < t; i++)
    {
        ptrstrmax[i] = 0;
    }

    for (int i = 0; i < t; i++)//ищем максимальный элемент в каждой строке
    {
        for (int j = 0; j < m; j++)
        {
            if (ptrarr2[i][j] > ptrstrmax[i]) ptrstrmax[i] = ptrarr2[i][j];
            ptrstrmin [i] = ptrstrmax [i];
            //cout << "[" << i << "]: " << ptrstrmax[i] << endl;
        }
    }

    for (int i = 0; i < t; i++)//вычитаем его из каждого элемента строки, а потом умножаем матрицу на "-1"
    {
        for (int j = 0; j < m; j++)
        {
            //cout << endl << ptrarr2[i][j] << " [" << i << "]" << "[" << j << "] - " << "ptrstrmax[" << i << "] (" << ptrstrmax[i] << ")" <<": " << ptrarr2[i][j] << endl;
            ptrarr2[i][j] = ((ptrarr2[i][j] - ptrstrmax[i]) * (-1.0));

        }
    }

    //double* ptrstrmin = new double [t];

    /*for (int i = 0; i < t; i++)
    {
        ptrstrmin [i] = ptrstrmax [i];
    }*/

    for (int i = 0; i < t; i++)//ищем минимальный элемент в каждой строке
    {
        for (int j = 0; j < m; j++)
        {
            if (ptrarr2[i][j] < ptrstrmin[i]) ptrstrmin[i] = ptrarr2[i][j];
            //cout << "[" << i << "]: " << ptrstrmax[i] << endl;
        }
    }

    for (int i = 0; i < t; i++)//вычитаем его из каждого элемента строки
    {
        for (int j = 0; j < m; j++)
        {
            //cout << endl << ptrarr2[i][j] << " [" << i << "]" << "[" << j << "] - " << "ptrstrmin[" << i << "] (" << ptrstrmin[i] << ")" <<": " << ptrarr2[i][j] << endl;
            ptrarr2[i][j] = ((ptrarr2[i][j] - ptrstrmin[i]));

        }
    }

    double* ptrcolmin = new double [m];
    for (int j = 0; j < m; j++)
    {
        ptrcolmin[j] = ptrarr2[0][j];
    }



    for (int j = 0; j < m; j++)//ищем минимальный элемент в каждом столбце
    {
        for (int i = 0; i < t; i++)
        {
            if(ptrcolmin[j] >= ptrarr2[i][j]) ptrcolmin[j] = ptrarr2[i][j];
        }
    }

    for (int j = 0; j < m; j++)//вычитаем его из каждого элемента столбца
    {
        for (int i = 0; i < j; i++)
        {
            ptrarr2[i][j] = ptrarr2[i][j] - ptrcolmin[j];
        }
    }

    /*for (int j = 0; j < m; j++)
    {
        for ( int i = 0; i < t; i ++)
        {
            if (ptrstrmin[])
        }
    }*/

    //for (int i = 0; i < )

    for (int count_row = 0; count_row < t; count_row++)//оригинал матрицы
    {
        for (int count_column = 0; count_column < m; count_column++)
        {
            cout.precision(4);
            cout << setw(12) << setprecision(4) << ptrarr[count_row][count_column] << "";
        }
        cout << endl;
    }


    for(int i = 0; i < 4; i++)
    {
        cout << endl;
    }


    for (int count_row = 0; count_row < t; count_row++)//измененный вариант матрицы
    {
        for (int count_column = 0; count_column < m; count_column++)
        {
            cout.precision(4);
            cout << setw(12) << setprecision(4) << ptrarr2[count_row][count_column] << "";
        }
        cout << endl;
    }



    delete[] ptrarr;//очищаем память
    delete[] ptrarr2;
    delete[] ptrstrmax;
    delete[] ptrstrmin;
}

int main()
{
    cout << "Hello World!" << endl;
    vengalg(4, 5);
    return 0;
}
