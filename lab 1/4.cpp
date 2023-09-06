#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

template<typename T>
string intToHex(T i)
{
    string result;
    // Я еще не понял как ниже это работает, надо прочитать
    stringstream stream;
    stream << hex << i;
    for(int buf = stream.str().length();buf < 17;buf++) {
        result += "0";
    }
    result += stream.str();
    
    return result;
}

template <typename T>
string addZeros(T value) {
    string result = intToHex(value);
    cout << result << endl;

    return result;
}

template <typename T>
void init(T arr, int N, double x) {
    for (int i = 0;i < N; i++) {
        arr[i] = x;
    }
}

template <typename T>
void printArre(T arr, int N) {
    printf("%e", arr[0]);
    for (int i = 1;i < N; i++) {
        printf(", %e", arr[i]);
    }
    printf("\n");
}

template <typename T>
void printArrd(T arr, int N) {
    printf("%llu", arr[0]);
    for (int i = 1;i < N; i++) {
        printf(", %llu", arr[i]);
    }
    printf("\n");
}

template <typename T>
void printArrf(T arr, int N) {
    printf("%.2f", arr[0]);
    for (int i = 1;i < N; i++) {
        printf(", %.2f", arr[i]);
    }
    printf("\n");
}

template <typename T>
void printArrx(T arr, int N) {
    printf("%llX", arr[0]);
    for (int i = 1;i < N; i++) {
        printf(", %llX", arr[i]);
    }
    printf("\n");
}

int main()
{
    double x = 2./3;
    int N = 5;
// Мб вообще надо без шаблонов сделать, а то они ко всем типам 
// применяют одинаковые параметры в печати
    unsigned short* Ms = new unsigned short[N];
    unsigned int* Ml = new unsigned int[N];
    unsigned long long* Mq = new unsigned long long[N];
    float* Mfs = new float[N];
    double* Mfl = new double[N];

    init(Ms, N, 0xDEAD);
    init(Ml, N, 0xC0CAC01A);
    init(Mq, N, 0xC0FFEE11BEA7);
    init(Mfs, N, x);
    init(Mfl, N, x);

    printf("d:\n");

    printArrd(Ms, N);
    printArrd(Ml, N);
    printArrd(Mq, N);
    printArrf(Mfs, N);
    printArrf(Mfl, N);
    printArre(Mfs, N);
    printArre(Mfl, N);

    printf("x:\n");

    printArrx(Ms, N);
    printArrx(Ml, N);
    printArrx(Mq, N);
    printArrx(Mfs, N);
    printArrx(Mfl, N);

    addZeros(Ms[0]);
    addZeros(Ml[0]);
    addZeros(Mq[0]);

    delete[] Ms;
    delete[] Ml;
    delete[] Mq;
    delete[] Mfs;
    delete[] Mfl;
    return 0;
}