/* так объявляется вектор векторов размерности RR*CC
vector<vector<int> > matrix(RR);
for ( int i = 0 ; i < RR ; i++ )
   matrix[i].resize(CC);
*/


#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class HangAlg
{
public:
    void set_matrix()
    {
        /*vector < vector <int> > matrix(n);
        for(int i = 0; i < n; i++)
        {
            matrix[i].resize(m);
        }*/
        //vector < vector <int> > matrix(m_row, vector <int> (m_col, 0));
    }

    void search_max()
    {
        /*vector < vector <int> > matrix(m_row);
        for (int i = 0; i < m_row; i++)
        {
            matrix[i].resize(m_col);
            for (int j = 0; j < m_col; j++) matrix[i][j] = 0;
        }*/
    }

    void print_mx()
    {
        vector < vector <double> > matrix(m_row);
        /*for (int n = 0; n < m_row; n++)
        {
            mmatrix.resize(m_col);
            for (int m = 0; m < m_col; m++)
            {
                mmatrix[n][m] = 0;
                cout << mmatrix[n][m] << " ";
            }
        }*/

        for (int i = 0; i < m_row; i++)
        {
            matrix[i].resize(m_col);
            for (int j = 0; j < m_col; j++) matrix[i][j] = 0;
        }
        matrix[0][2] = 3;
        for (int i = 0; i < m_row; i++)
        {
            for (int j = 0; j < m_col; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    int m_row = 4;
    int m_col = 5;
    //vector < vector <double> > matrix;
    //vector < vector <int> > matrix(n, vector <int> (m, 0));
};


int main()
{
    /*int n = 4;
    int m = 5;
    cout << "Hello World!" << endl;
    vector < vector <double> > matrix(n);
    for (int i = 0; i < n; i++)
    {
        matrix[i].resize(m);
        for (int j = 0; j < m; j++) matrix[i][j] = 0;
    }
    matrix[0][2] = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/
    //cout << matrix[0][2] << endl;
    //vector < vector <int> > matrix(n, vector <int> (m, 0));
    HangAlg le;

    le.print_mx();

    return 0;
}

/*vector<vector<double>> HangAlg::matrix(m_row) как это работает?
{
    return vector<vector<double>>();
}
*/
//https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix
