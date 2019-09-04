#include <stdio.h>
#include <stdlib.h>
#include "juancc.h"
int main()
{
    char seguir='n';
    int operandoA;
    int operandoB;
    int flag=0;
    int result;
    do{
    switch(menu(flag, operandoA, operandoB)){
case 1:
    printf("Ingrese A: ");
    scanf("%d",&operandoA);
    flag=1;
    system("pause");
    break;
case 2:
    if(flag==1){
    printf("ingrese B: ");
    scanf("%d", &operandoB);
    flag=2;
    system("pause");
    }else{
    printf("Error. Debe ingresar el primer operando (A)\n\n\n");
    }
    break;
case 3:
    if(flag==2){
    result=sumar(operandoA, operandoB);
    printf ("El resultado de A+B es: %d\n\n\n", result);
    system("pause");
    }else{
            printf("Error. No ha ingresado los dos operandos\n\n");
    }
    break;
case 4:
    if(flag==2){
    result=restar(operandoA, operandoB);
    printf("El resultado de A-B es: %d\n\n\n", result);
    system("pause");
    }else{
        printf("Error. No ha ingresado los dos operandos\n\n");
    }
    break;
case 5:
    if(flag==2){
    dividir(operandoA, operandoB,"El resultado de A/B es: ", "Error, no se puede dividir por cero");
    }else{
        printf("Error. No ha ingresado los dos operandos\n\n");
    }
    system("pause");
    break;
case 6:
    if(flag==2){
    result=multiplicar(operandoA, operandoB);
    printf("El resultado de A*B es: %d\n", result);
    }else{
        printf("Error. No ha ingresado los dos operandos \n\n");
    }
    system("pause");
    break;
case 7:
    if(flag>=1){
    GetFactorial(operandoA, "El resultado de A! es: ", "Error, no se puede factorial cero o numeros negativos");
    }else{
        printf("Error. No ha ingresado el operando A \n\n");
    }
    system("pause");
    break;
case 8:
    printf("¿Confirma Salida? y/n ");
    fflush(stdin);
    scanf("%c", &seguir);
    break;
default:
    printf("Error. No ha ingresado opcion valida\n\n");
    system("pause");
    }
    }while(seguir=='n');
    return 0;
}
