public class Nodo<T>{
        protected T data;
        protected Nodo<T> pNext, pPrev;
    
    Nodo (T elem){  
            this.data = elem;
            this.pNext = null;
            this.pPrev = null;
    }
}

public class Lista_Doblemente_Circular<T>{
        private Nodo<T> pFirst, pLast;
        private int iN;
        
    
    public Lista_Doblemente_Circular(){     
            this.pFirst = null;
            this.pLast = null;
            this.iN = 0;
    }

    public Nodo<T> Insertar(T x, Nodo<T> pValor){
            Nodo<T> pNew = new Nodo<>(x);
        
        if (pValor == null){    
                this.pLast = pNew;
                this.pFirst = pNew;
                this.pFirst.pPrev = pFirst;
                this.pFirst.pNext = pFirst;
                this.iN++;
                return pNew;
        } 
        else if (pValor == this.pFirst){     
                pNew.pNext = pFirst;
                this.pFirst.pPrev = pNew;
                this.pLast.pNext = pNew;
                pNew.pPrev = this.pLast;
                this.pFirst = pNew; 
                this.iN++;
                return pNew;
        }
        else{   // insertar en una posicion "X"
                Nodo<T> pAnterior = pValor.pPrev;
                pNew.pNext = pValor;
                pNew.pPrev = pAnterior;
                pAnterior.pNext = pNew;
                pValor.pPrev = pNew;
                this.iN++;
                return pNew;
        }
    } 

    public void Invertir(){
            if (this.pFirst == null || this.pFirst.pNext == pFirst){    
                    return;
            }
        
            Nodo<T> current = this.pFirst;
            Nodo<T> temp = null;    // se crea un nodo temporal
        
        do{     // se crea un bucle de inversion.
                temp = current.pNext;
                current.pNext = current.pPrev;  // el siguiente ahora es el Anterior
                current.pPrev = temp;   // el anterior ahora es el que era siguiente
                current = temp;
        } while (current != this.pFirst);   // se detiene cuando llega al principio
        
                // se invierten la cabeza y la cola de la lista
            temp = this.pFirst;
            this.pFirst = this.pLast;
            this.pLast = temp;
    }
}
