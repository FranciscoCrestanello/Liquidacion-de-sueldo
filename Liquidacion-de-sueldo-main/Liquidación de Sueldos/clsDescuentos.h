#ifndef CLSDESCUENTOS_H_INCLUDED
#define CLSDESCUENTOS_H_INCLUDED

class Descuentos{
	private:
        float jubilacion,ley19032,obraSocial,SEC,FAEC;
	public:
        // sets
        void setJubilacion(float x){jubilacion=x;}
        void setObraSocial(float x){obraSocial=x;}
        void setLey19032(float x){ley19032=x;}
        void setSEC(float x){SEC=x;}
        void setFAEC(float x){FAEC=x;}
        // gets
        float getJubilacion(){return jubilacion;}
        float getObraSocial(){return obraSocial;}
        float getLey19032(){return ley19032;}
        float getSEC(){return SEC;}
        float getFAEC(){return FAEC;}
        // mostrar y cargar
        void cargar();
        void mostrar();
        // grabar y leer en disco
        bool leerDeDisco(int );
        bool grabarEnDisco();
};

void Descuentos::cargar(){
    system("cls");
    cout<<"JUBILACION: % ";
    cin>>jubilacion;
    cout<<"LEY 19032: % ";
    cin>>ley19032;
    cout<<"OBRA SOCIAL: % ";
    cin>>obraSocial;
    cout<<"SEC: % ";
    cin>>SEC;
    cout<<"FAEC: % ";
    cin>>FAEC;
    cout<<endl;
}

void mostrarDescuentosRecuadro(int fila,Descuentos reg){
    locate(11,fila);cout<<reg.getJubilacion()<<"%";
    locate(24,fila);cout<<reg.getLey19032()<<"%";
    locate(37,fila);cout<<reg.getObraSocial()<<"%";
    locate(47,fila);cout<<reg.getSEC()<<"%";
    locate(54,fila);cout<<reg.getFAEC()<<"%";
}

void Descuentos::mostrar(){
    int fila, cant=1;
    fila=7;
    Descuentos reg;
    dibujarTablaDescuentos(fila);
    for(int i=0;i<cant;i++){
        reg.leerDeDisco(i);
        ampliarTablaDescuentos(fila);
        mostrarDescuentosRecuadro(fila,reg);
        fila++;
        if(i!=cant-1){
            separadorH(5,fila,57,LETRA_COLOR,FONDO_COLOR);
            setlocale(LC_ALL,"C");
            locate(18, fila);
            cout<<(char)206;
            locate(29, fila);
            cout<<(char)206;
            locate(45, fila);
            cout<<(char)206;
            locate(51, fila);
            cout<<(char)206;
            setlocale(LC_ALL,"spanish");
            fila++;
        }
    }
    /*
    cout<<"JUBILACION: "<<jubilacion<<"%"<<endl;
    cout<<"LEY 19032: "<<ley19032<<"%"<<endl;
    cout<<"OBRA SOCIAL: "<<obraSocial<<"%"<<endl;
    cout<<"SEC: "<<SEC<<"%"<<endl;
    cout<<"FAEC: "<<FAEC<<"%"<<endl<<endl;*/
}

bool Descuentos::grabarEnDisco(){
    FILE *p;
    bool escribio;
    p=fopen(FILE_TABLA_DESC,"ab");
    if(p==NULL)return false;
    escribio=fwrite(this,sizeof(Descuentos),1,p);
    fclose(p);
    return escribio;
}
bool Descuentos::leerDeDisco(int pos){
    FILE *p;
    bool leyo;
    p=fopen(FILE_TABLA_DESC, "rb");
    if(p==NULL)return false;
    fseek(p,pos*sizeof(Descuentos),0);
    leyo = fread(this,sizeof(Descuentos),1,p);
    fclose(p);
    return leyo;
}

#endif // CLSDESCUENTOS_H_INCLUDED
