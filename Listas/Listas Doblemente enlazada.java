//lista doblemente enlazada
public class Nodo<T>{
    protected T data;
    protected Nodo T pNext, pAnt;
    
    Nodo (T elem){
        this.data = elem;
        this.pNext = null;
        this.pAnt = null;
    }
}

public class Double_List<T>{
    private Nodo<T> pFirst, pLast; // se crea los apuntadores al primero y al ultimo
    private int iN;
    private String name; // nombre de la lista
    
    public Double_List (string s){ // cosntructor de la lista
        this.name = s;
        this.pFirst = null;
        this.pLast = null;
        this.iN = 0;
        // pFirst, pLast y iN no tienen valor ya que la lista empieza vacia
    }
    
    public int Size(){ // devuelve el tamaño de la lista
        return this.iN;
    }
    
    public boolean Is_Null(){ // este metodo nos ayudara cuando la lista este vacia
        return this.pFirst == null;
    }
    
    public Nodo<T> getFirst(){ // nos da el primer nodo de la lista
        return  this.pFirst;
    }
    
    public Nodo<T> getLast(){ // nos da el ultimo nodo de la lista
        return this.pLast;
    }
    
    public T leer(Nodo<T> pValor){
        return pValor.data;
    }
    
    public Nodo<T> Proximo(Nodo<T> pValor){ // nos da el siguiente nodo al que esta pValor
        if (pValor != null){
            return pValor.pNext;
        } else{
            return null;
        }
    }
    
    public Nodo<T> Anterior(Nodo<T> pValor){ // nos da el anterior nodo al de pValor    
        if (pValor != null){
            return pValor.pAnt;
        } else{
            return null;
        }
    }
    
    public void pre_insertar (T x, Nodo<T> pValor){ // este metodo nos ayudara a insertar ya sea en una lista vacia, antes del primero o entre dos elementos
        Nodo<T> pNew = new Nodo<>(x);
        if (Is_Null()){
            this.pFirst = pNew;
            this.pLast = pNew;
            this.iN++;
        } else{
            if (pValor == this.pFirst){
                pNew.pNext = this.pFirst;
                this.pFirst.pAnt = pNew;
                this.pFirst = pNew;
                this.iN++;
            } else{
                Nodo<T> pAnterior = pValor.pAnt;
                pNew.pNext = pValor;
                pNew.pAnt = pAnterior;
                
                pAnterior.pNext = pNew;
                pValor.pAnt = pNew;
                this.iN++;
        }
        } 
    }
    
    public void addLast (T x){ // para no añadir una un PostInsertar solo agregamos este que añade un nodo despues de pLast 
        Nodo<T> pNew= new Nodo<>(x);
        if (Is_Null()){
            this.pFirst = pNew;
            this.pLast = pNew;
            this.iN++;
        } else{
            this.pLast.pNext = pNew;
            pNew.pAnt = this.pLast;
            this.pLast = pNew;
            this.iN++;
        }
    }
    
    public String Recorrer(){ // recorre la lista completa
        Nodo<T> pAux;
        String cadena = "";
        if (this.Is_Null()){
            return "La lista esta vacia";
    } else{
        pAux = this.getFirst();
        while (pAux != null){
            cadena = cadena + this.leer(pAux) + ". ";
            pAux = pAux.pNext;
        }
    }
    return cadena;
}


public void Eliminar(Nodo<T> pValor){ // este metodo nos ayudara a elminar ya sea el primero, el ultimo o entre dos elementos
    if (Is_Null || pValor == null){
        return  
    } 
    
    if (pValor == pFirst){
        this.pFirst =this.pFirst.pNext;
        
        if (pFirst != null){
            this.pFirst.pAnt = null;
        } else{
            this.pLast = null;
        }
    }   
    
    else if (pValor == pLast){
        this.pLast = this.pLast.pAnt;
        
        if (pLast != null){
            this.pLast.pNext = null;
        }
    }
    
    else{
        Nodo<T> pAnterior = pValor.pAnt;
        Nodo<T> pSiguiente = pValor.pNext;
        
        pAnterior.pNext = pSiguiente;
        pSiguiente.pAnt = pAnterior;
    }
    this.iN--;
    
    pValor.pNext = null;
    pValor.pAnt = null;
    
}
