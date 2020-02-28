#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void function_name (int i, int j)
{
    int **a;
  
    if (a[i][j] == 1)
  {
    a[i][j] = 0;
    function_name(i+1,j);
    function_name(i-1,j);
    function_name(i,j+1);
    function_name(i,j-1);    
  }

  if (a[i][j] == 0) exit(0);

}

int main()
{
 int n = 0;
 int m = 0;

 int **a;

 //открываем файл
 FILE * fp = fopen("matrix.txt", "r");
 if (fp)
 {
  //читаем количество строк и столбцов
  fscanf(fp, "%d %d", &n, &m);

  //выделяем место
  *a = new int(n);
  for (int i = 0; i < n; i++) a[i] = new int(m);

  //считываем данные из файла в матрицу
  for (int i = 0; i < n; i++)
  {
   for (int j = 0; j < m; j++)
   {
    fscanf(fp, "%d", &a[i][j]);
   }
  }
  
  //закрываем файл
  fclose(fp);
 }

 //печать матрицы
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < m; j++)
  {
   printf("%d ", a[i][j]);
  }

  printf("\n");
 }

    //освобождение памяти
 for (int i = 0; i < n; i++) delete a[i];
 delete *a;

int counter;
for (int i = 1; i < n - 2; i++)
 {
  for (int j = 1; j < m - 2; j++)
  {  
      if (a[i][j] ==1)
      {
        counter = counter + 1;
        function_name(i,j);
      }
  }
  }

int temp = 0;
for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < m; j++)
  {
		if (a[i][j] == 1)
			temp = temp + 1;
  }
  }
   cout << counter << endl;

  system("pause"); 
 return 0;
}
