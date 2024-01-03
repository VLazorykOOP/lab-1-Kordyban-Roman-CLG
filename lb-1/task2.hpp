#include<iostream>
using namespace std;

//15. Знайти мінімальне значення додатних елементів, розташованих правіше першого елемента, кратного двом.

class dynamic_array_2
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

void swap(int *a,int *b) { int *tmp=a; a=b; b=tmp; }

int find_1(int *A,int N)
{
    dynamic_array_2 B;
    int i{0};
    for(; A[i]%2; i++) {}
    for(i--; i<N; i++)
        if(A[i]>0)
            B.push_back(A[i]);
    int min[2]{B.data[0],B.data[1]};
    for(i=2; i<B.get_Size(); i++)
    {
        if(min[0]>min[1]) { swap(min[0],min[1]); }
        if(min[1]>B.data[i]) { min[1]=B.data[i]; }
    }
    B.clear();
    return min[0]*min[1];
}

void t2()
{
    int A[]={1, 3, -3, -4, 5, -7, 9, 3, 5, 8, 10};
    cout<<find_1(A,sizeof(A)/sizeof(A[0]));
}