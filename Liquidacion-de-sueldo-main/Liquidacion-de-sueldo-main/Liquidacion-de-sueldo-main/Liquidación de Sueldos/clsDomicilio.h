#ifndef CLSDOMICILIO_H_INCLUDED
#define CLSDOMICILIO_H_INCLUDED
void cargarCadena(char *pal, int tam);
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
    cout<<"LOCALIDAD: ";
    cargarCadena(localidad, 29);
    while(strlen(localidad)==0){cargarCadena(localidad, 29);}
    cout<<"CALLE: ";
    cargarCadena(calle, 29);
    while(strlen(calle)==0){cargarCadena(calle, 29);}
    cout<<"NUMERO DE CALLE: ";
    cin>> numero;
    while(numero<1){
        cout<<"DEBE SER UN NUMERO MAYOR A 0. INTENTE DE NUEVO: "<<endl;
        cin>>numero;
    }
}

void Domicilio::mostrar(){
    cout<<"DOMICILIO: "<<localidad<<", "<<calle<<" "<<numero<<endl;
}


#endif // CLSDOMICILIO_H_INCLUDED
