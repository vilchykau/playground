#include <iostream>
/*
 * Все функция написанные с test_ нужны только для проверки решения, они решают алгоритм медленно но 100% верно
 * Самая важная функция - fast(double x, n). Именно она является решением.
 */
int test_fact(int n){
    if(n <= 1){
        return 1;
    }
    return test_fact(n-1)*n;
}

double test_power(double x, int n){
    double p = 1;
    for(int i = 0; i < n; ++i){
        p*=x;
    }
    return p;
}

double test_slow(double x, int n){
    double res = 1;
    for(int i = 1; i <= n; ++i){
        double sum1 = 0;
        for(int j = 1; j <= i; ++j){
            double pr2 = 1;
            for(int m = 1; m <= j; ++m){
                double sum2 = 0;
                for(int l = 1; l <= m; ++l){
                    sum2 += test_power(x, l);
                }
                pr2 *= sum2;
            }
            sum1 += (pr2)/test_fact(j);
        }
        res *= sum1;
    }
    return res;
}

double fast(double x, int n){
    if(n == 0){
        return 0;
    }

    double sum2 = x;  //Внутренняя сумма. При n = 1, она равна x.
    double mult2 = x; //Внутреннее произведение. При n = 1, оно равно x.
    double sum1 = x;  //Внешняя сумма. При n = 1, она равна x.
    double mult1 = x; //Внешнее произведение. При n = 1, оно равно x.
    double power = x; //x^l при n = 1, равно x
    int fact = 1;     // !j при n=1, равен 1

    for(int i = 2; i <= n; ++i){ // выполняется, если n >= 2
        power *= x;            //x^l, по сравнению с предыдущим разом, увеличилось в x раз(x^l = x^(l-1) * x)
        sum2 += power;         //сумма, по сравнению с предыдущим разом, увеличилось на x^l
        mult2 *= sum2;         //Произведение увеличилось в sum2 раз(mul2 хранит в себе прозведения сумм при m = 1, m = 2......)
        fact *= i;              //..........
        sum1 += (mult2)/fact;
        mult1 *= sum1;
    }

    return mult1;
}

int main() {
    std::cout << test_slow(4, 4) << "  -  " << fast(4, 4);
    return 0;
}