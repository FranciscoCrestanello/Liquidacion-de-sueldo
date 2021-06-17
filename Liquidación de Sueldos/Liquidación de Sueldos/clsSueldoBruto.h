#ifndef CLSSUELDOBRUTO_H_INCLUDED
#define CLSSUELDOBRUTO_H_INCLUDED

class SueldoBruto{
	private:
        int cargo;
        float sBasico,antiguedad,presentismo,puntualidad;
	public:
        // sets
        void setCargo(int x){cargo=x;}
        void setSueldoBasico(float x){sBasico=x;}
        void setAntiguedad(float x){antiguedad=x;}
        void setPresentismo(float x){presentismo=x;}
        void setPuntualidad(float x){puntualidad=x;}
        // gets
        int getCargo(){return cargo;}
        float getSueldoBasico(){return sBasico;}
        float getAntiguedad(){return antiguedad;}
        float getPresentismo(){return presentismo;}
        float getPuntualidad(){return puntualidad;}
        // cargar y mostrar
        void cargar();
        void mostrar();
        // leer y grabar
        bool leerDeDisco(int );
        bool grabarEnDisco();
};

void SueldoBruto::cargar(){
    cout<<"CARGO: ";
    cin>>cargo;
    cout<<"SUELDO BASICO: $";
    cin>>sBasico;
    cout<<"ANTIGUEDAD: ";
    cin>>antiguedad;
    cout<<"PRESENTISMO: ";
    cin>>presentismo;
    cout<<"PUNTUALIDAD: ";
    cin>>puntualidad;
    cout<<endl;
}
void SueldoBruto::mostrar(){
    cout<<"CARGO: "<<cargo<<endl;
    cout<<"SUELDO BASICO: $"<<sBasico<<endl;
    cout<<"ANTIGUEDAD: "<<antiguedad<<endl;
    cout<<"PRESENTISMO: "<<presentismo<<endl;
    cout<<"PUNTUALIDAD: "<<puntualidad<<endl<<endl;
}
bool SueldoBruto::leerDeDisco(int pos){
    FILE *p;
    bool leyo;
    p=fopen(FILE_SUELDO_BRUTO, "rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(SueldoBruto),0);
    leyo = fread(this,sizeof(SueldoBruto),1,p);
    fclose(p);
    return leyo;
}
bool SueldoBruto::grabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen(FILE_SUELDO_BRUTO,"ab");
    if(p==NULL)return false;
    escribio=fwrite(this,sizeof(SueldoBruto),1,p);
    fclose(p);
    return escribio;
}

#endif // CLSSUELDOBRUTO_H_INCLUDED
