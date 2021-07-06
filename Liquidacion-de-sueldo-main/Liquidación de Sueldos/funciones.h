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

int MenuPreliquidacion(); // MUESTRA EL MENU DE PRELIQUIDACIONES

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
    int opc;
    while(true){
        system("cls");
        cout<<"MENU EMPLEADO"<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<" 1) AGREGAR EMPLEADO "<<endl;
        cout<<" 2) MOSTRAR EMPLEADO"<<endl;
        cout<<" 3) MODIFICAR NOMBRE DEL EMPLEADO."<<endl;
        cout<<" 4) MODIFICAR APELLIDO DEL EMPLEADO."<<endl;
        cout<<" 5) MODIFICAR MAIL DEL EMPLEADO."<<endl;
        cout<<" 6) MODIFICAR DOMICILIO DE EMPLEADO."<<endl;
        cout<<" 7) MODIFICAR TELEFONO DE EMPLEADO."<<endl;
        cout<<" 8) MODIFICAR FECHA DE NACIMIENTO DE EMPLEADO."<<endl;
        cout<<" 9) MODIFICAR FECHA DE INGRESO DE EMPLEADO."<<endl;
        cout<<" 10) MODIFICAR CARGO DE EMPLEADO."<<endl;
        cout<<" 11) MODIFICAR DNI DE EMPLEADO."<<endl;
        cout<<" 12) DAR DE BAJA A UN EMPLEADO."<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    cargarEmpleado();
                    system("pause>nul");
                    system("cls");
                    break;
            case 2:
                    mostrarEmpleados();
                    system("pause>nul");
                    system("cls");
                    break;
            case 3:
                    modificarNombre();
                    break;
            case 4:
                    modificarApellido();
                    break;
            case 5:
                    modificarMail();
                    break;
            case 6:
                    if(modificarDomicilio()==true){cout<<"SE MODIFICO EL DOMICILIO."<<endl;}
                    else{cout<<"NO SE PUDO MODIFICAR EL DOMICILIO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 7:
                    if(modificarTelefono()==true){cout<<"SE MODIFICO EL NUMERO DE TELEFONO."<<endl;}
                    else{cout<<"NO SE PUDO MODIFICAR EL NUMERO DE TELEFONO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 8: modificarFechaDeNacimiento();
                break;
            case 9: modificarFechaDeIngreso();
                break;
            case 10: modificarCargo();
                break;
            case 11: modificarDni();
                break;
            case 12: bajaLogicaEmpleado();
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
        cout<<"MENU PRELIQUIDACION"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<" 1) CARGAR PRE LIQUIDACION"<<endl;
        cout<<" 2) MOSTRAR PRE LIQUIDACIONES"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<" 0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        system("cls");
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
            case 0: return 0;
                break;
            default:
                break;
        }
    }
}

int MenuLiquidacion(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRELIQUIDACION"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<" 1) CARGAR LIQUIDACION"<<endl;
        cout<<" 2) MOSTRAR LIQUIDACIONES"<<endl;
        cout<<" 3) GENERAR LIQUIDACION POR DNI"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        system("cls");
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
    int opc=-1;
    while(opc!=0){
        system("cls");
        cout<<"MENU BACKUPS"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<" 1) GENERAR BACKUP EMPLEADOS"<<endl;
        cout<<" 2) GENERAR BACKUP CARGOS"<<endl;
        cout<<" 3) GENERAR BACKUP PRE LIQUIDACIONES"<<endl;
        cout<<" 4) GENERAR BACKUP LIQUIDACIONES"<<endl;
        cout<<" 5) GENERAR BACKUP DESCUENTOS"<<endl<<endl;
        cout<<" 6) RESTAURAR BACKUP EMPLEADOS"<<endl;
        cout<<" 7) RESTAURAR BACKUP CARGOS"<<endl;
        cout<<" 8) RESTAURAR BACKUP PRE LIQUIDACIONES"<<endl;
        cout<<" 9) RESTAURAR BACKUP LIQUIDACIONES"<<endl;
        cout<<" 10) RESTAURAR BACKUP DESCUENTOS"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<" 0) VOLVER AL MENU DE CONFIGURACIONES"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
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

int MenuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRELIQUIDACION"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<" 1) GENERAR/RESTAURAR BACKUPS"<<endl;
        cout<<" 2) CARGAR DESCUENTOS"<<endl;
        cout<<" 3) MOSTRAR DESCUENTOS"<<endl;
        cout<<" 4) CARGAR CARGO"<<endl;
        cout<<" 5) MOSTRAR CARGOS"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: menuBackups();
                    break;
            case 2:
                    cargarDescuentos();
                    system("pause>nul");
                    system("cls");
                    break;
            case 3:
                    mostrarDescuentos();
                    system("pause>nul");
                    system("cls");
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

/*void bajaLogicaEmpleado(){
    FILE *p;
    Empleado reg;
    int auxDni;
    cout<<"INGRESE EL DNI DEL EMPLEADO: ";
    cin>>auxDni;
    p=fopen(FILE_EMPLEADOS,"rb+");
    while(fread(&reg,sizeof reg,1,p)){
        if(reg.getDni()==auxDni){
            fseek(p,sizeof(Empleado),1);
            reg.setEstado(0);
            fwrite(&reg,sizeof reg, 1, p);
            fclose(p);
            return;
        }
    }
    fclose(p);
}*/

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
    return-1;
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

#endif // FUNCIONES_H_INCLUDED
