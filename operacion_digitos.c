#include <stdio.h>
#include <math.h>

int segmentarNum_operar(int numero, char operacion){
    int dig1, dig2, dig3;
    
    //numero_3cifras=(dig1)(dig2)(dig3)
    dig1 = numero/100;
    dig2=(numero-dig1*100)/10;
    dig3 = numero%10;

    return (operacion=='+') ? (dig1+dig2+dig3): (dig1*dig2*dig3);
}

int main(){
    int num;
    char oper;

    printf("Ingrese operacion: ");
    scanf("%c", &oper);
    printf("Ingrese numero de 3 digitos: ");
    scanf("%d", &num);

    printf("Resultado => %d", segmentarNum_operar(num, oper));

    return 0;
}