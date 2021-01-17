#include <iostream>
#include <cmath>
#include <sstream>  
#include <math.h>
float dizi[5][5] = {0.2243, 0.2364, 0.1079, 0.8959, 0.3119,
					0.2691, 0.1771, 0.1822, 0.0991, 0.1790,
					0.6730, 0.8296, 0.0991, 0.0442, 0.3390,
					0.4775, 0.7669, 0.4898, 0.5573, 0.2101,
					0.6237, 0.9345, 0.1932, 0.7725, 0.5102 };
int sayi;
using namespace std;


float determinant( float matrix[5][5], int n) {
   float det = 0.0f;
   float submatrix[5][5];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return det;
}


float iz( float matrix[5][5], int n) {
  	float transpoz_a[5][5];
	cout<<"A Matrisinin Transpozu"<<"\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			transpoz_a[i][j]=matrix[j][i];
			cout<<" "<<transpoz_a[i][j];
		}
		cout<<"\n";
	}
	float CARP [5][5], Toplam;
	cout<<"ATA Matrisi" << "\n";
	for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            Toplam=0;
            for(int k=0; k<5; k++)
            {
                Toplam+= matrix[i][k]*transpoz_a[k][j];
            }
			cout.precision(5);
            CARP[i][j]= Toplam;
            cout<<" "<<CARP[i][j];
        }
        cout<<"\n";
    }
    
	float iz;
	iz = CARP[0][0] +CARP[1][1] + CARP[2][2]+CARP[3][3]+CARP[4][4];
	cout<<"ATA Matrisinin izi" << " " << iz << "\n";
	return iz;
}


float satir_norm( float matrix[5][5], int n) {
float a,b,c,d,e;	
a=sqrt(pow(matrix[0][0],2) + pow(matrix[0][1],2)+  pow(matrix[0][2],2) + pow(matrix[0][3],2) + pow(matrix[0][4],2));
cout<<"A1 (1. Satirinn normu) :" << a << "\n";
b=sqrt(pow(matrix[1][0],2) + pow(matrix[1][1],2)+  pow(matrix[1][2],2) + pow(matrix[1][3],2) + pow(matrix[1][4],2));
cout<<"A2 (2. Satirinn normu) :" << b << "\n";
c=sqrt(pow(matrix[2][0],2) + pow(matrix[2][1],2)+  pow(matrix[2][2],2) + pow(matrix[2][3],2) + pow(matrix[2][4],2));
cout<<"A3 (3. Satirinn normu) :" << c << "\n";
d=sqrt(pow(matrix[3][0],2) + pow(matrix[3][1],2)+  pow(matrix[3][2],2) + pow(matrix[3][3],2) + pow(matrix[3][4],2));
cout<<"A4 (4. Satirinn normu) :" << d << "\n";
e=sqrt(pow(matrix[4][0],2) + pow(matrix[4][1],2)+  pow(matrix[4][2],2) + pow(matrix[4][3],2) + pow(matrix[4][4],2));
cout<<"A5 (5. Satirinn normu) :" << e << "\n";
}


float sutun_norm( float matrix[5][5], int n) {
float a,b,c,d,e;	
a=sqrt(pow(matrix[0][0],2) + pow(matrix[1][0],2) + pow(matrix[2][0],2)+  pow(matrix[3][0],2) + pow(matrix[4][0],2));
cout<<"A1 (1. Sutunun normu) :" << a << "\n";
b=sqrt(pow(matrix[0][1],2) + pow(matrix[1][1],2)+  pow(matrix[2][1],2) + pow(matrix[3][1],2) + pow(matrix[4][1],2));
cout<<"A2 (2. Sutunun normu) :" << b << "\n";
c=sqrt(pow(matrix[0][2],2) + pow(matrix[1][2],2)+  pow(matrix[2][2],2) + pow(matrix[3][2],2) + pow(matrix[4][2],2));
cout<<"A3 (3. Sutunun normu) :" << c << "\n";
d=sqrt(pow(matrix[0][3],2) + pow(matrix[1][3],2)+  pow(matrix[2][3],2) + pow(matrix[3][3],2) + pow(matrix[4][3],2));
cout<<"A4 (4. Sutunun normu) :" << d << "\n";
e=sqrt(pow(matrix[0][4],2) + pow(matrix[1][4],2)+  pow(matrix[2][4],2) + pow(matrix[3][4],2) + pow(matrix[4][4],2));
cout<<"A5 (5. Sutunun normu) :" << e << "\n";
	return a;
}


