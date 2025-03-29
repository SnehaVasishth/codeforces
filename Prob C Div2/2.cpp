Node * solve(Node* head){
    Node* prev=head;
    Node* temp=head->next;
    Node* act=head;
    int sum=0;
    while(temp!=NULL){
        if(temp->val!=0){
            sum+=(temp->val);
        }
        else if(temp->val==0){
            temp->val=sum;
            sum=0;
            act->next=temp;
            act=temp;
        }
        temp=temp->next;

    }
    return prev->next;
}