#include <iostream>
//Двунаправленнный список и вывод суммы
struct Node{
    int value;
    Node *next;
    Node *prev;
};

Node *init(int value){
    Node *p = new Node;
    p -> value = value;
    p -> next = NULL;
    p -> prev = NULL;
    return p;
}
Node* getLast(Node* list){
    Node *value = list;
    while(value -> next)
        value = value->next;
    return value;
}

Node *pushBack(Node *node, int value){
    Node *p = init(value);
    Node *lastValue = getLast(node);
    lastValue -> next = p;
    p ->prev = lastValue;
    return node;
}
Node *stringToNode(std::string string, int value){
    char str = string[0];
    Node *list = init(str - '0');
    for(int i = 1 ; i < string.length() - 1 ; i ++){
        char ch = string[i];
        if(ch - '0' == value){
            return list;
        }
        else
            Node *newList = pushBack(list,ch - '0');
    }
    return list;
}

int sum(Node *node){
    int sum = 0;
    Node *node1 = node;
    Node *node2 = node;
    bool flag;

    while(node1 ->next){
        node1 = node1 -> next;
    }
    while(node2 ->next != nullptr){
        sum+= node2 -> value * node1 ->value;
        node2 = node2 -> next;
        node1 = node1 ->prev;
    }
    sum+= node1 -> value * node2 ->value;
    return sum;
}
void print(Node *list){
    do{
        std::cout << list ->value;
        list = list -> next;
    } while(list);
    std::cout <<"\n";
}
int main() {
    Node *list;
    list = stringToNode("123456789",7);
    print(list);
    std::cout<<"Сумма: " << (sum(list));

    return 0;
}
