void deleteNode(Node *node)
{

   Node* aux = node;
   while(aux->next->next != NULL){
       aux->data = aux->next->data;
       aux = aux->next;
   }
   aux->data = aux->next->data;
   aux->next = NULL;

}

//or (simplified)

/*
void deleteNode(Node *node){
    *node = *(node->next);
}
*/
