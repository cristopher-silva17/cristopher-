#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *padre;
	Nodo *der;
	Nodo *izd;
};

Nodo *arbol=NULL;
 
//Prototipos
void menu();
Nodo *crearNodo(int n, Nodo *padre);
void insertarNodo(Nodo *&arbol,int n, Nodo *padre);
void mostrarArbol(Nodo *arbol, int cont);
bool buscarNodo(Nodo *arbol,int n);
void preOrden(Nodo*arbol);
void inOrden(Nodo *arbol);
void postOrden(Nodo *arbol);
void eliminar(Nodo *arbol, int n);
void eliminarNodo(Nodo *nodoEliminar);
Nodo *minimo(Nodo *arbol);
void reemplazar(Nodo *arbol, Nodo *nuevoNodo);
void destruirNodo(Nodo *nodo);

//programa principal
int main(){
	menu();
	getch();
	return 0;
}

//funcion para crear menu de opciones
void menu(){
	int dato,opcion,cont=0;
	bool resp;
	
	do{
		cout<<"\t ** Menu arbol ABB **"<<endl;
		cout<<"1. Insertar Elemento"<<endl;
		cout<<"2. Mostrar Arbol"<<endl;
		cout<<"3. Buscar Elemento"<<endl;
		cout<<"4. Recorrer el arbol en PreOrden"<<endl;
		cout<<"5. Recorrer el arbol en InOrden"<<endl;
		cout<<"6. Recorrer el arbol en PostOrden"<<endl;
		cout<<"7. Eliminar elemento"<<endl;
		cout<<"8. Salir"<<endl;
		cout<<"\n\t Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"\nDigite numero:";
				cin>>dato;
				insertarNodo(arbol,dato,NULL);
				cout<<"\n";
				system("pause");
			break;
			case 2:
				cout<<"\nMostrando el arbol completo\n\n";
				mostrarArbol(arbol,cont);
				cout<<"\n";
				system("pause");
			break;
			case 3:
				cout<<"\nBuscando elemento en el arbol\n\n";
				cout<<"\n Digite numero: ";
				cin>>dato;
				resp=buscarNodo(arbol,dato);
				if(resp=true)
				cout<<"\n Existe elemento...";
				else
				cout<<"\n NO existe elemento...";
				cout<<"\n\n";
				system("pause");
			break;
			case 4:
				cout<<"\nRecorrido del arbol en PreOrden;";
				preOrden(arbol);
				cout<<"\n\n";
				system("pause");
			break;
			case 5:
				cout<<"\nRecorrido del arbol en InOrden:";
				inOrden(arbol);
				cout<<"\n\n";
				system("pause");
			break;
			case 6:
				cout<<"\nRecorrido del arbol en PostOrden:";
				postOrden(arbol);
				cout<<"\n\n";
				system("pause");
			break;
			case 7:
				cout<<"\nDigite numero: ";
				cin>>dato;
				eliminar(arbol,dato);
				cout<<"\n\n";
				system("pause");
			break;		
		}
		system("cls");
	}while(opcion !=8);
}
 //Funcion para crear nodo
 Nodo *crearNodo(int n, Nodo *padre){
 	Nodo *nuevo=new Nodo();
 	
 	if(nuevo !=NULL){
 		nuevo->dato=n;
 		nuevo->der=NULL;
 		nuevo->izd=NULL;
 		nuevo->padre=padre;
	 }
	 return nuevo;
	}
	
//Funcion para insertar nodo
void insertarNodo(Nodo *&arbol, int n,Nodo *padre){
	if(!buscarNodo(arbol,n)){
		Nodo *nuevo=crearNodo(n,padre);
		if(nuevo){
			//arbol vacio
			if(arbol==NULL){
				arbol=nuevo;
			}
			//arbol no vacio, tiene un nodo o más
			else{
				int valorRaiz = arbol->dato; //obtenemos el valor de la raiz
				//aplicando recursividad
				if(n<valorRaiz)
				insertarNodo(arbol->izd,n,arbol);  //inserccion a la izquierda
				else
				insertarNodo(arbol->der,n,arbol);  //inserccion a la derecha
			}
		}
		else
		cout<<"\nNo se puede insertar, no hay espacio"<<endl;
	}else
	cout<<"\n Nodo ya existe, no se puede insertar"<<endl;
}
//Funcion para mostrar todos los nodos
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol==NULL)
	return;
	
