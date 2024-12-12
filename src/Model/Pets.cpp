#include"Pets.h"
#pragma once
string pets:: getMascotaID()const{return mascotaID;};
string pets:: getNombreMascota()const{return nombreMascota;};
string pets:: getEspecie()const{return especie;};
string pets:: getRaza()const{return raza;};
int pets:: getEdad()const{return edad;};
int pets:: getOwnerID()const{return ownerID;};

void pets:: setMascotaID(const string &mascotaID){this->mascotaID = mascotaID;};
void pets:: setNombreMascota(const string &nombreMascota){this->nombreMascota = nombreMascota;};
void pets:: setEspecie(const string &especie){this->especie = especie;};
void pets:: setRaza(const string &raza){this->raza = raza;};
void pets:: setEdad(const int &edad){this->edad = edad;};
void pets:: setOwnerID(const int &ownerID){this->ownerID = ownerID;};