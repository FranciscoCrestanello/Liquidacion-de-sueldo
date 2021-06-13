#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
////////// COMIENZO DE LOS PROTOTIPOS //////////

bool cargarEmpleado(); //CARGA 1 EMPLEADO

bool mostrarEmpleados(); //MUESTRA TODOS LOS EMPLEADOS

bool cargarPreLiquidacion(); // CARGA UNA PRELIQUIDACION

bool mostrarPreLiquidaciones(); //MUESTRA TODAS LAS PRELIQUIDACIONES.

bool cargarLiquidacion(); // CARGA UNA LIQUIDACION.

bool mostrarLiquidaciones(); //MUESTRA TODAS LAS LIQUIDACIONES.

bool cargarSueldoBruto(); // CARGA UN SUELDO BRUTO.

bool mostrarSueldosBrutos(); //MUESTRA TODOS LOS SUELDOS BRUTOS.

bool cargarDescuentos(); // CARGA LOS DESCUENTOS.

bool mostrarDescuentos(); //MUESTRA LOS DESCUENTOS.

bool cargarCargo(); // AGREGA UN CARGO.

bool mostrarCargos(); // MUESTRA TODOS LOS CARGOS.

////////// FIN DE LOS PROTOTIPOS //////////

bool cargarEmpleado(){
    Empleado reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarEmpleados(){
    Empleado reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerEnDisco(pos++)==true){
        reg.mostrar();
        leyo=true;
    }
    return leyo;
}

bool cargarPreLiquidacion(){
    PreLiquidacion reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarPreLiquidaciones(){
    PreLiquidacion reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrarPL();
        leyo=true;
    }
    return leyo;
}

bool cargarLiquidacion(){
    Liquidacion reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarLiquidaciones(){
    Liquidacion reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrarL();
        leyo=true;
    }
    return leyo;
}

bool cargarSueldoBruto(){
    SueldoBruto reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarSueldosBrutos(){
    SueldoBruto reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrar();
        leyo=true;
    }
    return leyo;
}


bool cargarDescuentos(){
    Descuentos reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarDescuentos(){
    Descuentos reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrar();
        leyo=true;
    }
    return leyo;
}

bool cargarCargo(){
    Cargo reg;
    reg.cargar();
    bool escribio=reg.grabarEnDisco();
    return escribio;
}

bool mostrarCargos(){
    Cargo reg;
    int pos=0;
    bool leyo=false;
    while(reg.leerDeDisco(pos++)==true){
        reg.mostrar();
        leyo=true;
    }
    return leyo;
}

#endif // FUNCIONES_H_INCLUDED
