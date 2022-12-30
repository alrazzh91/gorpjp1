#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void isi_data(int d[], int s) {
   int i;
   for (i = 0; i < s; i++) {
      d[i] = rand();
   }
}

void cetak_data(int d[], int s) {
   int i;
   for (i = 0; i < s; i++) {
      cout << setw(8) << right << d[i];
   }
   cout << endl;
}

void tukar(int &a, int &b) {
   int t;
   t = a;
   a = b;
   b = t;
}

void bubble_sort(int data[], int s) {
   int i, j;

   for (i = 0; i < s - 1; i++) {
      for (j = s - 1; j > i; j--) {
         if (data[j] < data[j - 1]) {
            tukar(data[j], data[j - 1]);
         }
      }
   }
}

int cari_biner(int data[], int s, int cari) {
   int a, b, t, langkah;
   bool ketemu;

   a = 0; b = s - 1;
   langkah = 0;
   ketemu = false;
   do {
      t = (a + b) / 2;
      if (data[t] == cari) {
         ketemu = true;
      } else {
         if (data[t] > cari) {
            b = t - 1;
         } else {
            a = t + 1;
         }
      }
      langkah++;
   } while ((a <= b) && !(ketemu));

   return ketemu ? langkah : 0;
}

// a = indeks terkecil
// b = indeks terbesar
int cari_biner_r(int data[], int a, int b, int cari, int langkahke = 0) {
   int t;

   langkahke++;
   if (a >= b) {
      if ((data[a] == cari && a >= 0) || (data[b] == cari && b >= 0)) {
         return langkahke;
      }
      return 0;
   } else {
      t = (a + b) / 2;
      if (data[t] < cari) {
         return cari_biner_r(data, t + 1, b, cari, langkahke);
      } else if (data[t] > cari) {
         return cari_biner_r(data, a, t - 1, cari, langkahke);
      } else {
         return langkahke;
      }
   }
}

int main() {
   int data100[100];
   int c;

   srand (time(NULL));

   isi_data(data100, 100);
   cout << "Pencarian Sekuensial" << endl;
   cout << "Data:" << endl;
   bubble_sort(data100, 100);
   cetak_data(data100, 100);

   cout << "Pilih data yang akan dicari: ";
   cin >> c;

   int langkahke = cari_biner(data100, 100, c);
   if (langkahke > 0) {
      cout << "Data ditemukan pada langkah ke-" << langkahke << endl;
   } else {
      cout << "Data tidak ditemukan" << endl;
   }

   langkahke = cari_biner_r(data100, 0, 99, c);
   if (langkahke > 0) {
      cout << "Data ditemukan pada langkah ke-" << langkahke << " pencarian biner rekursif" << endl;
   } else {
      cout << "Data tidak ditemukan" << endl;
   }

   return 0;
}
