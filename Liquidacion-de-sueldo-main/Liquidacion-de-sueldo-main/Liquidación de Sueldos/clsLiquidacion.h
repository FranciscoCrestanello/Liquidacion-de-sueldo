#ifndef CLSLIQUIDACION_H_INCLUDED
#define CLSLIQUIDACION_H_INCLUDED

#include "clsEmpleado.h"

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
    int d,m,a;
    locate(8,4);cout<<"PERIODO DE LIQUIDACION:"<<endl;
    locate(34,4);cin>>d;
    periodoLiquidacion.setDia(d);
    locate(36,4);cout<<"/";
    locate(37,4);cin>>m;
    periodoLiquidacion.setMes(m);
    locate(39,4);cout<<"/";
    locate(40,4);cin>>a;
    periodoLiquidacion.setAnio(a);

    locate(8,5);cout<<"DNI: ";
    cin>>dni;
    while(verificarDni(dni)==false){
        locate(7,5);cout<<"!";
        locate(5,19);cout<<"NO EXISTE EMPLEADO CON ESE DNI";
        locate(8,5);cin>>dni;
    }
    locate(7,5);cout<<" ";
    locate(5,19);cout<<"                            ";

    locate(8,6);cout<<"SUELDO: $";
    cin>>sueldo;
    while(sueldo<1){
        locate(7,6);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,6);cin>>sueldo;
    }

    locate(7,6);cout<<" ";
    locate(5,19);cout<<"                                ";


    locate(8,7);cout<<"ANTIGUEDAD: ";
    cin>>antiguedad;
    while(antiguedad<1){
        locate(7,7);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,7);cin>>antiguedad;
    }

    locate(7,7);cout<<" ";
    locate(5,19);cout<<"                                ";


    locate(8,8);cout<<"ASISTENCIA: ";
    cin>>asistencia;
    while(asistencia<1){
        locate(7,8);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,8);cin>>asistencia;
    }
    locate(7,7);cout<<" ";
    locate(5,19);cout<<"                                ";


    locate(8,9);cout<<"PUNTUALIDAD: ";
    cin>>puntualidad;
    while(puntualidad<1){
        locate(7,9);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,9);cin>>puntualidad;
    }
    locate(7,9);cout<<" ";
    locate(5,19);cout<<"                                ";

    locate(8,10);cout<<"FERIADO: ";
    cin>>feriado;
    while(feriado<1){
        locate(7,10);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,10);cin>>feriado;
    }
    locate(7,10);cout<<" ";
    locate(5,19);cout<<"                                ";


    locate(8,11);cout<<"JUBILACION: ";
    cin>>jubilacion;
    while(jubilacion<1){
        locate(7,11);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,11);cin>>jubilacion;
    }
    locate(7,11);cout<<" ";
    locate(5,19);cout<<"                                ";

    locate(8,12);cout<<"OBRA SOCIAL: ";
    cin>>obraSocial;
    while(obraSocial<1){
        locate(7,12);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,12);cin>>obraSocial;
    }
    locate(7,12);cout<<" ";
    locate(5,19);cout<<"                                ";

    locate(8,13);cout<<"LEY 19032: ";
    cin>>ley19032;
    while(ley19032<1){
        locate(7,13);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,13);cin>>ley19032;
    }
    locate(7,13);cout<<" ";
    locate(5,19);cout<<"                                ";


    locate(8,14);cout<<"SEC: ";
    cin>>SEC;
    while(SEC<1){
        locate(7,14);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,14);cin>>SEC;
    }
    locate(7,14);cout<<" ";
    locate(5,19);cout<<"                                ";


    locate(8,15);cout<<"FAEC: ";
    cin>>FAEC;
    while(FAEC<1){
        locate(7,15);cout<<"!";
        locate(5,19);cout<<"NO SON VALIDOS NUMEROS NEGATIVOS";
        locate(8,15);cin>>FAEC;
    }
    locate(7,15);cout<<" ";
    locate(5,19);cout<<"                                ";

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
        if(obj.getDni()==dni && obj.getFecha().getMes() == fechaP.getMes() && obj.getFecha().getAnio()==fechaP.getAnio())return true;
    }
    return false;
}

