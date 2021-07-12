#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

////////// COMIENZO DE LOS PROTOTIPOS //////////

void cargarEmpleado(); //CARGA 1 EMPLEADO

void mostrarEmpleados(); //MUESTRA TODOS LOS EMPLEADOS (EXCEPTO LOS REGISTROS QUE TIENEN ESTADO==0)

int contadorDeCargos(); // CUENTA LA CANTIDAD DE CARGOS PARA HACER UN AUTONUMERICO EN CLASE CARGO FUNCION CARGAR

void cargarPreLiquidacion(); // CARGA UNA PRELIQUIDACION

void mostrarPreLiquidaciones(); //MUESTRA TODAS LAS PRELIQUIDACIONES.

void cargarLiquidacion(); // CARGA UNA LIQUIDACION.

void mostrarLiquidaciones(); //MUESTRA TODAS LAS LIQUIDACIONES.

void cargarDescuentos(); // CARGA LOS DESCUENTOS.

void mostrarDescuentos(); //MUESTRA LOS DESCUENTOS.

void cargarCargo(); // AGREGA UN CARGO.

void mostrarCargos(); // MUESTRA TODOS LOS CARGOS.

void cargarCadena(char *pal, int tam); //CARGA MAS DE 1 O MAS NOMBRES

int MenuEmpleado(); // MUESTRA EL MENU DE EMPLEADOS

int menuModificacionesEmpleado();

int MenuPreliquidacion(); // MUESTRA EL MENU DE PRELIQUIDACIONES

int menuModificacionesPreLiquidaciones();

int MenuLiquidacion(); // MUESTRA EL MENU DE LIQUIDACIONES

int MenuConfiguracion(); // MUESTRA EL MENU DE CONFIGURACIONES

int menuBackups(); // MUESTRA EL MENU DE LOS BACKUPS

void generarBackupEmpleados(); // GENERA EL BACKUP DE EMPLEADOS

void generarBackupCargos(); // GENERA EL BACKUP DE CARGOS

void generarBackupDescuentos(); // GENERA EL BACKUP DE DESCUENTOS

void generarBackupPreLiquidacion(); // GENERA EL BACKUP DE PRELIQUIDACIONES

void generarBackupLiquidacion(); // GENERA EL BACKUP DE LAS LIQUIDACIONES

void restaurarBackupEmpleados(); // RESTAURA EL BACKUP DE EMPLEADOS

void restaurarBackupCargos(); // RESTAURA EL BACKUP DE CARGOS

void restaurarBackupDescuentos(); // RESTAURA EL BACKUP DE DESCUENTOS

void restaurarBackupPreLiquidacion(); // RESTAURA EL BACKUP DE PRELIQUIDACIONES

void restaurarBackupLiquidacion(); // RESTAURA EL BACKUP DE LAS LIQUIDACIONES

void bajaLogicaEmpleado(); // BAJA LOGICA DE UN EMPLEADO SEGUN EL DNI

bool modificarDomicilio(); // MODIFICAR DOMICILIO DE UN EMPLEADO

int buscarposDni(int);

bool modificarEnDisco(Empleado , int);

bool modificarTelefono();

void modificarMail(); // MODIFICA EL MAIL DE UN EMPLEADO

void modificarNombre(); // MODIFICA EL NOMBRE DE UN EMPLEADO

void modificarApellido(); // MODIFICA EL APELLIDO DE UN EMPLEADO

void modificarFechaDeNacimiento(); // MODIFICA LA FECHA DE NACIMIENTO DEL EMPLEADO

void modificarFechaDeIngreso(); // MODIFICA LA FECHA DE INGRESO DEL EMPLEADO

void modificarCargo(); // MODIFICA EL CARGO DEL EMPLEADO

void modificarDni(); // MODIFICA EL DNI DEL EMPLEADO

void modificarPDLiquidacion();

void modificarDNIPreLiquidacion();

void modificarFeriadosPreLiquidacion();

void modificarHorasTrabajadasPreLiquidacion();

void modificarPresentismoPreLiquidacion();

void modificarPuntualidadPreLiquidacion();

bool modificarEnDiscoDescuentos(Descuentos );

void modificarJubilacion();

void modificarDescuentLey19032();

void modificarObraSocial();

void modificarSEC();

void modificarFAEC();

int MenuModificarCargos();

void modificarNombreDelCargo();

void modificarSueldoBasicoCargo();

void modificarAntiguedadDelCargo();

void modificarAsistenciaDelCargo();

void modificarPuntualidadDelCargo();

void modificarFeriadoDelCargo();

////////// FIN DE LOS PROTOTIPOS //////////

void cargarEmpleado(){
    Empleado reg;
    reg.cargar();
    reg.grabarEnDisco();

}

void mostrarEmpleados(){
    Empleado reg;
    int pos=0;
    while(reg.leerEnDisco(pos++)==true){
        if(reg.getEstado()!=0){
            reg.mostrar();
        }
    }
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

void cargarPreLiquidacion(){
    PreLiquidacion reg;
    reg.cargar();
    reg.grabarEnDisco();
}

void mostrarPreLiquidaciones(){
    PreLiquidacion reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrarPL();
    }
}

void cargarLiquidacion(){
    Liquidacion reg;
    reg.cargar();
    reg.grabarEnDisco();
}

void mostrarLiquidaciones(){
    Liquidacion reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrarL();
    }
}

void cargarDescuentos(){
    Descuentos reg;
    reg.cargar();
    reg.grabarEnDisco();
}

