# include<iostream>
# include<cstdlib>
# include<cstring>
# include<stdio.h>
# include<ctime>
# include"rlutil.h"
using namespace std;
using namespace rlutil;
const char *FILE_EMPLEADOS = "Empleados.dat";
const char *FILE_EMPLEADOS_BKP = "Empleados.bkp";
const char *FILE_PRELIQUIDACION = "PreLiquidacion.dat";
const char *FILE_PRELIQUIDACION_BKP = "PreLiquidacion.bkp";
const char *FILE_LIQUIDACION = "Liquidacion.dat";
const char *FILE_LIQUIDACION_BKP = "Liquidacion.bkp";
const char *FILE_TABLA_DESC = "TablaDescuentos.dat";
const char *FILE_TABLA_DESC_BKP = "TablaDescuentos.bkp";
const char *FILE_TABLA_CARGO = "TablaCargos.dat";
const char *FILE_TABLA_CARGO_BKP = "TablaCargos.bkp";
const char LETRA_COLOR=BLACK;
const char FONDO_COLOR=GREY;
#include "clsDomicilio.h"
#include "clsFecha.h"
#include "clsCargo.h"
#include "clsDescuentos.h"
#include "clsEmpleado.h"
#include "clsPreLiquidacion.h"
#include "clsLiquidacion.h"
#include "rlutilFunciones.h"
#include "funciones.h"


int main(){
    int POSMENUX=35,POSMENUY=8, ANCHO_MENU=30,ALTO_MENU=10;
    int opc=1,cursorX,cursorY;
    setlocale(LC_ALL, "spanish");
    setConsoleTitle("LIQUIDACION DE SUELDO");
    setColor(LETRA_COLOR);
    setBackgroundColor(FONDO_COLOR);
    AjustarVentana(100,30);

    while(opc!=0){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+9,POSMENUY+1);
        cout<<"MENÚ PRINCIPAL"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" MENÚ EMPLEADOS"<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" MENÚ PRELIQUIDACIONES"<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" MENÚ LIQUIDACIONES"<<endl;
        locate(POSMENUX+4,POSMENUY+6);
        cout<<" CONFIGURACIONES"<<endl;
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" CREDITOS. "<<endl; /// ACA HABRÍA QUE PONER NUESTROS NOMBRES Y UNAS COSAS MAS. (CON UN "MENU")
        separadorH(POSMENUX,POSMENUY+8,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+9);
        cout<<" SALIR DEL PROGRAMA"<<endl;

        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,5,9);

        switch(opc){
            case 1: MenuEmpleado();
                    break;
            case 2: MenuPreliquidacion();
                    break;
            case 3: MenuLiquidacion();
                    break;
            case 4: MenuConfiguracion();
                    break;
            case 0: cout<<"FIN DEL PROGRAMA"<<endl;
                    system("pause>nul");
                    system("cls");
                    break;
            default:
                    cout<<"OPCION NO VALIDA. INTENTE DE NUEVO"<<endl;
                    system("pause>nul");
                    system("cls");
                    break;
        }
    }
    return 0;
}
