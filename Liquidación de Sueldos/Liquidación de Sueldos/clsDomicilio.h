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
    cout<<"CALLE: ";
    cargarCadena(calle, 29);
    cout<<"NUMERO: ";
    cin>> numero;
    while(numero<1){
        cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. INTENTE DE NUEVO: "<<endl;
        cin>>numero;
    }
}

void Domicilio::mostrar(){
    cout<<"DOMICILIO: "<<localidad<<", "<<calle<<" "<<numero<<endl;
}


#endif // CLSDOMICILIO_H_INCLUDED
