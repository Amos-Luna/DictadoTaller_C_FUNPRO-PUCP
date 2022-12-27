#include <stdio.h>
#include <math.h>

double calcula_distancia(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

double calcula_pendiente(int x1, int y1, int x2, int y2){
    return (y1-y2)/(x1-x2);
}

double calcula_area_trapecio(int x1, int y1, int x2, int y2, double dAB, double dDC, double mDC){
    double altura;
    altura=fabs((mDC*x1-y1+(y2-mDC*x1))/(sqrt(pow(mDC,2)+pow(-1,2))));
    return ((dAB+dDC)*altura)/(double)2;
}

int main(){
    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, paralelismo_AB_DC, dif_tamanos_AB_DC, no_paralelismo_AB_ADyAC;
    int no_paralelismo_DC_ADyAC, no_perpendiculares_AB_ADyAC,no_perpendiculares_DC_ADyAC;
    int no_paralelismo_AD_BC, igual_tamanos_AD_BC; 
    double mAB, mDC, dAB, dDC, mBC, dBC, mDA, dDA, perimetro, area;

    printf("Ingrese los PA, PB, PC y PD: ");
    scanf("%d %d %d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);

    //idea es verificar si esos 4 puntos forman un TRAPECIO ISOSCELES

    mAB = calcula_pendiente(Ax, Ay, Bx, By);
    dAB = calcula_distancia(Ax, Ay, Bx, By);

    mBC = calcula_pendiente(Bx, By, Cx, Cy);
    dBC = calcula_distancia(Bx, By, Cx, Cy);

    mDC = calcula_pendiente(Dx, Dy, Cx, Cy);
    dDC = calcula_distancia(Dx, Dy, Cx, Cy);

    mDA = calcula_pendiente(Dx, Dy, Ax, Ay);
    dDA = calcula_distancia(Dx, Dy, Ax, Ay);

    //condicion AB//DC
    paralelismo_AB_DC = (mAB==mDC) ? 1 : 0; //1=yes, 0=no
    dif_tamanos_AB_DC = (dAB != dDC) ? 1 : 0;

    no_paralelismo_AB_ADyAC = ((mAB!=mDA) && (mAB!=mBC)) ? 1 : 0;
    no_paralelismo_DC_ADyAC = ((mDC!=mDA) && (mDC!=mBC)) ? 1 : 0;

    no_perpendiculares_AB_ADyAC = (mAB*mDA==(double)-1) && (mAB*mBC==(double)-1) ? 1 : 0;
    no_perpendiculares_DC_ADyAC = (mDC*mDA==(double)-1) && (mDC*mBC==(double)-1) ? 1 : 0;

    //condicion AD Y BC
    no_paralelismo_AD_BC = (mDA!=mBC) ? 1 : 0;
    igual_tamanos_AD_BC = (dDA == dBC) ? 1 : 0;

    if (paralelismo_AB_DC==dif_tamanos_AB_DC==no_paralelismo_AB_ADyAC==no_paralelismo_DC_ADyAC==no_paralelismo_AD_BC==igual_tamanos_AD_BC){
        
        perimetro = dAB + dBC + dDA + dDC;
        area = calcula_area_trapecio(Bx, By, Cx, Cy, dAB, dDC, mDC);

        printf("Los puntos ingresados forman un trapecio isosceles\n");
        printf("El area del trapecio isosceles es: %lf\n", area);
        printf("El perimetro del trapecio isosceles es: %lf", perimetro);
    }
    else{
        printf("Los puntos ingresados NO forman un trapecio isosceles");
    }

    return 0;
}