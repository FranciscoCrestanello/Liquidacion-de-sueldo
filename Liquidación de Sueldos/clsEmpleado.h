#ifndef CLSEMPLEADO_H_INCLUDED
#define CLSEMPLEADO_H_INCLUDED

#include "rlutilFunciones.h"

void cargarCadena(char *pal, int tam);
int calcularAnios(Fecha obj);

class Empleado{
	private:
	char nombre[25],apellido[25],email[35];
	Fecha fechaDeNacimiento,fechaIngreso;
	Domicilio domicilio;
	int telefono, dni, cargo;
    float sueldo;
	bool estado;
public:
	//sets
	void setNombre(const char *x){strcpy(nombre,x);}
	void setApellido(const char *x){strcpy(apellido,x);}
	void setEmail(const char *x){strcpy(email,x);}
	void setFechaIngreso(Fecha i){fechaIngreso=i;}
	void setFechaDeNacimiento(Fecha i){fechaDeNacimiento=i;}
	void setDomicilio(Domicilio d){domicilio=d;}
	void setTelefono(int x){telefono=x;}
	void setDni(int x){dni=x;}
	void setCargo(int x){cargo=x;}
	void setSueldo(float x){sueldo=x;}
	void setEstado(bool x){estado=x;}
	//gets
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    Fecha getFechaIngreso(){return fechaIngreso;}
    Fecha getFecha(){return fechaDeNacimiento;}
    Domicilio getDomicilio(){return domicilio;}
    int getTelefono(){return telefono;}
    int getDni(){return dni;}
    int getCargo(){return cargo;}
    float getSueldo(){return sueldo;}
    bool getEstado(){return estado;}
	//cargar y mostrar Empleado
	void cargar();
    void mostrar();
    //Leer y grabar Empleado
	bool grabarEnDisco();
	bool leerEnDisco(int );
};

void Empleado::cargar(){

    dibujarTablaEmpleados(5);
    ///ampliarTabla(5);
    ///recuadro(5,15,83,10,LETRA_COLOR,FONDO_COLOR);

    locate(6,21);
    cout<<"-EL NOMBRE Y EL APELLIDO DEBE SER MAXIMO DE 25 LETRAS ";
    locate(6,22);
    cout<<"-EL EMAIL DEBE TENER COMO MÁXIMO 35 CARACTERES Y @";
    locate(6,23);
    cout<<"-LA DIRECCIÓN DEBE ESTAR COMPUESTA POR LA LOCALIDAD, CALLE Y NUMERO";
    locate(6,24);
    cout<<"-EL CARGO PUEDE SER:";
    locate(6,26);
    cout<<"\t\t1: MAESTRANZA";
    locate(6,27);
    cout<<"\t\t2: ADMINISTRATIVO";
    locate(6,28);
    cout<<"\t\t3: CAJERO";
    locate(6,29);
    cout<<"\t\t4: VENDEDOR";

    //bool mayorDeEdad=false;
    //cout<<"NOMBRE: ";
    locate(27,7);cargarCadena(nombre, 24);
    while(strlen(nombre)==0){cargarCadena(nombre, 24);}
    //cout<<"APELLIDO: ";
    locate(27,8);cargarCadena(apellido, 24);
    while(strlen(apellido)==0){cargarCadena(apellido, 24);}
    //cout<<"EMAIL: ";
    locate(27,9);cargarCadena(email, 34);
    while(strlen(email)==0){cargarCadena(email, 34);}

/*
    //cout<<"FECHA DE NACIMIENTO ";
    locate(27,10);
    fechaDeNacimiento.cargar();
    while(CalcularEdad(fechaDeNacimiento)<18){
            cout<<"NO SE PERMITE REGISTRAR A MENORES DE EDAD."<<endl;
            cout<<"INGRESE NUEVAMENTE LA FECHA DE NACIMIENTO: ";
            fechaDeNacimiento.cargar();
        }

    cout<<"FECHA DE INGRESO: ";
    locate(27,11);
    fechaIngreso.cargar();
*/
    //cout<<"TELEFONO: ";
    locate(27,12);cin>>telefono;
    while(telefono<1){
        cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. INTENTE DE NUEVO: \nTelefono: ";
        cin>>telefono;
    }
    //cout<<"DNI: ";
    locate(27,13);cin>>dni;
    while(dni<1){
        cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. INTENTE DE NUEVO: \nDNI: ";
        cin>>dni;
    }
    locate(27,14);


    //cout<<"CODIGO DE CARGO: ";
    locate(27,15);cin>>cargo;
    int x,cant=contadorDeCargos();
    Cargo reg;
    bool cargoEncontrado=false;
    while(cargoEncontrado==false){
        for(x=0;x<cant;x++){
            reg.leerDeDisco(x);
            if(reg.getCargo()==cargo){
                cargoEncontrado=true;
                sueldo=reg.getSueldoBasico();
                cout<<"NOMBRE DEL CARGO: "<<reg.getNombreCargo()<<endl;
            }
        }
        if(cargoEncontrado==false){
            cout<<"EL CARGO NO EXISTE. INTENTE DE NUEVO: \nCARGO: ";
            cin>>cargo;
        }
    }
    //cout<<"SUELDO: $"
    locate(27,16);cout<<sueldo<<endl;
    domicilio.cargar();
    setEstado(1);




}

void Empleado::mostrar(){
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"EMAIL: "<<email<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaDeNacimiento.mostrar();
    cout<<"FECHA DE INGRESO: ";
    fechaIngreso.mostrar();
    domicilio.mostrar();
    cout<<"TELEFONO: "<<telefono<<endl;
    cout<<"DNI: "<<dni<<endl;
    Cargo reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getCargo()==cargo){
            cout<<"CODIGO DE CARGO: "<<cargo<<endl;
            cout<<"NOMBRE DEL CARGO: "<<reg.getNombreCargo()<<endl;
        }
    }
    cout<<"SUELDO: $"<<sueldo<<endl;
    cout<<"ESTADO: "<<estado<<endl<<endl;
}

bool Empleado::grabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen(FILE_EMPLEADOS,"ab");
    if(p==NULL)return false;
    escribio=fwrite(this,sizeof(Empleado),1,p);
    fclose(p);
    return escribio;
}
bool Empleado::leerEnDisco(int pos){
    FILE *p;
    bool leyo;
    p=fopen(FILE_EMPLEADOS, "rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Empleado),0);
    leyo = fread(this,sizeof(Empleado),1,p);
    fclose(p);
    return leyo;
}

#endif // CLSEMPLEADO_H_INCLUDED
