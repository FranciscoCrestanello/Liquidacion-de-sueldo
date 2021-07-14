#ifndef CLSEMPLEADO_H_INCLUDED
#define CLSEMPLEADO_H_INCLUDED

#include "rlutilFunciones.h"

void cargarCadena(char *pal, int tam);
int calcularAnios(Fecha obj);
bool verificarDni(int);
bool verificarEdad(int,int,int);


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
    char aux[30];
    int num;

    recuadro(5,20,83,10,LETRA_COLOR,FONDO_COLOR);
    locate(6,21);cout<<"-EL NOMBRE Y EL APELLIDO DEBE SER MAXIMO DE 25 LETRAS ";
    locate(6,22);cout<<"-EL EMAIL DEBE TENER COMO MÁXIMO 35 CARACTERES Y @";
    locate(6,23);cout<<"-LA FECHA DE NACIMIENTO E INGRESO DEBE SER EN FORMATO DD/MM/AAAA";
    locate(6,24);cout<<"-EL DNI DEBE INGRESARSE SIN PUNTOS NI COMAS";
    locate(6,25);cout<<"-EL CARGO PUEDE SER:";
    locate(6,26);cout<<"\t\t1: MAESTRANZA";
    locate(6,27);cout<<"\t\t2: ADMINISTRATIVO";
    locate(6,28);cout<<"\t\t3: CAJERO";
    locate(6,29);cout<<"\t\t4: VENDEDOR";

    locate(6,4);cout<<"NOMBRE: ";
    locate(6,5);cout<<"APELLIDO: ";
    locate(6,6);cout<<"E-MAIL: ";
    locate(6,7);cout<<"FECHA NACIMIENTO: ";
    locate(6,8);cout<<"FECHA DE INGRESO: ";
    locate(6,9);cout<<"DOMICILIO: ";
        locate(6,10);cout<<"-LOCALIDAD: ";
        locate(6,11);cout<<"-CALLE: ";
        locate(6,12);cout<<"-NUMERO: ";
    locate(6,13);cout<<"TELEFONO: ";
    locate(6,14);cout<<"DNI: ";
    locate(6,15);cout<<"CARGO: ";
    locate(6,16);cout<<"SUELDO ";
    locate(6,17);cout<<"ESTADO: ";

    locate(27,4);cargarCadena(nombre, 24);
    while(strlen(nombre)==0){
            locate(4,4);cout<<"!";
            locate(5,19);cout<<"! ESTE CAMPO NO PUEDE ESTAR VACIO";
            locate(27,4);cargarCadena(nombre, 24);}
    locate(4,4);cout<<" ";
    locate(5,19);cout<<"                                          ";

    locate(27,5);cargarCadena(apellido, 24);
    while(strlen(apellido)==0){
            locate(4,5);cout<<"!";
            locate(5,19);cout<<" ! ESTE CAMPO NO PUEDE ESTAR VACIO";
            locate(27,5);cargarCadena(apellido, 24);}
    locate(4,5);cout<<" ";
    locate(5,19);cout<<"                                           ";

    locate(27,6);cargarCadena(email, 34);
    while(strlen(email)==0){
            locate(4,6);cout<<"!";
            locate(5,19);cout<<"! ESTE CAMPO NO PUEDE ESTAR VACIO";
            locate(27,6);cargarCadena(email, 24);}
    locate(4,6);cout<<" ";
    locate(5,19);cout<<"                                            ";


    //cout<<"FECHA DE NACIMIENTO ";
    int d,m,a;
    locate(28,7);cin>>d;
    fechaDeNacimiento.setDia(d);
    locate(30,7);cout<<"/";
    locate(31,7);cin>>m;
    fechaDeNacimiento.setMes(m);
    locate(33,7);cout<<"/";
    locate(34,7);cin>>a;
    fechaDeNacimiento.setAnio(a);

    //validar fecha de nacimiento formato correcto
    while(verificarEdad(d,m,a)== true || CalcularEdad(fechaDeNacimiento)<18){
            locate(4,7);cout<<"!";
            locate(5,19);cout<<" ERROR EN LA FECHA DE NACIMIENTO!";
            locate(28,7);cin>>d;
            fechaDeNacimiento.setDia(d);
            locate(31,7);cin>>m;
            fechaDeNacimiento.setMes(m);
            locate(34,7);cin>>a;
            fechaDeNacimiento.setAnio(a);
    }
    locate(4,7);cout<<" ";
    locate(5,19);cout<<"                                        ";

    //cout<<"FECHA DE INGRESO: ";
    locate(28,8);cin>>d;
    fechaIngreso.setDia(d);
    locate(30,8);cout<<"/";
    locate(31,8);cin>>m;
    fechaIngreso.setMes(m);
    locate(33,8);cout<<"/";
    locate(34,8);cin>>a;
    fechaIngreso.setAnio(a);
    while(CalcularEdad(fechaDeNacimiento)<18){
            locate(4,8);cout<<"!";
            locate(5,19);cout<<" ERROR EN LA FECHA DE INGRESO!";
            locate(28,8);cin>>d;
            fechaIngreso.setDia(d);
            locate(31,8);cin>>m;
            fechaIngreso.setMes(m);
            locate(34,8);cin>>a;
            fechaIngreso.setAnio(a);
    }
    locate(4,8);cout<<" ";
    locate(5,19);cout<<"                                        ";

    // DOMICILIO OK
    locate(27,10);cargarCadena(aux,30);
    domicilio.setLocalidad(aux);
    locate(27,11);cargarCadena(aux,30);
    domicilio.setCalle(aux);
    locate(27,12);cin>>num;
    domicilio.setNumero(num);

    locate(27,13);cin>>telefono;
    while(telefono<1){
        cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. INTENTE DE NUEVO: \nTelefono: ";
        cin>>telefono;
    }

    locate(27,14);cin>>dni;
    while(verificarDni(dni)){
        locate(4,13);cout<<"!";
        locate(5,19);cout<<"! YA EXISTE UN DNI CON ESE EMPLEADO";
        locate(27,14);cout<<"           ";
        locate(27,14);cin>>dni;}
    locate(4,13);cout<<" ";
    locate(5,19);cout<<"                                                        ";

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
                locate(27,15);cout<<reg.getNombreCargo();
            }
        }
        if(cargoEncontrado==false){
            locate(5,19);cout<<"EL CARGO NO EXISTE!";
            locate(27,15);cin>>cargo;
        }
        locate(5,19);cout<<"                                                   ";
    }

    locate(27,16);cout<<"$"<<sueldo<<endl;
    locate(27,17);
    setEstado(1);
}

