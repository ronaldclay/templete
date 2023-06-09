#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
private:
  T *data;
  int size;

public:
  DynamicArray() {
    data = new T[0];
    this->size = 0;
  }

  DynamicArray(T *arr, int size) {
    data = new T[size];
    this->size = size;
    for (int i = 0; i < size; i++) {
      data[i] = arr[i];
    }
  }

  DynamicArray(const DynamicArray &o) {
    this->size = o.size;
    data = new T[o.size];
    for (int i = 0; i < o.size; i++) {
      data[i] = o.data[i];
    }
  }

  ~DynamicArray() { delete[] data; }

  void pushback(T value) {
    size++;
    T *aux = new T[size];
    for (int i = 0; i < size - 1; i++) {
      aux[i] = data[i];
    }
    delete[] data;
    data = aux;
    data[size - 1] = value;
  }
  void insert(T value, int pos){
      size++;
      T *aux = new T[size];
      for( int i=0; i<size-1; i++){
        aux[i]=data[i];
      }
      delete[] data;
      data = aux;
      T auxpos;
      for (int i=size -1; i>pos;i--){
          auxpos=data[i];
          data[i]=data[i-1];
          data[i-1]=auxpos;
      }
      data[pos]=value;
  }
  void remover(int pos){
        T aux1;
        for(int i=pos; i<size-1; i++){
            aux1=data[i];
            data[i]=data[i+1];
            data[i+1]=aux1;
        }
        size--;
        T *aux=new T[size];
        for(int i=0;i<size; i++){
            aux[i]=data[i];
        }
        delete [] data;
        data=aux;
    }
    

  void print() {
    for (int i = 0; i < size; i++) {
        cout<<data[i]<<endl;
    }
  }
  
};

//class persona
class Persona {
private:
  string nombre;
  int edad;

public:
  Persona() {
    this->nombre = "";
    this->edad = 0;
  }
  Persona(string n, int e) {
    this->nombre = n;
    this->edad = e;
  }
  string getName(){return nombre;}
  int getEdad() { return edad; }
  void setEdad(int e) { edad = e; }
  void setNombre(string n) { nombre = n; }
  friend ostream& operator<<(ostream& os, const Persona& dt);
};
ostream& operator<<(ostream& os, const Persona& dt){
    os <<"Nombre: "<< dt.nombre <<"\n"<<"Edad: " << dt.edad<<"\n";
    return os;
}
//class polygon
class Polygon {
protected:
    int width, heigth;
public:
    Polygon() = default;
    Polygon(int a, int b) :width(a), heigth(b) {}
    int area(void) { return 0; }
    void printarea() {
        std::cout << this->area() << '\n';
    }
    friend ostream& operator<<(ostream& os, const Polygon& dt);
};
ostream& operator<<(ostream& os, const Polygon& dt)
{
    os << "width: " << dt.width << "\n" << "heigth: " << dt.heigth << "\n";
    return os;
}
//main
int main()
{
    cout<<"-----------------------int-----------------------"<<endl;
    DynamicArray<int> num;
    num.pushback(7);
    num.pushback(8);
    num.print();
    cout<<"----------------------------"<<endl;
    num.insert(2,0);
    num.print();
    cout<<"-----------------------------"<<endl;
    num.remover(0);
    num.print();
    
    cout<<"-----------------------string-----------------------"<<endl;
    DynamicArray<string> strin;
    strin.pushback("Ronald");
    strin.insert("Ventura",1);
    strin.print();
    cout<<"-----------------------------"<<endl;
    strin.remover(0);
    strin.print();
    
    cout<<"------------------------objeto----------------------------"<<endl;
    DynamicArray<Persona> persona;
    Persona p1("Ronald",18);
    Persona p2("Ventura",18);
    persona.pushback(p1);
    persona.insert(p2,1);
    persona.print();
    cout<<"-----------------------------"<<endl;
    persona.remover(0);
    persona.print();
    
    cout<<"------------------------Polygon----------------------------"<<endl;
    DynamicArray<Polygon> p;
    Polygon a(18, 10);
    Polygon b(2, 2);
    p.pushback(a);
    p.insert(b, 0);
    p.print();
    std::cout << "------------------------" << std::endl;
    p.remover(0);
    p.print();
    return 0;
}
