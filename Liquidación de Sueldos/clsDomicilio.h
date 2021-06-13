#ifndef CLSDOMICILIO_H_INCLUDED
#define CLSDOMICILIO_H_INCLUDED

class Domicilio{
    private:
        int numero;
        char calle[30];
        char localidad[30];
    public:
        //sets
        void setNumero(int x){numero=x;}
        void setCalle(const char *x){strcpy(calle,x);}
        void setLocalidad(const char *x){strcpy(localidad,x);}
        //gets
        int getNumero(){return numero;}
        const char *getCalle(){return calle;}
        const char *getLocalidad(){return localidad;}
        // cargar y mostrar Domicilio
        void cargar();
        void mostrar();
};

void Domicilio::cargar(){
    int aux;
    cout<<"LOCALIDAD: ";
    cin>>localidad;
    cout<<"CALLE: ";
    cin>>calle;
    cout<<"NUMERO: ";
    cin>> aux;
    if(aux>0)setNumero(aux);
    else{setNumero(-1);}
}

void Domicilio::mostrar(){
    cout<<"DOMICILIO: "<<localidad<<", "<<calle<<" "<<numero<<endl;
}


#endif // CLSDOMICILIO_H_INCLUDED
