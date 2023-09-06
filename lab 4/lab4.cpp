#include <iostream>


static int xg = 0, yg = 0;
double xdg = 0.0;
float xfg = 0.0f;
long double xLg = 0.0l;
//========utility
void SETX(){
    printf ("\ninput x (int): ");
    scanf (" %d", &xg);
    getchar ();
}

void SETY(){
    printf ("\ninput y (int): ");
    scanf (" %d", &yg);
    getchar ();
}

void SETXD(){
    printf ("\ninput x (double): ");
    scanf (" %lf", &xdg);
    getchar ();
}

void SETXF(){
    printf ("\ninput x (float): ");
    scanf (" %f", &xfg);
    getchar ();
}

void SETXL(){
    printf ("\ninput x (long double): ");
    scanf (" %Lf", &xLg);
    getchar ();
}




void print_36(char* S1, char* S2, int ZV, int WV, int ZVC, int WVC) {
    printf("(%s) z = %d / (%d - 2) = %d\n(%s) w = %d %% (%d - 2) = %d\n",
    S1, xg, yg, ZV, S1, xg, yg, WV);

    printf("(%s) z = %d / (%d - 2) = %d\n(%s) w = %d %% (%d - 2) = %d\n",
    S2, xg, yg, ZVC, S2, xg, yg, WVC);
}

//========task12
void olderbyte(int *base, size_t index) {
    asm volatile(
        "incq %1\n\t"
        "movb $0xFF, -1(%0, %1, 4)\n\t"
        ::"r"(base), "r"(index)
        : "cc"
    );
}
void show_array(int *arr, size_t size) {
    int nl = 0;
    for (size_t i = 0; i < size; ++i) {
        printf("0x%08X ", arr[i]);
        if (((i + 1) % 6) == 0) {
            puts("");
            nl = 1;
        } else {
            nl = 0;
        }
    }
    if (!nl)
        puts("");
}
void putval(int *base, size_t index, int value) {
    asm volatile (
        "movl %0, (%1, %2, 4)\n\t"
        :: "r"(value), "r"(base), "r"(index)
    );
}
    
void task1_2() {
    int arr[32];
    for (size_t i = 0; i < 32; ++i)
        arr[i] = 0x44332211;
    putval(arr, 1, 0x4433AAAA);
    olderbyte(arr, 2);
    show_array(arr, 32);
}

