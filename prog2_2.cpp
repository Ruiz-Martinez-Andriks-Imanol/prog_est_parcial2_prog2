/* Autor: Andriks Imanol Ruiz Mártinez, Realizado: 24/03/2022
Escuela: Universidad del Valle de Mexico Campus Villahermosa
Materia: Programación Estructrada
Ciclo: 01/2022

Este es un programa de ciclos y condicionales en Lenguaje C de la materia de Programación Estructurada<br>
Muestra el uso de:

    -Variables tipo unsigned
    -printf para mostrar mensajes y variables
    -scanf
    -El uso de include para las librerías
    -Uso de la librería math.h
    -Arreglo por método de la burbuja
    -Ciclos
    -Contador
    -Condicionales
    -Arreglos
    -#define MAX  para definir cierta cantidad para el arreglo
    -Comentarios para la documentación interna del programa
		*/
#include<stdio.h>
// Definiciones
#define MAX 10
#include<math.h>
//const int TAMANO=50;
int main(){
	//int edades[10];
	unsigned char edades[MAX], aux;
	unsigned int centro;
	float media, suma=0, var, desviacion, mediana;
	int validar;
	//Leer datos del teclado para llenar el arreglo completo
	for (int i=0;i<MAX;i++){
	//for (int i=0;i<10;i++){
		do{
			printf("Introduce la edad del alumno #%d: ", i);
			scanf("%d", &validar);
			if (!(validar >=0 && validar<=150)){
				printf("Edad invalida!!! intenta nuevamente \n");
			}
		} while(!(validar >=0 && validar<=150));
		edades[i]=validar;
	}
	//Imprimir todo el arreglo
	printf("Listado de Alumnos\n");
	for (int i=0;i<MAX;i++){
	// for (int i=0;i<10;i++){	
		printf("Edad del alumno #%d: %d\n", i, edades[i]);
	}
	//Calcular la media
	for (int i=0;i<MAX;i++){	
		suma=suma+edades[i];
	}
	media=suma/MAX;
	printf("La media es: %.2f\n", media);
	//Varianza
	suma=0;
	for (int i=0;i<MAX;i++){	
		suma=suma+pow(edades[i]-media,2);
	}
	var=suma/MAX;
	printf("La varianza es: %.2f\n", var);
	//Desviacion estandar
	desviacion=sqrt(var);
	printf("La desviacion estandar es: %.2f\n", desviacion);
	//Ordenamiendo del arreglo por el metodo de la burbuja
	//Usando el codigo de https://es.wikipedia.org/wiki/Ordenamiento_de_burbuja
	for(int z = 1; z < MAX; ++z) {
      	for(int v = 0; v < (MAX - z); v++) {
         	if(edades[v] > edades[v+1]){
            	aux = edades[v];
            	edades[v] = edades[v + 1];
            	edades[v + 1] = aux;
         	}
      	}
    }
    //Imprimir todo el arreglo
    printf("Listado de Alumnos Ordenados\n");
    for (int i=0;i<MAX;i++){	
		printf("Edad del alumno #%d: %d\n",i,edades[i]);
	}
	//calcular la mediana
	if (MAX%2==0){
		centro=MAX/2;
		mediana = (edades[centro]+edades[centro-1])/2.0;
	}
	else{
		centro=MAX/2;
		mediana=edades[centro];
	}
	printf("La mediana es: %.2f\n", mediana);
	return 0;
}

