#ifndef CLSPRELIQUIDACION_H_INCLUDED
#define CLSPRELIQUIDACION_H_INCLUDED

#include "rlutilFunciones.h"

//PROTOTIPOS//
bool validacionDni(int);
bool validarPreliquidacion(Fecha,int);
int validarTexto(const char *);
const char*convertirTexto(bool);
int contarRegistrosPreliquidacion();
bool validarFecha(Fecha);



class PreLiquidacion{
	private:
        Fecha periodoLiquidacion;
        int dni,feriados;
        float horasTrabajadas;
        bool presentismo,puntualidad;
	public:
        //sets
         void setDni(int x){
            while(!validacionDni(x)){
                cout<<"El DNI NO EXISTE EN EL SISTEMA"<<endl;
                cout<<"INGRESE OTRO NUMERO: ";
                cin>>x;
            }
            dni=x;
        }
        void setFeriados(int x){
            while(x<0){
                cout<<"EL NUMERO DEBE SER MAYOR O IGUAL A 0: "<<endl;
                cout<<"INGRESE OTRO NUMERO: ";
                cin>>x;
            }
            feriados=x;
        }
        void setHorasTrabajadas(float x){
            while( !(x>0 && x<201) ){
                locate(35,13);cout<<"CANTIDAD DE HORAS NO VALIDAS"<<endl;
                locate(36,13);cout<<"INGRESE LA CANTIDAD DE HORAS NUEVAMENTE: ";
                cin>>x;
            }
            horasTrabajadas=x;}
        void setPresentismo(bool x){presentismo=x;}
        void setPuntualidad(bool x){puntualidad=x;}
        void setFecha(Fecha i){periodoLiquidacion=i;}
        //gets
        Fecha getFecha(){return periodoLiquidacion;}
        int getDni(){return dni;}
        int getFeriados(){return feriados;}
        float getHorasTrabajadas(){return horasTrabajadas;}
        bool getPresentismo(){return presentismo;}
        bool getPuntualidad(){return puntualidad;}
        //cargar y mostrar
        void cargar();
        void mostrarPL();
        //grabar y leer
        bool grabarEnDisco();
        bool leerDeDisco(int );
        // sobrecarga de operadores
        bool operator==(int auxDni){
            if(dni==auxDni)return true;
            return false;
        }
};

bool validacionDni(int _dni){
    Empleado reg;
    int pos=0;
    while(reg.leerEnDisco(pos++)==true){
        if(reg.getDni()==_dni){
            return true;
        }
    }
    return false;
}

void PreLiquidacion::cargar(){
    dibujarTablaPreliquidacion(5);
    ampliarTabla(5);
    recuadro(5,15,73,10,LETRA_COLOR,FONDO_COLOR);
    locate(6,16);
    cout<<"-LA FECHA ES EL PERIODO DE LIQUIDACION EN FORMATO DD/MM/AAAA";
    locate(6,17);cout<<"-EL PERIODO DE LIQUIDACION ES MENSUAL, SOLO PUEDE HABER UNA";
    locate(6,18);cout<<" PRELIQUIDACION POR MES/ANIO";
    locate(6,19);cout<<"-FERIADOS CORRESPONDE A LA CANTIDAD TRABAJADAS EN EL MES";
    locate(6,20);cout<<"-PRESENTISMO Y PUNTIALIDAD SE INGRESA SI/NO, SEGUN CORRESPONDA";
    char aux[3];
    int d,m,a;

    locate(7,5);cin>>d;
    periodoLiquidacion.setDia(d);
    locate(9,5);cout<<"/";
    locate(10,5);cin>>m;
    periodoLiquidacion.setMes(m);
    locate(12,5);cout<<"/";
    locate(13,5);cin>>a;
    periodoLiquidacion.setAnio(a);
    while(validarFecha(periodoLiquidacion)){
        locate(6,5);cout<<"!";
        locate(19,17);cout<<"!";
        locate(19,9);cout<<"FECHA NO VALIDA";
        locate(7,5);cout<<"          ";
        locate(7,5);cin>>d;
        periodoLiquidacion.setDia(d);
        locate(9,5);cout<<"/";
        locate(10,5);cin>>m;
        periodoLiquidacion.setMes(m);
        locate(12,5);cout<<"/";
        locate(13,5);cin>>a;
        periodoLiquidacion.setAnio(a);
    }
    locate(6,5);cout<<" ";
    locate(19,5);cout<<"    ";
    locate(19,9);cout<<"                    ";

    locate(22,5);cin>>dni;
    while(validarPreliquidacion(periodoLiquidacion,dni)){
        locate(6,5);cout<<"!";
        locate(19,5);cout<<"!";
        locate(19,9);cout<<"YA EXISTE PRELIQUIDACION PARA EL PERIODO Y DNI INGRESADO";
        locate(7,5);cout<<"          ";
        locate(19,5);cout<<"      ";
        locate(7,5);cin>>d;
        while(d<1 || d>31){
            locate(7,5);cout<<"  ";
            locate(7,5);cin>>d;
        }
        periodoLiquidacion.setDia(d);
        locate(9,5);cout<<"/";
        locate(10,5);cin>>m;
        while(m<1 || m>12){
            locate(10,5);cout<<"  ";
            locate(10,5);cin>>m;
        }
        periodoLiquidacion.setMes(m);
        locate(12,5);cout<<"/";
        locate(13,5);cin>>a;
        while(a<1900 || m>2002){
            locate(10,5);cout<<"    ";
            locate(10,5);cin>>a;
        }
        periodoLiquidacion.setAnio(a);

        locate(20,5);cout<<"     ";
        locate(22,5);cin>>dni;
        while(dni<1 || dni>99999999){
            locate(20,5);cout<<"         ";
            locate(20,5);cin>>dni;
        }

    }
    locate(6,5);cout<<" ";
    locate(19,5);cout<<"   ";
    locate(19,9);cout<<"                                                             ";

    locate(36,5);cin>>horasTrabajadas;
    while(horasTrabajadas<1 || horasTrabajadas>200){
        locate(35,5);cout<<"!";
        if(horasTrabajadas>200){
            locate(19,9);cout<<"NO PUEDE INGRSAR HORAS MAYORES A 200";
            locate(36,5);cout<<"        ";
            locate(36,5);cin>>horasTrabajadas;
        }
        locate(19,9);cout<<"NO PUEDE INGRESAR NUMEROS NEGATIVOS";
        locate(36,5);cout<<"        ";
        locate(36,5);cin>>horasTrabajadas;
    }
    locate(35,5);cout<<" ";
    locate(19,9);cout<<"                                        ";

    locate(53,5);cin>>feriados; //TODO ARREGLE PUNTUALIDAD

    //PRESENTISMO Y PUNTUALIDAD SON BOOLEANOS
    locate(64,5);cin>>aux;

    if(validarTexto(aux)==0){setPresentismo(false);}
    else{setPresentismo(true);}

    locate(80,5);cin>>aux;

    if(validarTexto(aux)==0){setPuntualidad(false);}
    else{setPuntualidad(true);}

}