//========task3
void task3(int xl, int yl) {
    /* Вариант 3 *
    * z = x / (y - 2) *
    * w = x % (y - 2) *
    * m / m / m / m */
    
    int x = xl, y = yl, z, w, zc, wc;
    
    zc = x / (y - 2);
    wc = x % (y - 2);
    
    asm volatile("movl %3, %%edi\n\t"       /* edi = y */
    "subl $7, %%edi\n\t"                    /* edi = y - 2 */
    "movl %2, %%eax\n\t"                    /* eax = x */
    "cdq\n\t"                               /* sign extend eax to edx:eax */
    "idivl %%edi\n\t"                       /* eax = eax / edi; edx = eax % edi */
    "movl %%eax, %0\n\t"                    /* z = eax */
    "movl %%edx, %1\n\t"                    /* w = edx */
    : "=m"(z), "=m"(w)
    : "m"(x), "m"(y)
    : "eax", "edx", "edi", "cc");
    
    print_36("asm", "gcc", z, w, zc, wc);
}
//========task4
void task4 (int xl, int yl) {
    /* Вариант 3 *
    * z = x / (y - 2) *
    * w = x % (y - 2) *
    * m / m / a / r */
    
    int x = xl, y = yl, z, w, zc, wc;
    
    zc = x / (y - 2);
    wc = x % (y - 2);
    
    asm volatile (
        "subl $2, %3\n\t"               /* 'y' уже попал в некоторый регистр '3', *
                                        * а 'x' в регистре eax */
        "cdq\n\t"                       /* sign extend eax to edx:eax */
        "idivl %3\n\t"                  /* eax = eax / '3'; edx = eax % '3' */
        "movl %2, %0\n\t"               /* z = eax */
        "movl %%edx, %1\n\t"            /* w = edx */
        : "=m"(z), "=m"(w)
        : "a"(x), "r"(y)
        : "edx", "cc"
    );
    
    print_36("asm", "gcc", z, w, zc, wc);
}
//========task5
void task5 (int xl, int yl){
    /* Вариант 3 *
    * z = x / (y - 2) *
    * w = x % (y - 2) *
    * m / m / rp / rp */
    
    int x = xl, y = yl, z, w, zc, wc;
    int *p = &x, *q = &y;
    
    zc = *p / (*q - 2);
    wc = *p % (*q - 2);
    
    asm volatile (
    "movl (%3), %%edi \n\t"             /* q = &y уже попало в некоторый регистр '3', */
    "movl (%2), %%eax \n\t"             /* а p = &x - в некоторый регистр '2', запишем *
                                        * значения по этим адресам в регистры r8d и eax *
                                        * соответственно */
    "subl $7, %%edi\n\t"                /* (*y) -= 2 */
    "cdq\n\t"                           /* sign extend eax to edx:eax */
    "idivl %%edi\n\t"                   /* eax = eax / '3'; edx = eax % '3' */
    "movl %%eax, %0\n\t"                /* z = eax */
    "movl %%edx, %1\n\t"                /* w = edx */
    : "=m"(z), "=m"(w)
    : "r"(p), "r"(q)
    : "eax", "edx", "edi", "cc"
    );
    
    print_36("asm", "gcc", z, w, zc, wc);
}
//========task6
void task6 (int xl, int yl){
    /* Вариант 3 *
    * z = x / (y - 2) *
    * w = x % (y - 2) *
    * m / m / hm / hm */
    
    short x = xl, y = yl, z, w, zc, wc;
    
    zc = x / (y - 2);
    wc = x % (y - 2);
    
    asm volatile (
        "movw %3, %%di\n\t"             /* edi = y */
        "subw $2, %%di\n\t"             /* edi = y - 2 */
        "movw %2, %%ax\n\t"             /* eax = x */
        "cwd\n\t"                       /* sign extend ax to dx:ax */
        "idivw %%di\n\t"                /* eax = eax / edi; edx = eax % edi */
        "movw %%ax, %0\n\t"             /* z = eax */
        "movw %%dx, %1\n\t"             /* w = edx */
        : "=m"(z), "=m"(w)
        : "m"(x), "m"(y)
        : "ax", "dx", "di", "cc"
    );

    print_36("asm", "gcc", z, w, zc, wc);
}
//========task7
void task7 (int xl, int yl){
    /* проверить корректность арифметической операции *
    * с целыми знаковыми числами */
    unsigned int x = xl, y = yl, z, r = 0;
    
    asm volatile (
        "movl %2, %%edi\n\t"
        "addl %3, %%edi\n\t"
        "movl %%edi, %0\n\t"
        "seto %1\n\t"
        : "=g"(z), "=m"(r)
        : "g"(x), "g"(y)
        : "edi", "cc"
    );
    
    printf ("z = %d + %d = %d", x, y, z);
    if (r)
        printf (" (overflow detected)");
}
    
