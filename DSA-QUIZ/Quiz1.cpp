// Write a function DisplayAll() which should print the address of each node and the value stored in each node.
void DisplayAll()
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << "Address of node: " << current << ", Value: " << current->data << std::endl;
        current = current->next;
    }
}
// Write a function swap for a linked list of type float that should swap the values of the first and last node.
void swap()
{
    // Ensure the list has at least two nodes to swap
    if (head == nullptr || head->next == nullptr)
        return;

    Node *first = head;
    Node *last = head;

    // Traverse to the last node
    while (last->next != nullptr)
    {
        last = last->next;
    }

    // Swap the data between the first and last nodes
    float temp = first->data;
    first->data = last->data;
    last->data = temp;
}
