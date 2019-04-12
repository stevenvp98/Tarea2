#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



struct estudiantes{
  char nombre[20];
  int matricula;
  char apellido[20];
  int telefono[20];
   char carrera[20];
   char asignaturas[20];
char nota[1];
};

typedef struct estudiantes ESTUD;

struct agregarcarrera{
  char carrera[50];
  char codigocarrera[3];
  char matperiodo1[30];
  char matperiodo2[30];
};
typedef struct agregarcarrera AC;


  int main(){
  char opcion;
  int e,i,j,m,c1,c2,mat,caltotal,credtotal;
  float indice;
  ESTUD ESTU[5];
  ESTUD ASIGNATURAS[15];
  AC CARRERAS[5];
  ESTUD NOTA[5];



inicio:

  printf("Opcion 1: INSCRIPCION\n",162);
  printf("Opcion 2: CARRERAS\n",162);
  printf("Opcion 3: ASIGNATURAS Y CALIFICACIONES\n",162);
  printf("Opcion 4: VISUALIZAR CALIFICACIONES\n",162);
  printf("Opcion 5: INDICE ACUMULADO\n",162);
  printf("Opcion 7: SALIR\n\n",162);



  do
  {
    printf("Seleccionar opcion: ");
    fflush( stdin );
    scanf("%s", &opcion);
  }

  while ( opcion < '1' || opcion > '7' );
  switch( opcion )
   {
     case '1':
     system("cls");
     printf("Cantidad de estudiantes a inscribir : ");
     scanf("%i",&e);
     for(i=0;i<e;i++){

       printf("Nombre del estudiante #%i: ",i+1);
       scanf("%s",&ESTU[i].nombre);
       printf("Apellido del estudiante #%i" ,i+1);
       scanf("%s",&ESTU[i].apellido);
       printf("Matricula del estudiante #%i: ",i+1);
       scanf("%i",&ESTU[i].matricula);
       printf("Telefono del estudiante #%i: ",i+1);
       scanf("%i",&ESTU[i].telefono);
       printf("Carrera del estudiante #%i: ",i+1);
       scanf("%s",&ESTU[i].carrera);
       printf("Cantidad de asignaturas cursadas #%i: ",i+1);
       printf("0= No ha cursado materias");
       scanf("%i",&m);
if(m==0){
  system("cls");
  goto inicio;
  system("cls");}
        for(j=0;j<m;j++){
        printf("Diga la materia #%i",j+1);
        scanf("%s",&ASIGNATURAS[j].asignaturas);
}
     }


  system("cls");
  goto inicio;
  system("cls");

case '2':
      system("cls");
      printf("Cantidad de carreras a agregar : ");
      scanf("%i",&e);
for(i=0;i<e;i++){
  printf("Escriba el nombre de la carrera: ");
  scanf("%s",&CARRERAS[i].carrera);
  printf("Escriba el codigo de la carrera: ");
  scanf("%s",&CARRERAS[i].codigocarrera);
  printf("Escriba cuantas materias tiene el primer ciclo: ");
  scanf("%i",&c1);

  for(j=0;j<c1;j++){
  printf("Nombre de la materia #%i : ",j+1);
  scanf("%s",&CARRERAS[j].matperiodo1);
}
  printf("Cantidad de asignaturas del segundo ciclo: ");
  scanf("%i",&c2);

  for(j=0;j<c2;j++){
  printf("Nombre de la materia #%i : ",j+1);
  scanf("%s",&CARRERAS[j].matperiodo2);
}
system("cls");
goto inicio;

}

case '3':
    system("cls");
      printf("Agregar asignaturas a estudiante\n");
      for(i=0;i<e;i++){
        printf("%s\t",&ESTU[i].nombre);
        printf("%s\t",&ESTU[i].apellido);
        printf("%i\t",&ESTU[i].matricula);
        printf("%i\t",&ESTU[i].telefono);
        printf("%s\n",&ESTU[i].carrera);

      }
printf("Introduzca la matricula a modificar: ");
scanf("%i",&mat);

for(i=0;i<e;i++){
  if(mat==ESTU[i].matricula){
    printf("Selecciono al estudiante %s\n\n",&ESTU[i].nombre);
    printf("Cantidad de asignaturas seleccionadas: ");
    scanf("%i",&m);
    if(m==0){
      system("cls");
      goto inicio;
      system("cls");}

    for(j=0;j<m;j++){
    printf("Escriba la asginatura #%i",j+1);
    scanf("%s",&ASIGNATURAS[j].asignaturas);
    printf("Escriba la calificacion de dicha asignatura: ");
    scanf("%s\n",&NOTA[j].nota);
    }

  }
}
system("cls");

goto inicio;

case '4':
  system("cls");
  printf("Introduzca Matricula: ");
  scanf("%i",&mat);

  for(i=0;i<e;i++){
    if(mat==ESTU[i].matricula){
    printf("Selecciono al estudiante %s\n\n",&ESTU[i].nombre);
  for(j=0;j<m;j++){
    printf("%s\t",&ASIGNATURAS[j].asignaturas);
    printf("%s\n",&NOTA[j].nota);
  }

}
else{printf("\nMatricula no existente\n");}
system("cls");

goto inicio;}

case '5':
system("cls");
for(i=0;j<e;i++){
  printf("Indice acomulado para matricula",ESTU[i].matricula);
  credtotal=0;
  caltotal=0;
for(j=0;j<m;j++){
  if(NOTA[i].nota=='a' ||NOTA[i].nota== 'A'){credtotal=credtotal+5; caltotal=caltotal+4;  }
  if(NOTA[i].nota=='b' ||NOTA[i].nota== 'B'){credtotal=credtotal+5; caltotal=caltotal+3;  }
  if(NOTA[i].nota=='c' ||NOTA[i].nota== 'C'){credtotal=credtotal+5; caltotal=caltotal+2;  }
  if(NOTA[i].nota=='d' || NOTA[i].nota=='D'){credtotal=credtotal+5; caltotal=caltotal+1;  }
  if(NOTA[i].nota=='f' ||NOTA[i].nota== 'F'){credtotal=credtotal+5; caltotal=caltotal+0;  }
}
indice=caltotal/credtotal;
printf("Indice acumulado de periodo #%i es : %f",i+1,indice);
}
goto inicio;
system("cls");
   } while ( opcion != '7' );


return 0;
}
