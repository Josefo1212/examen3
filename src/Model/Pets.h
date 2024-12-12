#ifndef PETS_H
#define PETS_H
#pragma once
#include<iostream>
using namespace std;

class pets{
    private:
        string mascotaID;
        string nombreMascota;
        string especie;
        string raza;
        int edad;
        int ownerID;

    public:
        string getMascotaID() const;
        string getNombreMascota() const;
        string getEspecie() const;
        string getRaza() const;
        int getEdad() const;
        int getOwnerID() const;

        void setMascotaID(const string &mascotaID);
        void setNombreMascota(const string &nombreMascota);
        void setEspecie(const string &especie);
        void setRaza(const string &raza);
        void setEdad(const int &edad);
        void setOwnerID(const int &ownerID);
};
#endif 