void mostrarDescuentos(){
    Descuentos reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrar();
    }
}

void cargarCargo(){
    Cargo reg;
    reg.cargar();
    reg.grabarEnDisco();
}

void mostrarCargos(){
    Cargo reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrar();
    }
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
    int POSMENUX=34,POSMENUY=9, ANCHO_MENU=37,ALTO_MENU=8;
    int opc,cursorX,cursorY;
    while(true){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+13,POSMENUY+1);
        cout<<"MENÚ EMPLEADO"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" AGREGAR EMPLEADO "<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" MOSTRAR EMPLEADO"<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" MODIFICAR CAMPOS DEL EMPLEADO."<<endl;
        separadorH(POSMENUX,POSMENUY+6,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" VOLVER AL MENÚ PRINCIPAL"<<endl;

        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,3,7);

        switch(opc){
            case 1:
                    cargarEmpleado();
                    system("pause>nul");
                    break;
            case 2:
                    mostrarEmpleados();
                    system("pause>nul");
                    break;
            case 3: menuModificacionesEmpleado();
                break;
            case 0: return 0;
                break;
        }
    }
}

int menuModificacionesEmpleado(){
    int POSMENUX=28,POSMENUY=6, ANCHO_MENU=48,ALTO_MENU=15;
    int opc=1,cursorX,cursorY;
    while(true){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+10,POSMENUY+1);
        cout<<"MENÚ PARA MODIFICAR EMPLEADO"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" MODIFICAR NOMBRE DEL EMPLEADO."<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" MODIFICAR APELLIDO DEL EMPLEADO."<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" MODIFICAR MAIL DEL EMPLEADO."<<endl;
        locate(POSMENUX+4,POSMENUY+6);
        cout<<" MODIFICAR DOMICILIO DE EMPLEADO."<<endl;
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" MODIFICAR TELEFONO DE EMPLEADO."<<endl;
        locate(POSMENUX+4,POSMENUY+8);
        cout<<" MODIFICAR FECHA DE NACIMIENTO DE EMPLEADO."<<endl;
        locate(POSMENUX+4,POSMENUY+9);
        cout<<" MODIFICAR FECHA DE INGRESO DE EMPLEADO."<<endl;
        locate(POSMENUX+4,POSMENUY+10);
        cout<<" MODIFICAR CARGO DE EMPLEADO."<<endl;
        locate(POSMENUX+4,POSMENUY+11);
        cout<<" MODIFICAR DNI DE EMPLEADO."<<endl;
        locate(POSMENUX+4,POSMENUY+12);
        cout<<" DAR DE BAJA A UN EMPLEADO."<<endl;
        separadorH(POSMENUX,POSMENUY+13,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+14);
        cout<<" VOLVER AL MENÚ EMPLEADO."<<endl;
        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,10,14);

        switch(opc){
            case 1:
                    modificarNombre();
                    break;
            case 2:
                    modificarApellido();
                    break;
            case 3:
                    modificarMail();
                    break;
            case 4:
                    if(modificarDomicilio()==true){cout<<"SE MODIFICO EL DOMICILIO."<<endl;}
                    else{cout<<"NO SE PUDO MODIFICAR EL DOMICILIO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 5:
                    if(modificarTelefono()==true){cout<<"SE MODIFICO EL NUMERO DE TELEFONO."<<endl;}
                    else{cout<<"NO SE PUDO MODIFICAR EL NUMERO DE TELEFONO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 6: modificarFechaDeNacimiento();
                break;
            case 7: modificarFechaDeIngreso();
                break;
            case 8: modificarCargo();
                break;
            case 9: modificarDni();
                break;
            case 10: bajaLogicaEmpleado();
                break;
            case 0: return 0;
                break;

        }
    }
    return 0;
}

int menuModificacionesPreLiquidaciones(){
    int POSMENUX=30,POSMENUY=8, ANCHO_MENU=40,ALTO_MENU=11;
    int opc=1,cursorX,cursorY;
    while(true){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+6,POSMENUY+1);
        cout<<"MENÚ MODIFICAR PRE LIQUIDACIÓN"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" MODIFICAR PERIODO DE LIQUIDACION"<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" MODIFICAR DNI"<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" MODIFICAR FERIADOS"<<endl;
        locate(POSMENUX+4,POSMENUY+6);
        cout<<" MODIFICAR HORAS TRABAJADAS"<<endl;
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" MODIFICAR PRESENTISMO"<<endl;
        locate(POSMENUX+4,POSMENUY+8);
        cout<<" MODIFICAR PUNTUALIDAD"<<endl;
        separadorH(POSMENUX,POSMENUY+9,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+10);
        cout<<" VOLVER AL MENU PRE LIQUIDACION"<<endl;
        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,6,10);
        switch(opc){
            case 1: modificarPDLiquidacion();
                    break;
            case 2: modificarDNIPreLiquidacion();
                    break;
            case 3: modificarFeriadosPreLiquidacion();
                break;
            case 4: modificarHorasTrabajadasPreLiquidacion();
                break;
            case 5: modificarPresentismoPreLiquidacion();
                break;
            case 6: modificarPuntualidadPreLiquidacion();
                break;
            case 0: return 0;
                break;
        }
    }
}