float oklid_norm( float matrix[5][5], int n) {
float a;
float Toplam=0;
for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) {
            Toplam+= pow(matrix[i][j],2);
		}
	}
a=sqrt(Toplam);
cout<<"A Matrisinin Oklid Normu:" << a << "\n";
return a;
}


float esitlik( float matrix[5][5], int n) {
float N = oklid_norm(matrix,5);
float i = iz(matrix,5);
float ii = sqrt(i);
cout<<"(iz(ATA))^(1/2) :" << ii <<"\n";
if(N==ii){
	cout<<"Esitlik saglanmis"<<"\n";
}
else{
	cout<<"Esitlik saglanmamis" <<"\n";
}
return ii;
}


float norm_norm( float matrix[5][5], int n) {
float N = oklid_norm(matrix,5);
cout << "Oklid normuna gore normlari" << "\n";
float norm_a[5][5];
for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) {
			norm_a[i][j] = matrix[i][j] / N;
			cout<<" "<<norm_a[i][j];		
					}
			cout<<"\n";
			}
return N;
}


float hadamard( float matrix[5][5], int n) {
float deter = abs(determinant(matrix,5));
float a,b,c,d,e;	
a=sqrt(pow(matrix[0][0],2) + pow(matrix[0][1],2)+  pow(matrix[0][2],2) + pow(matrix[0][3],2) + pow(matrix[0][4],2));
b=sqrt(pow(matrix[1][0],2) + pow(matrix[1][1],2)+  pow(matrix[1][2],2) + pow(matrix[1][3],2) + pow(matrix[1][4],2));
c=sqrt(pow(matrix[2][0],2) + pow(matrix[2][1],2)+  pow(matrix[2][2],2) + pow(matrix[2][3],2) + pow(matrix[2][4],2));
d=sqrt(pow(matrix[3][0],2) + pow(matrix[3][1],2)+  pow(matrix[3][2],2) + pow(matrix[3][3],2) + pow(matrix[3][4],2));
e=sqrt(pow(matrix[4][0],2) + pow(matrix[4][1],2)+  pow(matrix[4][2],2) + pow(matrix[4][3],2) + pow(matrix[4][4],2));
float carpim = a*b*c*d*e;
float KH = deter/carpim;
cout<<"A matrisinin Hadamard sart sayisi:"<<KH<<"\n";
if(KH<pow(10,-2)){
	cout<<"Kararsiz"<<"\n";
}
else{
	cout<<"Kararli"<<"\n";
}
return KH;
}

int main (){
	while(1==1){
	cout << "Matrisi gormek icin 0 tusuna basiniz:" << "\n";
	cout << "Matrisin determinantini gormek icin 1 tusuna basiniz:" << "\n";
	cout << "ATA Matrisinin izini gormek icin 2 tusuna basiniz:" << "\n";
	cout << "A Matrisinin Satir Normlarini gormek icin 3 tusuna basiniz:" << "\n";
	cout << "A Matrisinin Sutun Normlarini gormek icin 4 tusuna basiniz:" << "\n";
	cout << "A Matrisinin Oklid Normumunu gormek icin 5 tusuna basiniz:" << "\n";
	cout << "N(A)=(iz(ATA))^(1/2) esitliginin oldugunu gormek icin 6 tusuna basiniz:" << "\n";
	cout << "A matrisinin Oklid normuna gore normlarini gormek icin 7 tusuna basiniz:" << "\n";

	
	cout << "A matrisinin Hadamard sart sayisini gormek icin 10 tusuna basiniz:" << "\n";
	cin>>sayi;
	cout<<"\n";
		if(sayi==0){
		for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++)
        cout<<" "<<dizi[i][j];
        cout<<"\n";
    							}
	}
		if(sayi==1){
		cout<<"Determinant degeri: "<< determinant(dizi, 5) << "\n";
	}
		if(sayi==2){
		cout<< iz(dizi, 5) << "\n";
	}
		if(sayi==3){
		cout<< satir_norm(dizi, 5) << "\n";
	}
		if(sayi==4){
		cout<< sutun_norm(dizi, 5) << "\n";
	}
		if(sayi==5){
		cout<< oklid_norm(dizi, 5) << "\n";
	}
		if(sayi==6){
		cout<< esitlik(dizi, 5) << "\n";
	}
		if(sayi==7){
		cout<< norm_norm(dizi, 5) << "\n";
	}
		if(sayi==10){
		cout<< hadamard(dizi, 5) << "\n";
	}
  }
}
