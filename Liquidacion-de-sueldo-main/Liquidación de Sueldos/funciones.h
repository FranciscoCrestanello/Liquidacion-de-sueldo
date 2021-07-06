#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
////////// COMIENZO DE LOS PROTOTIPOS //////////

bool cargarEmpleado(); //CARGA 1 EMPLEADO

bool mostrarEmpleados(); //MUESTRA TODOS LOS EMPLEADOS (EXCEPTO LOS REGISTROS QUE TIENEN ESTADO==0)

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

int MenuEmpleado(); // MUESTRA EL MENU DE EMPLEADOS

int MenuPreliquidacion(); // MUESTRA EL MENU DE PRELIQUIDACIONES

int MenuLiquidacion(); // MUESTRA EL MENU DE LIQUIDACIONES

int MenuConfiguracion(); // MUESTRA EL MENU DE CONFIGURACIONES

int menuBackups(); // MUESTRA EL MENU DE LOS BACKUPS

bool generarBackupEmpleados(); // GENERA EL BACKUP DE EMPLEADOS

bool generarBackupCargos(); // GENERA EL BACKUP DE CARGOS

bool generarBackupDescuentos(); // GENERA EL BACKUP DE DESCUENTOS

bool generarBackupPreLiquidacion(); // GENERA EL BACKUP DE PRELIQUIDACIONES

bool generarBackupLiquidacion(); // GENERA EL BACKUP DE LAS LIQUIDACIONES

bool restaurarBackupEmpleados(); // RESTAURA EL BACKUP DE EMPLEADOS

bool restaurarBackupCargos(); // RESTAURA EL BACKUP DE CARGOS

bool restaurarBackupDescuentos(); // RESTAURA EL BACKUP DE DESCUENTOS

bool restaurarBackupPreLiquidacion(); // RESTAURA EL BACKUP DE PRELIQUIDACIONES

bool restaurarBackupLiquidacion(); // RESTAURA EL BACKUP DE LAS LIQUIDACIONES

void bajaLogicaEmpleado(); // BAJA LOGICA DE UN EMPLEADO SEGUN EL DNI

bool modificarDomicilio(); // MODIFICAR DOMICILIO DE UN EMPLEADO

int buscarposDni(int);

bool modificarEnDisco(Empleado , int);

