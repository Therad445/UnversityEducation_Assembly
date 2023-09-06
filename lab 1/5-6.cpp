#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

template<typename T>
string intToHex(T i)
{
    string result;
      
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
    printf("%d", arr[0]);
    for (int i = 1;i < N; i++) {
        printf(", %d", arr[i]);
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

int task5_6()
{
    double x = 2.0/3;
    int N = 5, i = 2;

    uint8_t* Mb = new uint8_t[N];
    unsigned short* Ms = new unsigned short[N];
    unsigned int* Ml = new unsigned int[N];
    unsigned long long* Mq = new unsigned long long[N];
    float* Mfs = new float[N];
    double* Mfl = new double[N];

    init(Mb, N, 0xED);
    init(Ms, N, 0xDEAD);
    init(Ml, N, 0xC0CAC01A);
    init(Mq, N, 0xC0FFEE11BEA7);
    init(Mfs, N, x);
    init(Mfl, N, x);

    printf("d:\n");

    printArrd(Mb, N);
    printArrd(Ms, N);
    printArrd(Ml, N);
    printArrd(Mq, N);
    printArrd(Mfs, N);
    printArrd(Mfl, N);

    printf("x:\n");

    printArrx(Mb, N);

    printf("\nunsigned int8: ");
    int res = scanf("%hhu", Mb);
    swap(Mb[0], Mb[i]);
    printf("result scanf = %d\n", res);

    printArrd(Mb, N);
  
    printf("\nunsigned short: ");
    res = scanf("%hu", Ms);
    swap(Ms[0], Ms[i]);
    printf("result scanf = %d\n", res);

    printArrd(Ms, N);

    printf("\nunsigned int: ");
    res = scanf("%d", Ml);
    swap(Ml[0], Ml[i]);
    printf("result scanf = %d\n", res);

    printArrd(Ml, N);

    printf("\nunsigned long long: ");
    res = scanf("%llu", Mq);
    swap(Mq[0], Mq[i]);
    printf("result scanf = %d\n", res);

    printArrd(Mq, N);

    printf("\nfloat: ");
    res = scanf("%f", Mfs);
    swap(Mfs[0], Mfs[i]);
    printf("result scanf = %d\n", res);

    printArrf(Mfs, N);

    printf("\ndouble: ");
    res = scanf("%lf", Mfl);
    swap(Mfl[0], Mfl[i]);
    printf("result scanf = %d\n", res);

    printArrf(Mfl, N);

    delete[] Ms;
    delete[] Ml;
    delete[] Mq;
    delete[] Mfs;
    delete[] Mfl;
    return 0;
}