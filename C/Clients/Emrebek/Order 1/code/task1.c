#include <stdio.h>

//Drake equation function definition
int drake_equation(double R,double fp, int ne, double fl, double fi, double fc, int L){
    int N; //number of intelligent civilization
    N = (R * fp * ne * fl * fi * fc * L);
    return N;
}

int main() {

    // set 1
    printf("N=%i R*=%.1f fp=%.1f ne=%i fl=%.1f fi=%.1f fc=%.1f L=%i\n", drake_equation(1.0,0.2,1,1.0,1.0,0.1,1000),1.0,0.2,1,1.0,1.0,0.1,1000);

    // set 2
    printf("N=%i R*=%.1f fp=%.1f ne=%i fl=%.1f fi=%.1f fc=%.1f L=%i\n", drake_equation(1.0,0.5,5,1.0,1.0,0.2,1000000000),1.0,0.5,5,1.0,1.0,0.2,1000000000);

    // set 3
    printf("N=%i R*=%.1f fp=%.1f ne=%i fl=%.1f fi=%.1f fc=%.1f L=%i\n", drake_equation(1.5,1.0,3,1.0,0.0001,0.001,304),1.5,1.0,3,1.0,0.0001,0.001,304);

    // set 4
    printf("N=%i R*=%.1f fp=%.1f ne=%i fl=%.1f fi=%.1f fc=%.1f L=%i\n", drake_equation(3.0,1.0,5,1.0,1.0,0.1,10000000),3.0,1.0,5,1.0,1.0,0.1,10000000);
    return 0;


}



