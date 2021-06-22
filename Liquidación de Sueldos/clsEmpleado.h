#ifndef CLSEMPLEADO_H_INCLUDED
#define CLSEMPLEADO_H_INCLUDED
void cargarCadena(char *pal, int tam);
class Empleado{
	private:
	char nombre[25],apellido[25],email[35];
	Fecha fechaDeNacimiento;
	Fecha fechaIngreso;
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
	/// leer registro especifico
	Empleado leerEmpleado(int);
};

void Empleado::cargar(){
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 24);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 24);
    cout<<"EMAIL: ";
    cin>>email;
    cout<<"FECHA DE NACIMIENTO ";
    fechaDeNacimiento.cargar();
    while(fechaDeNacimiento.getAnio()==-1||fechaDeNacimiento.getMes()==-1||fechaDeNacimiento.getDia()==-1){
        cout<<"FECHA INCORRECTA. INGRESE UNA FECHA VALIDA: ";
        fechaDeNacimiento.cargar();
    }
    cout<<"FECHA DE INGRESO: ";
    fechaIngreso.cargar();
    while(fechaIngreso.getAnio()==-1||fechaIngreso.getMes()==-1||fechaIngreso.getDia()==-1){
        cout<<"FECHA INCORRECTA. INGRESE UNA FECHA VALIDA: ";
        fechaIngreso.cargar();
    }
    cout<<"TELEFONO: ";
    cin>>telefono;
    while(telefono<1){
        cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. INTENTE DE NUEVO: \nTelefono: ";
        cin>>telefono;
    }
    cout<<"DNI: ";
    cin>>dni;
    while(dni<1){
        cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. INTENTE DE NUEVO: \nDNI: ";
        cin>>dni;
    }
    cout<<"CARGO: ";
    cin>>cargo;
    int x,cant=contadorDeCargos();
    Cargo reg;
    bool cargoEncontrado=false;
    while(cargoEncontrado==false){
        for(x=0;x<cant;x++){
            reg.leerDeDisco(x);
            if(reg.getCargo()==cargo){
                cargoEncontrado=true;
                sueldo=reg.getSueldoBasico();
            }
        }
        if(cargoEncontrado==false){
            cout<<"EL CARGO NO EXISTE. INTENTE DE NUEVO: \nCARGO: ";
            cin>>cargo;
        }
    }
    cout<<"SUELDO: $"<<sueldo<<endl;
    domicilio.cargar();
    setEstado(1);
    cout<<"ESTADO: "<<estado<<endl;
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
    cout<<"CARGO: "<<cargo<<endl;
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

Empleado leerEmpleado(int pos){
    Empleado reg;
    FILE *P;
    P=fopen(FILE_EMPLEADOS,"rb");
    if(P==NULL){return reg;}
    fseek(P, pos*sizeof reg, 0);
    fread(&reg,sizeof reg,1,P);
    fclose(P);
    return reg;
}
#endif // CLSEMPLEADO_H_INCLUDED
