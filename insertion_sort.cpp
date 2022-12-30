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

void insertion_sort(int data[], int s) {
   // kodisi awal:
   // sublarik urut terdiri dari satu anggota, yaitu elemen indeks ke-0
   // elemen ke-1, dst adalah anggota dari sublarik tidak urut
   for (int i = 1; i < s; i++) {
      for (int j = 0; j < i; j++) {
         if (data[j] > data[i]) {
            tukar(data[j], data[i]);
         }
      }

      cout << "Putaran ke-" << i << ": ";
      cetak_data(data, s, true);
  }
}

int main() {
   int data[] = {64, 6, 51, 45, 67};

   cout << "Insertion sort" << endl;
   cout << "Data awal   : ";
   cetak_data(data, 5, true);
   insertion_sort(data, 5);
   cout << endl << "Data akhir  : ";
   cetak_data(data, 5, true);

   return 0;
}
