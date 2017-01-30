#include<iostream>
using namespace std;

void TimeSearch();
void Selection(int *,int);

int main(){
	TimeSearch(); // 함수 호출

}
void TimeSearch() {
  int a[1001], n[20]; // 연산할 배열 크기 할당.
  int j=0; // j 초기화
   const long r[20] = {3000000, 3000000, 2000000, 2000000, 1000000, 1000000,
  1000000, 180000, 180000, 150000, 150000, 125000, 115000, 115000, 110000, 75000, 70000,
  60000, 50000, 50000};
  // 연산을 반복할 크기 할당.
  for (j = 1; j <= 1000; j++) // 연산할 배열인 a에 임의의 값을 집어넣음
    a[j] = j;
  
  for (j = 0; j < 10; j++)  {// 연산할 배열 크기를 할당해줌.
    n[j] = 10 * j ; 
    n[j+10] = 100 * (j+1);
  }
  
  cout <<  "   배열 길이(n)      연산소요시간(total)     회당연산시간(runtime)" << endl;
  
  for(j = 0; j < 20; j++)  { // 총 20회 반복.
    long start, stop ;
    time(&start); // 연산 시작 시간 체크
    for (long b = 1; b <= r[j]; b++) // b가 r[j] 값이 될때까지 반복
      Selection(a, n[j]);
    time(&stop) ; // 연산 종료 시간 체크
    double totalTime = (double)stop - (double)start ;
    double runTime = (double) (totalTime)/(double)(r[j]) ;
    cout << "   " << n[j] << "   " << totalTime << "   " << runTime << endl;
  }
  cout << "출력 종료." << endl;
}

void Selection(int *arr, int one){ // arr = 연산할 배열, one = 배열 '길이'
	int i,j,index,bin; // i,j = for 문 순환용, index = 현재 위치, bin = 임시값 저장.
	
	for (i=0;i<one-1;i++){
		index=i;

		for (j=i+1 ; j<one ; j++)
		{
			if(arr[j]<arr[index]){ // 확인결과, 선택정렬은 오름차순과 내림차순의 시간복잡도가 동일하였음.
				index=j;
			}
		}
		bin = arr[index]; // 결과값 전환.
		arr[index]=arr[i];
		arr[i]=bin;
	}
}


