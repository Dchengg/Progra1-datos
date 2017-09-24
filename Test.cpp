#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <map>


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
	void split(string txt);
	void validar (lista& test);
	void listavalidar(lista &lista, int pos);
	void limpiar();
	bool inList(string str);

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
void lista::split(string txt){
	string split;
	std::ifstream file(txt);
	std::string str;
	while (std::getline(file, str)) {
		char seps[] = ";";
		char *token;
		string agencia;
		token = strtok(&str[0],seps );
		agencia = agencia + token + ":";
		token = strtok( NULL, seps );
		while( token != NULL )
		{
			agencia = agencia + token;
			token = strtok( NULL, seps );
		}
		InsertarFinal(agencia);
	}
	Mostrar();
}
void lista::listavalidar(lista &lista, int pos)
{
	pnodo_simple aux = lista.primero;
	pnodo_simple aux2 = lista.primero;
	do
	{
		string str = aux2->valor;
		string segmento;
		stringstream stream(str);
		int cont = 0;
		while (getline(stream, segmento, ';'))
		{
			if (cont == pos){
				InsertarFinal(segmento);
			}
			cont++;
		}
		aux2 = aux2->siguiente;
	} while (aux2 != aux);
}
bool lista::inList(string str){
	pnodo_simple aux = primero;
	do{
		if (aux->valor == str){
			return true;
		}
		aux = aux->siguiente;
	}while(aux != primero);
	return false;
}

void lista::validar (lista& test){
	int cont=1;
	bool flag = false;
	string v,v2;
	pnodo_simple aux = test.primero;
	do{
		v = aux->valor;
		aux = aux->siguiente;
		pnodo_simple aux2 = test.primero;
		flag = false;
		cont = 1;
		do{
			v2 = aux2->valor;
			aux2 = aux2->siguiente;
			if (v == v2  &&flag == true){
				borrarPosicion(cont);
				test.borrarPosicion(cont);
			}
			else if( v == v2){
				flag = true;
			}
			cont++;

		}while(aux2 != test.primero);
	}while(aux != test.primero);
}

