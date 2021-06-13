#ifndef CLSCARGO_H_INCLUDED
#define CLSCARGO_H_INCLUDED

class Cargo{
    private:
        int cargo;
        float sBasico,antiguedad,asisYPunt,plusFeriado;
    public:
        // sets
        void setCargo(int x){cargo=x;}
        void setSueldoBasico(float x){sBasico=x;}
        void setAntiguedad(float x){antiguedad=x;}
        void setAsisYPunt(float x){asisYPunt=x;}
        void setPlusFeriado(float x){plusFeriado=x;}
        // gets
        int getCargo(){return cargo;}
        float getSueldoBasico(){return sBasico;}
        float getAntiguedad(){return antiguedad;}
        float getAsisYPunt(){return asisYPunt;}
        float getPlusFeriado(){return plusFeriado;}
        // mostrar y cargar
        void cargar();
        void mostrar();
        // leer y grabar
        bool leerDeDisco(int );
        bool grabarEnDisco();
};

void Cargo::cargar(){
    cout<<"CARGO: ";
    cin>>cargo;
    cout<<"SUELDO BASICO: $";
    cin>>sBasico;
    cout<<"ANTIGUEDAD: ";
    cin>>antiguedad;
    cout<<"ASISTENCIA Y PUNTUALIDAD: ";
    cin>>asisYPunt;
    cout<<"PLUS FERIADO: ";
    cin>>plusFeriado;
    cout<<endl;
}

void Cargo::mostrar(){
    cout<<"CARGO: "<<cargo<<endl;
    cout<<"SUELDO BASICO: $"<<sBasico<<endl;
    cout<<"ANTIGUEDAD: "<<antiguedad<<endl;
    cout<<"ASISTENCIA Y PUNTUALIDAD: "<<asisYPunt<<endl;
    cout<<"PLUS FERIADO: "<<plusFeriado<<endl<<endl;
}

bool Cargo::grabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen(FILE_TABLA_REMUN,"ab");
    if(p==NULL)return false;
    escribio=fwrite(this,sizeof(Cargo),1,p);
    fclose(p);
    return escribio;
}
bool Cargo::leerDeDisco(int pos){
    FILE *p;
    bool leyo;
    p=fopen(FILE_TABLA_REMUN, "rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Cargo),0);
    leyo = fread(this,sizeof(Cargo),1,p);
    fclose(p);
    return leyo;
}


#endif // CLSCARGO_H_INCLUDED