bool modificarTelefono();

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
        if(reg.getEstado()!=0){
            reg.mostrar();
            leyo=true;
        }
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
        cout<<"MENU EMPLEADO"<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<" 1) AGREGAR EMPLEADO "<<endl;
        cout<<" 2) MOSTRAR EMPLEADO"<<endl;
        cout<<" 3) MODIFICAR DOMICILIO DE EMPLEADO."<<endl;
        cout<<" 4) MODIFICAR TELEFONO DE EMPLEADO."<<endl;
        cout<<" 5) DAR DE BAJA A UN EMPLEADO."<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    if(cargarEmpleado()==true){cout<<"REGISTRO EXITOSO."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR AL CLIENTE."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 2:
                    if(mostrarEmpleados()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 3:
                    if(modificarDomicilio()==true){cout<<"SE MODIFICO EL DOMICILIO."<<endl;}
                    else{cout<<"NO SE PUDO MODIFICAR EL DOMICILIO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 4:
                    if(modificarTelefono()==true){cout<<"SE MODIFICO EL NUMERO DE TELEFONO."<<endl;}
                    else{cout<<"NO SE PUDO MODIFICAR EL NUMERO DE TELEFONO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 5:
                    bajaLogicaEmpleado();
                    system("pause>nul");
                    system("cls");
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
                    if(cargarPreLiquidacion()==true){cout<<"SE CARGO LA PRE LIQUIDACION."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LA PRE LIQUIDACION."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 2: system("cls");
                    if(mostrarPreLiquidaciones()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
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
                    if(cargarLiquidacion()==true){cout<<"SE CARGO LA LIQUIDACION."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LA LIQUIDACION."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 2:
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
            case 1:
                    if(generarBackupEmpleados()==true){cout<<"SE GENERO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO GENERAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 2:
                    if(generarBackupCargos()==true){cout<<"SE GENERO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO GENERAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 3:
                    if(generarBackupPreLiquidacion()==true){cout<<"SE GENERO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO GENERAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 4:
                    if(generarBackupLiquidacion()==true){cout<<"SE GENERO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO GENERAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 5:
                    if(generarBackupDescuentos()==true){cout<<"SE GENERO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO GENERAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 6:
                    if(restaurarBackupEmpleados()==true){cout<<"SE RESTAURO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO RESTAURAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 7:
                    if(restaurarBackupCargos()==true){cout<<"SE RESTAURO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO RESTAURAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 8:
                    if(restaurarBackupPreLiquidacion()==true){cout<<"SE RESTAURO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO RESTAURAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 9:
                    if(restaurarBackupLiquidacion()==true){cout<<"SE RESTAURO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO RESTAURAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 10:
                    if(restaurarBackupDescuentos()==true){cout<<"SE RESTAURO EL BACKUP."<<endl;}
                    else{cout<<"NO SE LOGRO RESTAURAR EL BACKUP."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 0:
                return 0;
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
        cout<<" 8) CARGAR DESCUENTOS"<<endl;
        cout<<" 88) MOSTRAR DESCUENTOS"<<endl;
        cout<<" 9) CARGAR CARGO"<<endl;
        cout<<" 99) MOSTRAR CARGOS"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: menuBackups();
                    break;
            case 8:
                    if(cargarDescuentos()==true){cout<<"SE CARGARON LOS DESCUENTOS."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LOS DESCUENTOS."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 88:
                    if(mostrarDescuentos()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 9:
                    if(cargarCargo()==true){cout<<"SE CARGARON LOS CARGOS."<<endl;}
                    else{cout<<"NO SE LOGRO REGISTRAR LOS CARGOS."<<endl;}
                    system("pause>nul");
                    system("cls");
                    break;
            case 99:
                    if(mostrarCargos()==true){cout<<"SE LEYO EL ARCHIVO."<<endl;}
                    else{cout<<"NO SE LOGRO LEER EL ARCHIVO."<<endl;}
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

bool generarBackupEmpleados(){
    FILE *o,*c;
    Empleado reg;
    bool escribio=false;
    o=fopen(FILE_EMPLEADOS,"rb");
    if(o==NULL)return false;
    c=fopen(FILE_EMPLEADOS_BKP,"wb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,o)){
        escribio=fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
    return escribio;
}
bool generarBackupCargos(){
    FILE *o,*c;
    Cargo reg;
    bool escribio=false;
    o=fopen(FILE_TABLA_CARGO,"rb");
    if(o==NULL)return false;
    c=fopen(FILE_TABLA_CARGO_BKP,"wb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,o)){
        escribio=fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
    return escribio;
}
bool generarBackupDescuentos(){
    FILE *o,*c;
    Descuentos reg;
    bool escribio=false;
    o=fopen(FILE_TABLA_DESC,"rb");
    if(o==NULL)return false;
    c=fopen(FILE_TABLA_DESC_BKP,"wb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,o)){
        escribio=fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
    return escribio;
}

bool generarBackupPreLiquidacion(){
    FILE *o,*c;
    PreLiquidacion reg;
    bool escribio=false;
    o=fopen(FILE_PRELIQUIDACION,"rb");
    if(o==NULL)return false;
    c=fopen(FILE_PRELIQUIDACION_BKP,"wb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,o)){
        escribio=fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
    return escribio;
}
bool generarBackupLiquidacion(){
    FILE *o,*c;
    Liquidacion reg;
    bool escribio=false;
    o=fopen(FILE_LIQUIDACION,"rb");
    if(o==NULL)return false;
    c=fopen(FILE_LIQUIDACION_BKP,"wb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,o)){
        escribio=fwrite(&reg,sizeof reg,1,c);
    }

    fclose(o);
    fclose(c);
    return escribio;
}
bool restaurarBackupEmpleados(){
    FILE *o,*c;
    Empleado reg;
    bool escribio=false;
    o=fopen(FILE_EMPLEADOS,"wb");
    if(o==NULL)return false;
    c=fopen(FILE_EMPLEADOS_BKP,"rb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,c)){
        escribio=fwrite(&reg,sizeof reg,1,o);
    }

    fclose(o);
    fclose(c);
    return escribio;
}

bool restaurarBackupCargos(){
    FILE *o,*c;
    Cargo reg;
    bool escribio=false;
    o=fopen(FILE_TABLA_CARGO,"wb");
    if(o==NULL)return false;
    c=fopen(FILE_TABLA_CARGO_BKP,"rb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,c)){
        escribio=fwrite(&reg,sizeof reg,1,o);
    }

    fclose(o);
    fclose(c);
    return escribio;
}
bool restaurarBackupDescuentos(){
    FILE *o,*c;
    Descuentos reg;
    bool escribio=false;
    o=fopen(FILE_TABLA_DESC,"wb");
    if(o==NULL)return false;
    c=fopen(FILE_TABLA_DESC_BKP,"rb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,c)){
        escribio=fwrite(&reg,sizeof reg,1,o);
    }

    fclose(o);
    fclose(c);
    return escribio;
}
bool restaurarBackupPreLiquidacion(){
    FILE *o,*c;
    PreLiquidacion reg;
    bool escribio=false;
    o=fopen(FILE_PRELIQUIDACION,"wb");
    if(o==NULL)return false;
    c=fopen(FILE_PRELIQUIDACION_BKP,"rb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,c)){
        escribio=fwrite(&reg,sizeof reg,1,o);
    }

    fclose(o);
    fclose(c);
    return escribio;
}
bool restaurarBackupLiquidacion(){
    FILE *o,*c;
    Liquidacion reg;
    bool escribio=false;
    o=fopen(FILE_LIQUIDACION,"wb");
    if(o==NULL)return false;
    c=fopen(FILE_LIQUIDACION_BKP,"rb");
    if(c==NULL){
        fclose(o);
        return false;
    }

    while(fread(&reg, sizeof reg,1,c)){
        escribio=fwrite(&reg,sizeof reg,1,o);
    }

    fclose(o);
    fclose(c);
    return escribio;
}

void bajaLogicaEmpleado(){
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
    if(pos==-1){cout<<"EL DNI NO EXISTE";}

    cout<<"INGRESE EL NUEVO NUMERO DE TELEFONO: ";
    cin>>ntel;

    reg.leerEnDisco(pos);
    reg.setTelefono(ntel);

    bool modifico=modificarEnDisco(reg,pos);
    return modifico;

}
#endif // FUNCIONES_H_INCLUDED
