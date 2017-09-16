#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

class nodo_simple {
public:
	nodo_simple(string v)
	{
		valor = v;
		siguiente = NULL;
	}

	nodo_simple(string v, nodo_simple * signodo)
	{
		valor = v;
		siguiente = signodo;
	}

private:
	string valor;
	nodo_simple *siguiente;



	friend class lista;
};

typedef nodo_simple *pnodo_simple;

class lista {
public:
	lista() { primero = actual = NULL; }
	~lista();

	void InsertarInicio(string v);
	void InsertarFinal(string v);
	void InsertarPos(string v, int pos);
	void EliminarInicio();
	void EliminarFinal();
	void EliminarPos(int pos);
	bool ListaVacia() { return primero == NULL; }
	void Imprimir();
	void Borrar(int v);
	void Mostrar();
	void Siguiente();
	void Primero();
	void Ultimo();
	void BorrarFinal();
	void BorrarInicio();
	void borrarPosicion(int pos);
	int largoLista();
	void Buscar(string num);
	void BuscarPos(string num, int pos);

private:
	pnodo_simple primero;
	pnodo_simple actual;
};

lista::~lista()
{
	pnodo_simple aux;

	while (primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
	actual = NULL;
}
int lista::largoLista() {
	int cont = 0;

	pnodo_simple aux;
	aux = primero;
	if (ListaVacia()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->siguiente;
			cont++;
		}
		return cont;
	}

}

void lista::InsertarInicio(string v)
{
	if (ListaVacia())
		primero = new nodo_simple(v);
	else
		primero = new nodo_simple(v, primero);
}

void lista::InsertarFinal(string v)
{
	if (ListaVacia())
		primero = new nodo_simple(v);
	else
	{
		pnodo_simple aux = primero;
		while (aux->siguiente != NULL)
			aux = aux->siguiente;
		aux->siguiente = new nodo_simple(v);
	}
}


void lista::InsertarPos(string v, int pos)
{
	if (ListaVacia())
		primero = new nodo_simple(v);
	else {
		if (pos <= 1) {
			pnodo_simple nuevo = new nodo_simple(v);
			nuevo->siguiente = primero;
			primero = nuevo;
		}
		else {
			pnodo_simple aux = primero;
			int i = 2;
			while ((i != pos) && (aux->siguiente != NULL)) {
				i++;
				aux = aux->siguiente;
			}
			pnodo_simple nuevo = new nodo_simple(v);
			nuevo->siguiente = aux->siguiente;
			aux->siguiente = nuevo;

		}
	}
}

void lista::BorrarFinal()
{
	if (ListaVacia()) {
		cout << "No hay elementos en la lista:" << endl;

	}
	else {
		if (primero->siguiente == NULL) {
			primero = NULL;
		}
		else {

			pnodo_simple aux = primero;
			while (aux->siguiente->siguiente != NULL) {
				aux = aux->siguiente;

			}

			pnodo_simple temp = aux->siguiente;
			aux->siguiente = NULL;


			delete temp;
		}
	}
}

void lista::BorrarInicio()
{
	if (ListaVacia()) {
		cout << "No hay elementos en la lista:" << endl;

	}
	else {
		if (primero->siguiente == NULL) {
			primero = NULL;
		}
		else {

			pnodo_simple aux = primero;
			primero = primero->siguiente;
			delete aux;
		}
	}
}



void lista::borrarPosicion(int pos) {
	if (ListaVacia()) {
		cout << "Lista vacia" << endl;
	}
	else {
		if ((pos>largoLista()) || (pos<0)) {
			cout << "Error en posicion" << endl;
		}
		else {
			if (pos == 1) {
				primero = primero->siguiente;
			}
			else {
				int cont = 2;
				pnodo_simple aux = primero;
				while (cont<pos) {
					aux = aux->siguiente;
					cont++;
				}
				aux->siguiente = aux->siguiente->siguiente;
			}
		}
	}

}


void lista::Mostrar()
{
	nodo_simple *aux;

	aux = primero;
	while (aux!=NULL) {
		cout << aux->valor << "-> ";
		aux = aux->siguiente;
	}
	cout << endl;
}


void lista::Siguiente()
{
	if (actual) actual = actual->siguiente;
}

void lista::Buscar(string num)
{
	pnodo_simple aux = primero;
	bool flag = false;
	string n1;
	while (aux->siguiente != NULL) {
		n1 = aux->valor;
		if (n1 == num) {
			cout << "El numero " << num << " esta en la lista" << endl;
			flag = true;
		}
		aux = aux->siguiente;
	}
	if (flag == false) {
		cout << "El numero " << num << " no esta en la lista" << endl;
	}
}
void lista::BuscarPos(string num, int pos) {
	pnodo_simple aux = primero;
	bool flag = false;
	string n1;
	int cont = 0;
	while (aux->siguiente != NULL)
	{

		n1 = aux->valor;
		if (cont == pos)
		{
			if (n1 == num)
			{
				cout << "El numero "<<num<<" esta en la lista" << endl;
				flag = true;
			}
		}
		aux = aux->siguiente;
		cont++;

	}
	if (flag == false) {
		cout << "El numero " << num << " no esta en la lista" << endl;
	}
}
class nodo_doble {
   public:
    nodo_doble(int v)
    {
       valor = v;
       siguiente = NULL;
       anterior = NULL;
    }

nodo_doble(int v, nodo_doble * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodo_doble *siguiente;
    nodo_doble *anterior;


   friend class listaD;
	 friend class listaDC;
};

typedef nodo_doble *pnodo_doble;

class listaD {
   public:
    listaD() { primero = actual = NULL; }
    ~listaD();

    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void Confirmar();

