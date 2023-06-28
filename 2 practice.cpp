#include <iostream>
using namespace std;

const int N = 8;

template<typename T> //шаблон
void Copying(T* mas1, T* mas2)
{
    cout << "Copying... " << endl;

    size_t* tmp1 = reinterpret_cast<size_t*>(mas1);
    size_t* tmp2 = reinterpret_cast<size_t*>(mas2);
    //cout << sizeof(*tmp1) << endl;
    //cout << sizeof(T) << endl; размер шаблона 4 байта т.к. int=4 байта
    for (int i = 0; i < N / (sizeof(*tmp1) / sizeof(T)); i++)
    {
        *tmp1 = *tmp2;
        tmp1++;
        tmp2++;
    }
}

template<typename T>
void Outp1(const T mas[N])
{
    cout << "Mas1: ";
    for (int i = 0; i < N; i++)
    {cout << mas[i] << " ";}
    cout << endl;
}

template<typename T>
void Outp2(const T mas[N])
{
    cout << "Mas2: ";
    for (int i = 0; i < N; i++)
    {cout << mas[i] << " ";}
    cout << endl;
}


int main()
{
    int mas1[N] = { 3, 1, 5, 2, 2 };
    int mas2[N] = { 99, 5, 3 };

    Outp1(mas1);
    Outp2(mas2);

    Copying(mas1, mas2); 

    Outp1(mas1);
    Outp2(mas2);
}