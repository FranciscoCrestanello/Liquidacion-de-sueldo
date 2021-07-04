# include<iostream>
# include<cstdlib>
# include<cstring>
# include<stdio.h>
# include<ctime>
using namespace std;
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
#include "clsDomicilio.h"
#include "clsFecha.h"
#include "clsCargo.h"
#include "clsDescuentos.h"
#include "clsEmpleado.h"
#include "clsPreLiquidacion.h"
#include "clsLiquidacion.h"
#include "funciones.h"

int main(){
    int opc=-1;
    while(opc!=0){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<" 1) MENU EMPLEADOS"<<endl;
        cout<<" 2) MENU PRELIQUIDACIONES"<<endl;
        cout<<" 3) MENU LIQUIDACIONES"<<endl;
        cout<<" 4) CONFIGURACIONES"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<" 0) SALIR DEL PROGRAMA"<<endl;
        cout<<" OPCION: ";
        cin>>opc;
        system("cls");
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
