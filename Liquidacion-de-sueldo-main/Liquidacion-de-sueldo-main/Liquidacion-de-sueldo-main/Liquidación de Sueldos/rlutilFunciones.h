#ifndef RLUTILFUNCIONES_H_INCLUDED
#define RLUTILFUNCIONES_H_INCLUDED

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            locate(i, j);
            setColor(colorLinea);
            setBackgroundColor(colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
    setlocale(LC_ALL, "spanish");
}
void separadorH(short iniX, short iniY, short ancho, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)204;
    for(i=1; i<ancho; i++){
        cout<<(char)205;
    }
    cout<<(char)185;
    setlocale(LC_ALL, "spanish");
}

void separadorV(short iniX, short iniY, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)203;
    for(i=1; i<alto; i++){
        locate(iniX,iniY+i);
        cout<<(char)186;
    }
    locate(iniX,iniY+alto);
    cout<<(char)202;
    setlocale(LC_ALL, "spanish");
}

void separadorV_4puntas(short iniX, short iniY, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)206;
    for(i=1; i<alto; i++){
        locate(iniX,iniY+i);
        cout<<(char)186;
    }
    locate(iniX,iniY+alto);
    cout<<(char)206;
    setlocale(LC_ALL, "spanish");
}

void separadorV_Final(short iniX, short iniY, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)186;
    for(i=1; i<alto; i++){
        locate(iniX,iniY+i);
        cout<<(char)186;
    }
    locate(iniX,iniY+alto);
    cout<<(char)202;
    setlocale(LC_ALL, "spanish");
}
void separadorV_Inicio(short iniX, short iniY, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)203;
    for(i=1; i<alto; i++){
        locate(iniX,iniY+i);
        cout<<(char)186;
    }
    locate(iniX,iniY+alto);
    cout<<(char)206;
    setlocale(LC_ALL, "spanish");
}

void separadorV_4PuntasFinal(short iniX, short iniY, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)206;
    for(i=1; i<alto; i++){
        locate(iniX,iniY+i);
        cout<<(char)186;
    }
    locate(iniX,iniY+alto);
    cout<<(char)202;
    setlocale(LC_ALL, "spanish");
}

bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}

int mostrarCursor(int cursorX,int cursorY,int opc,int POSMENUY, int cant, int fin){
    int key;
    hidecursor();
    locate(cursorX,cursorY);
    cout<<" ->";
    key = getkey();
        while(key != KEY_ENTER){
            locate(cursorX,cursorY);
            cout<<"   ";
            switch(key){
                case KEY_DOWN:
                        if(opc < cant)opc++;
                        else{opc=0;}
                    break;
                case KEY_UP:
                        if(opc > 0)opc--;
                        else{opc=cant;}
                    break;
            }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + fin;
        }
        locate(cursorX,cursorY);
        cout<<" ->";
        key = getkey();
      }
      system("cls");
      showcursor();
      return opc;
}

/////////////

