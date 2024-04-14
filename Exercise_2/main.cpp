#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("data.csv");
    ofstream fout("result.txt");
    string line;
    double S;
    int n;
    double *w, *r; //per definire i puntatori

    getline(fin, line); //per leggere n ed S dal file
    S = stod(line.substr(2));
    getline(fin, line);
    n = stoi(line.substr(2));

    w = new double[n];
    r = new double[n];

    getline(fin, line); //salto linea con w e r che non serve

    for (int i = 0; i < n; i++)
    {
        getline(fin, line);
        stringstream sstr(line);
        string h;
        getline(sstr, h, ';');
        w[i] = stod(h);
        getline(sstr, h, ';');
        r[i] = stod(h);
    }

    fin.close();

    double R = 0;
    for (int i = 0; i < n; i++)
    {
        R += w[i] * r[i];
    }

    double V = S * (1 + R);

    fout << "S = " << fixed << setprecision(2) << S << endl << "n = " << n << endl; //visto che chiede 2 cifre significative: uso setprecision(2)

    fout << "w = [ ";
    for (int i = 0; i < n; i++)
    {
        fout << fixed << setprecision(2) << w[i] << " ";
    }
    fout << "]" << endl;

    fout << "r = [ ";
    for (int i = 0; i < n; i++)
    {
        fout << fixed << setprecision(2) << r[i] << " ";
    }
    fout << "]" << endl;

    fout << "Rate of return of the portfolio: " << fixed << setprecision(4) << R << endl; //4 cifre significative (vedi numero 0.0296)
    fout << "V= " << fixed << setprecision(2) << V << endl;

    //elimino puntatori dopo averli utilizzati:
    delete[] w;
    delete[] r;

    fout.close();

    ifstream f("result.txt"); //prendo dal file creato e printo anche a schermo
    char c;
    while (f.get(c))
    {
        cout << c;
    };
    f.close();

    return 0;
}
