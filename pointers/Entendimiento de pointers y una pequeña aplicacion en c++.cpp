//Hecho por Juan Coll

#include <iostream>

int main()
{
    int c = 23446;
    //declaracion de variable a y el puntero a
   int a = 3;
   int *Pa;
   Pa = &a; // el puntero "Pa" ahora apunta a la variable "a"
   std::cout <<"direccion de a: " <<  &a << std::endl; // imprime la direccion de memoria de "a"
   std::cout <<"hacia donde apunta Pa: " <<  Pa << std::endl; // imprime hacia donde apunta el apuntador "Pa"
   std::cout <<"Direccion de memoria del puntero Pa: " << &Pa << std::endl; // imprime la direccion de memoria en donde se almacena el puntero "Pa"
   std::cout <<"Direccion de memoria de C: " << &c << std::endl; //imprime la direccion de C
   
   std::cout << "\n --Prueba--" << std::endl;
   
   long distancia = &c - &a; //calcula la distancia en la memoria de a hasta c
   
   std::cout << "\nLa distancia entre c y a en la memoria es: " << distancia << std::endl;
   
   int *Punteroxxx = Pa + distancia; //se crea un puntero nuevo
   
   std::cout << "\nHacia donde apunta Pa: " << Pa << std::endl; 
   std::cout <<"Hacia donde apunta Punteroxxx: " <<  Punteroxxx << std::endl;
   std::cout <<  "direccion de c (muehehehe): " << *Punteroxxx << std::endl;
   
   if (Punteroxxx == &c) {
       std::cout << "\nAdivinaste la direccion de C con el Punteroxxx" << std::endl;
       *Punteroxxx = 485939203;
       std::cout << "Cambiamos el valor de c a: " << c << std::endl;
       std::cout << "musica de hacker: pipipipiiiii" << std::endl;
   }
       else {
       std::cout << "\nsonidos tristes:: " << std::endl;
   }
