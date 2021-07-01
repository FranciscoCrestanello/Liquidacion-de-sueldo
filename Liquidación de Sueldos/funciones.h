#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
////////// COMIENZO DE LOS PROTOTIPOS //////////

bool cargarEmpleado(); //CARGA 1 EMPLEADO

bool mostrarEmpleados(); //MUESTRA TODOS LOS EMPLEADOS

int contadorDeCargos(); // CUENTA LA CANTIDAD DE CARGOS PARA HACER UN AUTONUMERICO EN CLASE CARGO FUNCION CARGAR

bool cargarPreLiquidacion(); // CARGA UNA PRELIQUIDACION

bool mostrarPreLiquidaciones(); //MUESTRA TODAS LAS PRELIQUIDACIONES.

bool cargarLiquidacion(); // CARGA UNA LIQUIDACION.

bool mostrarLiquidaciones(); //MUESTRA TODAS LAS LIQUIDACIONES.

bool cargarDescuentos(); // CARGA LOS DESCUENTOS.

bool mostrarDescuentos(); //MUESTRA LOS DESCUENTOS.

bool cargarCargo(); // AGREGA UN CARGO.

bool mostrarCargos(); // MUESTRA TODOS LOS CARGOS.

void cargarCadena(char *pal, int tam); //CARGA MAS DE 1 O MAS NOMBRES

int MenuEmpleado();

int MenuPreliquidacion();

int MenuLiquidacion();

int MenuConfiguracion();

////////// FIN DE LOS PROTOTIPOS //////////


bool cargarEmpleado(){
    Empleado reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarEmpleados(){
    Empleado reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerEnDisco(pos++)==true){
        reg.mostrar();
        leyo=true;
    }
    return leyo;
}

int contadorDeCargos(){
    int c = 0, tam;
    FILE *p;

    p = fopen(FILE_TABLA_CARGO,"rb");
    if(p == NULL){return -1;}

    fseek(p, 0, 2);
    tam = ftell(p);

    fclose(p);

    c = tam/sizeof(Cargo);
    return c;
}

bool cargarPreLiquidacion(){
    PreLiquidacion reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarPreLiquidaciones(){
    PreLiquidacion reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrarPL();
        leyo=true;
    }
    return leyo;
}

bool cargarLiquidacion(){
    Liquidacion reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarLiquidaciones(){
    Liquidacion reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrarL();
        leyo=true;
    }
    return leyo;
}

bool cargarDescuentos(){
    Descuentos reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarDescuentos(){
    Descuentos reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrar();
        leyo=true;
    }
    return leyo;
}

bool cargarCargo(){
    Cargo reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarCargos(){
    Cargo reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrar();
        leyo=true;
    }
    return leyo;
}

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

int MenuEmpleado(){
    int opc;
    while(true){
        system("cls");
        cout<<"---------- MENU EMPLEADO ----------"<<endl;
        cout<<" 1) AGREGAR EMPLEADO "<<endl;
        cout<<" 2) MOSTRAR EMPLEADO"<<endl;
        cout<<" 3) MODIFICAR DATOS DE UN EMPLEADO."<<endl;
        cout<<" 4) DAR DE BAJA A UN EMPLEADO."<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        switch(opc){
            case 1: system("cls");
                    if(cargarEmpleado()==true){cout<<"REGISTRO EXITOSO."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR AL CLIENTE."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
                    system("pause");
                break;
            case 2: system("cls");
                    if(mostrarEmpleados()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
                    system("pause");
                break;
            case 0: return 0;
                break;
        }
    }
}

int MenuPreliquidacion(){
    int opc;
    while(true){
        system("cls");
        cout<<"---------- MENÚ PRELIQUIDACION ----------"<<endl;
        cout<<" 1) CARGAR PRE LIQUIDACION"<<endl;
        cout<<" 2) MOSTRAR PRE LIQUIDACIONES"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<" 0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        switch(opc){
            case 1: system("cls");
                    if(cargarPreLiquidacion()==true){cout<<"SE CARGO LA PRE LIQUIDACION."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LA PRE LIQUIDACION."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
                    system("pause");
                break;
            case 2: system("cls");
                    if(mostrarPreLiquidaciones()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    break;
                    system("pause");
                break;
            case 0: return 0;
                break;
        }
    }
}

int MenuLiquidacion(){
    int opc;
    while(true){
        system("cls");
        cout<<""<<endl;
        cout<<"---------- MENÚ PRELIQUIDACION ----------"<<endl;
        cout<<" 1) CARGAR LIQUIDACION"<<endl;
        cout<<" 2) MOSTRAR LIQUIDACIONES"<<endl;
        cout<<" 3) GENERAR LIQUIDACION POR DNI"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        switch(opc){
            case 1: system("cls");
                    if(cargarLiquidacion()==true){cout<<"SE CARGO LA LIQUIDACION."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LA LIQUIDACION."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
                    system("pause");
                break;
            case 2: system("cls");
                    if(mostrarLiquidaciones()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    system("pause");
                break;
            case 3: system("cls");
                    if(generarliquidacion()==true){
                        cout<<"SE GENERO LA LIQUIDACION CON EXITO"<<endl;
                    }else{
                        cout<<"NO SE HA PODIDO GENERAR LA LIQUIDACION"<<endl;
                    }
                    system("pause");
                break;
            case 0: return 0;
                    break;
        }
    }
}

int MenuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENÚ PRELIQUIDACION"<<endl;
        cout<<"---------------------"<<endl;
        cout<<endl;
        cout<<" 5) CARGAR DESCUENTOS"<<endl;
        cout<<" 55) MOSTRAR DESCUENTOS"<<endl;
        cout<<" 6) CARGAR CARGO"<<endl;
        cout<<" 66) MOSTRAR CARGOS"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        switch(opc){
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
            case 0: return 0;
                    break;
        }
    }
}

#endif // FUNCIONES_H_INCLUDED
