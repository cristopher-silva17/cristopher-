#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izd;
};

Nodo *arbol = NULL;

//Prototipos
void menu();
Nodo *crearNodo(int n);
void insertarNodo(Nodo *&arbol,int n);
void mostrarArbol(Nodo *arbol,int cont);
bool buscarNodo(Nodo *arbol,int n);
void preOrden(Nodo *arbol);
void inOrden(Nodo *arbol);
void postOrden(Nodo *arbol);

//Programa priNcipal
int main(){
	menu();
	getch();
	return 0;
}

//Funcion para crear menu de opciones
void menu(){
	int dato=0,opcion=0,cont=0;
	bool resp;
	
	do{
		cout<<"\t\t** Menu arbol ABB**\n"<<endl;
		cout<<"\t1. Insertar elemento"<<endl;
		cout<<"\t2. Mostrar Arbol"<<endl;
		cout<<"\t3. Buscar elemento"<<endl;
		cout<<"\t4. Recorrer el arbol en PreOrden"<<endl;
		cout<<"\t5. Recorrer el arbol en InOrden"<<endl;
		cout<<"\t6. Recorrer el arbol en PostOrden"<<endl;
		cout<<"\t7. Salir"<<endl;
		cout<<"\n\t\t Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\n Digite un numero: ";
					cin>>dato;
					insertarNodo(arbol,dato);
					cout<<"\n";
					system("pause");
					break;
			
			case 2: cout<<"\n Mostrando el arbol completo\n\n";
					mostrarArbol(arbol,cont);
					cout<<"\n";
					system("pause");
					break;
			
			case 3: cout<<"\n Buscando elemento en el arbol\n\n";
					cout<<"\n Digite numero: ";
					cin>>dato;
					resp=buscarNodo(arbol,dato);
					if(resp==true)
						cout<<"\n Existe elemento..";
					else
						cout<<"\n NO existe elemento";
						cout<<"\n\n";
					system("pause");
					break;
		
			case 4: cout<<"\n Recorrido del arbol en PreOrden:";
					preOrden(arbol);			
					cout<<"\n\n";
					system("pause");
					break;
			
			case 5:	cout<<"\n Recorrido del arbol en InOrden:";
					inOrden(arbol);			
					cout<<"\n\n";
					system("pause");
					break;		
			
			case 6:	cout<<"\n Recorrido del arbol en PostOrden:";
					postOrden(arbol);			
					cout<<"\n\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion!=7);
}

//Funcion para crear nodo
Nodo *crearNodo(int n){
	Nodo *nuevo=new Nodo();
	
	if(nuevo!=NULL){
		nuevo->dato=n;
		nuevo->der=NULL;
		nuevo->izd=NULL;
	}
	
	return nuevo;
}

//Funcion para insertar nodo
void insertarNodo(Nodo *&arbol,int n){
	//arbol vacio
	if(arbol==NULL){
		Nodo *nuevo=crearNodo(n);
		arbol=nuevo;
	}
	//arbol no vacio, tiene un nodo o mas 
	else{
		Nodo *nuevo=crearNodo(n);
		int valorRaiz=arbol->dato; //obtenemos el valor de la raiz
		//aplicando recursividad
		if(n<valorRaiz)
			insertarNodo(arbol->izd,n); //insercion a la izquierda
		else
			insertarNodo(arbol->der,n); //insercion a la derecha
	}
}

//Funcion para mostrar todos los nodos
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++)
			cout<<"      ";
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izd,cont+1);
	}
}

//Funcion para buscar nodo en el arbol
bool buscarNodo(Nodo *arbol,int n){
	if(arbol==NULL)
		return false;
	else{
		if(arbol->dato==n)
			return true;
		else if(n<arbol->dato)
			return buscarNodo(arbol->izd,n);
		else
			return buscarNodo(arbol->der,n);
	}
}

//Funcion para recorrido en profundidad PreOrden
void preOrden(Nodo *arbol){
	if(arbol==NULL)
		return;
	else{
		cout<<arbol->dato<<"-";
		preOrden(arbol->izd);
		preOrden(arbol->der);
	}
}

//Funcion para recorrido en profundidad InOrden
void inOrden(Nodo *arbol){
	if(arbol==NULL)
		return;
	else{
		inOrden(arbol->izd);
		cout<<arbol->dato<<"-";
		inOrden(arbol->der);
	}
}

//Funcion para recorrido en profundidad PostOrden
void postOrden(Nodo *arbol){
	if(arbol==NULL)
		return;
	else{
		postOrden(arbol->izd);
		postOrden(arbol->der);
		cout<<arbol->dato<<"-";
	}
}
