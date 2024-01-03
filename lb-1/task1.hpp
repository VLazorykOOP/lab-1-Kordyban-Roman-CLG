#include<iostream>
using namespace std;

//15. Задано одновимірний масив А розміру N. Вилучити всі додатні елементи масиву.

class dynamic_array_1
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

void t1()
{
    int tmp,N;
    dynamic_array_1 A,B;

    cout<<"N: ";
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cout<<"A["<<i<<"]: ";
        cin>>tmp;
        A.push_back(tmp);
    }
    for(int i=0; i<A.get_Size(); i++) { if(A.data[i]<=0) { B.push_back(A.data[i]); } }

    A.print();
    A.clear();
    cout<<endl;

    B.print();
    B.clear();
    cout<<endl;
}
