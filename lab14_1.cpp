#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N, double B[6]){
    
    double max = A[0], min = A[0]; // start with first array is the savest way for max and min.
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 1.0;

    for(int i = 0; i < N; i++ ){
        sum1 = sum1 + A[i];
    }

     double B1 = sum1 / (N);

    for(int i = 0; i < N; i++ ){
        sum2 = sum2 + ( (A[i] - (B1))*(A[i] - B1));
        sum4 = sum4 * A[i];
        sum3 = sum3 + ( 1/A[i] );
        if(max <= A[i]){
            max = A[i];
        }else if(min >= A[i]){
            min = A[i];
        }
    }

    double B2 = sqrt( sum2/N );
    double B3 =  pow(sum4,1.0/N);
    double B4 = N/sum3;
    double B5 = max;
    double B6 = min;

    B[0] = B1;
    B[1] = B2;
    B[2] = B3;
    B[3] = B4;
    B[4] = B5;
    B[5] = B6;

}