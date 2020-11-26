//#include <QCoreApplication>
#include <iostream>
/*#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>*/

#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;

void MT(int t, int m)
{
    cout << "Matrix:" << endl;

    float** ptrstr = new float*[t];

    for(int count = 0; count < t; count++)
    {
        ptrstr[count] = new float[m];
    }

    for(int count_row = 0; count_row < t; count_row++)
    {
        for(int count_column = 0; count_column < m; count_column++)
        {
            ptrstr[count_row][count_column] = (rand() % 10+1) / float((rand() % 10+1));
        }
    }

    for (int count_row = 0; count_row < t; count_row++)
    {
        for(int count_column = 0; count_column < m; count_column++)
        {
            cout << setw(4) << setprecision(2) << ptrstr[count_row][count_column] << "";
            cout << endl;
        }
    }

    cout << endl << endl << endl << endl;

    float* ptrstrmax = new float[t];
    for(int i = 0; i < t; i++) ptrstrmax[i] = 0;

    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < t; i++)
        {
            if(ptrstrmax[i] < ptrstr[i][j]) ptrstrmax[i] = ptrstr[i][j];
        }
    }

    float max = 0;
    for(int i = 0; i < t; i++)
    {
        if(ptrstrmax[i] > max) max = ptrstrmax[i];
    }

    cout << endl << "Link Matrix:" << endl;

    for(int i = 0; i < t; i++)
    {
        cout << endl << i+1 << setw(int(max)) << ptrstrmax[i] << endl;
    }

}

int main(int argc, char** argv)
{
    cout << "Hello World!" << endl;

    MT(3,5);

    return 0;

    /*QApplication app(argc, argv);
    QLabel lbl("Hello World!");
    lbl.show();
    return app.exec();*/
}
