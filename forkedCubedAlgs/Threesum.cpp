#include<iostream>
#include<fstream>
using namespace std;

long int count(long int *a)
{ int N = 10000; 
  int counting = 0;
  for (int i = 0; i < N; ++i)
    for (int j = i+1; j < N; ++j)
      for (int k = j+1; k < N; ++k)
       if ((a[i]+a[j]+a[k]) == 0)
          { cout << a[i] << "\t" << a[j] << "\t" << a[k] << endl; 
           counting++;
          } 
  return counting;
}

int main()
{ 
  long int arr[10000], i = 0; 
  ifstream data_file;
  ofstream out_file;

  data_file.open("numbers1.dat");
  while(i < 10000)
  { 
    data_file >> arr[i];
    ++i;
  }
  cout << endl;
  cout << count(&arr[0]) << endl;  
  cout << endl;
  return 0;
}

