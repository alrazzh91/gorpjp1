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

    for (i=0; i<N; i++){   
        cout<<mahasiswa[i].nama<<endl;
    }
    
    return 0;
}
