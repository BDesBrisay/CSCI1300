#include <iostream>
using namespace std;

int main ()
{
    int n_rows;
    cout << "Enter number of rows: ";
    cin >> n_rows;

    for(int i = n_rows; i > 0; i--) {
        for(int j = i; j > 0; j--) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
