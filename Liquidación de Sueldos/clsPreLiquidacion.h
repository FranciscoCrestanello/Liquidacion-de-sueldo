#ifndef CLSPRELIQUIDACION_H_INCLUDED
#define CLSPRELIQUIDACION_H_INCLUDED

class PreLiquidacion{
	private:
        Fecha periodoLiquidacion;
        int dni,feriados;
        float horasTrabajadas;
        bool presentismo,puntualidad;
	public:
        //sets
        void setDni(int x){dni=x;}
        void setFeriados(int x){feriados=x;}
        void setHorasTrabajadas(float x){horasTrabajadas=x;}
        void setPresentismo(bool x){presentismo=x;}
        void setPuntualidad(bool x){puntualidad=x;}
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
};

void PreLiquidacion::cargar(){
    cout<<"PERIODO DE LIQUIDACION: "<<endl;
    periodoLiquidacion.cargar();
    cout<<"DNI: ";
    cin>>dni;
    cout<<"FERIADOS: ";
    cin>>feriados;
    cout<<"HORAS TRABAJADAS: ";
    cin>>horasTrabajadas;
    cout<<"PRESENTISMO: ";
    cin>>presentismo;
    cout<<"PUNTUALIDAD: ";
    cin>>puntualidad;
    cout<<endl;
}
void PreLiquidacion::mostrarPL(){
    cout<<"PERIODO DE LIQUIDACION: ";
    getFecha().mostrar();
    cout<<"DNI: "<<dni<<endl;
    cout<<"FERIADOS: "<<feriados<<endl;
    cout<<"HORAS TRABAJADAS: "<<horasTrabajadas<<endl;
    cout<<"PRESENTISMO: "<<presentismo<<endl;
    cout<<"PUNTUALIDAD: "<<puntualidad<<endl<<endl;
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

#endif // CLSPRELIQUIDACION_H_INCLUDED