   private:
    pnodo_doble primero;
    pnodo_doble actual;
};

listaD::~listaD()
{
   pnodo_doble aux;

   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

int listaD::largoLista(){
    int cont=0;

    pnodo_doble aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }

}

void listaD::InsertarInicio(int v)
{
   if (ListaVacia())
     primero = new nodo_doble(v);
   else
   {
     primero=new nodo_doble (v,primero);
     primero->siguiente->anterior=primero;
   }
}

void listaD::InsertarFinal(int v)
{
   if (ListaVacia())
     primero = new nodo_doble(v);
   else
     { pnodo_doble aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo_doble(v);
        aux->siguiente->anterior=aux;
      }
}


void listaD::InsertarPos(int v,int pos)
{
   if (ListaVacia())
     primero = new nodo_doble(v);
   else{
        if(pos <=1)
          InsertarInicio(v);
        else
        {
             pnodo_doble aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo_doble nuevo= new nodo_doble(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;
        }
        }
}

void listaD::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;

   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo_doble aux = primero;
                while (aux->siguiente->siguiente != NULL)
                {
                    aux = aux->siguiente;
                }

              pnodo_doble temp = aux->siguiente;
              aux->siguiente= NULL;


                delete temp;
            }
        }
}

void listaD::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;

   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo_doble aux = primero;
                primero=primero->siguiente;
                delete aux;
            }
        }
}



void listaD:: borrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicio();
        else
        {
          if (pos == largoLista())
             BorrarFinal();
          else
          {
            int cont=2;
            pnodo_doble aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodo_doble temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}


void listaD::Mostrar()
{
   nodo_doble *aux;

   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}
class listaDC {
   public:
    listaDC() { primero = actual = NULL; }
    ~listaDC();

    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    void Confirmar();

   private:
    pnodo_doble primero;
    pnodo_doble actual;
};

listaDC::~listaDC()
{
   pnodo_doble aux;

   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}
void listaDC::InsertarInicio(int v)
{
   if (ListaVacia())
   {
     pnodo_doble nuevo= new nodo_doble(v);
     primero = nuevo;
     nuevo->siguiente=primero;
     nuevo->anterior=primero;
   }
   else
   {
    pnodo_doble nuevo= new nodo_doble(v);
    pnodo_doble aux=primero;
    while (aux->siguiente!=primero)
       aux= aux->siguiente;
    nuevo->siguiente=primero;
    primero->anterior = nuevo;
    nuevo->anterior = aux;
    aux->siguiente=nuevo;
    primero=nuevo;
   }
}
void listaDC::InsertarFinal(int v)
{
   if (ListaVacia())
   {
     pnodo_doble nuevo= new nodo_doble(v);
     primero = nuevo;
     nuevo->siguiente=primero;
     nuevo->anterior = primero;
   }
   else
   {
      pnodo_doble nuevo=new nodo_doble(v);
      pnodo_doble aux = primero;
      while (aux->siguiente!=primero)
         aux= aux->siguiente;
      nuevo->siguiente= primero;
      primero->anterior = nuevo;
      nuevo->anterior= aux;
      aux->siguiente= nuevo;


   }
}


void listaDC::InsertarPos(int v,int pos)
{
 if (ListaVacia())
 {
   pnodo_doble nuevo= new nodo_doble(v);
   primero = nuevo;
   nuevo->siguiente=primero;
   nuevo->anterior = primero;
 }
 else
 {
   if(pos <=1)
   {
     InsertarInicio(v);
   }
   else
   {
     pnodo_doble aux= primero;
     int i =2;
     while((i != pos )&&(aux->siguiente!= primero))
     {
        i++;
        aux=aux->siguiente;
     }
     pnodo_doble nuevo= new nodo_doble(v);
     nuevo->siguiente=aux->siguiente;
     nuevo->siguiente->anterior = nuevo;
     aux->siguiente=nuevo;
     nuevo->anterior = aux;
    }
  }
}
void listaDC::Mostrar()
{
   pnodo_doble aux=primero;
   while(aux->siguiente!=primero)
     {

      cout << aux->valor << "-> ";
      aux = aux->siguiente;
     }
     cout<<aux->valor<<"->";
     cout<<endl;
}

int main()
{
	while (true){
		string i;
		string p;
		cout<<"Ingrese el nombre del archivo: ";
		cin >> i;
		i = i+".txt";
		std::ifstream file(i);
		std::string str;
		while (std::getline(file, str)) {
			lista Lista1;
			char seps[] = ";";
			char *token;
			token = strtok( &str[0], seps );
			while( token != NULL )
			{
				 Lista1.InsertarFinal(token);
				 token = strtok( NULL, seps );
			}
			Lista1.Mostrar();
		}
	}
  cin.get();
  return 0;
}
