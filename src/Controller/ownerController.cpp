#include"../Model/Owners.h"
#include<fstream>
#include<sstream>
#include<string>
#pragma once
using namespace std;

extern owners* ownersPtr;
extern int ownersCount;

void leerOwners(const string &ownersFile) {
    ifstream archivoOwner("../bin/owners.csv");
    string line;

    if (!archivoOwner.is_open()) {
        cout << "No se pudo abrir el archivo " << ownersFile << endl;
        return;
    }
    getline(archivoOwner, line);
    while (getline(archivoOwner, line)) {
        owners owner;
        stringstream ss(line);
        string tempStr;

        getline(ss, tempStr, ',');
        owner.setIdOwner(tempStr); 
        getline(ss, tempStr, ',');
        owner.setNombre(tempStr);
        getline(ss, tempStr, ',');
        owner.setApellido(tempStr);
        getline(ss, tempStr, ',');
        owner.setDireccion(tempStr);
        getline(ss, tempStr, ',');
        owner.setTelefono(tempStr);
        getline(ss, tempStr, ',');
        owner.setEmail(tempStr);

        owners* temp = new owners[ownersCount + 1];
        for (int i = 0; i < ownersCount; ++i) {
            temp[i] = ownersPtr[i];
        }
        temp[ownersCount] = owner;
        delete[] ownersPtr;
        ownersPtr = temp;
        ownersCount++;
    }
    archivoOwner.close();
}

void guardarOwners(const string &ownersFile) {
    ofstream file("../bin/owners.csv");
    file << "IdOwner,nombre,apellido,direccion,telefono,email\n"; 
    for (int i = 0; i < ownersCount; ++i) {
        file << ownersPtr[i].getIdOwner() << ","
             << ownersPtr[i].getNombre() << ","
             << ownersPtr[i].getApellido() << ","
             << ownersPtr[i].getDireccion() << ","
             << ownersPtr[i].getTelefono() << ","
             << ownersPtr[i].getEmail() << endl;
    }
    file.close();
}

void actualizarOwners(const string &IdOwner) {
    for (int i = 0; i < ownersCount; ++i) {
        if (ownersPtr[i].getIdOwner() == IdOwner) { 
            owners original = ownersPtr[i];
            owners &owner = ownersPtr[i];
            cout << "Ingrese nuevos datos (nombre, apellido, direccion, telefono, email): " << endl;
            string nombre, apellido, direccion, telefono, email;
            cin >> nombre >> apellido >> direccion >> telefono >> email;
            getline(cin, email); 
            owner.setNombre(nombre);
            owner.setApellido(apellido);
            owner.setDireccion(direccion);
            owner.setTelefono(telefono);
            owner.setEmail(email);

            cout << "Confirma los cambios? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S') {
                guardarOwners("../bin/owners.csv");
                cout << "Cambios confirmados y guardados." << endl;
            } else {
                ownersPtr[i] = original;
                cout << "Cambios revertidos." << endl;
            }
            return;
        }
    }
    cout << "Owner no encontrado." << endl;
}

void insertarOwners() {
    owners owner;
    cout << "Ingrese datos del owner (IdOwner, nombre, apellido, direccion, telefono, email): " << endl; 
    string IdOwner, nombre, apellido, direccion, telefono, email;
    cin >> IdOwner >> nombre >> apellido >> direccion >> telefono >> email;
    getline(cin, email);
    owner.setIdOwner(IdOwner);
    owner.setNombre(nombre);
    owner.setApellido(apellido);
    owner.setDireccion(direccion);
    owner.setTelefono(telefono);
    owner.setEmail(email);

    cout << "Confirma la insercion del owner? (s/n): ";
    char confirmacion;
    cin >> confirmacion;
    if (confirmacion == 's' || confirmacion == 'S') {
        owners* temp = new owners[ownersCount + 1];
        for (int i = 0; i < ownersCount; ++i) {
            temp[i] = ownersPtr[i];
        }
        temp[ownersCount] = owner;
        delete[] ownersPtr;
        ownersPtr = temp;
        ownersCount++;
        guardarOwners("../bin/owners.csv");
        cout << "Owner insertado." << endl;
    } else {
        cout << "Insercion cancelada." << endl;
    }
}

void borrarOwners(const string &IdOwner) {
    for (int i = 0; i < ownersCount; ++i) {
        if (ownersPtr[i].getIdOwner() == IdOwner) { 
            cout << "Esta seguro de que desea eliminar el owner con IdOwner " << IdOwner << "? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S') {
                owners* temp = new owners[ownersCount - 1];
                for (int j = 0, k = 0; j < ownersCount; ++j) {
                    if (j != i) {
                        temp[k++] = ownersPtr[j];
                    }
                }
                delete[] ownersPtr;
                ownersPtr = temp;
                ownersCount--;
                guardarOwners("../bin/owners.csv");
                cout << "Owner eliminado." << endl;
            } else {
                cout << "Eliminacion cancelada." << endl;
            }
            return;
        }
    }
    cout << "Owner no encontrado." << endl;
}