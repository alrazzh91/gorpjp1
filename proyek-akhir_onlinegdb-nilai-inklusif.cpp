#include<iostream>
#include<windows.h>
using namespace std;

int main() {
    system("color 8B"); 
    int js; //js = jumlah siswa
    cout<<"Masukkan jumlah siswa: ";
    cin>>js; 
    if (js > 1000) {
        cout<<"Jumlah siswa yang Anda masukkan terlalu banyak!"<<endl;
    }
    else {
    cout<<endl;
    
    string nama[js];
    int a[js], b[js];
    int total[js];
    int atas, bawah, output=0, i;
    
        cout<<"---- Masukkan data sesuai petunjuk sebanyak jumlah siswa yang telah Anda masukkan ----"<<endl;
        cout<<"PENTING : Nama siswa hanya diisi satu kata dengan huruf kecil dan maksimal 10 huruf."<<endl;
        cout<<"FORMAT  : nama (spasi) nilai menggambar (spasi) nilai mewarnai (enter)"<<endl;
        cout<<"Setelah data siswa dan nilai, enter 1x dan masukkan rentang (batasan) dari total nilai yang diinginkan (max (spasi) min)"<<endl;
        for(int i=0; i<js; i++) {
            cin >> nama[i] >> a[i] >> b[i];
            total[i] = a[i] + b[i];
        }
        
        cin >> atas >> bawah;
        
        for(int i=0; i<js; i++) {
            if(total[i] >= bawah && total[i] <= atas) output++;
        cout<<nama[i]<<" "<<total[i]<<endl;
        }

        if (output > 0) {
            cout<<endl;
            cout << "Jumlah siswa yang total nilainya berada di dalam rentang "<<bawah<<" sampai dengan "<<atas<<" ada: " <<output <<" orang"<< endl;
        }

        else {
            cout<<"not found"<<endl;
        }
        
        system("pause");
        

    return 0;
    }
}





