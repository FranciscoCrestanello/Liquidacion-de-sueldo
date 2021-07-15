#ifndef CLSCARGO_H_INCLUDED
#define CLSCARGO_H_INCLUDED

#include "rlutilFunciones.h"

int contadorDeCargos();
void cargarCadena(char *pal, int tam);
class Cargo{
    private:
        int cargo;
        float sBasico,antiguedad,asistencia,puntualidad,plusFeriado;
        char nombreCargo[25];
    public:
        // sets
        void setCargo(int x){cargo=x;}
        void setSueldoBasico(float x){sBasico=x;}
        void setAntiguedad(float x){antiguedad=x;}
        void setAsisistencia(float x){asistencia=x;}
        void setPuntualidad(float x){puntualidad=x;}
        void setPlusFeriado(float x){plusFeriado=x;}
        void setNombreCargo(const char *x){strcpy(nombreCargo,x);}
        // gets
        int getCargo(){return cargo;}
        float getSueldoBasico(){return sBasico;}
        float getAntiguedad(){return antiguedad;}
        float getAsisistencia(){return asistencia;}
        float getPuntualidad(){return puntualidad;}
        float getPlusFeriado(){return plusFeriado;}
        const char *getNombreCargo(){return nombreCargo;}
        // mostrar y cargar
        void cargar();
        void mostrar();
        // leer y grabar
        bool leerDeDisco(int );
        bool grabarEnDisco();
};

void Cargo::cargar(){ ///TODO VERIFICAR VACIO
    system("cls");
    recuadro(20,3,40,8,LETRA_COLOR,FONDO_COLOR);

    int col=25;
    int auxCargo=contadorDeCargos()+1;
    if(auxCargo==0)auxCargo++;
    setCargo(auxCargo);
    locate(col,4);cout<<"CARGO: ";
    locate(col,5);cout<<"NOMBRE DEL CARGO: ";
    locate(col,6);cout<<"SUELDO BASICO: ";
    locate(col,7);cout<<"ANTIGUEDAD: ";
    locate(col,8);cout<<"ASISTENCIA: ";
    locate(col,9);cout<<"PUNTUALIDAD: ";
    locate(col,10);cout<<"PLUS FERIADO: ";

    locate(col+20,4);cout<<cargo<<endl;
    locate(col+20,5);cargarCadena(nombreCargo, 24);
    while(strlen(nombreCargo)==0){cargarCadena(nombreCargo, 24);}

    locate(col+20,6);cin>>sBasico;
    while(sBasico<0){
            locate(col-2,6);cout<<"!";
            locate(col,14);cout<<"NO SE PERMITEN NUMEROS NEGATIVOS ";
            locate(col+20,6);cout<<"      ";
            locate(col+20,6);cin>>sBasico;}
    locate(col-2,6);cout<<"  ";
    locate(col,14);cout<<"                                      ";

    locate(col+20,7);cin>>antiguedad;
    while(antiguedad<0){
            locate(col-2,7);cout<<"!";
            locate(col,14);cout<<"NO SE PERMITEN NUMEROS NEGATIVOS";
            locate(col+20,7);cout<<"        ";
            locate(col+20,7);cin>>antiguedad;}
    locate(col-2,7);cout<<"  ";
    locate(col,14);cout<<"                                      ";

    locate(col+20,8);cin>>asistencia;
    while(asistencia<0){
            locate(col-2,8);cout<<"!";
            locate(col,14);cout<<"NO SE PERMITEN NUMEROS NEGATIVOS";
            locate(col+20,8);cout<<"        ";
            locate(col+20,8);cin>>asistencia;}
    locate(col-2,8);cout<<"  ";
    locate(col,14);cout<<"                                      ";


    locate(col+20,9);cin>>puntualidad;
    while(puntualidad<0){
            locate(col-2,9);cout<<"!";
            locate(col,14);cout<<"NO SE PERMITEN NUMEROS NEGATIVOS ";
            locate(col+20,9);cout<<"      ";
            locate(col+20,9);cin>>puntualidad;}
    locate(col-2,9);cout<<"  ";
    locate(col,14);cout<<"                                      ";


    locate(col+20,10);cin>>plusFeriado;
    while(plusFeriado<0){
            locate(col-2,10);cout<<"!";
            locate(col,14);cout<<"NO SE PERMITEN NUMEROS NEGATIVOS ";
            locate(col+20,10);cout<<"      ";
            locate(col+20,10);cin>>plusFeriado;}
    locate(col-2,10);cout<<"  ";
    locate(col,14);cout<<"                                      ";
}

void mostrarCargoRecuadro(int fila,Cargo reg){
    locate(7,fila);cout<<reg.getCargo();
    locate(15,fila);cout<<reg.getNombreCargo();
    locate(35,fila);cout<<"$"<<reg.getSueldoBasico();
    locate(51,fila);cout<<reg.getAntiguedad()<<"%";
    locate(63,fila);cout<<reg.getAsisistencia()<<"%";
    locate(77,fila);cout<<reg.getPuntualidad()<<"%";
    locate(91,fila);cout<<reg.getPlusFeriado()<<"%";
}

void Cargo::mostrar(){
    int fila, cant=4;
    fila=7;
    Cargo reg;
    dibujarTablaCargo(fila);
    for(int i=0;i<cant;i++){
        reg.leerDeDisco(i);
        ampliarTablaCargo(fila);
        mostrarCargoRecuadro(fila,reg);
        fila++;
        if(i!=cant-1){
            separadorH(5,fila,95,LETRA_COLOR,FONDO_COLOR);
            setlocale(LC_ALL,"C");
            locate(13, fila);
            cout<<(char)206;
            locate(32, fila);
            cout<<(char)206;
            locate(45, fila);
            cout<<(char)206;
            locate(58, fila);
            cout<<(char)206;
            locate(71, fila);
            cout<<(char)206;
            locate(85, fila);
            cout<<(char)206;
            setlocale(LC_ALL,"spanish");
            fila++;
        }
    }
}

bool Cargo::grabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen(FILE_TABLA_CARGO,"ab");
    if(p==NULL)return false;
    escribio=fwrite(this,sizeof(Cargo),1,p);
    fclose(p);
    return escribio;
}
bool Cargo::leerDeDisco(int pos){
    FILE *p;
    bool leyo;
    p=fopen(FILE_TABLA_CARGO, "rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Cargo),0);
    leyo = fread(this,sizeof(Cargo),1,p);
    fclose(p);
    return leyo;
}


#endif // CLSCARGO_H_INCLUDED
