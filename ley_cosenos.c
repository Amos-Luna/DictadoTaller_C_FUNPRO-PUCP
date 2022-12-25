#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.141516

double funcion_calcula_lados(double lado1, double lado2, double angulo){
    double lado3;
    lado3 = sqrt(pow(lado1, 2) + pow(lado2, 2) - 2*lado1*lado2*cos(angulo*PI/(double)180));
    return lado3;
}

double funcion_calcula_angulos(double lado_frontal, double lado_ady_1, double lado_ady_2){
    double angulo;
    angulo = acos((pow(lado_ady_1,2)+pow(lado_ady_2,2)-pow(lado_frontal,2))/(2*lado_ady_1*lado_ady_2))*180/PI;
    return angulo;
}

int main(){
    double A, B, C, alpha, beta, teta;

    //ingresamos los datos
    printf("Ingrese el lado_A, lado_B y angulo alpha (en ese orden): ");
    scanf("%lf %lf %lf", &A, &B, &alpha);

    //creamos una funcion que calcula el lado C
    C = funcion_calcula_lados(A, B, alpha);
    printf("El lado_C es: %lf\n", C);

    //funcion que calcula los angulos beta y teta;
    beta = funcion_calcula_angulos(B, A, C);
    teta = funcion_calcula_angulos(A, B, C);
    printf("Los angulos beta y teta son, respectivamente: %lf %lf", beta, teta);

    return 0;
}



