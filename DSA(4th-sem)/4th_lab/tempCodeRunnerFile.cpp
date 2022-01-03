    void deleteAtStart()
    {
        if (start==NULL){
            cout<<"List Empty."<<endl;
            return;
        }
        if (end==start){
            delete start;
            start=end=NULL;
            return;
        }
        node<T> *temp = start;
        start = start->next;
        end->next = start;
        cout << "Deleted item: " << temp->data << endl;
        delete temp;
    }