#include <iostream>
using namespace std;

struct datamhs {
    double IPK;
    string nama;
};

int main() {
    int N, i, j;
    double ttlnilai, ttlSKS;
    double temp;
    int cari;
    int l, r, mid;
    
    cin>>N;
    
    datamhs mahasiswa[N];
    
    for (i=0; i<N; i++) {
        cin>>mahasiswa[i].nama;
        cin>>ttlnilai;
        cin>>ttlSKS;
        
        mahasiswa[i].IPK= ttlnilai / ttlSKS;
    }

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            if (mahasiswa[i].IPK > mahasiswa[j].IPK || (mahasiswa[i].IPK == mahasiswa[j].IPK && mahasiswa[i].nama < mahasiswa[j].nama)){
                temp = mahasiswa[j].IPK;
                swap (mahasiswa[j].IPK, mahasiswa[i].IPK);
                swap (mahasiswa[j].nama, mahasiswa[i].nama);
                mahasiswa[i].IPK = temp;
            }
        }
    }

    
    cin>>cari;
    for (i=0; i<N; i++) {
        l = 1;
        r = (N-1);
        if (l<r) {
            mid = (l+r)/2;
        }
    }
    
    for (i=0; i<N; i++) {
    if (cari == mid) {
            cout<<mahasiswa[mid].IPK;
            break;
        }
        else if (cari < mid) {
            r = mid-1;
            cout<<mahasiswa[mid].IPK;
            break;
        }
        else {
            l =mid+1;
            cout<<mahasiswa[mid].IPK;
            break;
        }
    }
    return 0;
}

