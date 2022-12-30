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

void array_merge(int data[], int first, int mid, int last) {
   int n1 = mid - first + 1;
   int n2 = last - mid;

   int tmp_left[n1], tmp_right[n2];

   for (int i = 0; i < n1; i++)
      tmp_left[i] = data[first + i];
   for (int i = 0; i < n2; i++)
      tmp_right[i] = data[mid + 1 + i];

   int i = 0;
   int j = 0;
   int k = first;
   while (i < n1 && j < n2) {
      if (tmp_left[i] <= tmp_right[j]) {
         data[k] = tmp_left[i];
         i++;
      } else {
         data[k] = tmp_right[j];
         j++;
      }
      k++;
   }

   while (i < n1) {
      data[k] = tmp_left[i];
      i++;
      k++;
   }

   while (j < n2) {
      data[k] = tmp_right[j];
      j++;
      k++;
   }
}

int depth = 0;

void merge_sort(int data[], int first, int last) {
   if (first < last) {
      // indeks tengah larik
      int mid = (first + last) / 2;

      depth++;

      // sublarik kiri
      cout << "Level " << depth << ", Sublarik kiri: ";
      cetak_sublarik(data, first, mid, true);
      merge_sort(data, first, mid);

      // sublarik kanan
      cout << "Level " << depth << ", Sublarik kanan: ";
      cetak_sublarik(data, mid + 1, last, true);
      merge_sort(data, mid + 1, last);

      // gabung sublarik kiri dan kanan sambil diurutkan
      array_merge(data, first, mid, last);
      cout << "Level " << depth << ", Larik gabungan: ";
      cetak_sublarik(data, first, last, true);

      depth--;
   }
}

int main() {
   int data[] = {23, 78, 45, 8, 32, 56};

   cout << "Merge sort" << endl;
   cout << "Data awal   : ";
   cetak_data(data, 6, true);
   merge_sort(data, 0, 5);
   cout << endl << "Data akhir  : ";
   cetak_data(data, 6, true);

   return 0;
}

