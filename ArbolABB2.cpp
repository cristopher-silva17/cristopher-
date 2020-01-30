//arbol ABB version 2
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo
{
	int dato;
	Nodo *der;
	Nodo *izq;
};

Nodo *arbol=NULL;

//prototipos
void menu();
Nodo *crearNodo(int n,Nodo *padre);
void insertarNodo(Nodo *&arbol,int n);
void mostrarArbol(Nodo *arbol,int cont);
bool buscarNodo(Nodo *arbol, int n);
void preOrden(Nodo *arbol);
void inOrden(Nodo *arbol);
void postOrden(Nodo *arbol);
void cantidadNodos(Nodo *arbol,int *cant);
int AlturaArbol(Nodo *arbol, int *altura);
void auxAltura(Nodo *arbol,int a,int*altura);
int EsHoja(Nodo *arbol);
void Podar(Nodo *&arbol);
int ProfundidadNodo(Nodo *arbol,int dat);

//programa principal
int main()
{
	menu();
	getch();
	return 0;
}

//funcion para crear menu de opciones
void menu()
{
	int dato=0,opcion=0,cont=0,cant=0,altura=0,altNodo=0;
	bool resp;
	do
	{
		cout<<"\t ******Menu ARBOL ABB********"<<endl;
				cout<<"\t 1.Insertar elemento:"<<endl;
				cout<<"\t 2.Mostrar Arbol"<<endl;
				cout<<"\t 3.Buscar elemento "<<endl;
				cout<<"\t 4.Recorrer el arbol en PreOrden"<<endl;
				cout<<"\t 5.Recorrer el arbol en InOrden"<<endl;
				cout<<"\t 6.Recorrer el arbol en PostOrden"<<endl;
				cout<<"\t 7.Cantidad de nodos"<<endl;
				cout<<"\t 8.Altura del arbol"<<endl;
				cout<<"\t 9.Podar el arbol"<<endl;
				cout<<"\t 10.profundidad de un nodo"<<endl;
				cout<<"\t 11. Salir"<<endl;
				cout<<"\n \t Opcion:";
				cin>>opcion;
				switch (opcion)
				{
					case 1:
					cout<<"\n Digite numero"<<endl;
					cin>>dato;
					insertarNodo(arbol,dato);
					system("pause");
					break;
					case 2:
						cout<<"\n Mostrar el arbol completo\n"<<endl;
						mostrarArbol(arbol,cont);
						system("pause");
					break;
					case 3:
						cout<<"\n Buscando elemento en el arbol"<<endl;
						cout<<"\n Digite numero:";
						cin>>dato;
						resp=buscarNodo(arbol,dato);
						if(resp==true)
						 cout<<"\n Existe elemento"<<endl;
					 else 
					  cout<<"\n No existe elemento"<<endl;
					  cout<<"\n \n";
					  system("pause");
					  break;
			  case 4:
			  	cout<<"\n Recorrrido del arbol en Preorden:"<<endl;
			  	preOrden(arbol);
			  	cout<<"\n \n";
			  	system("pause");
		  		break;
	  		case 5:
	  			cout<<"\n Recorrido del arbol en Inorden"<<endl;
	  			inOrden(arbol);
	  			cout<<"\n \n";
	  			system("pause");
	  			break;
  			case 6:
  				cout<<"\nRecorrido del arbol en Postorden \n"<<endl;
	  			postOrden(arbol);
	  			cout<<"\n \n";
	  			system("pause");
	  			break;
  			case 7:
  				cant=0;
  				cantidadNodos(arbol,&cant);
  				cout<<"\nCantidad de nodos"<<cant;
  				cout<<"\n \n";
	  			system("pause");
  				break;
 				case 8:
 					AlturaArbol(arbol,&altura);
 					cout<<"\n Altura del arbol:"<<altura;
 					cout<<"\n \n";
	  			system("pause");
	  			break;
  			case 9:
  				Podar(arbol);
  				cout<<"\n Arbol vacio"<<endl;
  				cout<<"\n \n";
	  			system("pause");
	  			break;
  			case 10:
  				cout<<"\n Digite numero:";
  				cin>>dato;
  				altNodo=ProfundidadNodo(arbol,dato);
  				if(altNodo==1)
  				cout<<"\n No existe ese nodo";
  				else 
  				cout<<"\n La altura del nodo"<<dato<<"es:"<<altNodo;
  				cout<<"\n \n";
	  			system("pause");
	  		break;	
				}
    system("cls");
  }while(opcion !=11);
  
	}
	
	//funcion para crear nodo
	Nodo *crearNodo(int n)
{
	Nodo *nuevo=new Nodo();
	if(nuevo !=NULL)
	{
		nuevo->dato=n;
		nuevo->der=NULL;
		nuevo->izq=NULL;
	}
	return nuevo;
}

