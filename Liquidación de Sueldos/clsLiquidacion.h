#ifndef CLSLIQUIDACION_H_INCLUDED
#define CLSLIQUIDACION_H_INCLUDED

bool generarliquidacion();
int buscarPreliq(int);
int calcularAntiguedad(int);
int calcularAnios(Fecha);

class Liquidacion{
	private:
        Fecha periodoLiquidacion;
        int dni;
        float sueldo,antiguedad,asistencia,puntualidad,feriado,jubilacion;
        float obraSocial,ley19032,SEC,FAEC;
        float sueldoBRUTO, sueldoNETO;
	public:
        // sets
        void setFecha(Fecha f){periodoLiquidacion=f;}
        void setDni(int x){dni=x;}
        void setSueldo(float x){sueldo=x;}
        void setAntiguedad(float x){antiguedad=x;}
        void setAsistencia(float x){asistencia=x;}
        void setPuntualidad(float x){puntualidad=x;}
        void setFeriado(float x){feriado=x;}
        void setJubilacion(float x){jubilacion=x;}
        void setObraSocial(float x){obraSocial=x;}
        void setLey19032(float x){ley19032=x;}
        void setSEC(float x){SEC=x;}
        void setFAEC(float x){FAEC=x;}
        // gets
        int setDni(){return dni;}
        float getSueldo(){return sueldo;}
        float getAntiguedad(){return antiguedad;}
        float getAsistencia(){return asistencia;}
        float getAPuntualidad(){return puntualidad;}
        float getFeriado(){return feriado;}
        float getJubilacion(){return jubilacion;}
        float getObraSocial(){return obraSocial;}
        float getLey19032(){return ley19032;}
        float getSEC(){return SEC;}
        float getFAEC(){return FAEC;}
        Fecha getFecha(){return periodoLiquidacion;}
        // mostrar y cargar
        void mostrarL();
        void cargar();
        void cargarAutomatico();
        //GRABAR Y LEER EN DISCO
        bool leerDeDisco(int );
        bool grabarEnDisco();
};

void Liquidacion::cargar(){
    cout<<"PERIODO DE LIQUIDACION: "<<endl;
    periodoLiquidacion.cargar();
    cout<<"DNI: ";
    cin>>dni;
    cout<<"SUELDO: $";
    cin>>sueldo;
    cout<<"ANTIGUEDAD: ";
    cin>>antiguedad;
    cout<<"ASISTENCIA: ";
    cin>>asistencia;
    cout<<"PUNTUALIDAD: ";
    cin>>puntualidad;
    cout<<"FERIADO: ";
    cin>>feriado;
    cout<<"JUBILACION: ";
    cin>>jubilacion;
    cout<<"OBRA SOCIAL: ";
    cin>>obraSocial;
    cout<<"LEY 19032: ";
    cin>>ley19032;
    cout<<"SEC: ";
    cin>>SEC;
    cout<<"FAEC: ";
    cin>>FAEC;
    cout<<endl;
}
void Liquidacion::mostrarL(){
    cout<<"PERIODO DE LIQUIDACION: ";
    getFecha().mostrar();
    cout<<"DNI: "<<dni<<endl;
    cout<<"SUELDO: $"<<sueldo<<endl;
    cout<<"ANTIGUEDAD: $"<<antiguedad<<endl;
    cout<<"ASISTENCIA: $"<<asistencia<<endl;
    cout<<"PUNTUALIDAD: $"<<puntualidad<<endl;
    cout<<"FERIADO: $"<<feriado<<endl;
    cout<<"JUBILACION: $"<<jubilacion<<endl;
    cout<<"OBRA SOCIAL: $"<<obraSocial<<endl;
    cout<<"LEY 19032: $"<<ley19032<<endl;
    cout<<"SEC: $"<<SEC<<endl;
    cout<<"FAEC: $"<<FAEC<<endl<<endl;
    cout<<"SUELDO BRUTO: $: "<<sueldoBRUTO<<endl;
    cout<<"SUELDO NETO: $: "<<sueldoNETO<<endl<<endl;
    cout<<"-----------------------------------"<<endl<<endl;
}

bool Liquidacion::grabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen(FILE_LIQUIDACION,"ab");
    if(p==NULL)return false;
    escribio=fwrite(this,sizeof(Liquidacion),1,p);
    fclose(p);
    return escribio;
}
bool Liquidacion::leerDeDisco(int pos){
    FILE *p;
    bool leyo;
    p=fopen(FILE_LIQUIDACION, "rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Liquidacion),0);
    leyo = fread(this,sizeof(Liquidacion),1,p);
    fclose(p);
    return leyo;
}

bool buscarEmpleado(int dni){
    Empleado reg;
    int pos=0;
    while(reg.leerEnDisco(pos++)==true){
        if(reg.getDni()==dni){
            return true;
        }
    }
    return false;
}

int buscarPreliq(int dni){
    PreLiquidacion reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if (reg.getDni()==dni){
            return pos;
        }
        pos++;
    }
    return -1;
}

