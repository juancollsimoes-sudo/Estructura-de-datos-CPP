#include <iostream>

int main() 
{
    std::cout << "--- Arrays y Aritmetica de Punteros ---" << std::endl;

    // Bloque contiguo de memoria (4 enteros x 4 bytes = 16 bytes totales)
    int numeros[4] = {10, 20, 30, 40}; 
    
    // DEMOSTRACION: El nombre del array decae en un puntero.
    // Ambos imprimen la misma dirección física, pero semánticamente son distintos:
    // 'numeros': Puntero al primer elemento.
    // '&numeros': Puntero al bloque completo.
    std::cout << "Direccion Base (numeros):  " << numeros << std::endl;
    std::cout << "Direccion Bloque (&numeros): " << &numeros << std::endl;
    
    std::cout << "\n--- Navegacion por memoria (Offset) ---" << std::endl;

    for (int i = 0; i < 4; i++) {
        // ARITMETICA DE PUNTEROS:
        // (numeros + i) -> Calcula la dirección: Base + (i * 4 bytes).
        // *(...)        -> Desreferencia: Viaja a esa dirección y lee el valor.
        // Esto es exactamente lo que hace 'numeros[i]' internamente.
        std::cout << "Offset " << i << " -> Valor: " << *(numeros + i) << std::endl;
    }

    return 0;
}