//funcion para insertar nodo
void insertarNodo(Nodo *&arbol, int n)
{
	if(!buscarNodo(arbol,n))
	{
		//arbol vacio
		if(arbol==NULL)
		{
			Nodo *nuevo=crearNodo(n);
			arbol=nuevo;
		}
		//arbol no vacio, tiene un nodo o mas
		else
		{
			Nodo *nuevo=crearNodo(n);
			int valorRaiz=arbol->dato;//obtenemos el valor de la raiz
			//aplicamos recursidad
			if(n< valorRaiz)
			insertarNodo(arbol->izq,n);//insercion a la izquierda
			else 
			insertarNodo(arbol->der,n);//insercion a la derecha
		}
	}
	else
	cout<<"\n Nodo ya existe, no se puede insertar";
}

//funcion para mostrar el arbol
void mostrarArbol(Nodo *arbol,int cont)
{
	if(arbol==NULL)
	return;
	else
	{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++)
		cout<<" ";
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

//funcion para bauscar nodo en el arbol
bool buscarNodo(Nodo *arbol,int n)
{
	if(arbol==NULL)
	return false;
	else
	{
		if(arbol->dato==n)
		return true;
		else if(n<arbol->dato)
		return buscarNodo(arbol->izq,n);
		else 
		return buscarNodo(arbol->der,n);
	}
}

//funcion para recorrido en profundidad -Preorden
void preOrden(Nodo *arbol)
{
	if(arbol==NULL)
	return;
	else
	{
		cout<<arbol->dato<<"_";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

//funcion para recorrido en profundidad -in orden
void inOrden(Nodo *arbol)
{
	if(arbol==NULL)
	return;
	else
	{
		preOrden(arbol->izq);
		cout<<arbol->dato<<"_";
		preOrden(arbol->der);
	}
}

//funcion para recorrido en profundidad -postOrden
void postOrden(Nodo *arbol)
{
	if(arbol==NULL)
	return;
	else
	{
		preOrden(arbol->izq);
		preOrden(arbol->der);
		cout<<arbol->dato<<"_";
	}
}

//funcion para contar nodo del arbol
void cantidadNodos(Nodo *arbol,int *cant)
{
	if(arbol!=NULL)
	{
		(*cant)++;
		if(arbol->izq) 
		cantidadNodos(arbol->izq,cant);
		if(arbol->der)
		cantidadNodos(arbol->der,cant);
	}
}

//funcion para saber altura de arbol
int AlturaArbol(Nodo *arbol,int *altura)
{
	if(arbol !=NULL)
	{
		*altura=0;
		auxAltura(arbol,0,altura);
		return *altura;
	}
	else
	return 0;
}

void auxAltura(Nodo *arbol,int a,int *altura)
{
	//recorrido post orden
	if(arbol->izq)
	auxAltura(arbol->izq,a+1,altura);
	if(arbol->der)
	auxAltura(arbol->der,a+1,altura);
	//proceso, si es un nodo hoja, y sua altura es mayor que la actual de arbol, actualizmosla altura actual del arbol
	if(EsHoja(arbol)&&a>*altura)
	*altura=a;
}

//comprobar si um nodo es hoja
int EsHoja(Nodo *arbol)
{
	return !arbol->der&& !arbol->izq;
}

//Borrar todos los nodos del arbol
void Podar(Nodo *&arbol)
{
	//algoritmo recursivo, recorrido en postorden
	if (arbol)
	{
		Podar(arbol->izq);//podar izquierdo
		Podar(arbol->der);//derecho
		free(arbol);//eliminar nodo
		arbol=NULL;
	}
}


//calcular la altura del nodo q contiene el dato dat
int ProfundidadNodo(Nodo *arbol,int dat)
{
	int altura=0;
	Nodo *actual=arbol;
	//todavia puede parecer, ya que quedan nodos popr mirar
	while(actual!=NULL)
	{
		if(dat==actual->dato)
		return altura;
		//encontrado:devolver altura
		else
		{
			altura++;
			//incrementamos la altura,seguimos buscando
			if(dat<actual->dato)
			actual=actual->izq;
			else if(dat>actual->dato)
			actual=actual->der;
		}
	}
	return -1;
	//no esta en arbol, devolver -1
}
