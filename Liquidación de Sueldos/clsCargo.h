#ifndef CLSCARGO_H_INCLUDED
#define CLSCARGO_H_INCLUDED
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

void Cargo::cargar(){
    system("cls");
    int auxCargo=contadorDeCargos()+1;
    if(auxCargo==0)auxCargo++;
    setCargo(auxCargo);
    cout<<"CARGO: "<<cargo<<endl;
    cout<<"NOMBRE DEL CARGO: ";
    cargarCadena(nombreCargo, 24);
    cout<<"SUELDO BASICO: $ ";
    cin>>sBasico;
    while(sBasico<0){cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. \nSUELDO BASICO: $ ";cin>>sBasico;}
    cout<<"ANTIGUEDAD: % ";
    cin>>antiguedad;
    while(antiguedad<0){cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. \nANTIGUEDAD: % ";cin>>antiguedad;}
    cout<<"ASISTENCIA: % ";
    cin>>asistencia;
    while(asistencia<0){cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. \nASISTENCIA: % ";cin>>asistencia;}
    cout<<"PUNTUALIDAD: % ";
    cin>>puntualidad;
    while(puntualidad<0){cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. \nASISTENCIA Y PUNTUALIDAD: % ";cin>>puntualidad;}
    cout<<"PLUS FERIADO: % ";
    cin>>plusFeriado;
    while(plusFeriado<0){cout<<"NO SE PERMITEN NUMEROS NEGATIVOS. \nPLUS FERIADO: % ";cin>>plusFeriado;}
    cout<<endl;
}

void Cargo::mostrar(){
    cout<<"CARGO: "<<cargo<<endl;
    cout<<"NOMBRE DEL CARGO: "<<nombreCargo<<endl;
    cout<<"SUELDO BASICO: $ "<<sBasico<<endl;
    cout<<"ANTIGUEDAD: % "<<antiguedad<<endl;
    cout<<"ASISTENCIA: % "<<asistencia<<endl;
    cout<<"PUNTUALIDAD: % "<<puntualidad<<endl;
    cout<<"PLUS FERIADO: % "<<plusFeriado<<endl<<endl;
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
