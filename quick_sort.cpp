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

void cetak_sublarik(int d[], int f, int l, bool nl = false) {
   int i;

   for (i = f; i <= l; i++) {
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

int depth = 0;

void quick_sort(int data[], int first, int last) {
   int a = first, b = last, pivot;

   depth++;

   // tentukan pivot: elemen di tengah larik
   pivot = data[(first + last) / 2];
   cout << "Level " << depth << ", Pivot: " << pivot << endl;

   // atur sublarik kiri dan kanan supaya nilainya kurang untuk sublarik kiri dan
   // lebih atau sama untuk sublarik kanan dari pivot
   do {
      // cari elemen di sisi kiri pivot yang lebih dari pivot
      while (data[a] < pivot) a++;
      // cari elemen di sisi kanan pivot yang kurang dari pivot
      while (data[b] > pivot) b--;

      // tukar posisi supaya posisi data[a] dan data[b] benar: data[a] < pivot < data[b]
      if (a <= b) {
         tukar(data[a], data[b]);
         a++;
         b--;
      }
   } while (a < b);

   cout << "Level " << depth << ", Sublarik kiri: ";
   cetak_sublarik(data, first, b, true);
   if (first < b) quick_sort(data, first, b);

   cout << "Level " << depth << ", Sublarik kanan: ";
   cetak_sublarik(data, a, last, true);
   if (a < last) quick_sort(data, a, last);

   cout << "Level " << depth << ", Sublarik kanan+kiri: ";
   cetak_sublarik(data, first, last, true);
   depth--;
}

int main() {
   int data[] = {23, 78, 45, 8, 32, 56};

   cout << "Quick sort" << endl;
   cout << "Data awal   : ";
   cetak_data(data, 6, true);
   quick_sort(data, 0, 5);
   cout << endl << "Data akhir  : ";
   cetak_data(data, 6, true);

   return 0;
}

