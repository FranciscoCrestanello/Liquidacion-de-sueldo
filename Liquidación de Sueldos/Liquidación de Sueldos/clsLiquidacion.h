#ifndef CLSLIQUIDACION_H_INCLUDED
#define CLSLIQUIDACION_H_INCLUDED

class Liquidacion{
	private:
        Fecha periodoLiquidacion;
        int dni;
        float sueldo,antiguedad,asisyPuntualidad,feriado,jubilacion;
        float obraSocial,ley19032,SEC,FAEC;
	public:
        // sets
        void setDni(int x){dni=x;}
        void setSueldo(float x){sueldo=x;}
        void setAntiguedad(float x){antiguedad=x;}
        void setAsisyPuntualidad(float x){asisyPuntualidad=x;}
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
        float gsisyPuntualidad(){return asisyPuntualidad;}
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
        //GRABAR Y LEER EN DISCO
        bool leerDeDisco(int );
        bool grabarEnDisco();
};

void Liquidacion::cargar(){
    cout<<"PERIODO DE LIQUIDACION: "<<endl;
    periodoLiquidacion.cargar();
    cout<<"DNI: ";
    cin>>dni;
    cout<<"SUELDO: $";
    cin>>sueldo;
    cout<<"ANTIGUEDAD: ";
    cin>>antiguedad;
    cout<<"ASISTENCIA Y PUNTUALIDAD: ";
    cin>>asisyPuntualidad;
    cout<<"FERIADO: ";
    cin>>feriado;
    cout<<"JUBILACION: ";
    cin>>jubilacion;
    cout<<"OBRA SOCIAL: ";
    cin>>obraSocial;
    cout<<"LEY 19032: ";
    cin>>ley19032;
    cout<<"SEC: ";
    cin>>SEC;
    cout<<"FAEC: ";
    cin>>FAEC;
    cout<<endl;
}
void Liquidacion::mostrarL(){
    cout<<"PERIODO DE LIQUIDACION: ";
    getFecha().mostrar();
    cout<<"DNI: "<<dni<<endl;
    cout<<"SUELDO: $"<<sueldo<<endl;
    cout<<"ANTIGUEDAD: "<<antiguedad<<endl;
    cout<<"ASISTENCIA Y PUNTUALIDAD: "<<asisyPuntualidad<<endl;
    cout<<"FERIADO: "<<feriado<<endl;
    cout<<"JUBILACION: "<<jubilacion<<endl;
    cout<<"OBRA SOCIAL: "<<obraSocial<<endl;
    cout<<"LEY 19032: "<<ley19032<<endl;
    cout<<"SEC: "<<SEC<<endl;
    cout<<"FAEC: "<<FAEC<<endl<<endl;
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

#endif // CLSLIQUIDACION_H_INCLUDED