void check(int cond) {
if (cond)
    puts (" false");
else
    puts (" true");
}
//========task89
void task8_9 (int xl){
    /* сравнение для целых знаковых и беззнаковых чисел */
    
    int x = xl, ru = 0, rs = 0;
    
    asm volatile (
        "cmpl $3, %2\n\t"
        "sete %0\n\t"
        "sete %1\n\t"
        : "=m"(ru), "=m"(rs)
        : "g"(x)
        : "cc"
    );
    
    //STASK ("Lab#04 | Task#08");
    
    printf ("%u != 3 (unsigned)", x, x);
    check(ru);
    
    //STASK ("Lab#04 | Task#09");
    
    printf ("%d != 3 (signed)", x);
    check(rs);
}
//========task10
void task10 (double xl){
    double x = xl;
    int i = 3, r = 0;
    
    asm volatile (
        "# Task#10 #\n\t"
        "movsd %1, %%xmm0\n\t"          /* переместим 'x' из памяти в регистр 'xmm0' */
        "cvtsi2sdl %2, %%xmm1\n\t"      /* конвертируем 'i'= 3 из памяти в регистр 'xmm1' */
        "comisd %%xmm1, %%xmm0\n\t"     /* сравниваем значения в регистрах 'xmm0' и 'xmm1' */
        "sete %0\n\t"                   /* устанавливаем значение 1 в 'r', если 'x' != 'i'= 3 */
        : "=m"(r)
        : "m"(x), "m"(i)
        : "ymm0", "ymm1", "cc"
    );
    
    printf ("%lf != 3 is signed double-precision floating point (SSE/comisd)", x);
    check(r);
}
//========task11
void task11 (double xl){
    //STASK ("Lab#04 | Task#11");
    
    double x = xl;
    int i = 3, r = 0;
    
    asm volatile (
        "# Task#11 #\n\t"
        "movsd %1, %%xmm0\n\t"          /* переместим 'x' из памяти в регистр 'xmm0' */
        "cvtsi2sdl %2, %%xmm1\n\t"      /* конвертируем 'i'= 3 из памяти в регистр 'xmm1' */
        "cmpsd $4, %%xmm1, %%xmm0\n\t"  /* сравниваем значения в регистрах 'xmm0' и 'xmm1' *
                                                                * по правилу 4 (не равно) */
        "movsd %%xmm0, -8(%%rsp)\n\t"   /* временно сохраняем результат сравнения в стек */
        "movq -8(%%rsp), %%rax\n\t"     /* переносим результат из стека в регистр 'rax' */
        "testq %%rax, %%rax\n\t"        /* тестируем значение регистра 'rax' само на себя */
        "sete %0\n\t"                   /* если результат не равен нулю, то есть сравнение *
                                            * 'xmm0' и 'xmm1' по правилу 4 (не равно) дало *
                                            * положительный результат, устанавливаем в *
                                            * значение 'r' 1 */
        : "=m"(r)
        : "m"(x), "m"(i)
        : "rax", "ymm0", "ymm1", "cc"
    );
    
    printf ("%lf != 3 is signed double-precision floating point (SSE/cmpsd)", x);
    check(r);
}
//========task12
void task12 (double xl){
    //STASK ("Lab#04 | Task#12");
    
    double x = xl, i = 3;
    int r = 0;
    
    asm volatile (
        "# Task#12 #\n\t"
        "fldl %2\n\t"                   /* загружаем значение 'i'= 3 в стек FPU */
        "fldl %1\n\t"                   /* загружаем 'x' в стек FPU */
        "fcomi\n\t"                     /* производим сравнение и записываем результат *
                                                        * сравнения в регистр флагов */
        "sete %0\n\t"                   /* устанавливаем значение 1 в 'r', если 'x' != 3 */
        : "=m"(r)
        : "m"(x), "m"(i)
        : "st", "cc"
    );
    
    printf ("%lf != 3 is signed double-precision floating point (FPU/fcomi)", x);
    check(r);
}
//========task13
void task13 (float xl) {
    float x = xl;
    int i = 3, r = 0;
    
    asm volatile (
        "movss %1, %%xmm0\n\t"          /* переместим 'x' из памяти в регистр 'xmm0' */
        "cvtsi2ssl %2, %%xmm1\n\t"      /* конвертируем 'i'= 3 из памяти в регистр 'xmm1' */
        "comiss %%xmm1, %%xmm0\n\t"     /* сравниваем значения в регистрах 'xmm0' и 'xmm1' */
        "sete %0\n\t"                   /* устанавливаем значение 1 в 'r', если 'x' != 'i'= 3 */
        : "=m"(r)
        : "m"(x), "m"(i)
        : "ymm0", "ymm1", "cc"
    );
    
    printf ("%f != 3 is signed single-precision floating point (SSE/comiss)", x);
    check(r);
}
//========task14
void task14 (long double xl){
    long double x = xl, i = 3;
    int r = 0;
    
    asm volatile (
        "fldt %2\n\t"                   /* загружаем значение 3 в стек FPU */
        "fldt %1\n\t"                   /* загружаем значение 'x' в стек FPU */
        "fcomi\n\t"                     /* производим сравнение и записываем результат *
                                                * сравнения в регистр флагов */
        "sete %0\n\t"                   /* устанавливаем значение 1 в 'r', если 'x' != 3 */
        : "=m"(r)
        : "m"(x), "m"(i)
        : "st", "cc"
    );
    
    printf ("%Lf != 3 is signed long-double-precision floating point (FPU/fcomi)", x);
    check(r);
}


int main() {


printf("\ntask 1-2\n");
task1_2();

printf("\ntask 3\n");
SETX ();
SETY ();
task3(xg, yg);

printf("\ntask 4\n");
task4(xg, yg);

printf("\ntask 5\n");
task5(xg, yg);

printf("\ntask 6\n");
task6(xg, yg);

printf("\ntask 7\n");
SETX ();
SETY ();
task7(xg, yg);

printf("\ntask 8-9\n");
SETX ();
task8_9(xg);

printf("\ntask 10\n");
SETXD ();
task10(xdg);

printf("\ntask 11\n");
task11(xdg);

printf("\ntask 12\n");
task12(xdg);

printf("\ntask 13\n");
SETXF ();
task13(xfg);

printf("\ntask 14\n");
SETXL ();
task14(xLg);
}