void dibujarTablaPreliquidacion(int fila){
    recuadro(5,fila-3,83,2,LETRA_COLOR,FONDO_COLOR);

    separadorV(18,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(29,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(48,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(59,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(73,fila-3,2,LETRA_COLOR,FONDO_COLOR);

    locate(9,fila-2);
    cout<<"FECHA";
    locate(22,fila-2);
    cout<<"DNI";
    locate(31,fila-2);
    cout<<"HORAS TRABAJADAS";
    locate(50,fila-2);
    cout<<"FERIADOS";
    locate(61,fila-2);
    cout<<"PRESENTISMO";
    locate(75,fila-2);
    cout<<"PUNTUALIDAD";
}

void ampliarTabla(int fila){
    recuadro(5, fila-1, 83, 2, LETRA_COLOR, FONDO_COLOR);
    separadorV(18,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(29,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(48,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(59,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(73,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorH(5,fila-1,83,LETRA_COLOR,FONDO_COLOR);
    setlocale(LC_ALL,"C");
    locate(18, fila-1);
    cout<<(char)206;
    locate(29, fila-1);
    cout<<(char)206;
    locate(48, fila-1);
    cout<<(char)206;
    locate(59, fila-1);
    cout<<(char)206;
    locate(73, fila-1);
    cout<<(char)206;
    setlocale(LC_ALL,"spanish");
}

///------TABLA CARGOS----------///

void dibujarTablaCargo(int fila){
    recuadro(5,fila-3,95,2,LETRA_COLOR,FONDO_COLOR);

    separadorV(13,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(32,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(45,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(58,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(71,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(85,fila-3,2,LETRA_COLOR,FONDO_COLOR);

    locate(7,fila-2);
    cout<<"CARGO";
    locate(15,fila-2);
    cout<<"NOMBRE DEL CARGO";
    locate(36,fila-2);
    cout<<"SUELDO ";
    locate(47,fila-2);
    cout<<"ANTIGUEDAD";
    locate(60,fila-2);
    cout<<"ASISTENCIA";
    locate(73,fila-2);
    cout<<"PUNTUALIDAD";
    locate(87,fila-2);
    cout<<"PLUS FERIADO";
}

void ampliarTablaCargo(int fila){
    recuadro(5, fila-1, 95, 2, LETRA_COLOR, FONDO_COLOR);
    separadorV(13,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(32,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(45,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(58,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(71,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(85,fila-1,2,LETRA_COLOR,FONDO_COLOR);

    separadorH(5,fila-1,95,LETRA_COLOR,FONDO_COLOR);
    setlocale(LC_ALL,"C");
    locate(13, fila-1);
    cout<<(char)206;
    locate(32, fila-1);
    cout<<(char)206;
    locate(45, fila-1);
    cout<<(char)206;
    locate(58, fila-1);
    cout<<(char)206;
    locate(71, fila-1);
    cout<<(char)206;
    locate(85, fila-1);
    cout<<(char)206;
    setlocale(LC_ALL,"spanish");
}

///--------TABLA DESCUENTOS------------///

void dibujarTablaDescuentos(int fila){
    recuadro(5,fila-3,57,2,LETRA_COLOR,FONDO_COLOR);

    separadorV(19,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(31,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(45,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(51,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    //separadorV(71,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    //separadorV(85,fila-3,2,LETRA_COLOR,FONDO_COLOR);

    locate(7,fila-2);
    cout<<"JUBILACION";
    locate(21,fila-2);
    cout<<"LEY 19032";
    locate(33,fila-2);
    cout<<"OBRA SOCIAL ";
    locate(47,fila-2);
    cout<<"SEC";
    locate(54,fila-2);
    cout<<"FAEC";

}

void ampliarTablaDescuentos(int fila){
    recuadro(5, fila-1, 57, 2, LETRA_COLOR, FONDO_COLOR);
    separadorV(19,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(31,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(45,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(51,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    //separadorV(71,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    //separadorV(85,fila-1,2,LETRA_COLOR,FONDO_COLOR);

    separadorH(5,fila-1,57,LETRA_COLOR,FONDO_COLOR);
    setlocale(LC_ALL,"C");
    locate(19, fila-1);
    cout<<(char)206;
    locate(31, fila-1);
    cout<<(char)206;
    locate(45, fila-1);
    cout<<(char)206;
    locate(51, fila-1);
    cout<<(char)206;
    /*locate(71, fila-1);
    cout<<(char)206;
    locate(85, fila-1);
    cout<<(char)206;*/
    setlocale(LC_ALL,"spanish");
}

///---- RECIBO SUELDO----///
void dibujarRecibo(int fila){
    recuadro(5,fila-3,95,2,LETRA_COLOR,FONDO_COLOR);

    separadorV(13,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(32,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(45,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(58,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(71,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(85,fila-3,2,LETRA_COLOR,FONDO_COLOR);

    /*locate(7,fila-2);
    cout<<"CARGO";
    locate(15,fila-2);
    cout<<"NOMBRE DEL CARGO";
    locate(36,fila-2);
    cout<<"SUELDO ";
    locate(47,fila-2);
    cout<<"ANTIGUEDAD";
    locate(60,fila-2);
    cout<<"ASISTENCIA";
    locate(73,fila-2);
    cout<<"PUNTUALIDAD";
    locate(87,fila-2);
    cout<<"PLUS FERIADO";*/
}
#endif // RLUTILFUNCIONES_H_INCLUDED
