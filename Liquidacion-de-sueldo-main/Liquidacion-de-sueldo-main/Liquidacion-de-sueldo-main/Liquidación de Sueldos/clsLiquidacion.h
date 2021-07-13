#ifndef CLSLIQUIDACION_H_INCLUDED
#define CLSLIQUIDACION_H_INCLUDED

bool generarliquidacion();
int buscarPreliq(int);
int calcularAntiguedad(int);
int calcularAnios(Fecha);
bool validarExistenciaPreliquidacion(Fecha,int);

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
        // SOBRECARGA DE OPERADORES

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
int calcularAntiguedad(int dni){
    Empleado reg;
    int pos=0,antiguedad;
    while(reg.leerEnDisco(pos++)){
        if(reg.getDni()==dni){
            antiguedad=CalcularEdad(reg.getFechaIngreso());
            return antiguedad;
        }
    }
    return -1;
}

//--------------VALIDAR EXISTENCIA PRELIQUIDACION-------------//
bool validarExistenciaPreliquidacion(Fecha fechaP,int dni){
    PreLiquidacion obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.getDni()==dni && obj.getFecha().getMes() == fechaP.getMes() && obj.getFecha().getAnio()==fechaP.getAnio())
        return true;
    }
    return false;
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
    char nombreDelCargo[25];
    //float sueldoBRUTO=-1, sueldoBASICO=-1, sueldoNETO=-1;
    float sueldoBASICO=-1;
    PreLiquidacion preLiq;
    Empleado empleado;
    Cargo cargo;
    Descuentos desc;
    Fecha peridioLiq;
    cout<<"INTRODUZCA EL DNI DEL EMPLEADO: ";
    cin>>auxDni;
    if(buscarEmpleado(auxDni)==false)cout<<"NO EXISTE EMPLEADO CON ESE NUMERO DE DNI"<<endl;
    cout<<"INGRESE EL PERIODO DE LIQUIDACION: ";
    peridioLiq.cargar();
    if(validarExistenciaPreliquidacion(peridioLiq,auxDni)==false){cout<<"NO EXISTE PRELIQUIDACION DE EMPLEADO PARA ESTE PERIODO";}

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
                        ///Lo que sigue es para generar el recibo
                        strcpy(nombreDelCargo, cargo.getNombreCargo());
                        }
                    }
                }
            }
        }
    }//// CORREGI EL PORCENTAJE SE SACA SOBRE EL SUELDO BRUTO
    //// ACA DESCONTAMOS Y SACAMOS EL SUELDO NETO
    if(desc.leerDeDisco(0)==true){
        jubilacion=(desc.getJubilacion()*sueldoBRUTO)/100;
        obraSocial=(desc.getObraSocial()*sueldoBRUTO)/100;
        ley19032=(desc.getLey19032()*sueldoBRUTO)/100;
        SEC=(desc.getSEC()*sueldoBRUTO)/100;
        FAEC=(desc.getFAEC()*sueldoBRUTO)/100;
    }
    sueldoNETO=sueldoBRUTO-(jubilacion+obraSocial+ley19032+SEC+FAEC);

    ///dibujartabla 32 filas 5 columnas
    system("cls");
    int POSMENUX=5,POSMENUY=4, ANCHO_MENU=91,ALTO_MENU=28;
    int opc=1,cursorX,cursorY;
    hidecursor();
    float deducciones=jubilacion+obraSocial+ley19032+SEC+FAEC;
    cursorX=POSMENUX+1;
    cursorY=POSMENUY+3;
    recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
    /////////////////////// PRIMERA PARTE //////////////////////////////////
    locate(10,5);cout<<"Nombre y apellido ";
    locate(10,6);cout<<empleado.getNombre()<<" "<<empleado.getApellido();
    locate(10,7);cout<<"FECHA INGRESO: ";
    locate(10,8);empleado.getFechaIngreso().mostrar();
    locate(10,9);cout<<"PERIODO TRABAJADO: "<<"--AGREGAR PERIODO-- EJ: 2/6/2021 AL 2/7/2021";
    //locate(40,7);cout<<"SUELDO BASICO: ";
    //locate(41,8);cout<<"$"<<empleado.getSueldo();
    locate(70,5);cout<<"DNI: "<<dni;
    locate(70,6);cout<<"--NOMBRE DEL CARGO--";
    locate(70,7);cout<<nombreDelCargo;
    /////////////////////// PRIMERA PARTE //////////////////////////////////
    separadorH(POSMENUX,POSMENUY+6,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    /////////////////////// SEGUNDA PARTE //////////////////////////////////
    locate(9,11);cout<<"HABERES";locate(40,11);cout<<"%";locate(84,11);cout<<"IMPORTE";
    separadorH(POSMENUX,POSMENUY+8,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    locate(9,13);cout<<"SUELDO BASICO";locate(83,13);cout<<"$ "<<empleado.getSueldo();
    locate(9,14);cout<<"ANTIGUEDAD";locate(40,14);cout<<"% ";locate(83,14);cout<<"$ "<<antiguedad;
    locate(9,15);cout<<"PRESENTISMO";locate(40,15);cout<<"% ";locate(83,15);cout<<"$ "<<asistencia;
    locate(9,16);cout<<"PUNTUALIDAD";locate(40,16);cout<<"% ";locate(83,16);cout<<"$ "<<puntualidad;
    locate(9,17);cout<<"PLUS FERIADO/S";locate(40,17);cout<<"% ";locate(83,17);cout<<"$ "<<feriado;
    locate(9,19);cout<<"SUB-TOTAL";locate(83,19);cout<<"$ "<<sueldoBRUTO;
    /////////////////////// SEGUNDA PARTE //////////////////////////////////
    separadorH(POSMENUX,POSMENUY+16,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    /////////////////////// TERCERA PARTE //////////////////////////////////
    locate(9,21);cout<<"DEDUCCIONES";locate(51,21);cout<<"%";locate(70,21);cout<<"IMPORTE";
    separadorH(POSMENUX,POSMENUY+18,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    locate(9,23);cout<<"JUBILACION";locate(50,23);cout<<"%";locate(68,23);cout<<"$ "<<jubilacion<<endl;
    locate(9,24);cout<<"OBRA SOCIAL";locate(50,24);cout<<"%";locate(68,24);cout<<"$ "<<obraSocial<<endl;
    locate(9,25);cout<<"LEY 19032";locate(50,25);cout<<"%";locate(68,25);cout<<"$ "<<ley19032<<endl;
    locate(9,26);cout<<"SEC";locate(50,26);cout<<"%";locate(68,26);cout<<"$ "<<SEC<<endl;
    locate(9,27);cout<<"FAEC";locate(50,27);cout<<"%";locate(68,27);cout<<"$ "<<FAEC<<endl;
    locate(9,29);cout<<"DEDUCCIONES";locate(83,29);cout<<"$ "<<deducciones;
    separadorH(POSMENUX,POSMENUY+26,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    /////////////////////// TERCERA PARTE //////////////////////////////////
    locate(40,31);cout<<"IMPORTE A COBRAR: ";locate(83,31);cout<<"$ "<<sueldoNETO;

    /*int fila, cant=5;
    fila=32;
    dibujarRecibo(fila);
    for(int i=0;i<cant;i++){
        //reg.leerDeDisco(i);
        //ampliarTablaDescuentos(fila);
        //mostrarDescuentosRecuadro(fila,reg);
        fila++;
        if(i!=cant-1){
                cout<<"HOLAAAAA";
            separadorH(5,fila,57,LETRA_COLOR,FONDO_COLOR);
            setlocale(LC_ALL,"C");
            locate(18, fila);
            cout<<"HOLAAAA";
            cout<<(char)206;
            locate(29, fila);
            cout<<(char)206;
            locate(45, fila);
            cout<<(char)206;
            locate(51, fila);
            cout<<(char)206;
            setlocale(LC_ALL,"spanish");
            fila++;
        }*/

/*
    cout<<"SUELDO BRUTO: $"<<sueldoBRUTO<<endl;
    cout<<"SUELDO NETO: $"<<sueldoNETO<<endl;

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
    cout<<"-----------------------------------"<<endl<<endl;*/

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
