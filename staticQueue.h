#ifndef STATICQUEUE_H_INCLUDED
#define STATICQUEUE_H_INCLUDED

#include <exception>
#include <string>
#include <iostream>

class QueueException : public std::exception
{
private:
    std::string msg;
public:
    explicit QueueException(const char* message) : msg(message) {}

    explicit QueueException(const std::string& message) : msg(message) {}

    virtual ~QueueException() throw () {}

    virtual const char* what() const throw ()
    {
        return msg.c_str();
    }
};
template <class T,int ARRAYSIZE = 20>
class Queue
{
private:
    T data[ARRAYSIZE];
    int firstPos;
    int lastPos;
    int sizeQueue;
    void copyAll( Queue<T,ARRAYSIZE>& );
public:
    Queue();
    Queue( Queue&);

    Queue& operator = (Queue&);


    bool isEmpty();
    bool isFull();

    void enqueue(const T);
    T dequeue();
    T getFirst();
    T getLast();

    int getFirstPos();
    int getLastPos();

    void showQueue();



};

using namespace std;
template <class T,int ARRAYSIZE>
Queue<T,ARRAYSIZE>::Queue() : firstPos(0), lastPos(ARRAYSIZE -1) ,sizeQueue(0){}


template <class T,int ARRAYSIZE>
void Queue<T,ARRAYSIZE>::copyAll(Queue& q)
{

    int i = q.getFirstPos() ;

    while(i <= q.getLastPos())
    {
        enqueue(q.dequeue());
        i++;
    }
}


template <class T,int ARRAYSIZE>
Queue<T,ARRAYSIZE>::Queue(Queue& q)
{
    copyAll(q);
}

template <class T,int ARRAYSIZE>
Queue<T,ARRAYSIZE>& Queue<T,ARRAYSIZE>::operator=(Queue& q)
{
    copyAll(q);
    return *this;
}
template <class T,int ARRAYSIZE>
bool Queue<T,ARRAYSIZE>::isEmpty()
{
    return(firstPos == lastPos + 1 or
           (firstPos == 0 and lastPos == ARRAYSIZE - 1));
}

template <class T,int ARRAYSIZE>
bool Queue<T,ARRAYSIZE>::isFull()
{
    return (firstPos == lastPos + 2 or
            (firstPos == 0 and lastPos == ARRAYSIZE - 2) or
            (firstPos == 1 and lastPos == ARRAYSIZE - 1));

}

template <class T,int ARRAYSIZE>
void Queue<T,ARRAYSIZE>::enqueue(const T element)
{
    if(isFull()){
        std::cout<<"Cola llena"<<std::endl;
        system("pause");
    }

    else
    {
        if(++lastPos == ARRAYSIZE) lastPos=0;

        data[lastPos] = element;
    }

    sizeQueue++;

}

template <class T,int ARRAYSIZE>
T Queue<T,ARRAYSIZE>::dequeue()
{
    if(isEmpty()){
        std::cout<<"Cola vacia"<<std::endl;
        system("pause");
    }
    else
    {
        T result=data[firstPos];

        firstPos++;
        if(firstPos== ARRAYSIZE)
        {
            firstPos = 0;
        }
        sizeQueue--;
        return result;
    }
}

template <class T,int ARRAYSIZE>
T Queue<T,ARRAYSIZE>::getFirst()
{
    return data[firstPos];
}
template <class T,int ARRAYSIZE>
T Queue<T,ARRAYSIZE>::getLast()
{
    return data[lastPos];
}

template <class T,int ARRAYSIZE>
int Queue<T,ARRAYSIZE>::getLastPos()
{
    return lastPos;
}
template <class T,int ARRAYSIZE>
int Queue<T,ARRAYSIZE>::getFirstPos()
{
    return firstPos;
}

template <class T,int ARRAYSIZE>
void Queue<T,ARRAYSIZE>::showQueue()
{
    int i;

    if(!isEmpty()) {

        system("cls");

        printf("\n\n\t\t%c%c%c%c%c  \n",201,205,205,205,187);
        for(i=sizeQueue-1; i>=0; i--) {
            if(i==sizeQueue-1)
                printf("Final->\t\t%c ",186,205);
            else
                printf("\t\t%c ",186,205);

            std::cout<<data[i]<<" ";
            printf("%c\n",186);


            if(i==0)
                printf("Frente->\t%c%c%c%c%c\n",200,205,205,205,188);
            else
                printf("\t\t%c%c%c%c%c\n",204,205,205,205,185);

            }
        system("pause");
        }

}


#endif // STATICQUEUE_H_INCLUDED