int MenuPreliquidacion(){
    int POSMENUX=34,POSMENUY=8, ANCHO_MENU=33,ALTO_MENU=8;
    int opc=1,cursorX,cursorY;
    while(true){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+7,POSMENUY+1);
        cout<<"MENÚ PRE LIQUIDACIÓN"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" CARGAR PRE LIQUIDACIÓN"<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" MOSTRAR PRE LIQUIDACIONES"<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" MODIFICAR PRE LIQUIDACIONES"<<endl;
        separadorH(POSMENUX,POSMENUY+6,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" VOLVER AL MENÚ PRINCIPAL"<<endl;
        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,3,7);
        switch(opc){
            case 1:
                    cargarPreLiquidacion();
                    system("pause>nul");
                    system("cls");
                    break;
            case 2:
                    mostrarPreLiquidaciones();
                    system("pause>nul");
                    break;
            case 3: menuModificacionesPreLiquidaciones();
                    break;
            case 0: return 0;
                break;
        }
    }
}

int MenuLiquidacion(){
    int POSMENUX=34,POSMENUY=8, ANCHO_MENU=34,ALTO_MENU=8;
    int opc=1,cursorX,cursorY;
    while(true){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+9,POSMENUY+1);
        cout<<"MENÚ LIQUIDACIÓN"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" CARGAR LIQUIDACIÓN"<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" MOSTRAR LIQUIDACIONES"<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" GENERAR LIQUIDACIÓN POR DNI"<<endl;
        separadorH(POSMENUX,POSMENUY+6,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" VOLVER AL MENÚ PRINCIPAL"<<endl;

        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,3,7);

        switch(opc){
            case 1:
                    cargarLiquidacion();
                    system("pause>nul");
                    system("cls");
                    break;
            case 2:
                    mostrarLiquidaciones();
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

int menuBackups(){
    int POSMENUX=28,POSMENUY=6, ANCHO_MENU=44,ALTO_MENU=15;
    int opc=1,cursorX,cursorY;
    while(opc!=0){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+17,POSMENUY+1);
        cout<<"MENÚ BACKUPS"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" GENERAR BACKUP EMPLEADOS"<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" GENERAR BACKUP CARGOS"<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" GENERAR BACKUP PRE LIQUIDACIONES"<<endl;
        locate(POSMENUX+4,POSMENUY+6);
        cout<<" GENERAR BACKUP LIQUIDACIONES"<<endl;
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" GENERAR BACKUP DESCUENTOS"<<endl;
        locate(POSMENUX+4,POSMENUY+8);
        cout<<" RESTAURAR BACKUP EMPLEADOS"<<endl;
        locate(POSMENUX+4,POSMENUY+9);
        cout<<" RESTAURAR BACKUP CARGOS"<<endl;
        locate(POSMENUX+4,POSMENUY+10);
        cout<<" RESTAURAR BACKUP PRE LIQUIDACIONES"<<endl;
        locate(POSMENUX+4,POSMENUY+11);
        cout<<" RESTAURAR BACKUP LIQUIDACIONES"<<endl;
        locate(POSMENUX+4,POSMENUY+12);
        cout<<" RESTAURAR BACKUP DESCUENTOS"<<endl;
        separadorH(POSMENUX,POSMENUY+13,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+14);
        cout<<" VOLVER AL MENÚ DE CONFIGURACIONES"<<endl;

        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,10,14);

        switch(opc){
            case 1: generarBackupEmpleados();
                break;
            case 2: generarBackupCargos();
                break;
            case 3: generarBackupPreLiquidacion();
                break;
            case 4: generarBackupLiquidacion();
                break;
            case 5: generarBackupDescuentos();
                break;
            case 6: restaurarBackupEmpleados();
                break;
            case 7: restaurarBackupCargos();
                break;
            case 8: restaurarBackupPreLiquidacion();
                break;
            case 9: restaurarBackupLiquidacion();
                break;
            case 10: restaurarBackupDescuentos();
                break;
            case 0: return 0;
                break;
            default:
                break;
        }
    }
    return -1;
}

int MenuModificarDescuentos(){
    int POSMENUX=33,POSMENUY=8, ANCHO_MENU=39,ALTO_MENU=10;
    int opc=1,cursorX,cursorY;
    while(true){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+8,POSMENUY+1);
        cout<<"MENÚ MODIFICAR DESCUENTOS"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" MODIFICAR JUBILACION"<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" MODIFICAR LEY 19032"<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" MODIFICAR OBRA SOCIAL"<<endl;
        locate(POSMENUX+4,POSMENUY+6);
        cout<<" MODIFICAR SEC"<<endl;
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" MODIFICAR FAEC"<<endl;

        separadorH(POSMENUX,POSMENUY+8,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+9);
        cout<<" VOLVER AL MENÚ DE CONFIGURACIÓN"<<endl;
        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,5,9);
        system("cls");
        switch(opc){
            case 1: modificarJubilacion();
                break;
            case 2: modificarDescuentLey19032();
                break;
            case 3: modificarObraSocial();
                break;
            case 4: modificarSEC();
                break;
            case 5: modificarFAEC();
                break;
            case 0: return 0;
                    break;
            default:
                break;
        }
    }
}

