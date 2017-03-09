#include "ArBinBus.h"

//Ejercicio 1

template <typename T>
void elimSubarbol(Abb<T>& A, const T& e)
{
    while(A.buscar(e).izqdo().vacio())
        A.eliminar(A.buscar(e).izqdo().elemento());
    while(A.buscar(e).drcho().vacio())
        A.eliminar(A.buscar(e).drcho().elemento());
    A.eliminar(A.buscar(e));
}

//Ejercicio 3

template <typename T>
Abb<T>& equilibrado(Abb<T>& A)
{
    int limite = num_elementos(A);
    T vect[limite] = nullptr;
    vectorizar(A,vect,0);
    Abb<T> B;
    equilibrado_rec(B,vect,0,limite-1);
    return B;
}

template <typename T>
int num_elementos(Abb<T>& A)
{
    if(A.vacio())
        return 0;
    else
        return num_elementos(A.izqdo()) + num_elementos(A.drcho())+1;

}

template <typename T>
void vectorizar(Abb<T>& A,T* vect, int& i)
{
    if(!A.vacio())
    {
        vectorizar(A.izqdo(),vect,i);
        vect[i] = A.elemento();
        i++;
        vectorizar(A.drcho(),vect,i);
    }
}

template <typename T>
void equilibrado_rec(Abb<T>& B, T* vect,int ini, int fin)
{
    B.insertar(vect[(fin-ini/2)+ini]);
    if(ini < fin)
    {
        equilibrado_rec(B,vect,ini,((fin-ini)/2+ini)-1);
        equilibrado_rec(B,vect,((fin-ini)/2+ini)+1,fin);

    }


}

//Ejercicio 4

template <typename T>
void join(Abb<T>& A, Abb<T>& B)
{
    int n = num_elementos(A) + num_elementos(B);
    T vect[n] = nullptr;

    int i = 0;
    vectorizar(A, vect, i);
    vectorizar(B, vect, i);
    quitar_rep(vect,n);
    ordenar(vect,n);

    Abb<T> C;
    equilibrado_rec(C,vect, 0, n-1);

    return C;
}

template <typename T> void rellenarvector(Abb<T>& A, Abb<T>& B, T* vect)
{
    A.buscar()
}


template <typename T>
void quitar_rep(T* vect, int& n)
{
    for(int i=0; i< n; i++)
    {
        if(vect[i] == vect[i+1])
        {
            for(int j = i+1; j<n-1;j++)
                vect[j]==vect[j+1];
                n--;

        }
    }

}

template <typename T>
void ordenar(T& vect,const int n)
{
    for(int i=0;i<= n;i++)
    {
        for(int j=0;j <= n-1;j++)
        {
        T* aux = vect[j];
        vect[j] = vect[j+1];
        vect[j+1] = aux;
        }
    }
}


//Ejercicio 5

template <typename T>
Abb<T> intersec(Abb<T>& A, Abb<T>& B)
{
    int n = max(num_elementos(A), num_elementos(B));
    T vect[n] = nullptr;

    elem_coincidentes(A, B, vect, 0);

    Abb<T> C;
    insertar_vector(vect, C, 0, n-1);

    return C;
}

template <typename T>
void elem_coincidentes(const Abb<T>& A, const Abb<T>& B, T* vect, const int i)
{
    if(!A.vacio() || !B.vacio())   // Si A o B están vacíos, la intersección será vacía.
        if(!B.izqdo().vacio())
        {
            elem_coincidentes(A, B.izqdo(), vect, i);   // Descendemos por la izquierda de B hasta un subarbol hoja.

            if(pertenece(B.elemento(),A))   // Si el elemento de ese subarbol se encuentra en A:
            {
                vect[i] = B.elemento;                           // La posición correspondiente del vector se rellena,
                elem_coincidentes(A, B.drcho(), vect, i+1);     // y se llama a la función con el otro hijo y una posición del vector desplazada.
            }
            else
                elem_coincidentes(A, B.drcho(), vect, i);   // Si el elemento no se encuentra en A sólo se realiza la llamada al otro hijo.
        }
}

// Ejercicio 6

template <typename T>
Abb<T> diferencia(Abb<T>& A, Abb<T>& B)
{
    int n = num_elementos(A) + num_elementos(B);
    T vect[n] = nullptr;

    diferencia_elem(A, B, vect, 0);

    Abb<T> C;
    insertar_vector(vect, C, 0, n-1);

    return C;
}

template <typename T>
void diferencia_elem(const Abb<T>& A, const Abb<T>& B, T* vect, const int i)
{
    if(A.vacio())
        vectorizar(B, vect, 0); // Si A está vacío, la unión será B.
    else
        if(B.vacio())
            vectorizar(A, vect, 0); // Si B está vacío, la unión será A.
        else
            if(!B.izqdo().vacio())
            {
                elem_exclusivos(A, B.izqdo(), vect, i);   // Descendemos por la izquierda de B hasta un subarbol hoja.

                if(pertenece(B.elemento(),A))  // Si el elemento de ese subarbol se encuentra en A:
                {
                    elem_exclusivos(A, B.drcho(), vect, i);     // sólo se realiza la llamada al otro hijo.
                }
                else
                    vect[i] = B.elemento;                       // Si el elemento no se encuentra en A, la posición correspondiente del vector se rellena,
                    elem_exclusivos(A, B.drcho(), vect, i + 1);   // y se llama a la función con el otro hijo y una posición del vector desplazada.
            }
}


template <typename T>
bool pertenece(T& e, Abb<T>& A)
{
    return (A.buscar(e).vacio()) ? false : true;
}





