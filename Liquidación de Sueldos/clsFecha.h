#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
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
    if(aux >= 1900){setAnio(aux);}
    else{setAnio(-1);}
}

void Fecha::mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<< endl;
}

#endif // CLSFECHA_H_INCLUDED
