#include <stdio.h>
#include <stdlib.h>

int menu(int flag, int A, int B){
    int opcion;
    if(flag==0){
    system("cls");
    printf("-----Manu de Opciones-----\n");
    printf("1.Ingresar primer operando (A=x)\n");
    printf("2.Ingresar segundo operando (B=y)\n");
    printf("3.Calcular suma (A+B)\n");
    printf("4.Calcular Resta (A-B)\n");
    printf("5.Calcular Division (A/B)\n");
    printf("6.Calcular Multiplicacion (A*B)\n");
    printf("7.Calcular Factorial (A!)\n");
    printf("8.Salir\n");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");
    }else if(flag==1){
    system("cls");
    printf("-----Manu de Opciones-----\n");
    printf("1.Ingresar primer operando (A= %d)\n",A);
    printf("2.Ingresar segundo operando (B=y)\n");
    printf("3.Calcular suma (A+B)\n");
    printf("4.Calcular Resta (A-B)\n");
    printf("5.Calcular Division (A/B)\n");
    printf("6.Calcular Multiplicacion (A*B)\n");
    printf("7.Calcular Factorial (A!)\n");
    printf("8.Salir\n");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");
    }else if(flag==2){
    system("cls");
    printf("-----Manu de Opciones-----\n");
    printf("1.Ingresar primer operando (A= %d)\n",A);
    printf("2.Ingresar segundo operando (B= %d)\n",B);
    printf("3.Calcular suma (A+B)\n");
    printf("4.Calcular Resta (A-B)\n");
    printf("5.Calcular Division (A/B)\n");
    printf("6.Calcular Multiplicacion (A*B)\n");
    printf("7.Calcular Factorial (A!)\n");
    printf("8.Salir\n");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");
    }
    return opcion;
    }
int sumar(int A, int B){
int rta;
rta = A+B;
return rta;
}
int restar(int A, int B){
    int rta;
    rta = A-B;
    return rta;
}
void dividir (int A, int B, char* mensaje, char* mensajeError){
    float rta;
    if(B!=0){
        rta =(float)A/B;
        printf("%s %.2f\n\n", mensaje, rta);
        }else{
        printf("%s\n\n", mensajeError);
    }

}
int multiplicar(int A, int B){
    int rta;
    rta = A*B;
    return rta;
}
void GetFactorial(int A, char* msj, char* msjError){
    int factorial=1;
    if(A>0){
    for(int i=1; i<=A; i++){
            factorial = factorial*i;
        }
        printf("%s %d\n", msj, factorial);
    }else{
    printf("%s\n\n", msjError);
    }

}
