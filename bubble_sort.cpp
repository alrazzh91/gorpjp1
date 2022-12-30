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

void bubble_sort(int data[], int s) {

   // kondisi awal:
   // sublarik urut tidak memiliki anggota
   // semua elemen larik adalah anggota sublarik tidak urut
   for (int i = 0; i < s - 1; i++) {
      for (int j = s - 1; j > i; j--) {
         if (data[j] < data[j - 1]) {
            tukar(data[j], data[j - 1]);
         }
      }

      cout << "Putaran ke-" << i + 1 << ": ";
      cetak_data(data, s, true);
  }
}

int main() {
   int data[] = {23, 78, 45, 8, 32, 56};

   cout << "Bubble sort" << endl;
   cout << "Data awal   : ";
   cetak_data(data, 6, true);
   bubble_sort(data, 6);
   cout << endl << "Data akhir  : ";
   cetak_data(data, 6, true);

   return 0;
}
