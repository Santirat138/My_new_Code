public class DataStruct_OpenHash{
    public static void main(String[] args) {
        LinkedList[] array = new LinkedList[5];  // Create an array of LinkedLists.

        for (int i = 0; i < array.length; i++) {
            array[i] = new LinkedList();  // Initialize each element of the array.
        }

        array[0].add(1);  // Add nodes to the linked list at index 0.
        array[0].add(2);
        array[0].add(3);

        Node currentNode = array[0].head;  // Get the head of the linked list at index 0.

        while (currentNode != null) {  // Print the nodes of the linked list at index 0.
            System.out.print(currentNode.data + " ");
            currentNode = currentNode.next;
        }
    }
}
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    void add(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }
}
