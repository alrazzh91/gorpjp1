#include <iostream>
#include <iomanip>

using namespace std;

void cetak_data(int d[], int s, bool nl = false) {
   int i;

   for (i = 0; i < s; i++) {
      cout << setw(3) << right << d[i];
   }
   if (nl) cout << endl;
}

void tukar(int &a, int &b) {
   int t;
   t = a;
   a = b;
   b = t;
}

void selection_sort(int data[], int s) {
   int lok, i, j;

   // kondisi awal:
   // sublarik urut tidak memiliki anggota
   // semua elemen larik adalah anggota sublarik tidak urut
   for (i = 0; i < s - 1; i++) {
      lok = i;
      for (j = i + 1; j < s; j++) {
         if (data[j] < data[lok]) {
            lok = j;
         }
      }
      tukar(data[i], data[lok]);

      cout << "Putaran ke-" << i + 1 << ": ";
      cetak_data(data, s, true);
   }
}

int main() {
   int data[] = {23, 78, 45, 8, 32, 56};

   cout << "Selection sort" << endl;
   cout << "Data awal   : ";
   cetak_data(data, 6, true);
   selection_sort(data, 6);
   cout << endl << "Data akhir  : ";
   cetak_data(data, 6, true);

   return 0;
}
