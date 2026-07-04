#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente{
    char nombre[30], cedula[20], telefono[20];
    struct Cliente *sig;
}Cliente;

typedef struct Auto{
    char nombre[30];
    struct Auto *sig;
}Auto;

int main(){
    Cliente *inicio=NULL,*fin=NULL,*nuevo,*aux;
    Auto *pila=NULL,*carro;
    int op;

    do{
        printf("\n1. Registrar cliente");
        printf("\n2. Atender cliente");
        printf("\n3. Entregar vehiculo");
        printf("\n0. Salir\nOpcion: ");
        scanf("%d",&op);

        if(op==1){
            nuevo=malloc(sizeof(Cliente));
            printf("Nombre Cedula Telefono: ");
            scanf("%s%s%s",nuevo->nombre,nuevo->cedula,nuevo->telefono);
            nuevo->sig=NULL;

            if(inicio==NULL)
                inicio=fin=nuevo;
            else{
                fin->sig=nuevo;
                fin=nuevo;
            }
        }

        else if(op==2){
            if(inicio==NULL)
                printf("No hay clientes.\n");
            else{
                printf("Atendiendo a %s\n",inicio->nombre);

                carro=malloc(sizeof(Auto));
                int i=0;
                while((carro->nombre[i]=inicio->nombre[i])) i++;
                carro->sig=pila;
                pila=carro;

                aux=inicio;
                inicio=inicio->sig;
                if(inicio==NULL) fin=NULL;
                free(aux);
            }
        }

        else if(op==3){
            if(pila==NULL)
                printf("No hay vehiculos.\n");
            else{
                printf("Entregando auto de %s\n",pila->nombre);
                carro=pila;
                pila=pila->sig;
                free(carro);
            }
        }

    }while(op);

    return 0;
}