int MenuModificarCargos(){
    int POSMENUX=33,POSMENUY=8, ANCHO_MENU=40,ALTO_MENU=11;
    int opc=1,cursorX,cursorY;
    while(true){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+10,POSMENUY+1);
        cout<<"MENÚ MODIFICAR CARGOS"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" MODIFICAR NOMBRE DEL CARGO"<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" MODIFICAR SUELDO BASICO"<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" MODIFICAR ANTIGUEDAD"<<endl;
        locate(POSMENUX+4,POSMENUY+6);
        cout<<" MODIFICAR ASISTENCIA"<<endl;
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" MODIFICAR PUNTUALIDAD"<<endl;
        locate(POSMENUX+4,POSMENUY+8);
        cout<<" MODIFICAR PLUS FERIADOS"<<endl;

        separadorH(POSMENUX,POSMENUY+9,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+10);
        cout<<" VOLVER AL MENÚ DE CONFIGURACIÓN"<<endl;
        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,6,10);
        system("cls");
        switch(opc){
            case 1: modificarNombreDelCargo();
                break;
            case 2: modificarSueldoBasicoCargo();
                break;
            case 3: modificarAntiguedadDelCargo();
                break;
            case 4: modificarAsistenciaDelCargo();
                break;
            case 5: modificarPuntualidadDelCargo();
                break;
            case 6: modificarFeriadoDelCargo();
                break;
            case 0: return 0;
                    break;
            default:
                break;
        }
    }
}

int MenuConfiguracion(){
    int POSMENUX=33,POSMENUY=8, ANCHO_MENU=35,ALTO_MENU=11;
    int opc=1,cursorX,cursorY;
    while(true){
        system("cls");
        opc=1;
        cursorX=POSMENUX+1;
        cursorY=POSMENUY+3;
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+9,POSMENUY+1);
        cout<<"MENÚ CONFIGURACIÓN"<<endl;
        locate(POSMENUX+4,POSMENUY+3);
        cout<<" GENERAR/RESTAURAR BACKUPS"<<endl;
        locate(POSMENUX+4,POSMENUY+4);
        cout<<" MOSTRAR DESCUENTOS"<<endl;
        locate(POSMENUX+4,POSMENUY+5);
        cout<<" MODIFICAR DESCUENTOS"<<endl;
        locate(POSMENUX+4,POSMENUY+6);
        cout<<" CARGAR CARGO"<<endl;
        locate(POSMENUX+4,POSMENUY+7);
        cout<<" MOSTRAR CARGOS"<<endl;
        locate(POSMENUX+4,POSMENUY+8);
        cout<<" MODIFICAR CARGOS"<<endl;
        separadorH(POSMENUX,POSMENUY+9,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
        locate(POSMENUX+4,POSMENUY+10);
        cout<<" VOLVER AL MENÚ PRINCIPAL"<<endl;
        opc=mostrarCursor(cursorX,cursorY,opc,POSMENUY,6,10);
        system("cls");
        switch(opc){
            case 1: menuBackups();
                    break;
            case 2:
                    mostrarDescuentos();
                    system("pause>nul");
                    system("cls");
                    break;
            case 3: MenuModificarDescuentos();
                    break;
            case 4:
                    cargarCargo();
                    system("pause>nul");
                    system("cls");
                    break;
            case 5:
                    mostrarCargos();
                    system("pause>nul");
                    system("cls");
                    break;
            case 6: MenuModificarCargos();
                break;
            case 0: return 0;
                    break;
            default:
                break;
        }
    }
}

