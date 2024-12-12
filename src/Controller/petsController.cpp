#include"../Model/Pets.h"
#include<fstream>
#include<sstream>
#include<string>
#pragma once
using namespace std;

extern pets* petsPtr;
extern int petsCount;

void leerPets() {
    ifstream file("../bin/pets.csv");
    string line;

    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo ../bin/pets.csv" << endl;
        return;
    }
    getline(file, line);
    while (getline(file, line)) {
        pets pet;
        stringstream ss(line);
        string tempStr;
        int tempInt;

        getline(ss, tempStr, ',');
        pet.setMascotaID(tempStr);
        getline(ss, tempStr, ',');
        pet.setNombreMascota(tempStr);
        getline(ss, tempStr, ',');
        pet.setEspecie(tempStr);
        getline(ss, tempStr, ',');
        pet.setRaza(tempStr);
        ss >> tempInt;
        pet.setEdad(tempInt);
        ss.ignore();
        ss >> tempInt;
        pet.setOwnerID(tempInt);

        pets* temp = new pets[petsCount + 1];
        for (int i = 0; i < petsCount; ++i) {
            temp[i] = petsPtr[i];
        }
        temp[petsCount] = pet;
        delete[] petsPtr;
        petsPtr = temp;
        petsCount++;
    }
    file.close();
}

void guardarPets(const string &filename) {
    ofstream file(filename);
    file << "mascotaID,nombreMascota,especie,raza,edad,ownerID\n";
    for (int i = 0; i < petsCount; ++i) {
        file << petsPtr[i].getMascotaID() << ","
             << petsPtr[i].getNombreMascota() << ","
             << petsPtr[i].getEspecie() << ","
             << petsPtr[i].getRaza() << ","
             << petsPtr[i].getEdad() << ","
             << petsPtr[i].getOwnerID() << "\n";
    }
    file.close();
}

void actualizarPet(const string &id) {
    for (int i = 0; i < petsCount; ++i) {
        if (petsPtr[i].getMascotaID() == id) {
            pets original = petsPtr[i];
            pets &pet = petsPtr[i];
            cout << "Ingrese nuevos datos (nombreMascota, especie, raza, edad, ownerID): " << endl;
            string nombreMascota, especie, raza;
            int edad, ownerID;
            cin >> nombreMascota >> especie >> raza >> edad >> ownerID;
            pet.setNombreMascota(nombreMascota);
            pet.setEspecie(especie);
            pet.setRaza(raza);
            pet.setEdad(edad);
            pet.setOwnerID(ownerID);

            cout << "Confirma los cambios? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S') {
                guardarPets("../bin/pets.csv");
                cout << "Cambios confirmados y guardados." << endl;
            } else {
                petsPtr[i] = original;
                cout << "Cambios revertidos." << endl;
            }
            return;
        }
    }
    cout << "Mascota no encontrada." << endl;
}

void insertarPet() {
    pets pet;
    cout << "Ingrese datos de la mascota (mascotaID, nombreMascota, especie, raza, edad, ownerID): " << endl;
    string mascotaID, nombreMascota, especie, raza;
    int edad, ownerID;
    cin >> mascotaID >> nombreMascota >> especie >> raza >> edad >> ownerID;
    pet.setMascotaID(mascotaID);
    pet.setNombreMascota(nombreMascota);
    pet.setEspecie(especie);
    pet.setRaza(raza);
    pet.setEdad(edad);
    pet.setOwnerID(ownerID);

    cout << "Confirma la insercion de la mascota? (s/n): ";
    char confirmacion;
    cin >> confirmacion;
    if (confirmacion == 's' || confirmacion == 'S') {
        pets* temp = new pets[petsCount + 1];
        for (int i = 0; i < petsCount; ++i) {
            temp[i] = petsPtr[i];
        }
        temp[petsCount] = pet;
        delete[] petsPtr;
        petsPtr = temp;
        petsCount++;
        guardarPets("../bin/pets.csv");
        cout << "Mascota insertada." << endl;
    } else {
        cout << "Insercion cancelada." << endl;
    }
}

void borrarPet(const string &id) {
    for (int i = 0; i < petsCount; ++i) {
        if (petsPtr[i].getMascotaID() == id) {
            cout << "Esta seguro de que desea eliminar la mascota con ID " << id << "? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S') {
                pets* temp = new pets[petsCount - 1];
                for (int j = 0, k = 0; j < petsCount; ++j) {
                    if (j != i) {
                        temp[k++] = petsPtr[j];
                    }
                }
                delete[] petsPtr;
                petsPtr = temp;
                petsCount--;
                guardarPets("../bin/pets.csv");
                cout << "Mascota eliminada." << endl;
            } else {
                cout << "Eliminacion cancelada." << endl;
            }
            return;
        }
    }
    cout << "Mascota no encontrada." << endl;
}