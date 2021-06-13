#ifndef CLSEMPLEADO_H_INCLUDED
#define CLSEMPLEADO_H_INCLUDED

class Empleado{
	private:
	char nombre[25],apellido[25],email[35];
	Fecha fechaDeNacimiento;
	Domicilio domicilio;
	int telefono, dni, cargo;
    float sueldo;
	bool estado;
public:
	//sets
	void setNombre(const char *x){strcpy(nombre,x);}
	void setApellido(const char *x){strcpy(apellido,x);}
	void setEmail(const char *x){strcpy(email,x);}
	void setTelefono(int x){telefono=x;}
	void setDni(int x){dni=x;}
	void setCargo(int x){cargo=x;}
	void setSueldo(float x){sueldo=x;}
	void setEstado(bool x){estado=x;}
	//gets
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
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
    cout<<"----- CARGA DE EMPLEADO -----"<<endl;
    cout<<"NOMBRE: ";
    cin>>nombre;
    cout<<"APELLIDO: ";
    cin>>apellido;
    cout<<"EMAIL: ";
    cin>>email;
    cout<<"FECHA DE NACIMIENTO ";
    fechaDeNacimiento.cargar();
    cout<<"TELEFONO: ";
    cin>>telefono;
    cout<<"DNI: ";
    cin>>dni;
    cout<<"CARGO: ";
    cin>>cargo;
    cout<<"SUELDO: $";
    cin>>sueldo;
    domicilio.cargar();
    setEstado(1);
    cout<<"ESTADO: "<<estado<<endl;
}
void Empleado::mostrar(){
    cout<<"----- MOSTRAR EMPLEADO -----"<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"EMAIL: "<<email<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaDeNacimiento.mostrar();
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

#endif // CLSEMPLEADO_H_INCLUDED
