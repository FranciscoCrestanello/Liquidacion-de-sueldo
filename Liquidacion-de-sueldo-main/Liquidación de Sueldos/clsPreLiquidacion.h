#ifndef CLSPRELIQUIDACION_H_INCLUDED
#define CLSPRELIQUIDACION_H_INCLUDED


//PROTOTIPOS//
bool validacionDni(int);
bool validarPreliquidacion(Fecha,int);

class PreLiquidacion{
	private:
        Fecha periodoLiquidacion;
        int dni,feriados;
        float horasTrabajadas;
        bool presentismo,puntualidad;
	public:
        //sets
         void setDni(int x){
            while(!validacionDni(x)){
                cout<<"El DNI NO EXISTE EN EL SISTEMA"<<endl;
                cout<<"INGRESE OTRO NUMERO: ";
                cin>>x;
            }
            dni=x;}
        void setFeriados(int x){feriados=x;}
        void setHorasTrabajadas(float x){
            while( !(x>0 && x<200) ){
                cout<<"CANTIDAD DE HORAS NO VALIDAS"<<endl;
                cout<<"INGRESE LA CANTIDAD DE HORAS NUEVAMENTE: ";
                cin>>x;
            }
            horasTrabajadas=x;}
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

bool validacionDni(int _dni){
    Empleado reg;
    int pos=0;
    while(reg.leerEnDisco(pos++)==true){
        if(reg.getDni()==_dni){
            return true;
        }
    }
    return false;
}

void PreLiquidacion::cargar(){
    /*
    cout<<"-LA FECHA DEBE SER MES/ANIO ";
    locate(6,17);*/

    cout<<"PERIODO DE LIQUIDACION: "<<endl;
    periodoLiquidacion.cargar();
    cout<<"DNI: ";
    cin>>dni;
    if(!(validarPreliquidacion(periodoLiquidacion,dni))){
        cout<<"FERIADOS: ";
        cin>>feriados;
        cout<<"HORAS TRABAJADAS: ";
        cin>>horasTrabajadas;
        cout<<"PRESENTISMO: ";
        cin>>presentismo;
        cout<<"PUNTUALIDAD: ";
        cin>>puntualidad;
        cout<<endl;
    }else{
        cout<<"YA EXISTE PRELIQUIDACION PARA EL PERIODO Y MES INGRESADO"<<endl;
    }
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

//--------------VALIDACION DOBLE PRELIQUIDACION------------//

bool validarPreliquidacion(Fecha preLi,int _dni){
    PreLiquidacion obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.getDni() == _dni){
            if(obj.getFecha().getMes() == preLi.getMes()){
                if(obj.getFecha().getAnio() == preLi.getAnio()){
                        return true;
                    }
            }
        }
    }
    return false;
}


#endif // CLSPRELIQUIDACION_H_INCLUDED
