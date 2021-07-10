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

/////

void dibujarTablaEmpleados(int fila){
    /*recuadro(5,fila-3,83,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(12,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(42,fila-3,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(82,fila-3,2,LETRA_COLOR,FONDO_COLOR);*/
    locate(6,fila+2);
    cout<<"NOMBRE: ";
    locate(6,fila+3);
    cout<<"APELLIDO";
    locate(6,fila+4);
    cout<<"E-MAIL";
    locate(6,fila+5);
    cout<<"FECHA NACIMIENTO: ";
    locate(6,fila+6);
    cout<<"FECHA DE INGRESO: ";
    locate(6,fila+7);
    cout<<"DOMICILIO: ";
    locate(6,fila+8);
    cout<<"TELEFONO: ";
    locate(6,fila+9);
    cout<<"DNI: ";
    locate(6,fila+10);
    cout<<"CARGO: ";
    locate(6,fila+11);
    cout<<"SUELDO ";
    locate(6,fila+12);
    cout<<"ESTADO: ";
    locate(6,fila+13);
}

void ampliarTabla(int fila){
    recuadro(5, fila-1, 83, 2, LETRA_COLOR, FONDO_COLOR);
    separadorV(12,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(42,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorV(82,fila-1,2,LETRA_COLOR,FONDO_COLOR);
    separadorH(5,fila-1,83,LETRA_COLOR,FONDO_COLOR);
    setlocale(LC_ALL,"C");
    locate(12, fila-1);
    cout<<(char)206;
    locate(42, fila-1);
    cout<<(char)206;
    locate(82, fila-1);
    cout<<(char)206;
    setlocale(LC_ALL,"spanish");
}

#endif // RLUTILFUNCIONES_H_INCLUDED