else{
	mostrarArbol(arbol->der,cont+1);
	for(int i=0;i<cont;i++)
	cout<<" ";
	cout<<arbol->dato<<endl;
	mostrarArbol(arbol->izd,cont+1);
}	
}
//Funcion para buscar nodo en el arbol
bool buscarNodo(Nodo *arbol, int n){
	if(arbol==NULL)
	return false;
	else{
		if(arbol->dato==n)
		return true;
		else if(n < arbol->dato)
		return buscarNodo(arbol->izd,n);
		else
		return buscarNodo(arbol->der,n);	
	}
}
//Funcion para recorrido en profundidad -PreOrden
void preOrden(Nodo *arbol){
	if(arbol==NULL)
	return;
	else{
		cout<<arbol->dato<<"-";
		preOrden(arbol->izd);
		preOrden(arbol->der);
	}
}

//Funcion para recorrido en profundidad - InOrden
void inOrden(Nodo *arbol){
	if(arbol ==NULL)
	return;
	else{
		inOrden(arbol->izd);
		cout<<arbol->dato<<"-";
		inOrden(arbol->der);		
    }
}

//Funcion par recorrido en profundidad - PostOrden
void postOrden(Nodo *arbol){
	if(arbol==NULL)
	return;
	else{
		postOrden(arbol->izd);
		postOrden(arbol->der);
		cout<<arbol->dato<<"-";
	}
}

//Funciones para eliminar nodo del arbol
void eliminar(Nodo *arbol, int n){
	if(arbol==NULL)
	return;
	else if(n < arbol->dato)
	eliminar(arbol->izd,n); //si el valor es menor busca por la izquierda
	else if(n > arbol->dato)
	eliminar(arbol->der,n);//si el valor es mayor busca por la derecha
	else
	eliminarNodo(arbol); //ya encontro el nodo
}

void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izd && nodoEliminar->der){//cuando el nodo tiene 2 hijos
	Nodo *menor=minimo(nodoEliminar->der);
	nodoEliminar->dato=menor->dato;
	eliminarNodo(menor);
	}
	else if(nodoEliminar->izd){ //cuando el nodo tiene 1 hijo pero izquierdo
	reemplazar(nodoEliminar,nodoEliminar->izd);
	destruirNodo(nodoEliminar);
	cout<<"\nElemento ya ha sido eliminado"<<endl;
	}
	else if(nodoEliminar->der){ //cuando el nodo tiene 1 hijo pero derecho
		reemplazar(nodoEliminar,nodoEliminar->izd);
		destruirNodo(nodoEliminar);
		cout<<"\n Elemento ya ha sido eliminado"<<endl;
	}
	else{//cuando el nodo no tiene hijos
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
		cout<<"\n Elemento ya ha sido eliminado"<<endl;
	}
}

//Funcion para asignar nuevo padre y nuevo hijo
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->padre){
		//hay que asignarle su nuevo hijo
		if(arbol->dato==arbol->padre->izd->dato)
		arbol->padre->izd=nuevoNodo;
		else if(arbol->dato==arbol->der->dato)
		arbol->padre->der=nuevoNodo;
	}
	//para asignarle su nuevo padre
	if(nuevoNodo)
	nuevoNodo->padre=arbol->padre;
}

//Funcion para liberar espacio en memoria
void destruirNodo(Nodo *nodo){
	nodo->der=NULL;
	nodo->izd=NULL;
	delete nodo;
}

//Funcion para encontrar el sucesor
Nodo *minimo(Nodo *arbol){
	if(arbol==NULL)
	return NULL;
	if(arbol->izd)  //Si tiene hijo izquierdo
	return minimo(arbol->izd);  //Se busca el nodo más a la izquierda
	else //si no tiene hijo izquierdo
	return arbol; //se retorna al mismo nodo
}





























 


