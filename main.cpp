#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
//-----------------------------------------FUNCIONES
//Ejercicio numero 2 de la guia
void fun_c(double *a, int n,double *promedio);
void fun_c(double *a, int n,double *promedio){
    int i;
    float suma=0.0;
    for(i=0;i<n;i++){
        suma+=(*a+i);
    }
    *promedio=(suma /n);
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


int factorial(int n);//Encuentra el factorial de un numero
int factorial(int n){
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
   }

int validar_numero(char *n);//Valida la entrada de un numero como char y los convierte a entero
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
//PROBLEMA NUMERO 4
int Ejercicio_4();
int Ejercicio_4(){
    char NumeroIngresado[]={};
    int NumeroConvertido;
    cout<<"Ingrese un numero por favor: ";
    cin>>NumeroIngresado;
    NumeroConvertido=atoi(NumeroIngresado);
    return NumeroConvertido;
}

//PROBLEMA NUMERO 5
void valnuevo(int&);
void valnuevo(int& xnum){
        cout<<"el valor del numero es: "<<xnum<<endl;
    }
//PROBLEMA NUMERO 13
int funcion_galaxia(int *a);
int funcion_galaxia(int *a){
    //Imprimir tabla
    float promedio;
    int contador=0;
    int cont =0;
    cout << "Matriz de la galaxia NGC 1300" << endl << endl;
    //Imprimir la tabla
    for(int i=0; i<(6*8); i++){
        if(*(a+i)>9){
            cout << *(a+i) << "| ";
        }else{
            cout << *(a+i) << " | ";
        }
        cont++;
        //Imprimir salto de linea
        if (cont ==8){
            cont = 0;
            cout << endl;
        }
    }
    //buscador de estrellas
    for(int i=0; i<(6*8);i++){
        if(i<8 || i==15 || i==(15+1) || i==23 || i==(23+1) || i==31 || i==(31+1) || i>39){
            //cout << *(a+i) << " - ";
            continue;
        }else{
            promedio = (*(a+i) + *(a+(i-1)) + *(a+(i+1)) + *(a+(i-8)) + *(a+(i+8)))/5;
            if(promedio >=6.0){
                contador++;
            }
        }
    }
    return contador;
}
void ejercicio_13();
void ejercicio_13(){
    int matriz_galaxia[6][8]={{0,3,4,0,0,0,6,8},
                              {5,13,6,0,0,0,2,3},
                              {2,6,2,7,3,0,10,0},
                              {0,0,4,15,4,1,6,0},
                              {0,0,7,12,6,9,10,4}
                              ,{5,0,6,10,6,4,8,0}};
    int *punt_galaxia = &matriz_galaxia[0][0];
    int promedio_galaxia;

    promedio_galaxia=funcion_galaxia(punt_galaxia);
    cout << "Estrellas encontradas en la imagen: " << promedio_galaxia << endl;
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
 case 1:{
     int valores[]={50000,20000,10000,5000,2000,1000,500,200,100,50,0},dinero,copia_dinero,veces,dinero2=0;
     cout<<"Ingrese por favor la cantidad de dinero: ";
     cin>>dinero;
     copia_dinero=dinero;
     for(int i=0; valores[i]!=0;i++){
         veces=dinero/valores[i];
         if(veces>0){
             cout<<valores[i]<<": "<<veces<<endl;
             dinero=dinero-((valores[i])*(veces));
             dinero2+=((valores[i])*(veces));
         }
         else{
             cout<<valores[i]<<": "<<0<<endl;
         }
     }
     if(dinero2<copia_dinero){
         cout<<"Faltante: "<<copia_dinero-dinero2<<endl;
     }
     break;
 }
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
 case 3:{
     char palabra1[]="carro";
     char palabra2[]="avion";

     if (strcmp(palabra1,palabra2)!=0){;
         cout<<"falso"<<endl;
     }
     if (strcmp(palabra1,palabra2)==0){;
         cout<<"verdadero"<<endl;
     }
    break;
 }
 case 4:{ //FALTA POR TERMINAR

     int N;
     N=Ejercicio_4();
     cout<<"Se transformo el numero: "<<N<<endl;
     break;
     }
 case 5:{
     int num;
     cout<<"digite un numero: ";
     cin>>num;
     valnuevo(num);
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
 case 7:{
     char resultado[27]="";
     char palabra[50];
     int i=0,j=0;
     printf("Ingresa un caracter: ");scanf("%s",palabra);
     while(palabra[i])
     {
         if(!strchr(resultado,palabra[i]))
             resultado[j++]=palabra[i];
         i++;
     }
     resultado[j]='\0';
     printf("\nEl caracter es: %s", resultado);

     getchar();
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
 case 9:{//FALTA EL 9
      char numer;
      int N=0,k=0,size,acum=0,contador=0,total=0;
      cout<<"Ingrese el numero: ";
      cin>>numer;
      cout<<"Ingrese el numero para seccionar: ";
      cin>>size;
      for(int i=0;i<size;i++){
          N=N*10+(numer[k++]-'0')
      }

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
 case 13:{
     ejercicio_13();
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
 case 15:{
         int a[4], b[4];
         //Se reciben los valores a ingresar en las listas
         cout << "TABLA DE VALORES"<<endl<<"#1 -> cordenada en X"<<endl<<
                 "#2 -> cordenada en Y"<<endl<<"#3 -> Ancho"<<endl<<"#4 -> Alto"<<endl;
         cout << "Ingresa valores para A: ";
         for(int i=0; i<4;i++){
             cout << "valor #"<<i+1<< " para A"<<endl;
             cin >> a[i];
         }
         for(int i=0; i<4;i++){
             cout << "valor #"<<i+1<< " para B"<<endl;
             cin >> b[i];
         }

         //          x-y-a-h
         //int a[4]={0,0,8,4};
         //int b[4]={5,2,6,7};
         int c[4]={0,0,0,0};
         int encontrado_cord=0; //guia para cordenaras, ancho y altura
         int encontrar_altura=0;
         //Generar grafica
         int ancho_grafica=30;
         int alto_grafica=25;

         string grafica[alto_grafica][ancho_grafica];
         for(int i=0; i<alto_grafica;i++){
             for(int j=0; j<ancho_grafica;j++){
                 grafica[i][j]=" - ";
                 cout << grafica[i][j];
             }
             cout << endl;
         }

         //Ingresar figura A al plano
         for(int i=a[1]; i<(a[3]+a[1]);i++){
             for(int j=a[0]; j<(a[2]+a[0]);j++){
                 grafica[i][j]=" X ";
             }
         }
         //Ingresar figura B al plano y reemplazar por la O las intersecciones de A Y B
         for(int i=b[1]; i<(b[3]+b[1]);i++){
             for(int j=b[0]; j<(b[2]+b[0]);j++){
                 if(grafica[i][j]== " X "){
                     if(encontrado_cord==0){
                         c[0]=i;
                         c[1]=j;
                         encontrado_cord++;
                     }
                     encontrar_altura=1;
                     if(encontrado_cord==1){
                         c[2]=c[2]+1;
                     }
                     grafica[i][j]=" O ";
                 }else{
                     grafica[i][j]=" x ";
                 }

             }
             if(encontrado_cord==1){
                 encontrado_cord++;
             }
             if(encontrar_altura==1){
                 c[3]++;
                 encontrar_altura=2;
             }
         }
         cout << "UPDATE"<<endl<<endl;

         //Imprime resultado

         for(int i=0; i<alto_grafica;i++){
             for(int j=0; j<ancho_grafica;j++){
                 cout << grafica[i][j];
             }
             cout << endl;
         }
         cout << "C={"<<c[1] << ","<<c[0] << ","<<c[2] << ","<<c[3] << "}"<<endl;
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
 case 17:{
     int numero_inicio, suma, suma_total=0;
         int numero_auxiliar = 0, contador=0;;

         cout<<"Ingresa un numero: ";
         cin >> numero_inicio;

         try {
             while (numero_inicio!=numero_auxiliar && contador<20) {

                 if(contador==0){
                     numero_auxiliar = numero_inicio;
                     suma = 0;
                 }else{
                     suma = 0;
                 }


                 for(int i=1;i<numero_auxiliar ;i++){
                     if(numero_auxiliar%i == 0){
                         suma += i;
                     }
                 }
                 if(suma<numero_inicio){
                     suma_total += suma;
                 }
                 numero_auxiliar = suma;
                 contador++;
                 cout << endl<<numero_auxiliar<<endl;

                 if(numero_auxiliar==0){
                     break;
                 }
             }
             cout << endl<<endl<<"El resultado de la suma es: "<<suma_total<<endl;
         } catch (char error) {
             cout << "Error: ";
         }
 }
 case 18:{//FALTA POR TERMINAR ESTE EJERCICIO
     int lista[]={0,1,2,3,4,5,6,7,8,9},n;
     cout<<"Ingrese el valor para n: ";
     cin>>n;
     for(int i=0;i<=n;i++){
         next_permutation(lista,lista+10);
     }
     cout<<"\nValor en la posicion  N introducida: ";
     for(int i=0;i<10;i++){
         cout<<lista[i];
     }
     cout<<"\n";
     break;
  }
 default:{
    cout<<"El ejercicio ingresado no existe"<<endl;
    break;
 }

 }
  return 0;
}





