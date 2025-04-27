//CALCULADOR DE MIN DE VENTA DE PRODUCTOS DE STEAM
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <windows.h>
using namespace std;
double impuesto = 0.13043478;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void reporteInicial(double pcompra);
void nuevaGanancia(double pventa, double pcompra);

int main()
{
	double pcompra,pventa,ganancia,obtengo;
	bool continuar=true, incorrecto=true,incorrecto2 =  true, seguir = true;
	while(seguir){
		cout<<"Ingrese el valor del producto de steam: S/. ";
		cin>>pcompra;
		while(continuar){
			reporteInicial(pcompra);
			cout<<"Ingrese el precio de venta para calcular la nueva ganancia: ";
			cin>>pventa;
			nuevaGanancia(pventa,pcompra);
			do
				{
					cout<<"¿Desea ingresar una NUEVA VENTA de esto articulo? s/n: "<<endl;
					char tecla = getch();
					if(tecla == 's' || tecla == 'S')
					{
						continuar = true;
						incorrecto = false;
					}
					else if(tecla == 'n' || tecla == 'N')
					{
						continuar = false;
						incorrecto = false;
						system("CLS");
					}
					else{
						cout<<"PRESIONES UNA TECLA CORRECTA"<<endl;
					}	
				}
			while(incorrecto);
		}
		cout<<"¿Desea ingresar un ARTICULO DIFERENTE a evaluar? s/n: "<<endl;
		char tecla2 = getch();
		do{
			if(tecla2 == 's' || tecla2 == 'S')
			{
				seguir = true;
				incorrecto2 = false;
				continuar = true;
				incorrecto = true;
				system("CLS");
			}
			else if(tecla2 == 'n' || tecla2 == 'N')
			{
				seguir = false;
				incorrecto2 = false;
				return 0;
			}
			else{
				cout<<"PRESIONES UNA TECLA CORRECTA"<<endl;
			}
		}while(incorrecto2);
	}
}

void reporteInicial(double pcompra){
	double pventa,ganancia,obtengo;
	pventa = pcompra/(1-impuesto);
	obtengo = pventa*(1-impuesto);
	ganancia = obtengo-pcompra;
	SetConsoleTextAttribute(hConsole, 9);
	cout<<"------------ REPORTE INICIAL ------------"<<endl;
	printf("Precio de Venta MINIMA: S/. %.2f\n", pventa);
	printf("Obtengo: S/. %.2f\n",obtengo);
	printf("Ganancia: S/. %.2f\n", ganancia);
	cout<<"-----------------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 7);
}
void nuevaGanancia(double pventa, double pcompra){
	double ganancia,obtengo;
	cout<<"----------------------------------"<<endl;
	printf("Nuevo Precio de Venta: S./ %.2f\n", pventa);
	obtengo = pventa*(1-impuesto);
	ganancia = obtengo-pcompra;
	printf("Obtengo: S/. %.2f\n",obtengo);
	if(ganancia>=0)
				{
					SetConsoleTextAttribute(hConsole, 10);
					printf("Ganancia: S/. %.2f\n", ganancia);
					SetConsoleTextAttribute(hConsole, 7);
				}else{
					SetConsoleTextAttribute(hConsole, 12);
					printf("Perdida: S/. %.2f\n", ganancia);
					SetConsoleTextAttribute(hConsole, 7);
				}
			
			cout<<"---------------------------------"<<endl;
}
