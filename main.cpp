#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
using namespace std;
//-----------------------------------------FUNCIONES
//Ejercicio numero 2 de la guia
void fun_c(double *a, int n,double *promedio, double *suma);
void fun_c(double *a, int n,double *promedio, double *suma){
    int i;
    *suma=0.0;
    for(i=0;i<n;i++){
        *suma+=(*a+i);
    }
    *promedio=(*suma /n);
    cout<<promedio<<endl;
}
int CharInt(char eo);
int CharInt(char eo){
    int numero;
    numero=eo-'0';
    return numero;
 }
//Combrueba si el caracter es un numero
char comprobar(char u);
char comprobar(char u){
    char lista[11]={'1','2','3','4','5','6','7','8','9','0'};
    bool r=false;
    for(int i=0;lista[i]!=0;i++){
        if(u==lista[i]){
            r=true;
            break;
        }
    }
    return r;
  }
char comprobar_cadena(char u);
char comprobar_cadena(char u){
    char lista[11]={'1','2','3','4','5','6','7','8','9','0'};
    bool r=false;
    int c=0;
    for(int i=0;lista[i]!=0;i++){
        if(u==lista[i]){
            c=1;
            break;
        }
    }
    if(c==1){
        r=true;
    }
    return r;
  }


int factorial(int n);
int factorial(int n){
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
   }
//Valida la entrada de un numero como char y los convierte a entero
int validar_numero(char *n);
int validar_numero(char *n){
    int ni;
    while(true){
        if(comprobar(n[0])){
           ni=atoi(n);
           break;
        }
        else{
            cout<<"Ingrese un valor numerico por favor"<<endl;
            cout<<"Ingrese el valor nuevamente: ";
            cin>>n;
            cout<<endl;
        }
    }
    return ni;
}

