# include<iostream>
# include<cstdlib>
# include<cstring>
# include<stdio.h>
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
const char *FILE_SUELDO_BRUTO = "SueldoBruto.dat";
const char *FILE_SUELDO_BRUTO_BKP = "SueldoBruto.bkp";
#include "clsDomicilio.h"
#include "clsFecha.h"
#include "clsCargo.h"
#include "clsDescuentos.h"
#include "clsEmpleado.h"
#include "clsPreLiquidacion.h"
#include "clsLiquidacion.h"
#include "clsSueldoBruto.h"
#include "funciones.h"

int main(){
    int opc=-1;
    while(opc!=0){
        cout<<"----- MENU PRINCIPAL -----"<<endl;
        cout<<" 1) CARGAR EMPLEADO"<<endl;
        cout<<" 11) MOSTRAR EMPLEADO"<<endl;
        cout<<" 2) CARGAR PRE LIQUIDACION"<<endl;
        cout<<" 22) MOSTRAR PRE LIQUIDACIONES"<<endl;
        cout<<" 3) CARGAR LIQUIDACION"<<endl;
        cout<<" 33) MOSTRAR LIQUIDACIONES"<<endl;
        cout<<" 4) CARGAR SUELDO BRUTO"<<endl;
        cout<<" 44) MOSTRAR SUELDOS BRUTOS"<<endl;
        cout<<" 5) CARGAR DESCUENTOS"<<endl;
        cout<<" 55) MOSTRAR DESCUENTOS"<<endl;
        cout<<" 6) CARGAR CARGO"<<endl;
        cout<<" 66) MOSTRAR CARGOS"<<endl;
        cout<<" 0) SALIR DEL PROGRAMA"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    if(cargarEmpleado()==true){cout<<"REGISTRO EXITOSO."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR AL CLIENTE."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 11:
                    if(mostrarEmpleados()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 2:
                    if(cargarPreLiquidacion()==true){cout<<"SE CARGO LA PRE LIQUIDACION."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LA PRE LIQUIDACION."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 22:
                    if(mostrarPreLiquidaciones()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 3:
                    if(cargarLiquidacion()==true){cout<<"SE CARGO LA LIQUIDACION."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LA LIQUIDACION."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 33:
                    if(mostrarLiquidaciones()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 4:
                    if(cargarSueldoBruto()==true){cout<<"SE CARGO EL SUELDO BRUTO."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR EL SUELDO BRUTO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 44:
                    if(mostrarSueldosBrutos()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 5:
                    if(cargarDescuentos()==true){cout<<"SE CARGARON LOS DESCUENTOS."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LOS DESCUENTOS."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 55:
                    if(mostrarDescuentos()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 6:
                    if(cargarCargo()==true){cout<<"SE CARGARON LOS CARGOS."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LOS CARGOS."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 66:
                    if(mostrarCargos()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 0:
                    cout<<"FIN DEL PROGRAMA"<<endl;
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
