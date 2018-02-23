#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    first(L) = NULL;
    last(L) = NULL;
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */

    delete P;
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    if (first(L) == NULL) {
        first(L) = P;
        next(first(L)) = first(L);
        prev(first(L)) = first(L);
        last(L) = first(L);
    }
    else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    if (first(L) == NULL) {
        first(L) = P;
        next(first(L)) = first(L);
        prev(first(L)) = first(L);
        last(L) = first(L);
    }
    else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    if (first(L) == NULL) {
        return NULL;
    }
    else {
        int found = 0;
        P = first(L);
        while (found == 0 || next(next(P)) == next(first(L))) {
            if (info(P).ID == x.ID) {
                found = 1;
            }
            P = next(P);
        }
        if (found = 0) {
            return NULL;
        }
    }

    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    if (first(L) == NULL) {
        return NULL;
    }
    else {
        int found = 0;
        P = first(L);
        while (found == 0 || next(next(P)) != next(first(L))) {
            if (info(P).name == x.name) {
                found = 1;
            }
            P = next(P);
        }
        if (found = 0) {
            return NULL;
        }
    }

    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    if (first(L) == NULL) {
        cout<<"List Kosong"<<endl;
    }
    else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    if (first(L) == NULL) {
        cout<<"list kosong"<<endl;
    }
    else {
        P = last(L);
        last(L) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
    prev(next(Prec)) = P;
}

void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}

