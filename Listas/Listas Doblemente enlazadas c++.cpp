// Hecho por Juan Coll

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class Nodo {
public:
    T data;
    Nodo<T>* pNext;
    Nodo<T>* pAnt;

    Nodo(T elem) {
        this->data = elem;
        this->pNext = nullptr;
        this->pAnt = nullptr;
    }
};

template <typename T>
class Double_List {
private:
    Nodo<T>* pFirst;
    Nodo<T>* pLast; // se crea los apuntadores al primero y al ultimo
    int iN;
    string name; // nombre de la lista

public:
    Double_List(string s) { // cosntructor de la lista
        this->name = s;
        this->pFirst = nullptr;
        this->pLast = nullptr;
        this->iN = 0;
        // pFirst, pLast y iN no tienen valor ya que la lista empieza vacia
    }

    // Destructor necesario en C++ para liberar memoria
    ~Double_List() {
        while (pFirst != nullptr) {
            Eliminar(pFirst);
        }
    }

    int Size() { // devuelve el tamaño de la lista
        return this->iN;
    }

    bool Is_Null() { // este metodo nos ayudara cuando la lista este vacia
        return this->pFirst == nullptr;
    }

    Nodo<T>* getFirst() { // nos da el primer nodo de la lista
        return this->pFirst;
    }

    Nodo<T>* getLast() { // nos da el ultimo nodo de la lista
        return this->pLast;
    }

    T leer(Nodo<T>* pValor) {
        if (pValor == nullptr) return T();
        return pValor->data;
    }

    Nodo<T>* Proximo(Nodo<T>* pValor) { // nos da el siguiente nodo al que esta pValor
        if (pValor != nullptr) {
            return pValor->pNext;
        } else {
            return nullptr;
        }
    }

    Nodo<T>* Anterior(Nodo<T>* pValor) { // nos da el anterior nodo al de pValor
        if (pValor != nullptr) {
            return pValor->pAnt;
        } else {
            return nullptr;
        }
    }

    void pre_insertar(T x, Nodo<T>* pValor) { // este metodo nos ayudara a insertar ya sea en una lista vacia, antes del primero o entre dos elementos
        Nodo<T>* pNew = new Nodo<T>(x);

        if (Is_Null()) {
            this->pFirst = pNew;
            this->pLast = pNew;
            this->iN++;
        } else {
            if (pValor == this->pFirst) {
                pNew->pNext = this->pFirst;
                this->pFirst->pAnt = pNew;
                this->pFirst = pNew;
                this->iN++;
            } else {
                Nodo<T>* pAnterior = pValor->pAnt;
                pNew->pNext = pValor;
                pNew->pAnt = pAnterior;

                pAnterior->pNext = pNew;
                pValor->pAnt = pNew;
                this->iN++;
            }
        }
    }

    void addLast(T x) { // para no añadir una un PostInsertar solo agregamos este que añade un nodo despues de pLast
        Nodo<T>* pNew = new Nodo<T>(x);

        if (Is_Null()) {
            this->pFirst = pNew;
            this->pLast = pNew;
            this->iN++;
        } else {
            this->pLast->pNext = pNew;
            pNew->pAnt = this->pLast;
            this->pLast = pNew;
            this->iN++;
        }
    }

    string Recorrer() { // recorre la lista completa
        Nodo<T>* pAux;
        stringstream ss;

        if (this->Is_Null()) {
            return "La lista esta vacia";
        } else {
            pAux = this->getFirst();
            while (pAux != nullptr) {
                ss << this->leer(pAux) << ". ";
                pAux = pAux->pNext;
            }
        }
        return ss.str();
    }

    void Eliminar(Nodo<T>* pValor) { // este metodo nos ayudara a elminar ya sea el primero, el ultimo o entre dos elementos
        if (Is_Null() || pValor == nullptr) {
            return;
        }

        if (pValor == pFirst) {
            this->pFirst = this->pFirst->pNext;

            if (pFirst != nullptr) {
                this->pFirst->pAnt = nullptr;
            } else {
                this->pLast = nullptr;
            }
        }
        else if (pValor == pLast) {
            this->pLast = this->pLast->pAnt;

            if (pLast != nullptr) {
                this->pLast->pNext = nullptr;
            }
        }
        else {
            Nodo<T>* pAnterior = pValor->pAnt;
            Nodo<T>* pSiguiente = pValor->pNext;

            pAnterior->pNext = pSiguiente;
            pSiguiente->pAnt = pAnterior;
        }

        this->iN--;
        delete pValor;
    }
};
