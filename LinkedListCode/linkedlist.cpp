#include<iostream>

struct ListNode{
      int val;
      struct ListNode* next;
      //constructor

      ListNode():val(0), next(nullptr){}
      ListNode(int value):val(value), next(nullptr){}
};

class LinkedList{
      private:
            ListNode *head;
            
      
      public:
            LinkedList():head(nullptr){}

            void insertAtBeginning(int val){
                  ListNode *temp = new ListNode(val);
                  if(head == nullptr){
                        head = temp;
                        return ;
                  }

                  temp -> next  = head;
                  head = temp;
                  return ;
            }

            void insertAtEnd(int val){
                  ListNode *temp = new ListNode(val);
                  if(head == nullptr){
                        head = temp;
                        return ;
                  }
                  ListNode *curr =  head;
                  while(curr -> next != nullptr){
                        curr = curr -> next;
                  }
                  curr -> next = temp;
                  return ;
            }

            void deleteNode(int val){
                  if(head == nullptr)
                        return ;
                  
                  if( head -> val == val){
                        
                        ListNode *temp = head;
                        head = head -> next;
                        delete temp;
                        return;
                  }

                  ListNode *temp = head;
                  while(temp -> next && temp -> next -> val != val){
                        temp = temp -> next;
                  }

                  if(temp -> next == nullptr)return ;

                  ListNode *node = temp -> next;
                  temp -> next = temp -> next -> next;
                  delete node;

                  return ;
            }

            bool search(int val){
                  ListNode *curr = head;
                  while(curr && curr -> val != val){
                        curr = curr -> next;
                  }
                  if(curr  == nullptr)return false;

                  return true;
            }

            void display(){
                  if(head == nullptr){
                        std::cout<<"NULL"<<std::endl;
                        return ;
                  }

                  ListNode *curr = head;
                  while(curr != nullptr){
                        std::cout<<curr -> val <<"->";
                        curr = curr -> next;
                  }
                  std::cout<<"NULL"<<std::endl;
                  return;


            }

            ~LinkedList(){
                  ListNode *curr = head;
                  while(curr != nullptr){
                        ListNode *node = curr;
                        curr = curr -> next;
                        delete node;

                  }
                  head = nullptr;
            }
            
};

int main() {
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.display(); // Expected: 5->10->20->NULL

    list.deleteNode(10);
    list.display(); // Expected: 5->20->NULL

    std::cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << std::endl;

    return 0;
}