void Liquidacion::cargarAutomatico(){
    int auxDni, pos=0, posEmpleado=0, posCargo=0,d,m,a;
    char nombreDelCargo[25];
    float descuentosHorasNoTrabajdas,horasNoTrabajadas;
    float asistenciaPorcent,puntualidadPorcent,feriadosPorcent,antiguedadPorcent;
    //float sueldoBRUTO=-1, sueldoBASICO=-1, sueldoNETO=-1;
    float sueldoBASICO=-1;
    PreLiquidacion preLiq;
    Empleado empleado;
    Cargo cargo;
    Descuentos desc;
    Fecha peridioLiq;

    recuadro(20,8,60,8,LETRA_COLOR,FONDO_COLOR);
    separadorH(20,8+2,60,LETRA_COLOR,FONDO_COLOR);
    locate(40,9);cout<<"GENERAR LIQUIDACION";
    locate(30,11);cout<<"INGRESE EL NUMERO DE DNI DEL EMPLEADO: ";
    cin>>auxDni;

    if(buscarEmpleado(auxDni)==false){
        locate(30,18);cout<<"NO EXISTE EMPLEADO CON ESE NUMERO DE DNI"<<endl;
        system("pause>nul");
        return;
    }

    locate(30,13);cout<<"INGRESE EL PERIODO DE LIQUIDACION: ";

    locate(66,13);cin>>d;
    peridioLiq.setDia(d);
    locate(68,13);cout<<"/";
    locate(69,13);cin>>m;
    peridioLiq.setMes(m);
    locate(71,13);cout<<"/";
    locate(72,13);cin>>a;
    peridioLiq.setAnio(a);

    if(validarExistenciaPreliquidacion(peridioLiq,auxDni)==false){
        locate(30,18);cout<<"NO EXISTE PRELIQUIDACION DE EMPLEADO PARA ESTE PERIODO";
        system("pause>nul");
        return;
    }

    while(preLiq.leerDeDisco(pos++)){
        if(preLiq.getDni()==auxDni && peridioLiq.getDia()==preLiq.getFecha().getDia() && peridioLiq.getMes() == preLiq.getFecha().getMes() && peridioLiq.getAnio()== preLiq.getFecha().getAnio()){
            periodoLiquidacion=preLiq.getFecha();
            dni=auxDni;

            while(empleado.leerEnDisco(posEmpleado++)){
                if(empleado.getDni()==auxDni){
                    sueldo=empleado.getSueldo();
                    while(cargo.leerDeDisco(posCargo++)){
                        if(cargo.getCargo()==empleado.getCargo()){
                            strcpy(nombreDelCargo,cargo.getNombreCargo()); //ESTO ES PARA EL RECIBO
                            horasNoTrabajadas=200-preLiq.getHorasTrabajadas(); // ESTO ES PARA EL RECIBO
                            descuentosHorasNoTrabajdas=(horasNoTrabajadas*empleado.getSueldo())/200;

                            antiguedad=((cargo.getAntiguedad()/100)*empleado.getSueldo())*calcularAntiguedad(empleado.getDni());
                            if(preLiq.getPresentismo()==true)asistencia=(cargo.getAsisistencia()*empleado.getSueldo())/100;
                            else{asistencia=0;}
                            if(preLiq.getPuntualidad()==true)puntualidad=(cargo.getPuntualidad()*empleado.getSueldo())/100;
                            else{puntualidad=0;}
                            feriado=preLiq.getFeriados()*((cargo.getPlusFeriado()/100)*empleado.getSueldo());
                            sueldoBRUTO=empleado.getSueldo()+asistencia+puntualidad+antiguedad+feriado;
                            sueldoBRUTO-=descuentosHorasNoTrabajdas;
                            sueldoBASICO=empleado.getSueldo();
                            ///porcentajes del recibo
                            asistenciaPorcent=cargo.getAsisistencia();
                            feriadosPorcent=cargo.getPlusFeriado();
                            puntualidadPorcent=cargo.getPuntualidad();
                            antiguedadPorcent=cargo.getAntiguedad();
                        }
                    }
                }
            }
        }
    }

/*
    while(preLiq.leerDeDisco(pos++)){
        if(preLiq.getDni()==auxDni){
            periodoLiquidacion=preLiq.getFecha();
            dni=auxDni;

            while(empleado.leerEnDisco(posEmpleado++)){
                if(empleado.getDni()==auxDni){
                    sueldo=empleado.getSueldo();
                    while(cargo.leerDeDisco(posCargo++)){
                        if(cargo.getCargo()==empleado.getCargo()){
                            strcpy(nombreDelCargo,cargo.getNombreCargo()); //ESTO ES PARA EL RECIBO
                            horasNoTrabajadas=200-preLiq.getHorasTrabajadas(); // ESTO ES PARA EL RECIBO
                            descuentosHorasNoTrabajdas=(horasNoTrabajadas*empleado.getSueldo())/100;

                            antiguedad=((cargo.getAntiguedad()/100)*empleado.getSueldo())*calcularAntiguedad(empleado.getDni());
                            if(preLiq.getPresentismo()==true)asistencia=(cargo.getAsisistencia()*empleado.getSueldo())/100;
                            else{asistencia=0;}
                            if(preLiq.getPuntualidad()==true)puntualidad=(cargo.getPuntualidad()*empleado.getSueldo())/100;
                            else{puntualidad=0;}
                            feriado=preLiq.getFeriados()*((cargo.getPlusFeriado()/100)*empleado.getSueldo());
                            sueldoBRUTO=empleado.getSueldo()+asistencia+puntualidad+antiguedad+feriado;
                            sueldoBRUTO-=descuentosHorasNoTrabajdas;
                            sueldoBASICO=empleado.getSueldo();
                            ///porcentajes del recibo
                            asistenciaPorcent=cargo.getAsisistencia();
                            feriadosPorcent=cargo.getPlusFeriado();
                            puntualidadPorcent=cargo.getPuntualidad();
                            antiguedadPorcent=cargo.getAntiguedad();
                        }
                    }
                }
            }
        }
    }
*/

    if(desc.leerDeDisco(0)==true){
        jubilacion=(desc.getJubilacion()*sueldoBRUTO)/100;
        obraSocial=(desc.getObraSocial()*sueldoBRUTO)/100;
        ley19032=(desc.getLey19032()*sueldoBRUTO)/100;
        SEC=(desc.getSEC()*sueldoBRUTO)/100;
        FAEC=(desc.getFAEC()*sueldoBRUTO)/100;
    }
    sueldoNETO=sueldoBRUTO-(jubilacion+obraSocial+ley19032+SEC+FAEC);


    system("cls");
    int POSMENUX=5,POSMENUY=4, ANCHO_MENU=91,ALTO_MENU=29;
    hidecursor();
    float deducciones=jubilacion+obraSocial+ley19032+SEC+FAEC;
    recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA_COLOR,FONDO_COLOR);
    /////////////////////// PRIMERA PARTE //////////////////////////////////
    locate(10,5);cout<<"Nombre y apellido ";
    locate(10,6);cout<<empleado.getNombre()<<" "<<empleado.getApellido();
    locate(10,7);cout<<"FECHA INGRESO: ";
    locate(10,8);empleado.getFechaIngreso().mostrar();
    locate(10,9);cout<<"FECHA DE LIQUIDACION: "<<periodoLiquidacion.getDia()<<"/"<<periodoLiquidacion.getMes()<<"/"<<periodoLiquidacion.getAnio();
    locate(70,6);cout<<"DNI: "<<dni;
    locate(70,7);cout<<"CARGO DEL EMPLEADO";
    locate(70,8);cout<<nombreDelCargo;
    /////////////////////// PRIMERA PARTE //////////////////////////////////
    separadorH(POSMENUX,POSMENUY+6,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    /////////////////////// SEGUNDA PARTE //////////////////////////////////
    locate(9,11);cout<<"HABERES";locate(40,11);cout<<"%";locate(84,11);cout<<"IMPORTE";
    separadorH(POSMENUX,POSMENUY+8,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    locate(9,13);cout<<"SUELDO BASICO";locate(83,13);cout<<"$ "<<empleado.getSueldo();
    locate(9,14);cout<<"HORAS NO TRABAJADAS";locate(37,14);cout<<horasNoTrabajadas<<" horas";locate(67,14);cout<<"$ "<<descuentosHorasNoTrabajdas;
    locate(9,15);cout<<"ANTIGUEDAD";locate(37,15);cout<<antiguedadPorcent<<"%";locate(83,15);cout<<"$ "<<antiguedad;
    locate(9,16);cout<<"PRESENTISMO";locate(37,16);cout<<asistenciaPorcent<<"%";locate(83,16);cout<<"$ "<<asistencia;
    locate(9,17);cout<<"PUNTUALIDAD";locate(37,17);cout<<puntualidadPorcent<<"%";locate(83,17);cout<<"$ "<<puntualidad;
    locate(9,18);cout<<"PLUS FERIADO/S";locate(37,18);cout<<feriadosPorcent<<"%";locate(83,18);cout<<"$ "<<feriado;
    locate(9,20);cout<<"SUB-TOTAL";locate(83,20);cout<<"$ "<<sueldoBRUTO;
    /////////////////////// SEGUNDA PARTE //////////////////////////////////
    separadorH(POSMENUX,POSMENUY+17,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    /////////////////////// TERCERA PARTE //////////////////////////////////
    locate(9,22);cout<<"DEDUCCIONES";locate(54,22);cout<<"%";locate(68,22);cout<<"IMPORTE";
    separadorH(POSMENUX,POSMENUY+19,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    locate(9,24);cout<<"JUBILACION";locate(54,24);cout<<desc.getJubilacion()<<"%";locate(67,24);cout<<"$ "<<jubilacion<<endl;
    locate(9,25);cout<<"OBRA SOCIAL";locate(54,25);cout<<desc.getObraSocial()<<"%";locate(67,25);cout<<"$ "<<obraSocial<<endl;
    locate(9,26);cout<<"LEY 19032";locate(54,26);cout<<desc.getLey19032()<<"%";locate(67,26);cout<<"$ "<<ley19032<<endl;
    locate(9,27);cout<<"SEC";locate(54,27);cout<<desc.getSEC()<<"%";locate(67,27);cout<<"$ "<<SEC<<endl;
    locate(9,28);cout<<"FAEC";locate(54,28);cout<<desc.getFAEC()<<"%";locate(67,28);cout<<"$ "<<FAEC<<endl;
    locate(9,30);cout<<"SUB-TOTAL";locate(83,30);cout<<"$ "<<deducciones;
    separadorH(POSMENUX,POSMENUY+27,ANCHO_MENU,LETRA_COLOR,FONDO_COLOR);
    /////////////////////// TERCERA PARTE //////////////////////////////////
    locate(56,32);cout<<"IMPORTE A COBRAR";locate(83,32);cout<<"$ "<<sueldoNETO;


    separadorV(POSMENUX+27,POSMENUY+8,ALTO_MENU-19,LETRA_COLOR,FONDO_COLOR);
    separadorV_Inicio(POSMENUX+27,POSMENUY+6,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);
    separadorV_4puntas(POSMENUX+27,POSMENUY+17,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);
    separadorV_Final(POSMENUX+27,POSMENUY+20,ALTO_MENU-22,LETRA_COLOR,FONDO_COLOR);

    separadorV(POSMENUX+43,POSMENUY+8,ALTO_MENU-19,LETRA_COLOR,FONDO_COLOR);
    separadorV_Inicio(POSMENUX+43,POSMENUY+6,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);
    separadorV_4puntas(POSMENUX+43,POSMENUY+17,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);
    separadorV_Final(POSMENUX+43,POSMENUY+20,ALTO_MENU-22,LETRA_COLOR,FONDO_COLOR);
    separadorV_4PuntasFinal(POSMENUX+43,POSMENUY+27,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);

    separadorV(POSMENUX+58,POSMENUY+8,ALTO_MENU-19,LETRA_COLOR,FONDO_COLOR);
    separadorV_Inicio(POSMENUX+58,POSMENUY+6,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);
    separadorV_4puntas(POSMENUX+58,POSMENUY+17,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);
    separadorV_Final(POSMENUX+58,POSMENUY+20,ALTO_MENU-22,LETRA_COLOR,FONDO_COLOR);

    separadorV(POSMENUX+74,POSMENUY+8,ALTO_MENU-19,LETRA_COLOR,FONDO_COLOR);
    separadorV_Inicio(POSMENUX+74,POSMENUY+6,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);
    separadorV_4puntas(POSMENUX+74,POSMENUY+17,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);
    separadorV_Final(POSMENUX+74,POSMENUY+20,ALTO_MENU-22,LETRA_COLOR,FONDO_COLOR);
    separadorV_4PuntasFinal(POSMENUX+74,POSMENUY+27,ALTO_MENU-27,LETRA_COLOR,FONDO_COLOR);

    system("pause>nul");
}

bool generarliquidacion(){
    Liquidacion reg;
    reg.cargarAutomatico();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

#endif // CLSLIQUIDACION_H_INCLUDED
