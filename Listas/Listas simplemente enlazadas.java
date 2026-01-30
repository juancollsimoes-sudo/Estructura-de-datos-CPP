//lista simplemente enlazada, hecho por Juan Coll

public class Nodo <T> { 
    protected T data;
    protected Nodo <T> pNext;
    
    
    Nodo (T elem){ // constructor de los nodos
        this.data = elem;
        this.pNext = null;
    }
}

public class Lista <T> { // clase lista
    private Nodo <T> pFirst;
    private int iN;
    private String name;
    
    public Lista (String s){ //constructor de la lista
        this.name = s;
        this.pFirst = null;
        this.iN = 0;
    }
    
    public int Tamaño(){
        return this.iN;
    }
    
    public boolean EsVacio(){
        return this.pFirst == null;
    }
    
    public Nodo<T> Primero(){
        return this.pFirst;
    }
    
    public T Leer(Nodo<T> pValor){
        return pValor.data;
    }
    
    
    public Nodo<T> Ultimo(){
        return null;
    }
    public Nodo<T> Proximo(Nodo<T> pValor){ // este metodo nos da el proximo valor de la lista dependiendo del caso
        if (pValor != this.Ultimo()){
            return pValor.pNext;
        } else{
            return this.Ultimo();
        }
    }
            
  public void Insertar (T x, Nodo<T> pValor){ // metodo de insertar en una lista
      Nodo<T> pNew= new Nodo<>(x);
      if (this.EsVacio()){
          this.pFirst = pNew;
          this.iN++;
      } else{
          if (pValor != this.Ultimo()){
              pNew.pNext = pValor.pNext;
              pValor.pNext = pNew;
              this.iN++;
          }
      }  
  }   
  
  public Nodo<T> Final(){
      if (this.EsVacio()){
          return null;
      } else{
          Nodo<T> pAux = this.Primero();
          while(pAux.pNext != this.Ultimo()){
              pAux = this.Proximo(pAux);
          }
          return pAux;
      }
  }
  
  public String Recorrer(){
      Nodo<T> pAux;
      String cadena = "";
      if (this.EsVacio()){
          return "La Lista esta vacia";
      } else{
          pAux=this.Primero();
          while(pAux!=this.Ultimo()){
              cadena = cadena + this.Leer(pAux) + ". ";
              pAux = this.Proximo(pAux);
          }
      }
      return cadena;
  }
  
    
}
