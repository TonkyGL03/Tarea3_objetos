#ifndef LISTADINAMICA_HPP_INCLUDED
#define LISTADINAMICA_HPP_INCLUDED

#include<iostream>
#include<string>
#include<exception>

// Implementación
template<class T>
class List{
    private:
        class Node{
        private:
            T data;
            Node* next;
            Node* prev;
        public:
            Node();

            Node(const T&);
            T getData() const;
            Node* getNext() const;
            Node* getPrev() const;
            void setData(const T&);
            void setNext(Node*);
            void setPrev(Node*);

        };
        
        Node* anchor;
        void copyAll(const List<T>&);
        bool isValidPos(Node*) const;
        void swapData(T&, T&);
    
    public:
        typedef Node* Position;
        class Exception : public std::exception{
        
    private:
        std::string msg;
    public:
        explicit Exception(const char* message) :

msg(message){}

explicit Exception(const std::string&

message) : msg(message){ }  

virtual ~Exception() throw(){}

virtual const char* what() const throw(){
    return msg.c_str();
}
        };
        
    List();
    List(const List<T>&);
    ~List();

    bool isEmpty() const;
    void insertData(Node*, const T&); // posición, elemento.
    void deleteData(Node*); // posición.
    
    Node* getFirstPos() const;
    Node* getLastPos() const;
    Node* getPrevPos(Node*) const;
    Node* getNextPos(Node*) const;
    Node* findData(const T&,int(const T&,const T&)) const;
    
    int findDataLinear(const T&);
    int findDataBinary(const T&);
    T retrieve(Node*) const;
    
    void sortDataBubble(int(const T&, const T&));
    void sortDataInsert(int(const T&, const T&));
    void sortDataSelect(int(const T&, const T&));
    void sortDataShell(int(const T&, const T&));
    void print();
    void deleteAll();
    List<T>& operator = (const List<T>&);
    std::string toString() const;

};
/// Node
// Definición
template<class T>
List<T>::Node::Node() : prev(nullptr), next(nullptr){ //Constructores
}
template<class T>
List<T>::Node::Node(const T& e) : data(e), prev(nullptr), next(nullptr){
//Constructor parametrizado
}
template<class T>
T List<T>::Node::getData() const{
return data;
}
template<class T>
typename List<T>::Node* List<T>::Node::getNext() const{
return next;
}
template<class T>
typename List<T>::Node* List<T>::Node::getPrev() const{
return prev;
}

template<class T>
void List<T>::Node::setData(const T& e){
data = e;
}
template<class T>
void List<T>::Node::setNext(Node* p){
next = p;
}
template<class T>
void List<T>::Node::setPrev(Node* p){
prev = p;
}
/// List
// Definición
using namespace std;
// Constructores
template<class T>
List<T>::List() : anchor(nullptr){
}
template<class T>
List<T>::~List(){
deleteAll();
}
template<class T>
List<T>::List(const List<T>& l) : anchor(nullptr){
deleteAll();
copyAll(l);
}
template<class T>
List<T>& List<T>::operator = (const List<T>& l){
copyAll(l);
return *this;
}
template<class T>
void List<T>::copyAll(const List<T>& l){
Node* aux(l.anchor);
Node* last(nullptr);
Node* newNode;
while(aux != nullptr){
newNode = new Node(aux->getData());

if(last == nullptr){
anchor = newNode;
}else{
last->setNext(newNode);
}
last = newNode;
aux = aux->getNext();
}
}
template<class T>
bool List<T>::isValidPos(Node* p) const{
Node* aux(anchor);
while(aux != nullptr){
if(aux == p){
return true;
}
aux = aux->getNext();
}
return false;
}
template<class T>
void List<T>::swapData(T& a, T& b){
T aux(a);
a = b;
b = aux;
}
template<class T>
bool List<T>::isEmpty() const{
return anchor == nullptr;
}
template<class T>
void List<T>::insertData(Node* p, const T& e){
if(p != nullptr and !isValidPos(p)){
throw("\nPosicion invalida, insertData");
}
Node* aux(new Node(e));
if(aux == nullptr){
throw("\nMemoria no disponible, insertData");
}

if(p == nullptr){ //Insertar al inicio.
aux->setNext(anchor);

if(anchor != nullptr){
anchor->setPrev(aux);
}
anchor = aux;
}
//insercion diferente al inicio
else{
aux->setPrev(p);
aux->setNext(p->getNext());
if(p->getNext() != nullptr){
p->getNext()->setPrev(aux);

}
p->setNext(aux);
}
}
template<class T>
void List<T>::deleteData(Node* p){
if(!isValidPos(p)){
throw Exception("Posicion invalida, deleteData");
}
if(p->getPrev() != nullptr){
p->getPrev()->setNext(p->getNext());
}
if(p->getNext() != nullptr){
p->getNext()->setPrev(p->getPrev());
}
if(p == anchor){
anchor = anchor->getNext();
}
delete p;
}
template<class T>
typename List<T>::Node* List<T>::getFirstPos() const{
return anchor;
}
template<class T>
typename List<T>::Node* List<T>::getLastPos() const{
if(isEmpty()){
return nullptr;
}
Node* aux(anchor);
while(aux->getNext() != nullptr){
aux = aux->getNext();

}
return aux;
}
template<class T>
typename List<T>::Node* List<T>::getPrevPos(Node* p) const{
if(!isValidPos(p)){
return nullptr;
}
return p->getPrev();
}
template<class T>
typename List<T>::Node* List<T>::getNextPos(Node* p) const{
if(!isValidPos(p)){
return nullptr;
}
return p->getNext();
}
template <class T>
typename List<T>::Node* List<T>::findData(const T& e, int cmp(const T&
a,const T& b)) const{
Node* aux(anchor);
while(aux != nullptr and cmp(aux->getData(),e) != 0){
aux = aux->getNext();
}
return aux;
}
template<class T>
T List<T>::retrieve(Node* p) const{
if(!isValidPos(p)){
throw("Posicion invalida, retrieve.");
}
return p->getData();
}
template<class T>
void List<T>::deleteAll(){
Node* aux;
while(anchor != nullptr){
aux = anchor;
anchor = anchor->getNext();
delete aux;
}

}
template<class T>
string List<T>::toString() const{
Node* aux(anchor);
string result;
while(aux != nullptr){
result += aux->getData().toString() + "\n";
aux = aux->getNext();
}
return result;
}
#endif // LISTADINAMICA_HPP_INCLUDED