void Empleado::mostrar(){
    int POSMENUX=28,POSMENUY=7, ANCHO_MENU=50,ALTO_MENU=15;
    recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
    locate(30,8);cout<<"NOMBRE: "<<nombre;
    locate(30,9);cout<<"APELLIDO: "<<apellido;
    locate(30,10);cout<<"E-MAIL: "<<email;
    locate(30,11);cout<<"FECHA NACIMIENTO: ";fechaDeNacimiento.mostrar();
    locate(30,12);cout<<"FECHA DE INGRESO: ";fechaIngreso.mostrar();
    locate(30,13);domicilio.mostrar();
    locate(30,14);cout<<"TELEFONO: "<<telefono;
    locate(30,15);cout<<"DNI: "<<dni;
    Cargo reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getCargo()==cargo){
            locate(30,16);cout<<"CODIGO DE CARGO: "<<cargo<<endl;
            locate(30,17);cout<<"NOMBRE DEL CARGO: "<<reg.getNombreCargo()<<endl;
        }
    }
    //locate(30,15);cout<<"CARGO: "<<cargo;
    locate(30,18);cout<<"SUELDO "<<sueldo;
    locate(30,19);cout<<"ESTADO: "<<estado;
    separadorH(POSMENUX,POSMENUY+13,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    /*
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
    */
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

//// VERIFICAR EXISTENCIA DNI////

bool verificarDni(int _dni){
    Empleado reg;
    int pos=0;
    while(reg.leerEnDisco(pos++)==true){
        if(reg.getDni()==_dni){
            return true;
        }
    }
    return false;
}

//// VERIFICAR FECHAS INGRESADAS///

bool verificarEdad(int d,int m,int a){
    if(a>3000 || a<1920){
        return true;
    }
    if(m>12 || m<1){
        return true;
    }
    if(d>31 || d<1){
        return true;
    }
    return false;
}



#endif // CLSEMPLEADO_H_INCLUDED