//--------------------------------------------------
int main()
{
 cout<<"PRACTICA NUMERO 2"<<endl;
 char numero_ejercicio[1]={};
 int numeroswitch;
 cout<<"Seleccione el ejercicio a revisar: ";
 cin>>numero_ejercicio;
 numeroswitch=validar_numero(numero_ejercicio);

 switch(numeroswitch){
 case 2: {
  int i,i2, contador=0,letra=0;
  char ListaDeCaracteres[200]={},ABC[26];
  srand(time(0));
 for(i=0;i<26;i++){
     letra=('A'+rand()%26);
     int letra2=0;
     while(letra2<i){
         if(letra!=ABC[letra2]){
             letra2++;
        }
         else{
                 letra=('A'+rand()%26);
                 letra2=0;
             }
     }

     ABC[i]=letra;
 }
 srand(time(NULL));
  for(i=0;i<200;i++){
      ListaDeCaracteres[i]=('A'+rand()%26);
  }
  cout<<"El arreglo es: "<<ListaDeCaracteres<<endl;
  for(i=0;i<26;i++){
      for(i2=0;i2<200;i2++){
          if(ABC[i]==ListaDeCaracteres[i2]){
              contador++;
          }
      }
      cout<<ABC[i]<<" se repite "<<contador<<" veces"<<endl;
      contador=0;
  }
  break;
 }
 case 4:{ //FALTA POR TERMINAR

     char NumeroIngresado[]={};
     int NumeroConvertido;
     cout<<"Ingrese un numero por favor: ";
     cin>>NumeroIngresado;
     NumeroConvertido=atoi(NumeroIngresado);
     cout<<"Se transformo el numero: "<<NumeroConvertido<<endl;
     break;
     }
  case 6:{
     char PalabraIngresada[]={};
     cout<<"Ingrese una palabra o una oracion: ";
     cin>>PalabraIngresada;
     strupr(PalabraIngresada);
     cout<<"Palabra convertida a Mayusculas: "<<PalabraIngresada<<endl;
     break;
 }
 case 8:{
     char PalNum[]={};
     cout<<"Ingrese la cadena de texto: "<<endl;
     cin>>PalNum;
     cout<<"Numeros: ";
     //Imprime los numeros de la cadena de texto
     for(int i=0; PalNum[i]!='\0'; i++){
         if(comprobar(PalNum[i])){
             cout<<PalNum[i];
                }
     }
     cout<<"\nLetras: ";
     //Imprime las letras de la cadena de texto
     for(int i=0; PalNum[i]!='\0'; i++){
         if(comprobar(PalNum[i])==false){
             cout<<PalNum[i];
         }
      }
     cout<<"\n";
    break;
    }
 case 10:{
       int i, total=0, valor,antvalor=0;
       char numerointro[]={};
       cout<<"Ingrese el numero: ";
       cin>>numerointro;
       strupr(numerointro);
       for(i=0;numerointro[i]!='\0';i++){
           switch (numerointro[i]) {
           case 'I': valor=1; break;
           case 'V': valor=5; break;
           case 'X': valor=10; break;
           case 'L': valor=50; break;
           case 'C': valor=100; break;
           case 'D': valor=500; break;
           case 'M': valor=1000; break;
           default: break;
           }
           if (total==0){
               total+=valor;
               antvalor=valor;
           }
           else if(antvalor>=valor){
               total+=valor;
               antvalor=valor;
           }
           else{
               total=(total-antvalor)+(valor-antvalor);
               antvalor=valor;
               if(total<0){
                total*=(-1);
               }
           }
         }
       cout<<"Valor en enteros: "<<total<<endl;
       break;
       }
 case 12:{
     int ic=0,jc=0,numeros[100][100],valores[100]={},filas, columnas, acumulador=0;
     cout<<"Ingrese el numero de filas y columnas: ";
     cin>>filas;
     columnas=filas;
     cout<<"POSICION[Fila][Columna]"<<endl;
     //El usuario ingresa los valores de la matriz nxn
     for(int i=0;i<filas;i++){
         for(int j=0;j<columnas;j++){
             cout<<"Posicion["<<(i+1)<<"]["<<(j+1)<<"], dijite el numero: ";
             cin>>numeros[i][j];
         }

 }  //Imprimo la matriz introduccida
     cout<<'\n';
     cout<<"La matriz introducida es: "<<endl;
     for(int i=0;i<filas;i++){ //HACER UNA FUNCION CON ESTE FOR##########################################
         for(int j=0;j<columnas;j++){
             cout<<" "<<numeros[i][j]<<" ";
         }
        cout<<"\n";
 }   //Añadir sumatoria de cada fila a la lista "valores"
     for(int i=0;i<filas;i++){
         acumulador=0;
         for(int j=0;j<columnas;j++){
             acumulador+=numeros[i][j];
         }
         valores[i]=acumulador;
     }
     //Añadir la sumatoria de cada columna a la lista "valores"
     for(int i=0;i<filas;i++){
         acumulador=0;
         for(int j=0;j<columnas;j++){
             acumulador+=numeros[j][i];
         }
         valores[(i+(filas))]=acumulador;
     }
    acumulador=0;
    //Calcula y añade el valor de la diagonal a la lista "valores"
    while(ic<filas){
        acumulador+=numeros[ic][jc];
        ic+=1;
        jc+=1;
    }
    valores[(filas*2)]=acumulador;
    acumulador=0;
    //Evaluo si es un en cubo magico, comparando cada una de las sumas anteriores
    for(int i=0;valores[i]!='\0';i++){
        if(valores[(i+1)]!='\0'){
            if(valores[i]!=valores[(i+1)]){
                acumulador+=1;
            }
      }
    }
    cout<<"\n";
    if(acumulador!=0){
        cout<<"La matriz ingresada no es un cubo magico."<<endl;
    }
    else{
        cout<<"La matriz ingresada si es un cubo magico."<<endl;
    }
    break;
 }
 case 14:{
     int matriz[5][5],matriz2[5][5],opcion,opcion2,contador=0;
     cout<<"Seleccione una de las siguientes opciones"<<"\n(1)Girar 90 grados"<<"\n(2)Girar 180 grados"<<"\n(3)Girar 270 grados"<<endl;
     cin>>opcion;
     //El usuario ingresa los valores para la matriz
     cout<<"Seleccione el modo de operar:"<<"\n(1)Introducir numeros"<<"\n(2)Usar valores al azar"<<endl;
     cin>>opcion2;
     if(opcion2==1){
         for(int i=0;i<5;i++){
             for(int j=0;j<5;j++){
                 while(true){
                     //El usario ingresa los valores
                     cout<<"Posicion["<<(i+1)<<"]["<<(j+1)<<"], dijite el numero: ";
                     cin>>matriz[i][j];
                     if(matriz[i][j]>25){
                         cout<<"Introduzca valores menores que 25"<<endl;
                     }
                     else{
                         break;
                     }
                 }
             }
         }
      }
     else{
         //Los valores se escogen al azar
         for(int i=0;i<5;i++){
             for(int j=0;j<5;j++){
                matriz[i][j]=(1+rand()%25);
             }
         }

     }
     //Imprimo la matriz original
     cout<<"Matriz original: "<<"\n"<<endl;
     for(int i=0;i<5;i++){
         for(int j=0;j<5;j++){
             cout<<'\t'<<matriz[i][j]<<'\t';
         }
        cout<<"\n";
     }
     while(contador<opcion){
         //Asigno los valores a la nueva matriz rotada
         for(int i=0;i<5;i++){
             for(int j=0;j<5;j++){
                matriz2[i][j]=matriz[(4-j)][(i)];
             }
         }
         contador+=1;
         //Reasigno valores para nuevamente rotar la maytriz
         for(int i=0;i<5;i++){
             for(int j=0;j<5;j++){
                matriz[i][j]=matriz2[i][j];
             }
         }
     }
     //Imprimo la matriz rotada
     cout<<"Matriz rotada: "<<"\n"<<endl;
     for(int i=0;i<5;i++){
         for(int j=0;j<5;j++){
             cout<<'\t'<<matriz2[i][j]<<'\t';
            }
        cout<<"\n";
     }
    break;
    }
 case 16:{
     char n[1]={};
     int ni,lado_malla;
     cout<<"Ingrese el valor del lado de la malla: ";
     cin>>n;
     ni=validar_numero(n); //Hago validar la entrada del usuario
     lado_malla=(factorial(ni+ni))/((factorial(ni))*(factorial(ni)));//Calculo el numero de caminos posibles
     cout<<"\nEl numero de caminos posibles es: "<<lado_malla<<endl;
     break;
    }
 case 18:{//FALTA POR TERMINAR ESTE EJERCICIO
     char n[]={};
     //int ni,contador=0;
     //long double i=123456789;
     cout<<"Ingrese el valor de lenesimo termino";
     cin>>n;
     //ni=validar_numero(n);
    break;
  }
 }
  return 0;
}





