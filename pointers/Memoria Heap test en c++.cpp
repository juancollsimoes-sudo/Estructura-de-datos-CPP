#include <iostream>

int main() 
{
    std::cout << "\nMemoria Heap: " << std::endl;
   
    // Solicitamos memoria al OS (Heap). 
    // Nota: 'memory_usage_test' es un puntero en el Stack que guarda la dirección del Heap.
    int *memory_usage_test = new int;
    *memory_usage_test = 999;
   
    std::cout << "Ubicacion del puntero (Stack): " << &memory_usage_test << std::endl;
    std::cout << "Ubicacion del dato (Heap):     " << memory_usage_test << std::endl;
    std::cout << "Valor guardado:                " << *memory_usage_test << std::endl;
   
    // Devolvemos la memoria al sistema.
    // CRITICO: El puntero NO se borra, solo se libera el destino.
    delete memory_usage_test; 

    std::cout << "\nDespues de liberar la memoria:" << std::endl;

    // El puntero sigue existiendo en el Stack (Dangling Pointer)
    std::cout << "Ubicacion del puntero (Stack): " << &memory_usage_test << std::endl;
    
    // Sigue apuntando a la dirección antigua, pero ya no tenemos permiso para estar ahí.
    std::cout << "Ubicacion del dato (Heap):     " << memory_usage_test << std::endl;
    
    // WARNING: Use-After-Free
    // Acceder a memoria liberada causa Comportamiento Indefinido (Basura o Crash).
    std::cout << "Lectura ilegal:                " << *memory_usage_test << std::endl;

    return 0;
}
