#include "player.h"
#include <ctime>

int randomInt(int  max_int) {
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L) {
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */

    address Q = first(L);
    do {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    } while(Q!=first(L));
    cout<<"==============================================="<<endl;
}


void playMusic(address P) {
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L) {
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    int n = 0;
    address P,a;
    int x;
    while (n <= 4) {
        P = first(L);
        x = randomInt(10);
         for (int i=1; i<x; i++) {
            P = next(P);
         }
        deleteAfter(L,P,a);
        insertFirst(L,a);
    }

        cout<<"UNDER MAIN TENIS"<<endl;

    //----------------------------------------
}

void sortListByID(List &L) {
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan ID
    * FS : isi (elemen) dari list L terurut
    */
    address P,R,Q;
    P = first(L);
    R = first(L);
    Q = last(L);
    int temp;
    while(next(next(P)) != next(first(L)))
    {
        while(next(R) != next(next(Q))){
            if(info(R).ID> info(next(R)).ID)
            {
                temp=info(R).ID;
                info(R).ID=info(next(R)).ID;
                info(next(R)).ID=temp;
            }
        R = next(R);
        Q = prev(Q);
        }
    P = next(P);
    }
        cout<<"UNDER MAIN TENIS"<<endl;

    //----------------------------------------

}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    address P;
    P = first(L);
    int i=0;
    while (i<n) {
        playMusic(P);
        i++;
        P = next(P);
    }

        cout<<"UNDER MAIN TENIS"<<endl;
    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x) {
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    if (first(L) == NULL) {
        cout<<"List kosong"<<endl;
    }
    else {
        address a, P;
        a = findElmByID(L,x);
        if (info(a).ID = 1) {
            if (info(P).ID = info(first(L)).ID) {
                deleteFirst(L,P);
            }
            else if (info(P).ID =info(last(L)).ID) {
                deleteLast(L,P);
            }
            else {
                deleteAfter(L,a,P);
            }
        }
    }

        cout<<"UNDER MAIN TENIS"<<endl;

    //----------------------------------------

}
