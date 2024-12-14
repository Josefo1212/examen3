#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "./Model/Pets.cpp"
#include "./Model/Owner.cpp"
#include "./Controller/petsController.cpp"
#include "./Controller/ownerController.cpp"
#include"./View/interfaz.cpp"
using namespace std;

pets* petsPtr = nullptr;
int petsCount = 0;

owners* ownersPtr = nullptr;
int ownersCount = 0;

int main() {
    leerPets();
    leerOwners("../bin/owners.csv");

    int opcion;
    string petID, ownerID;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarPet();
                break;
            case 2:
                cout << "Ingrese el ID de la mascota a actualizar: ";
                cin >> petID;
                actualizarPet(petID);
                break;
            case 3:
                cout << "Ingrese el ID de la mascota a borrar: ";
                cin >> petID;
                borrarPet(petID);
                break;
            case 4:
                for (int i = 0; i < petsCount; ++i) {
                    const pets &pet = petsPtr[i];
                    cout << pet.getMascotaID()
                         << ", " << pet.getNombreMascota()
                         << ", " << pet.getEspecie()
                         << ", " << pet.getRaza()
                         << ", " << pet.getEdad()
                         << ", " << pet.getOwnerID() << endl;
                }
                break;
            case 5:
                insertarOwners();
                break;
            case 6:
                cout << "Ingrese la cedula del owner a actualizar: ";
                cin >> ownerID;
                actualizarOwners(ownerID);
                break;
            case 7:
                cout << "Ingrese la cedula del owner a borrar: ";
                cin >> ownerID;
                borrarOwners(ownerID);
                break;
            case 8:
                leerOwners("../bin/owners.csv");
                for (int i = 0; i < ownersCount; ++i) {
                    const owners &owner = ownersPtr[i];
                    cout << owner.getIdOwner() << ", "
                         << owner.getNombre() << ", "
                         << owner.getApellido() << ", "
                         << owner.getDireccion() << ", "
                         << owner.getTelefono() << ", "
                         << owner.getEmail() << endl;
                }
                break;
            case 9: {
                int subOpcion;
                cout << "Seleccione la consulta que desea realizar: " << endl
                     << "1. Consultar una Mascota" << endl
                     << "2. Consultar un Owner" << endl;
                cin >> subOpcion;

                switch (subOpcion) {
                    case 1:
                        cout << "Ingrese el ID de la mascota: ";
                        cin >> petID;
                        for (int i = 0; i < petsCount; ++i) {
                            if (petsPtr[i].getMascotaID() == petID) {
                                const pets &pet = petsPtr[i];
                                cout << pet.getMascotaID() << ", "
                                     << pet.getNombreMascota() << ", "
                                     << pet.getEspecie() << ", "
                                     << pet.getRaza() << ", "
                                     << pet.getEdad() << ", "
                                     << pet.getOwnerID() << endl;
                                break;
                            }
                        }
                        break;
                    case 2:
                        cout << "Ingrese el ID del owner: ";
                        cin >> ownerID;
                        for (int i = 0; i < ownersCount; ++i) {
                            if (ownersPtr[i].getIdOwner() == ownerID) { 
                                const owners &owner = ownersPtr[i];
                                cout << owner.getIdOwner() << ", " 
                                     << owner.getNombre() << ", "
                                     << owner.getApellido() << ", "
                                     << owner.getDireccion() << ", "
                                     << owner.getTelefono() << ", "
                                     << owner.getEmail() << endl;
                                break;
                            }
                        }
                        break;
                    default:
                        cout << "Opcion no valida." << endl;
                        break;
                }
            }
            break;
            case 10:
                cout << "Saliendo...";
                return 0;
                break;
            
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 10);

    return 0;
}