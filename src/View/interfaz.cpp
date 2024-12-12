#include<iostream>
#include "../Model/owner.cpp"
#include "../Model/pets.cpp"
#pragma once
using namespace std;

void mostrarMenu() {
    cout << "Seleccione una opcion: " << endl;
    cout << "1. Insertar Mascota" << endl
         << "2. Actualizar Mascota" << endl
         << "3. Borrar Mascota" << endl
         << "4. Leer Mascotas" << endl
         << "5. Insertar owner" << endl
         << "6. Actualizar owner" << endl
         << "7. Borrar owner" << endl
         << "8. Leer owners" << endl
         << "9. Realizar consultas especificas" << endl
         << "10. Salir" << endl;
}