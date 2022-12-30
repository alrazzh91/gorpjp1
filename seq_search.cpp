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

int cari_sekuensial(int data[], int s, int cari) {
   bool ketemu;
   int i = 0;

   ketemu = false;
   while ((i < s) && !(ketemu)) {
      ketemu = (data[i++] == cari);
   }

   if (ketemu) {
      return i;
   } else {
      return 0;
   }
}

// s = ukuran larik
int cari_sekuensial_r(int data[], int s, int cari, int langkahke = 0) {
   if (s <= 1) {
      // jika ukuran larik kurang atau sama dengan satu
      if (data[s - 1] == cari) {
         return ++langkahke;
      } else {
         return 0;
      }
   } else {
      if (data[langkahke++] == cari) {
         return langkahke;
      } else {
         if (langkahke < s) {
            return cari_sekuensial_r(data, s, cari, langkahke);
        } else {
           return 0;
        }
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
   cetak_data(data100, 100);

   cout << "Pilih data yang akan dicari: ";
   cin >> c;

   int langkahke = cari_sekuensial(data100, 100, c);
   if (langkahke > 0) {
      cout << "Data ditemukan pada langkah ke-" << langkahke << endl;
   } else {
      cout << "Data tidak ditemukan" << endl;
   }

   langkahke = cari_sekuensial_r(data100, 100, c);
   if (langkahke > 0) {
      cout << "Data ditemukan pada langkah ke-" << langkahke << " pencarian sekuensial rekursif" << endl;
   } else {
      cout << "Data tidak ditemukan" << endl;
   }

   bubble_sort(data100, 100);
   langkahke = cari_sekuensial(data100, 100, c);
   if (langkahke > 0) {
      cout << "Data ditemukan pada langkah ke-" << langkahke << " setelah data diurutkan" << endl;
   } else {
      cout << "Data tidak ditemukan" << endl;
   }

   langkahke = cari_sekuensial_r(data100, 100, c);
   if (langkahke > 0) {
      cout << "Data ditemukan pada langkah ke-" << langkahke << " pencarian sekuensial rekursif setelah data diurutkan" << endl;
   } else {
      cout << "Data tidak ditemukan" << endl;
   }

   return 0;
}