void mostrarPreliRecuadro(int fila,PreLiquidacion reg){
    locate(7,fila);reg.getFecha().mostrar();
    locate(20,fila);cout<<reg.getDni();
    locate(36,fila);cout<<reg.getHorasTrabajadas();
    locate(53,fila);cout<<reg.getFeriados();
    locate(64,fila);cout<<convertirTexto(reg.getPresentismo());
    locate(80,fila);cout<<convertirTexto(reg.getPuntualidad());
}

void PreLiquidacion::mostrarPL(){
    int fila, cant;
    cant=contarRegistrosPreliquidacion();
    fila=7;
    PreLiquidacion reg;
    dibujarTablaPreliquidacion(fila);
    for(int i=0;i<cant;i++){
        reg.leerDeDisco(i);
        ampliarTabla(fila);
        mostrarPreliRecuadro(fila,reg);
        fila++;
        if(i!=cant-1){
            separadorH(5,fila,83,LETRA_COLOR,FONDO_COLOR);
            setlocale(LC_ALL,"C");
            locate(18, fila);
            cout<<(char)206;
            locate(29, fila);
            cout<<(char)206;
            locate(48, fila);
            cout<<(char)206;
            locate(59, fila);
            cout<<(char)206;
            locate(73, fila);
            cout<<(char)206;
            setlocale(LC_ALL,"spanish");
            fila++;
        }
    }

}

bool PreLiquidacion::grabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen(FILE_PRELIQUIDACION,"ab");
    if(p==NULL)return false;
    escribio=fwrite(this,sizeof(PreLiquidacion),1,p);
    fclose(p);
    return escribio;
}
bool PreLiquidacion::leerDeDisco(int pos){
    FILE *p;
    bool leyo;
    p=fopen(FILE_PRELIQUIDACION, "rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(PreLiquidacion),0);
    leyo = fread(this,sizeof(PreLiquidacion),1,p);
    fclose(p);
    return leyo;

}

//--------------VALIDACION DOBLE PRELIQUIDACION------------//

bool validarPreliquidacion(Fecha preLi,int _dni){
    PreLiquidacion obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.getDni() == _dni){
            if(obj.getFecha().getMes() == preLi.getMes()){
                if(obj.getFecha().getAnio() == preLi.getAnio()){
                        return true;
                    }
            }
        }
    }
    return false;
}

//--------------VALIDAR INGRESO EN PRESENTISMO/PUNTUALIDAD------///

int validarTexto(const char *rt){
    if(strcmp(rt,"si")==0 || strcmp(rt,"SI")==0){
            return 1;}
    else if(strcmp(rt,"no")==0 || strcmp(rt,"NO")==0){return 0;}
}

const char * convertirTexto(bool b){
    if(b==true){
        return "SI";
    }else{
        return "NO";
    }
}

int contarRegistrosPreliquidacion(){
    int cant;
    FILE *p;
    p=fopen(FILE_PRELIQUIDACION,"rb");
    if(p==NULL)return -1;
    fseek(p,0,2);
    cant=ftell(p)/sizeof(PreLiquidacion);
    fclose(p);
    return cant;
}

//-----------VALIDAR FECHA------------------------///

bool validarFecha(Fecha x){
    Fecha obj;
    if(x.getDia()<1 || x.getDia()>31){return true;}
    if(x.getMes()<1 || x.getMes()>12){return true;}
    if(x.getAnio()<1990 || x.getAnio()>obj.getAnio()){return true;}
    return false;
}



#endif // CLSPRELIQUIDACION_H_INCLUDED
