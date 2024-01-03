#include<iostream>
using namespace std;

// Задано масив чисел A(2n), n <= 200. Розробити програму, яка обчислює значення :
// max(min(A(1), A(2n)), min(A(2), A(2n-1)), ..., min(A(n), A(n+1)))

class dynamic_array_3
{
public:
    int *data{new int[0]};
    void push_back(int integer)
    {
        int *tmp{new int[size+1]};
        for(int i=0; i<size; i++) { tmp[i]=data[i]; }
        tmp[size++]=integer;
        delete[] data;
        data=tmp;
        tmp=NULL;
    }
    void print()
    {
        cout<<"[ ";
        for(int i=0; i<size-1; i++) { cout<<data[i]<<","; }
        cout<<data[size-1]<<" ]";
    }
    void clear() { delete[] data; }
    int get_Size() { return size; }
private:
    int size{0};
};

int min(int a,int b) { return a<b?a:b; }
int max(int a,int b) { return a>b?a:b; }
int find_2(int *A,int N)
{
    dynamic_array_3 B;
    for(int i=int(N/2.0)-1; i>=0; i--) { B.push_back(min(A[i],A[N-1-i])); }
    int mx=B.data[0];
    for(int i=0; i<B.get_Size(); i++) { mx=max(mx,B.data[i]); }
    B.clear();
    return mx;
}

void t3()
{
    int A[]={21, 3, -3, -4, 5, -7, 9, 3, 5, 8, 10, 19};
    cout<<find_2(A,sizeof(A)/sizeof(A[0]));
}