void lista::limpiar(){
	while (!ListaVacia())
	{
		BorrarInicio();
	}
}
class nodo_doble {
   public:
    nodo_doble(string v)
    {
       valor = v;
       siguiente = NULL;
       anterior = NULL;
			 referencia = NULL;
    }

nodo_doble(string v, nodo_doble * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    string valor;
    nodo_doble *siguiente;
    nodo_doble *anterior;
		nodo_doble *referencia;

   friend class listaD;
	 friend class listaDC;
};

typedef nodo_doble *pnodo_doble;

class listaD {
   public:
    listaD() { primero = actual = NULL; }
    ~listaD();

    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(string v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void Confirmar();
		void split(string txt);
		void validar (listaD& test);
		void listavalidar(listaD &lista, int pos);
		void limpiar();
		bool inList(string str);

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

void listaD::InsertarInicio(string v)
{
   if (ListaVacia())
     primero = new nodo_doble(v);
   else
   {
     primero=new nodo_doble (v,primero);
     primero->siguiente->anterior=primero;
   }
}

void listaD::InsertarFinal(string v)
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


void listaD::InsertarPos(string v,int pos)
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
void listaD::split(string txt){
	string split;
	std::ifstream file(txt);
	std::string str;
	while (std::getline(file, str)) {
		char seps[] = ";";
		char *token;
		string agencia;
		token = strtok(&str[0],seps );
		agencia = agencia + token + ";";
		token = strtok( NULL, seps );
		while( token != NULL )
		{
			agencia = agencia + token+";";
			token = strtok( NULL, seps );
		}
		InsertarFinal(agencia);
	}
	Mostrar();
}
void listaD::listavalidar(listaD &lista, int pos)
{
	pnodo_doble aux2 = lista.primero;
	do
	{
		string str = aux2->valor;
		string segmento;
		stringstream stream(str);
		int cont = 0;
		while (getline(stream, segmento, ';'))
		{
			if (cont == pos){
				InsertarFinal(segmento);
			}
			cont++;
		}
		aux2 = aux2->siguiente;
	} while (aux2 != NULL);
}
void listaD::validar (listaD& test){
	int cont=1;
	bool flag = false;
	string v,v2;
	pnodo_doble aux = test.primero;
	do{
		v = aux->valor;
		aux = aux->siguiente;
		pnodo_doble aux2 = test.primero;
		flag = false;
		cont = 1;
		do{
			v2 = aux2->valor;
			aux2 = aux2->siguiente;
			if (v == v2  &&flag == true){
				borrarPosicion(cont);
				test.borrarPosicion(cont);
			}
			else if( v == v2){
				flag = true;
			}
			cont++;

		}while(aux2 != NULL);
	}while(aux != NULL);
}
bool listaD::inList(string str){
	pnodo_doble aux = primero;
	do{
		if (aux->valor == str){
			return true;
		}
		aux = aux->siguiente;
	}while(aux != NULL);
	return false;
}
void listaD::limpiar(){
	while (!ListaVacia())
	{
		BorrarInicio();
	}
}




class listaDC {
   public:
    listaDC() { primero = actual = NULL; }
    ~listaDC();
		int largoLista();
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(string pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(string v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
		void split(string txt);
		void listavalidar(listaDC& lista,int pos);
		void validar(listaDC& test);
		void crearListasDC(listaDC& l,std::map< std::string, listaDC* > &Listmap);
		void limpiar();
		bool inList(string str);
		void Asignar(listaDC& l1,listaDC& l2,std::map< std::string, listaDC* > &Listmap);
		void enlazar(listaDC& l1,std::map< std::string, listaDC* > &Listmap);

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
int listaDC::largoLista(){
    int cont=0;

    pnodo_doble aux= primero;
    if(ListaVacia())
        return cont;
    else
    {
      while(aux->siguiente!=primero)
      {
        cont++;
       aux=aux->siguiente;
      }
      cont=cont+1;
      return cont;
     }
}
void listaDC::InsertarInicio(string v)
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
void listaDC::InsertarFinal(string v)
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


void listaDC::InsertarPos(string v,int pos)
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
void listaDC::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodo_doble temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodo_doble aux = primero;
        pnodo_doble temp= primero;
        while (aux->siguiente!=primero)
            aux= aux->siguiente;
        primero=primero->siguiente;
        primero->anterior = aux;
        aux->siguiente=primero;
        delete temp;
      }
    }
}
void listaDC:: borrarPosicion(int pos)
{
	cout<<"pos = "<<pos<<endl;
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoLista())||(pos<0)){
     cout << "Error en posicion" << endl;
	 }else
    {
      if(pos==1)
        BorrarInicio();
      else
      {
       int cont=2;
       pnodo_doble aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodo_doble temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       aux->siguiente->anterior = aux;
       delete temp;
     }
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
void listaDC::split(string txt){
	string split;
	std::ifstream file(txt);
	std::string str;
	while (std::getline(file, str)) {
		char seps[] = ";";
		char *token;
		string agencia;
		token = strtok(&str[0],seps );
		agencia = agencia + token + ";";
		token = strtok( NULL, seps );
		while( token != NULL )
		{
			agencia = agencia + token+";";
			token = strtok( NULL, seps );
		}
		InsertarFinal(agencia);
	}
	Mostrar();
}
void listaDC::listavalidar(listaDC &lista, int pos)
{
	pnodo_doble aux2 = lista.primero;
	do
	{
		string str = aux2->valor;
		string segmento;
		stringstream stream(str);
		int cont = 0;
		while (getline(stream, segmento, ';'))
		{
			if (cont == pos){
				InsertarFinal(segmento);
			}
			cont++;
		}
		aux2 = aux2->siguiente;
	} while (aux2 != lista.primero);
}

bool listaDC::inList(string str){
	pnodo_doble aux = primero;
	do{
		if (aux->valor == str){
			return true;
		}
		aux = aux->siguiente;
	}while(aux != primero);
	return false;
}

void listaDC::validar (listaDC& test){
	int cont=1;
	bool flag = false;
	string v,v2;
	pnodo_doble aux = test.primero;
	do{
		v = aux->valor;
		pnodo_doble aux2 = test.primero;
		flag = false;
		cont = 1;
		do{
			v2 = aux2->valor;
			aux2 = aux2->siguiente;
			if (v == v2  &&flag == true){
				borrarPosicion(cont);
				test.borrarPosicion(cont);
				cont--;
			}
			else if( v == v2){
				flag = true;
			}
			cont++;
		}while(aux2 != test.primero);
	aux = aux->siguiente;
	}while(aux != test.primero);
}

void listaDC::limpiar(){
	while (!ListaVacia())
	{
		BorrarInicio();
	}
}
 void listaDC::crearListasDC(listaDC& l,std::map< std::string, listaDC* > &Listmap){
	string name;
	pnodo_doble aux = l.primero;
	do{
		name = aux->valor;
		Listmap.insert(std::make_pair(name,new listaDC()));
		aux = aux->siguiente;
	}while(aux != l.primero);
}
void listaDC::Asignar(listaDC& l1,listaDC& l2,std::map< std::string, listaDC* > &Listmap){
	string v1;
	string v2;
	string v3;
	pnodo_doble aux1 = l1.primero;
	pnodo_doble aux2 = l2.primero;
	pnodo_doble aux3 = primero;
	l1.Mostrar();
	l2.Mostrar();
	do{
		v1 = aux1->valor;
		do{
			v2 = aux2->valor;
			v3 = aux3->valor;
			if (v1 == v2){
				if(Listmap.find(v1) == Listmap.end() ){
					cout<<"Error"<<endl;
				}
				else{
					Listmap[v1]->InsertarFinal(v3);
					cout<<v1<<" = ";
					Listmap[v1]->Mostrar();
				}
			}
			aux2 = aux2->siguiente;
			aux3 = aux3->siguiente;
			}while(aux2 != l2.primero);
			aux1 = aux1->siguiente;
	}while(aux1 != l1.primero);
}
void listaDC::enlazar(listaDC& l1,std::map< std::string, listaDC* > &Listmap){
	string v;
	string v2;
	pnodo_doble aux = primero;
	pnodo_doble aux2 = l1.primero;
	do{
		v = aux2->valor;
		if (Listmap.find(v) == Listmap.end()){
			cout<<"no hay lista"<<endl;
		}else{
			pnodo_doble aux3 =  Listmap[v]->primero;
			aux -> referencia = aux3;
		}
	}while(aux != primero);
	aux = primero;
	v2 = primero->valor;
	v = primero->referencia->valor;
	cout<<v2<<"->"<<v<<endl;

}


int main()
{
	listaDC Lista_Agencias, Lista_Aerolineas, Lista_Aviones,Lista_Funcionarios,Lista_Tripulacion,Lista_Vuelos,Lista_AsignacionVuelos,id_agencias,id_funcionarios,id_aerolinea,tempDC;
	listaD Lista_Rutas,tempD;
	lista Lista_Trips, Lista_Destinos,Lista_TripulaVuela,Lista_ClientesVuelo,temp;
	string opcion , id;
	cout<<"_____________________________________________"<<endl;

	Lista_Agencias.split("Agencias.txt");
	id_agencias.listavalidar(Lista_Agencias,0);
	Lista_Agencias.validar(id_agencias);
	Lista_Agencias.Mostrar();
	id_agencias.limpiar();


	cout<<"_____________________________________________"<<endl;

	Lista_Aerolineas.split("Aerolineas.txt");
	id_aerolinea.listavalidar(Lista_Aerolineas,0);
	Lista_Aerolineas.validar(id_aerolinea);
	Lista_Aerolineas.Mostrar();
	id_aerolinea.limpiar();
	id_agencias.listavalidar(Lista_Agencias,0);
	std::map< std::string, listaDC* >Listmap;
	tempDC.listavalidar(Lista_Aerolineas,1);
	Lista_Aerolineas.crearListasDC(id_agencias,Listmap);
	Lista_Aerolineas.Asignar(id_agencias,tempDC,Listmap);
	Lista_Agencias.enlazar(id_agencias,Listmap);
	cout<<"_____________________________________________"<<endl;

	Lista_Aviones.split("Aviones.txt");
	tempDC.listavalidar(Lista_Aviones,2);
	Lista_Aviones.validar(tempDC);
	Lista_Aviones.Mostrar();
	tempDC.limpiar();
	cout<<"_____________________________________________"<<endl;

	Lista_Rutas.split("Rutas.txt");
	tempD.listavalidar(Lista_Rutas,3);
	Lista_Rutas.validar(tempD);
	Lista_Rutas.Mostrar();
	tempD.limpiar();
	cout<<"_____________________________________________"<<endl;

	Lista_Trips.split("Trip.txt");
	cout<<"_____________________________________________"<<endl;
	cout<<"Funcionarios"<<endl;
	Lista_Funcionarios.split("Funcionarios.txt");
	id_funcionarios.listavalidar(Lista_Funcionarios,0);
	id_funcionarios.Mostrar();

	cout<<"_____________________________________________"<<endl;

	Lista_Tripulacion.split("Tripulacion.txt");

	cout<<"_____________________________________________"<<endl;

	Lista_Vuelos.split("Vuelos.txt");

	cout<<"_____________________________________________"<<endl;

	Lista_Destinos.split("Destinos.txt");
	temp.listavalidar(Lista_Destinos,0);
	Lista_Destinos.validar(temp);
	Lista_Destinos.Mostrar();
	temp.limpiar();
	cout<<"_____________________________________________"<<endl;

	Lista_TripulaVuela.split("TripulaVuela.txt");

	cout<<"_____________________________________________"<<endl;

	Lista_AsignacionVuelos.split("Asignacion de Vuelos.txt");

	cout<<"_____________________________________________"<<endl;

	Lista_ClientesVuelo.split("ClientesVuelo.txt");
	temp.listavalidar(Lista_ClientesVuelo,1);
	Lista_ClientesVuelo.validar(temp);
	Lista_ClientesVuelo.Mostrar();
	temp.limpiar();
	cout<<"_____________________________________________"<<endl;

	cout<<"Por favor digite: 1 para Funcionarios o 2 para clientes"<<endl;
	cin >> opcion;
	int i;
	string str;
	bool flag = true;
	if(opcion == "2"){
		cout<<"ahora ud es un cliente"<<endl;
	}
	else if(opcion == "1"){
		while(true){
		cout<<"Si desea salir por favor escriba: 'Salir' "<<endl;;
		cout<<"Por favor digite su id :"<<endl;
		cin >> id;
		if (id_funcionarios.inList(id)){
			cout<<"id = "<<id<<endl;
			cout<<"Bienvenido"<<endl;
			while(flag == true){
				cout<<"1.Eliminar"<<endl;
				cout<<"2.Crear la Asignacion de vuelos"<<endl;
				cout<<"3.Cambiar status de avion"<<endl;
				cout<<"4.Manejo de la Tripulacion"<<endl;
				cout<<"5.Asignar Avion a una ruta"<<endl;
				cout<<"6.Ver rutas"<<endl;
				cout<<"7.Ver disponibles"<<endl;
				cout<<"8.Ver vuelo"<<endl;
				cout<<"9.Venta de tiquetes"<<endl;
				cout<<"0.Salir"<<endl;
				cout<<endl;
				cout<<"Digite una opcion: ";
				cin>>i;
				switch(i){
					case 0:
					flag = false;
					break;
					case 1:
					while(flag == true){
						cout<<"1.Eliminar Aviones"<<endl;
						cout<<"2.Eliminar Rutas"<<endl;
						cout<<"3.Eliminar Vuelos"<<endl;
						cout<<"4.Eliminar Clientes"<<endl;
						cout<<"5.Eliminar Asignaciones de vuelo"<<endl;
						cout<<"0.Salir"<<endl;
						cout<<endl;
						cout<<"Digite una opcion: ";
						cin>>i;
						switch (i) {
							case 0:
							flag = false;
							break;
							case 1:
							Lista_Aviones.Mostrar();
							cout<<endl;
							cout<<"Por favor digite el número de placa del avion que desea eliminar"<<endl;
							cout<<"Numero de placa: ";
							cin>>str;
						}
						flag = true;
					}
					break;
				}
			}
			break;
		}else if(id == "Salir"){
			break;
		}else{
			cout<<"Codigo invalido, por favor intentelo de nuevo"<<endl;
			}
		}
	}

	cin.get();
	return 0;
}