/// CALCULAR ANTIGUEDAD

int calcularAnios(Fecha obj1){
    int anios;
    int anioAct, mesAct, diaAct;
    time_t t = time(0);
    tm* now = localtime(&t);

    anioAct=(now->tm_year + 1900);
    mesAct= (now->tm_mon + 1);
    diaAct= now->tm_mday;
    obj1.mostrar();
    cout<<diaAct<<"/"<<mesAct<<"/"<<anioAct<<endl;
    anios = anioAct-obj1.getAnio();
    if ( (mesAct< obj1.getMes() ) || ( ( obj1.getMes() == mesAct ) && (obj1.getDia()< diaAct ))){
        anios--;
    }
    return anios;
}

////// CODIGO QUE ASIGNA FECHA ACUTAL ////
/*
    time_t t = time(0);
    tm* now = localtime(&t);
    cout << now->tm_mday<<"/"<< (now->tm_mon + 1)<<"/"<<(now->tm_year + 1900)<<endl;

    FUENTE: https://www.it-swarm-es.com/es/c%2B%2B/como-obtener-la-hora-y-fecha-actual-en-c/957697906/
*/
int calcularAntiguedad(int dni){
    Empleado reg;
    int pos=0,antiguedad;
    while(reg.leerEnDisco(pos++)){
        if(reg.getDni()==dni){
            antiguedad=calcularAnios(reg.getFechaIngreso());
            return antiguedad;
        }
    }
    return -1;
}

/*
float generarSueldoBruto(){
    int dni, pos=0;
    Liquidacion obj;
    PreLiquidacion reg;
    Empleado emp;
    cout<<"INTRODUZCA EL DNI DEL EMPLEADO: ";
    cin>>dni;
    while(reg.leerDeDisco(pos++)){
        if(reg.getDni==dni){

        }
    }
}*/

void Liquidacion::cargarAutomatico(){
    int auxDni, pos=0, posEmpleado=0, posCargo=0;
    //float sueldoBRUTO=-1, sueldoBASICO=-1, sueldoNETO=-1;
    float sueldoBASICO=-1;
    PreLiquidacion preLiq;
    Empleado empleado;
    Cargo cargo;
    Descuentos desc;
    cout<<"INTRODUZCA EL DNI DEL EMPLEADO: ";
    cin>>auxDni;

    while(preLiq.leerDeDisco(pos++)){
        if(preLiq.getDni()==auxDni){
            periodoLiquidacion=preLiq.getFecha();
            dni=auxDni;

            while(empleado.leerEnDisco(posEmpleado++)){
                if(empleado.getDni()==auxDni){
                    sueldo=empleado.getSueldo();
                    while(cargo.leerDeDisco(posCargo++)){
                        if(cargo.getCargo()==empleado.getCargo()){
                        antiguedad=((cargo.getAntiguedad()/100)*empleado.getSueldo())*calcularAntiguedad(empleado.getDni());
                        if(preLiq.getPresentismo()==true)asistencia=(cargo.getAsisistencia()*empleado.getSueldo())/100;
                        else{asistencia=0;}
                        if(preLiq.getPuntualidad()==true)puntualidad=(cargo.getPuntualidad()*empleado.getSueldo())/100;
                        else{puntualidad=0;}
                        feriado=preLiq.getFeriados()*((cargo.getPlusFeriado()/100)*empleado.getSueldo());
                        sueldoBRUTO=empleado.getSueldo()+asistencia+puntualidad+antiguedad+feriado;
                        sueldoBASICO=empleado.getSueldo();
                        }
                    }
                }
            }
        }
    }
    //// ACA DESCONTAMOS Y SACAMOS EL SUELDO NETO
    if(desc.leerDeDisco(0)==true){
        jubilacion=(desc.getJubilacion()*sueldoBASICO)/100;
        obraSocial=(desc.getObraSocial()*sueldoBASICO)/100;
        ley19032=(desc.getLey19032()*sueldoBASICO)/100;
        SEC=(desc.getSEC()*sueldoBASICO)/100;
        FAEC=(desc.getFAEC()*sueldoBASICO)/100;
    }
    sueldoNETO=sueldoBRUTO-(jubilacion+obraSocial+ley19032+SEC+FAEC);

    cout<<"SUELDO BRUTO: $"<<sueldoBRUTO<<endl;
    cout<<"SUELDO NETO: $"<<sueldoNETO<<endl;
    system("pause>nul");
    cout<<endl;
}

bool generarliquidacion(){
    Liquidacion reg;
    reg.cargarAutomatico();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

#endif // CLSLIQUIDACION_H_INCLUDED
