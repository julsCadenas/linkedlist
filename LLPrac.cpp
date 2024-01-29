#include <iostream>

class FloatList{
    private:
    struct Node{
        float value;
        Node* next;
    };
    Node* head;
    public:
    FloatList(){
        head=NULL;
    }

    void append(float num){
        Node* newNode,*nodePtr;

        newNode=new Node;
        newNode->value=num;
        newNode->next=NULL;

        if(!head){
            head=newNode;
        }else{
            nodePtr=head;
            while(nodePtr->next){
                nodePtr=nodePtr->next;
            }nodePtr->next=newNode;
        }
        std::cout<<"input has been appended!"<<std::endl;

    }

    void insert(float num){
        Node* newNode,*nodePtr,*prevNode;

        newNode=new Node;
        newNode->value=num;

        if(!head){
            head=newNode;
            newNode->next=NULL;
        }else{
            nodePtr=head;
            prevNode=NULL;
            
            while(nodePtr!=NULL && nodePtr->value<num){
                prevNode=nodePtr;
                nodePtr=nodePtr->next;
            }
            if(prevNode==NULL){
                head=newNode;
                newNode->next=nodePtr;
            }else{
                prevNode->next=newNode;
                newNode->next=nodePtr;
            }
            std::cout<<"input has been inserted"<<std::endl;

        }

    }

    void del(float num){
        Node* nodePtr,*prevNode;
        int found=0;
        
        if(!head){
            std::cout<<"the list is empty"<<std::endl;
        }
        if(head->value==num){
            nodePtr=head->next;
            delete head;
            head=nodePtr;
            found=1;
        }else{
            nodePtr=head;
            prevNode=NULL;
            while(nodePtr!=NULL && nodePtr->value!=num){
                prevNode=nodePtr;
                nodePtr=nodePtr->next;
            }
            if(nodePtr!=NULL){
                prevNode->next=nodePtr->next;
                delete nodePtr;
                std::cout<<"input has been deleted"<<std::endl;
                found=1;
            }
            if(found=0){
                std::cout<<"intput not in the list"<<std::endl;
            }
        }

    }

    void display(){
        Node* nodePtr;

        if(head==NULL){
            std::cout<<"list is empty"<<std::endl;
        }else{
            nodePtr=head;
            while(nodePtr){
                std::cout<<nodePtr->value<<std::endl;
                nodePtr=nodePtr->next;
            }
        }

    }

};

int main(){
    
    FloatList list;

    list.append(69);
    list.append(420);
    list.insert(69420);
    list.append(911);
    list.display();
    list.del(69420);
    list.display();
    
    return 0;
}