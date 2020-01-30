#include <iostream>
using namespace std;
 
struct nodo
{
    int nro;
    struct nodo *sgte;
    int ;
};
struct cola
{
    nodo *delante;
    nodo *atras  ;
};
void encolar( struct cola &c, int valor )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( c.delante == NULL)
         c.delante = aux;   // encola el primero elemento
     else
         (c.atras)->sgte = aux;
         
     c.atras = aux;        // puntero cue siempre apunta al ultimo elemento
     
}
	int desencolar( struct cola &c )
	{
     int num ;
     struct nodo *aux ;
     
     aux = c.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     c.delante = (c.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     return num;
}
void muestraCola( struct cola c )
{
     struct nodo *aux;
     
     aux = c.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}
void vaciaCola( struct cola &c)
{
     struct nodo *aux;
     
     while( c.delante != NULL)
     {
            aux = c.delante;
            c.delante = aux->sgte;
            delete(aux);
     }
     c.delante = NULL;
     c.atras   = NULL;
     
}
void longCola(struct cola &c){
	struct nodo *aux;
     
     aux = c.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro;
			aux = aux->sgte;
            
     }
     
}
void menu()
{
    cout<<"\n\t IMPLEMENTACION DE COLA\n\n";
    cout<<" 1. INGRESAR                              "<<endl;
    cout<<" 2. ELIMINAR                              "<<endl;
    cout<<" 3. MOSTRAR COLA                          "<<endl;
    cout<<" 4. VACIAR COLA                           "<<endl;
    cout<<" 5. LONGITUD DE LA COLA                   "<<endl;
    cout<<" 6. SALIR                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
 
int main()
{
    struct cola c;
   
    c.delante = NULL;
    c.atras   = NULL;
   
   
    int dato;  // numero a encolar
    int op;    // opcion del menu
    int x ;    // numero cue devuelve la funcon pop
   
    system("color 0b");
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A ENCOLAR: "; cin>> dato;
                 encolar( c, dato );
                 cout<<"\n\n\t\tNumero " << dato << " encolado...\n\n";
            break;
 
 
            case 2:
 
                 x = desencolar( c );
                 cout<<"\n\n\t\tNumero "<< x <<" desencolado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO COLA\n\n";
                 if(c.delante!=NULL) muestraCola( c );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
            break;
 
 
            case 4:
 
                 vaciaCola( c );
                 cout<<"\n\n\t\tHecho...\n\n";
            break;
            
            case 5:
            	 longCola( c );
            	 cout<<"\n\n\t\tHecho\n\n"<<endl;
            break; 
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=6);
    return 0;
}
