#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        /*Fecha(int d=-1,int m=-1,int a=-1){
            dia=d;
            mes=m;
            dia=a;
        }*/
        Fecha(){
            //fecha actual
            time_t t;
            t = time(NULL);
            struct tm *f;
            f = localtime(&t);

            dia=f->tm_mday;
            mes=f->tm_mon+1;
            anio=f->tm_year+1900;
        }

        //sets
        void setDia(int x){dia = x;}
        void setMes(int x){mes = x;}
        void setAnio(int x){anio = x;}

        //gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        //cargar y mostrar
        void cargar();
        void mostrar();
};

void Fecha::cargar(){
    int aux;
    cout<<endl;
    cout << "DIA: ";
    cin >> aux;
    if(aux >= 1 && aux <=31){setDia(aux);}
    else{setDia(-1);}

    cout << "MES: ";
    cin >> aux;
    if(aux >= 1 && aux <=12){setMes(aux);}
    else{setMes(-1);}

    cout << "ANIO: ";
    cin >> aux;
    if(aux >= 1900&&aux<=2021){setAnio(aux);}
    else{setAnio(-1);}
        while(anio==-1||mes==-1||dia==-1){
            if(anio==-1||mes==-1||dia==-1)cout<<"FECHA INCORRECTA. INGRESE UNA FECHA VALIDA: ";
            cout<<endl;
            cout << "DIA: ";
            cin >> aux;
            if(aux >= 1 && aux <=31){setDia(aux);}
            else{setDia(-1);}

            cout << "MES: ";
            cin >> aux;
            if(aux >= 1 && aux <=12){setMes(aux);}
            else{setMes(-1);}

            cout << "ANIO: ";
            cin >> aux;
            if(aux >= 1900&&aux<=2021){setAnio(aux);}
            else{setAnio(-1);}
        }
}

void Fecha::mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}


int CalcularEdad(Fecha fechaNac){
    Fecha obj;
    int edad;
    edad=obj.getAnio()-fechaNac.getAnio();
    if((obj.getMes()<fechaNac.getMes()) || (obj.getMes()==fechaNac.getMes() && obj.getDia()<fechaNac.getDia())){
        edad--;
    }
    return edad;
}



#endif // CLSFECHA_H_INCLUDED
