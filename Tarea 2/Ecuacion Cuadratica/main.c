#include<stdio.h>
#include<math.h>
// 90/100
// Hubiese sido bueno usar funciones -10
int main(int argc, char** args){
   float a, b, c, disc, x1, x2, xi, xr;
   printf("Solucion de una ecuacion de segundo grado\n");
   printf("Escribe el valor de a --> \n");
   scanf("%f", &a);
   while(a==0){
   printf("El valor de a no puede ser 0 ingrese el valor de nuevo -->\n");
   scanf("%f", &a);
   }
   printf("Escribe el valor de b --> \n");
   scanf("%f", &b);
   printf("Escribe el valor de c --> \n");

   disc=pow(b, 2.0)-4*a*c;
   if(disc>0.0){
       printf("Las dos raices son reales");
       x1=((-b+sqrt(disc))/(2.0*a));
       x2=((-b-sqrt(disc))/(2.0*a));
       printf("\ntx1=%.2f   x2=%.2f", x1, x2);
   }
   else{
       if(disc==0.0){
           x1=(-b)/(2.0*a);
           printf("\nLa ecuacion solo tiene una raiz %.2f", x1);
       }
       else{
           xr=(-b/(2.0*a));
           xi=(sqrt(-disc)/(2.0*a));
           printf("\nLa raiz real es %.2f y la imaginaria es %.2f", xr, xi);
       }
   }
   printf("\n\n");
}
