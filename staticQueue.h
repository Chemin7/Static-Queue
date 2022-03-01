#ifndef STATICQUEUE_H_INCLUDED
#define STATICQUEUE_H_INCLUDED

#include <exception>
#include <string>

class QueueException : public std::exception {
    private:
        std::string msg;
    public:
        explicit QueueException(const char* message) : msg(message) {}

        explicit QueueException(const std::string& message) : msg(message) {}

        virtual ~QueueException() throw () {}

        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };
template <class T,int ARRAYSIZE = 20>
class Queue {
    private:
        T data[ARRAYSIZE];
        int firstPos;
        int lastPos;

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

        int getFirstPos();
        int getLastPos();



    };

using namespace std;
template <class T,int ARRAYSIZE>
Queue<T,ARRAYSIZE>::Queue() : firstPos(0), lastPos(ARRAYSIZE -1) {}


template <class T,int ARRAYSIZE>
void Queue<T,ARRAYSIZE>::copyAll(Queue& q) {

         int i = q.getFirstPos() ;

        while(i <= q.getLastPos()){
            enqueue(q.dequeue());
            i++;
        }
    }


template <class T,int ARRAYSIZE>
Queue<T,ARRAYSIZE>::Queue(Queue& q) {
        copyAll(q);
    }

template <class T,int ARRAYSIZE>
Queue<T,ARRAYSIZE>& Queue<T,ARRAYSIZE>::operator=(Queue& q) {
    copyAll(q);
    return *this;
    }
template <class T,int ARRAYSIZE>
bool Queue<T,ARRAYSIZE>::isEmpty() {
    return(firstPos == lastPos + 1 or
           (firstPos == 0 and lastPos == ARRAYSIZE - 1));
    }

template <class T,int ARRAYSIZE>
bool Queue<T,ARRAYSIZE>::isFull() {
    return (firstPos == lastPos + 2 or
            (firstPos == 0 and lastPos == ARRAYSIZE - 2) or
            (firstPos == 1 and lastPos == ARRAYSIZE - 1));

    }

template <class T,int ARRAYSIZE>
void Queue<T,ARRAYSIZE>::enqueue(const T element) {
    if(isFull())
        throw QueueException("Desbordamiento de datos,enqueue");


    if(++lastPos == ARRAYSIZE) lastPos=0;

    data[lastPos] = element;

    }

template <class T,int ARRAYSIZE>
T Queue<T,ARRAYSIZE>::dequeue() {
    if(isEmpty())
        throw QueueException("Insuficiencia de datos,dequeue");

    T result=data[firstPos];

    firstPos++;
    if(firstPos== ARRAYSIZE) {
        firstPos = 0;
        }
    return result;
    }

template <class T,int ARRAYSIZE>
T Queue<T,ARRAYSIZE>::getFirst() {
    return data[firstPos];
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

#endif // STATICQUEUE_H_INCLUDED
