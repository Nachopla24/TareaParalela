#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


using namespace std;
//Compilar y ejecutar
//g++ npmbre.cpp -o nombre
//./nombre

void calculos();
float promedio();


int main()
{
    cout << "Tarea 1 Computacion Paralela\n\n\n\n";
    calculos();
    return 0;
}

void calculos(){
  string valor,aux;
  int i=0;
  float num=0, numerador=0, aux2=0, prom=0, mediana=0;
  long long suma=0;
  ifstream numeros; // Creo el fichero de entrada
  prom = promedio();
  numeros.open ("numeros.txt", ios::in);
  while(numeros >> valor){
     aux=valor;
     aux[1]='.';
     num=strtof((aux).c_str(),0);//Convierte el string de entrada en un float
     if (i==1073741823) {
       mediana = num;
       cout << mediana << endl;
     }
     i+=1;
     suma += num;
     numerador = num-prom;
     aux2 += pow(numerador,2);
  }
  aux2 = aux2/(i-1);

  numeros.close();
  cout << "La suma es :" << suma << endl;
  cout << "La cantidad de datos es: " << i << endl;
  cout << "La media es : " << prom << endl;
  cout << "La mediana es : " << mediana <<endl;
  cout << "La moda es : " << endl;
  cout << "La desviacion es : " << sqrt(aux2) << endl;

}


float promedio()
{
  string valor,aux;
  int i=0;
  float num=0, prom=0;
  ifstream numeros; // Creo el fichero de entrada
  numeros.open ("numeros.txt", ios::in);
  while(numeros >> valor){
     aux=valor;
     aux[1]='.';
     num=strtof((aux).c_str(),0);//Convierte el string de entrada en un float
     i+=1;
     prom += num;
  }
  prom = prom/i;
  numeros.close();
  return prom;
}
