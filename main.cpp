#include <iostream>

struct ListNode {
    int val;
    ListNode *next_;
    ListNode() : val(0), next_(nullptr) {}
    ListNode(int x) : val(x), next_(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next_(next) {}

    ~ListNode() {
        delete next_;
    }

    friend ListNode add_two_linked_numbers(ListNode *l1, ListNode *l2) {
        ListNode result;
        ListNode *presult = &result;
        while (l1 && l2){
            if(presult->val + l1->val + l2->val < 10){
                presult->val = presult->val + l1->val + l2->val;
                presult->next_ = new ListNode;
                presult = presult->next_;
                l1 = l1->next_;
                l2 = l2->next_;
            }else{
                presult->val = presult->val + l1->val + l2->val - 10;
                presult->next_ = new ListNode;
                presult = presult->next_;
                presult->val += 1;
                l1 = l1->next_;
                l2 = l2->next_;
            }

            if(!l1){
                while (l2){
                    if(presult->val + l2->val < 10){
                        presult->val = presult->val + l2->val;
                        presult->next_ = new ListNode;
                        presult = presult->next_;
                        l2 = l2->next_;
                    }else{
                        presult->val = presult->val + l2->val - 10;
                        presult->next_ = new ListNode;
                        presult = presult->next_;
                        l2 = l2->next_;
                    }
                }
            }

            if(!l2){
                while (l1){
                    if(presult->val + l1->val < 10){
                        presult->next_ = new ListNode;
                        presult = presult->next_;
                        l1 = l1->next_;
                    }else{
                        presult->val = presult->val + l1->val - 10;
                        presult->next_ = new ListNode;
                        presult = presult->next_;
                        presult->val += 1;
                        l1 = l1->next_;
                    }
                }
            }
        }
        return result;
    }

};

void ListPrint(ListNode *somelist) {
    std::cout << "[";
    while (somelist) {
        std::cout << somelist->val;
        somelist = somelist->next_;
        if (somelist) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    ListNode l1(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode l2(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    ListNode res = add_two_linked_numbers(&l1, &l2);
    ListPrint(&res);
}
