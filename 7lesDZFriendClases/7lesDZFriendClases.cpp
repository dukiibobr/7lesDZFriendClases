#include <iostream>
using namespace std;

//class Array
//{
//    int* arr;
//    int size;
//public:
//    Array()
//    {
//        size = 0;
//        arr = nullptr;
//    }
//    explicit Array(int size)
//    {
//        this->size = size;
//        arr = new int[size];
//        for (int i = 0; i < size; i++)
//        {
//            arr[i] = rand() % 30;
//        }
//    }
//    Array(int size, int num)
//    {
//        this->size = size;
//        arr = new int[size];
//    }
//    ~Array()
//    {
//        if (arr != nullptr)
//            delete[]arr;
//    }
//    int getSize()const
//    {
//        return size;
//    }
//    int getValue(int index)
//    {
//        return arr[index];
//    }
//    void setValue(int num, int index)
//    {
//        arr[index] = num;
//    }
//    void display(int index)const
//    {
//        cout << arr[index] << " ";
//    }
//
//
//    int operator[](int index)
//    {
//        if (index>=0 and index<size)
//        {
//            return arr[index];
//        }
//    }
//
//    void operator()(int num) {
//        for (int i = 0; i < size; i++)
//        {
//            arr[i] += num;
//        }
//    }
//
//    void PrintArray()
//    {
//        for (int i = 0; i <getSize(); i++)
//        {
//            display(i);
//        }
//        cout << endl;
//    }
//};



class Airplane {
    string model;
    string type;
    int passengerAmount;
    int maxPassengers;
public:
    Airplane(string model,string type,int passengerAmount,int maxPassengers)
    {
        this->model = model;
        this->type = type;
        this->passengerAmount = passengerAmount;
        this->maxPassengers = maxPassengers;
    }
    void print() {
        cout << "model: " << model << endl;
        cout << "type: " << type << endl;
        cout << "passengerAmount: " << passengerAmount << endl;
        cout << "maxPassengers: " << maxPassengers << endl;
    }


    
    friend bool operator == (const Airplane& left, const Airplane& right);
    friend bool operator > (const Airplane& left, const Airplane& right);
    friend Airplane operator--( Airplane& plane);
    friend Airplane operator++( Airplane& plane);

    void operator()(int num) {
        if (passengerAmount+num>maxPassengers)
        {
            cout << "too many passengers" << endl;
            return;
        }
        passengerAmount += num;
    }

};
 

Airplane operator--( Airplane& plane)
{
    if (plane.passengerAmount - 1 < 0)
    {
        cout << "passengers cant be negative" << endl;
        return plane;
    }
    --plane.passengerAmount;
    return plane;
}
Airplane operator++( Airplane& plane)
{
    if (plane.passengerAmount + 1 > plane.maxPassengers)
    {
        cout << "too many passengers" << endl;
        return plane;
    }
    ++plane.passengerAmount;
    return plane;
}

bool operator == (const Airplane& left, const Airplane& right)
{
    return  (left.model==right.model) and (left.type==right.type) and (left.passengerAmount == right.passengerAmount) and (left.maxPassengers == right.maxPassengers);
}

bool operator > (const Airplane& left, const Airplane& right)
{
    return  ((left.maxPassengers) > (right.maxPassengers));
}

int main()
{
    //2
    Airplane a1("boeng", "passanger", 30, 40);
    Airplane a2("boeng", "passanger", 10, 10);
    Airplane a3("boeng99", "passanger", 30, 50);
    a3.print();
    a3(15);
    a3.print();

    //a1.print();
    //++a1;
    //cout << endl;
    //a1.print();
    //++a2;
    //a1.print();
    //if (a3>a1)
    //{
    //    cout << "a3>a1" << endl;
    //}
    //else
    //{
    //    cout << "a3<a1" << endl;
    //}

    //if (a1==a2)
    //{
    //    cout << "a1==a2" << endl;
    //}
    //else
    //{
    //    cout << "a1=!a2" << endl;
    //}




    //1
    //Array a1(10);
    //a1.PrintArray();
    //cout<<a1[2];
    //cout << endl;
    //a1.PrintArray();
    //a1(3);
    //a1.PrintArray();
    

}