void generarBackupEmpleados(){
    FILE *o,*c;
    Empleado reg;
    o=fopen(FILE_EMPLEADOS,"rb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_EMPLEADOS_BKP,"wb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }

    while(fread(&reg, sizeof reg,1,o)){
        fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
}
void generarBackupCargos(){
    FILE *o,*c;
    Cargo reg;
    o=fopen(FILE_TABLA_CARGO,"rb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_TABLA_CARGO_BKP,"wb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }

    while(fread(&reg, sizeof reg,1,o)){
        fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
}
void generarBackupDescuentos(){
    FILE *o,*c;
    Descuentos reg;
    o=fopen(FILE_TABLA_DESC,"rb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_TABLA_DESC_BKP,"wb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }

    while(fread(&reg, sizeof reg,1,o)){
        fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
}

void generarBackupPreLiquidacion(){
    FILE *o,*c;
    PreLiquidacion reg;
    o=fopen(FILE_PRELIQUIDACION,"rb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_PRELIQUIDACION_BKP,"wb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }

    while(fread(&reg, sizeof reg,1,o)){
        fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
}
void generarBackupLiquidacion(){
    FILE *o,*c;
    Liquidacion reg;
    o=fopen(FILE_LIQUIDACION,"rb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_LIQUIDACION_BKP,"wb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }

    while(fread(&reg, sizeof reg,1,o)){
        fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
}
void restaurarBackupEmpleados(){
    FILE *o,*c;
    Empleado reg;
    o=fopen(FILE_EMPLEADOS,"wb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_EMPLEADOS_BKP,"rb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }

    while(fread(&reg, sizeof reg,1,c)){
        fwrite(&reg,sizeof reg,1,o);
    }

    fclose(o);
    fclose(c);
}

void restaurarBackupCargos(){
    FILE *o,*c;
    Cargo reg;
    o=fopen(FILE_TABLA_CARGO,"wb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_TABLA_CARGO_BKP,"rb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }

    while(fread(&reg, sizeof reg,1,c)){
        fwrite(&reg,sizeof reg,1,o);
    }
    fclose(o);
    fclose(c);
}
void restaurarBackupDescuentos(){
    FILE *o,*c;
    Descuentos reg;
    o=fopen(FILE_TABLA_DESC,"wb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_TABLA_DESC_BKP,"rb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    while(fread(&reg, sizeof reg,1,c)){
        fwrite(&reg,sizeof reg,1,o);
    }
    fclose(o);
    fclose(c);
}
void restaurarBackupPreLiquidacion(){
    FILE *o,*c;
    PreLiquidacion reg;
    o=fopen(FILE_PRELIQUIDACION,"wb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_PRELIQUIDACION_BKP,"rb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    while(fread(&reg, sizeof reg,1,c)){
        fwrite(&reg,sizeof reg,1,o);
    }
    fclose(o);
    fclose(c);
}
void restaurarBackupLiquidacion(){
    FILE *o,*c;
    Liquidacion reg;
    o=fopen(FILE_LIQUIDACION,"wb");
    if(o==NULL){
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    c=fopen(FILE_LIQUIDACION_BKP,"rb");
    if(c==NULL){
        fclose(o);
        cout<<endl;
        cout<<"ERROR DE ARCHIVO."<<endl;
        return;
    }
    while(fread(&reg, sizeof reg,1,c)){
        fwrite(&reg,sizeof reg,1,o);
    }
    fclose(o);
    fclose(c);
}

//-----------------MODIFICAR DOMICILIO-----------------//

int buscarposDni(int _dni){
    Empleado reg;
    int pos=0;
    FILE *p;
    p=fopen(FILE_EMPLEADOS,"rb");
    if(p==NULL){return -2;}

    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getDni()==_dni){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool modificarEnDisco(Empleado reg,int pos){
    FILE *p;
    p=fopen(FILE_EMPLEADOS,"rb+");

    if(p==NULL){return false;}

    fseek(p,pos*sizeof(Empleado),0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

bool modificarDomicilio(){
    int _dni,pos;
    Domicilio nuevoDom;
    Empleado reg;
    cout<<"INGRESE EL NUMERO DE DNI: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){cout<<"EL DNI NO EXISTE";}

    cout<<"INGRESE EL NUEVO DOMICILIO: "<<endl;
    nuevoDom.cargar();

    reg.leerEnDisco(pos);
    reg.setDomicilio(nuevoDom);


    bool modifico=modificarEnDisco(reg,pos);
    return modifico;
}


//-------------MODIFICAR TELEFONO-------------------------//

bool modificarTelefono(){
    int _dni,ntel,pos;
    Empleado reg;

    cout<<"INGRESE EL NUMERO DE DNI: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return false;
    }

    cout<<"INGRESE EL NUEVO NUMERO DE TELEFONO: ";
    cin>>ntel;

    reg.leerEnDisco(pos);
    reg.setTelefono(ntel);

    bool modifico=modificarEnDisco(reg,pos);
    return modifico;

}

//-----------------MODIFICAR MAIL ----------------//

void modificarMail(){
    int _dni,pos;
    char email[35];
    Empleado reg;

    cout<<"INGRESE EL NUMERO DE DNI: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }

    cout<<"INGRESE EL NUEVO E-MAIL: ";
    cargarCadena(email,34);
    while(strlen(email)==0){
        cargarCadena(email,34);
    }

    reg.leerEnDisco(pos);
    reg.setEmail(email);

    modificarEnDisco(reg,pos);
}

//---------MODIFICAR NOMBRE-------------//
void modificarNombre(){
    int _dni,pos;
    char nombre[25];
    Empleado reg;

    cout<<"INGRESE EL NUMERO DE DNI: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }

    cout<<"INGRESE EL NUEVO NOMBRE: ";
    cargarCadena(nombre,24);
    while(strlen(nombre)==0){
        cargarCadena(nombre,24);
    }

    reg.leerEnDisco(pos);
    reg.setNombre(nombre);

    modificarEnDisco(reg,pos);
}

//---------MODIFICAR APELLIDO-------------//

void modificarApellido(){
    int _dni,pos;
    char apellido[25];
    Empleado reg;

    cout<<"INGRESE EL NUMERO DE DNI: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }

    cout<<"INGRESE EL NUEVO APELLIDO: ";
    cargarCadena(apellido,24);
    while(strlen(apellido)==0){
        cargarCadena(apellido,24);
    }

    reg.leerEnDisco(pos);
    reg.setApellido(apellido);

    modificarEnDisco(reg,pos);
}

//------------- MODIFICAR FECHA DE NACIMIENTO --------------//

void modificarFechaDeNacimiento(){
    int _dni,pos;
    Fecha fechaNueva;
    Empleado reg;
    cout<<"INGRESE EL NUMERO DE DNI: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){cout<<"EL DNI NO EXISTE";}

    cout<<"INGRESE LA NUEVA FECHA DE NACIMIENTO: ";
    fechaNueva.cargar();

    reg.leerEnDisco(pos);
    reg.setFechaDeNacimiento(fechaNueva);

    modificarEnDisco(reg,pos);
}

//-------------- MODIFICAR FECHA DE INGRESO -------------//

void modificarFechaDeIngreso(){
    int _dni,pos;
    Fecha fechaNueva;
    Empleado reg;
    cout<<"INGRESE EL NUMERO DE DNI: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){cout<<"EL DNI NO EXISTE";}

    cout<<"INGRESE LA NUEVA FECHA DE INGRESO: ";
    fechaNueva.cargar();

    reg.leerEnDisco(pos);
    reg.setFechaIngreso(fechaNueva);

    modificarEnDisco(reg,pos);
}

//--------------- MODIFICAR EL CARGO -----------------//
void modificarCargo(){
    int _dni,pos,auxCargo;
    Empleado emp;
    cout<<"INGRESE EL NUMERO DE DNI: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){cout<<"EL DNI NO EXISTE";}

    cout<<"INGRESE EL NUEVO CARGO: ";
    cin>>auxCargo;

    int x,cant=contadorDeCargos();
    float sueldo;
    Cargo reg;
    bool cargoEncontrado=false;
    while(cargoEncontrado==false){
        for(x=0;x<cant;x++){
            reg.leerDeDisco(x);
            if(reg.getCargo()==auxCargo){
                cargoEncontrado=true;
                sueldo=reg.getSueldoBasico();
               // cout<<"NOMBRE DEL CARGO: "<<reg.getNombreCargo()<<endl;
            }
        }
        if(cargoEncontrado==false){
            cout<<"EL CARGO NO EXISTE. INTENTE DE NUEVO: \nCARGO: ";
            cin>>auxCargo;
        }
    }

    // MOSTRAR LOS CARGOS DISPONIBLES//
    // MOSTRAR LOS CARGOS DISPONIBLES//
    // MOSTRAR LOS CARGOS DISPONIBLES//

    emp.leerEnDisco(pos);
    emp.setCargo(auxCargo);
    emp.setSueldo(sueldo);

    modificarEnDisco(emp,pos);
}

void modificarDni(){
    int _dni,nuevoDni,pos;
    Empleado reg;

    cout<<"INGRESE EL NUMERO DE DNI ACTUAL: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }

    cout<<"INGRESE EL NUEVO DNI: ";
    cin>>nuevoDni;

    reg.leerEnDisco(pos);
    reg.setDni(nuevoDni);

    modificarEnDisco(reg,pos);
}

void bajaLogicaEmpleado(){
    int _dni,pos;
    Empleado reg;

    cout<<"INGRESE EL NUMERO DE DNI ACTUAL: ";
    cin>>_dni;

    pos=buscarposDni(_dni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }

    reg.leerEnDisco(pos);
    reg.setEstado(0);

    modificarEnDisco(reg,pos);
}

//------------ MODIFICACIONES PRE LIQUIDACIONES ---------//
int buscarposDniPreLiq(int _dni){
    PreLiquidacion reg;
    int pos=0;
    FILE *p;
    p=fopen(FILE_PRELIQUIDACION,"rb");
    if(p==NULL){return -2;}

    while(fread(&reg,sizeof reg,1,p)){
        if(reg.getDni()==_dni){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool modificarEnDiscoPreLiq(PreLiquidacion reg,int pos){
    FILE *p;
    p=fopen(FILE_PRELIQUIDACION,"rb+");

    if(p==NULL){return false;}

    fseek(p,pos*sizeof(PreLiquidacion),0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

void modificarPDLiquidacion(){
    PreLiquidacion reg;
    Fecha nuevaFecha;
    int auxDni,pos=0;
    cout<<"INGRESE EL DNI DEL EMPLEADO: ";
    cin>>auxDni;
    pos=buscarposDniPreLiq(auxDni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }
    cout<<"INGRESE LA FECHA NUEVA: ";
    nuevaFecha.cargar();

    reg.leerDeDisco(pos);
    reg.setFecha(nuevaFecha);

    modificarEnDiscoPreLiq(reg,pos);
}

void modificarDNIPreLiquidacion(){
    PreLiquidacion reg;
    int auxDni,pos=0;
    cout<<"INGRESE EL DNI DEL EMPLEADO: ";
    cin>>auxDni;
    pos=buscarposDniPreLiq(auxDni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }
    cout<<"INGRESE EL NUEVO DNI: ";
    cin>>auxDni;

    reg.leerDeDisco(pos);
    reg.setDni(auxDni);

    modificarEnDiscoPreLiq(reg,pos);
}

void modificarFeriadosPreLiquidacion(){
    PreLiquidacion reg;
    int auxDni,nuevoFeriados,pos=0;
    cout<<"INGRESE EL DNI DEL EMPLEADO: ";
    cin>>auxDni;
    pos=buscarposDniPreLiq(auxDni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }
    cout<<"INGRESE LOS FERIADOS TRABAJADOS: ";
    cin>>nuevoFeriados;

    reg.leerDeDisco(pos);
    reg.setFeriados(nuevoFeriados);

    modificarEnDiscoPreLiq(reg,pos);
}

void modificarHorasTrabajadasPreLiquidacion(){
    PreLiquidacion reg;
    int auxDni,pos=0;
    float nuevoHorasTrabajadas;
    cout<<"INGRESE EL DNI DEL EMPLEADO: ";
    cin>>auxDni;
    pos=buscarposDniPreLiq(auxDni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }
    cout<<"INGRESE LA CANTIDAD DE HORAS TRABAJADAS: ";
    cin>>nuevoHorasTrabajadas;

    reg.leerDeDisco(pos);
    reg.setHorasTrabajadas(nuevoHorasTrabajadas);

    modificarEnDiscoPreLiq(reg,pos);
}

void modificarPresentismoPreLiquidacion(){
    PreLiquidacion reg;
    int auxDni,pos=0;
    char presentismo[3];
    cout<<"INGRESE EL DNI DEL EMPLEADO: ";
    cin>>auxDni;
    pos=buscarposDniPreLiq(auxDni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }
    cout<<"PRESENTISMO (SI/NO): ";
    cin>>presentismo;


    reg.leerDeDisco(pos);
    reg.setPresentismo(validarTexto(presentismo));

    modificarEnDiscoPreLiq(reg,pos);
}

void modificarPuntualidadPreLiquidacion(){
    PreLiquidacion reg;
    int auxDni,pos=0;
    char puntualidad[3];
    cout<<"INGRESE EL DNI DEL EMPLEADO: ";
    cin>>auxDni;
    pos=buscarposDniPreLiq(auxDni);
    if(pos==-1){
        cout<<"EL DNI NO EXISTE";
        return;
    }
    cout<<"PUNTUALIDAD (SI/NO): ";
    cin>>puntualidad;


    reg.leerDeDisco(pos);
    reg.setPuntualidad(validarTexto(puntualidad));

    modificarEnDiscoPreLiq(reg,pos);
}
//----------- MODIFICAR DESCUENTOS ----------------//

bool modificarEnDiscoDescuentos(Descuentos reg){
    int pos=0;
    FILE *p;
    p=fopen(FILE_TABLA_DESC,"rb+");

    if(p==NULL){return false;}

    fseek(p,pos*sizeof(Descuentos),0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

void modificarJubilacion(){
    Descuentos reg;
    float nuevoValor;
    cout<<"INGRESE EL NUEVO PORCENTAJE: ";
    cin>>nuevoValor;
    while(nuevoValor<0){
        cout<<"NO SE PERMITE UN NUMERO NEGATIVO.\nINGRESE EL NUEVO PORCENTAJE: ";
        cin>>nuevoValor;
    }
    reg.leerDeDisco(0);
    reg.setJubilacion(nuevoValor);

    modificarEnDiscoDescuentos(reg);
}

void modificarDescuentLey19032(){
    Descuentos reg;
    float nuevoValor;
    cout<<"INGRESE EL NUEVO PORCENTAJE: ";
    cin>>nuevoValor;
    while(nuevoValor<0){
        cout<<"NO SE PERMITE UN NUMERO NEGATIVO.\nINGRESE EL NUEVO PORCENTAJE: ";
        cin>>nuevoValor;
    }
    reg.leerDeDisco(0);
    reg.setLey19032(nuevoValor);

    modificarEnDiscoDescuentos(reg);
}

void modificarObraSocial(){
    Descuentos reg;
    float nuevoValor;
    cout<<"INGRESE EL NUEVO PORCENTAJE: ";
    cin>>nuevoValor;
    while(nuevoValor<0){
        cout<<"NO SE PERMITE UN NUMERO NEGATIVO.\nINGRESE EL NUEVO PORCENTAJE: ";
        cin>>nuevoValor;
    }
    reg.leerDeDisco(0);
    reg.setObraSocial(nuevoValor);

    modificarEnDiscoDescuentos(reg);
}

void modificarSEC(){
    Descuentos reg;
    float nuevoValor;
    cout<<"INGRESE EL NUEVO PORCENTAJE: ";
    cin>>nuevoValor;
    while(nuevoValor<0){
        cout<<"NO SE PERMITE UN NUMERO NEGATIVO.\nINGRESE EL NUEVO PORCENTAJE: ";
        cin>>nuevoValor;
    }
    reg.leerDeDisco(0);
    reg.setSEC(nuevoValor);

    modificarEnDiscoDescuentos(reg);
}

void modificarFAEC(){
    Descuentos reg;
    float nuevoValor;
    cout<<"INGRESE EL NUEVO PORCENTAJE: ";
    cin>>nuevoValor;
    while(nuevoValor<0){
        cout<<"NO SE PERMITE UN NUMERO NEGATIVO.\nINGRESE EL NUEVO PORCENTAJE: ";
        cin>>nuevoValor;
    }
    reg.leerDeDisco(0);
    reg.setFAEC(nuevoValor);

    modificarEnDiscoDescuentos(reg);
}

//------------- MODIFICAR CARGO ------------------//

bool modificarEnDiscoCargos(Cargo reg,int pos){
    FILE *p;
    p=fopen(FILE_TABLA_CARGO,"rb+");

    if(p==NULL){return false;}

    fseek(p,pos*sizeof(Cargo),0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int buscarPosEnTablaCargo(int posBuscada){
    Cargo reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getCargo()==posBuscada)return pos-1;
    }
    return -1;
}

void modificarNombreDelCargo(){
    Cargo reg;
    char nuevoNombre[25];
    int pos,numCargo;

    cout<<"INGRESE EL NUMERO DE CARGO: ";
    cin>>numCargo;
    pos=buscarPosEnTablaCargo(numCargo);
    while(pos==-1){
        cout<<"EL CARGONO EXISTE."<<endl;
        cout<<"INGRESE EL NUMERO DE CARGO: ";
        cin>>numCargo;
        pos=buscarPosEnTablaCargo(numCargo);
    }

    cout<<"INGRESE EL NUEVO NOMBRE: ";
    cargarCadena(nuevoNombre,24);
    while(strlen(nuevoNombre)==0){
        cout<<"LA CADENA NO DEBE QUEDAR VACÍA."<<endl;
        cout<<"INGRESE EL NUEVO NOMBRE: ";
        cargarCadena(nuevoNombre,24);
    }
    reg.leerDeDisco(pos);
    reg.setNombreCargo(nuevoNombre);
    modificarEnDiscoCargos(reg,pos);
}
float buscarSueldoBasicoCargo(int posBuscado){
    Cargo reg;
    int pos=0;
    float sueldoBasico=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getCargo()==posBuscado+1){
            sueldoBasico=reg.getSueldoBasico();
            return sueldoBasico;
        }
    }
    return sueldoBasico;
}
void modificarSueldoBasicoCargo(){
    Cargo reg;
    float sueldoBasicoNuevo,sueldoBasicoViejo;
    int pos,numCargo;
    cout<<"INGRESE EL NUMERO DE CARGO: ";
    cin>>numCargo;
    pos=buscarPosEnTablaCargo(numCargo);
    while(pos==-1){
        cout<<"EL CARGONO EXISTE."<<endl;
        cout<<"INGRESE EL NUMERO DE CARGO: ";
        cin>>numCargo;
        pos=buscarPosEnTablaCargo(numCargo);
    }

    sueldoBasicoViejo=buscarSueldoBasicoCargo(pos);
    cout<<"SUELDO ACTUAL: $"<<sueldoBasicoViejo<<endl;
    cout<<"INGRESE EL NUEVO SUELDO BASICO: $ ";
    cin>>sueldoBasicoNuevo;
    while(sueldoBasicoNuevo<=sueldoBasicoViejo){
        cout<<"EL SUELDO DEBE SER MAYOR AL SUELDO ANTERIOR."<<endl;
        cout<<"SUELDO ACTUAL: $"<<sueldoBasicoViejo<<endl;
        cout<<"INGRESE EL SUELDO NUEVO: $";
        cin>>sueldoBasicoNuevo;
    }
    reg.leerDeDisco(pos);
    reg.setSueldoBasico(sueldoBasicoNuevo);
    modificarEnDiscoCargos(reg,pos);
}

void modificarAntiguedadDelCargo(){
    Cargo reg;
    float porcentajeNuevo;
    int pos,numCargo;
    cout<<"INGRESE EL NUMERO DE CARGO: ";
    cin>>numCargo;
    pos=buscarPosEnTablaCargo(numCargo);
    while(pos==-1){
        cout<<"EL CARGONO EXISTE."<<endl;
        cout<<"INGRESE EL NUMERO DE CARGO: ";
        cin>>numCargo;
        pos=buscarPosEnTablaCargo(numCargo);
    }

    cout<<"INGRESE EL NUEVO PORCENTAJE: % ";
    cin>>porcentajeNuevo;
    while(porcentajeNuevo<0){
        cout<<"EL PORCENTAJE DEBE SER MAYOR/IGUAL A 0."<<endl;
        cout<<"INGRESE EL NUEVO PORCENTAJE: % ";
        cin>>porcentajeNuevo;
    }
    reg.leerDeDisco(pos);
    reg.setAntiguedad(porcentajeNuevo);
    modificarEnDiscoCargos(reg,pos);
}

void modificarAsistenciaDelCargo(){
    Cargo reg;
    float porcentajeNuevo;
    int pos,numCargo;
    cout<<"INGRESE EL NUMERO DE CARGO: ";
    cin>>numCargo;
    pos=buscarPosEnTablaCargo(numCargo);
    while(pos==-1){
        cout<<"EL CARGONO EXISTE."<<endl;
        cout<<"INGRESE EL NUMERO DE CARGO: ";
        cin>>numCargo;
        pos=buscarPosEnTablaCargo(numCargo);
    }

    cout<<"INGRESE EL NUEVO PORCENTAJE: % ";
    cin>>porcentajeNuevo;
    while(porcentajeNuevo<0){
        cout<<"EL PORCENTAJE DEBE SER MAYOR/IGUAL A 0."<<endl;
        cout<<"INGRESE EL NUEVO PORCENTAJE: % ";
        cin>>porcentajeNuevo;
    }
    reg.leerDeDisco(pos);
    reg.setAsisistencia(porcentajeNuevo);
    modificarEnDiscoCargos(reg,pos);
}

void modificarPuntualidadDelCargo(){
    Cargo reg;
    float porcentajeNuevo;
    int pos,numCargo;
    cout<<"INGRESE EL NUMERO DE CARGO: ";
    cin>>numCargo;
    pos=buscarPosEnTablaCargo(numCargo);
    while(pos==-1){
        cout<<"EL CARGONO EXISTE."<<endl;
        cout<<"INGRESE EL NUMERO DE CARGO: ";
        cin>>numCargo;
        pos=buscarPosEnTablaCargo(numCargo);
    }

    cout<<"INGRESE EL NUEVO PORCENTAJE: % ";
    cin>>porcentajeNuevo;
    while(porcentajeNuevo<0){
        cout<<"EL PORCENTAJE DEBE SER MAYOR/IGUAL A 0."<<endl;
        cout<<"INGRESE EL NUEVO PORCENTAJE: % ";
        cin>>porcentajeNuevo;
    }
    reg.leerDeDisco(pos);
    reg.setPuntualidad(porcentajeNuevo);
    modificarEnDiscoCargos(reg,pos);
}

void modificarFeriadoDelCargo(){
    Cargo reg;
    float porcentajeNuevo;
    int pos,numCargo;
    cout<<"INGRESE EL NUMERO DE CARGO: ";
    cin>>numCargo;
    pos=buscarPosEnTablaCargo(numCargo);
    while(pos==-1){
        cout<<"EL CARGONO EXISTE."<<endl;
        cout<<"INGRESE EL NUMERO DE CARGO: ";
        cin>>numCargo;
        pos=buscarPosEnTablaCargo(numCargo);
    }

    cout<<"INGRESE EL NUEVO PORCENTAJE: % ";
    cin>>porcentajeNuevo;
    while(porcentajeNuevo<0){
        cout<<"EL PORCENTAJE DEBE SER MAYOR/IGUAL A 0."<<endl;
        cout<<"INGRESE EL NUEVO PORCENTAJE: % ";
        cin>>porcentajeNuevo;
    }
    reg.leerDeDisco(pos);
    reg.setPlusFeriado(porcentajeNuevo);
    modificarEnDiscoCargos(reg,pos);
}



#endif // FUNCIONES_H_INCLUDED
