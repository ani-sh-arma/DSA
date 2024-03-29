import java.util.Scanner;

class Node {
    int data;
    Node next;
    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedList {
    Node head;
    LinkedList() {
        head = null;
    }

    void insertAtStart(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }

        Node current = head;
        while (current.next!= null) {
            current = current.next;
        }
        current.next = newNode;
    }

    void deleteAtStart() {
        if (head == null) {
            // List is empty, nothing to delete
            return;
        }
        Node temp = head;
        head = head.next;
        temp.next = null; // Detach the old head node from the list
    }

    void insertInSortedOrder(int data) {
        Node newNode = new Node(data);
        
        if (head == null || data < head.data) {
            newNode.next = head;
            head = newNode;
            return;
        }

        Node current = head;
        while (current.next != null && current.next.data < data) {
            current = current.next;
        }

        newNode.next = current.next;
        current.next = newNode;
    }

    void deleteNodeBeforeSpecifiedPosition(int position) {

        if (position <= 0 || head == null || head.next == null) {
            System.out.println("Invalid position");;
            return;
        }

        Node current = head;
        for (int i = 1; i < position - 1 && current.next != null ; i++) {
            current = current.next;
        }

        if (current.next == null) {
            System.out.println("Invalid position");
            return;
        }
        Node temp = current.next.next;
        current.next.next = null;
        current.next = temp;
    }

    void deleteNodeAfterSpecifiedPosition(int position) {

        if (position <= 0 || head == null || head.next == null) {
            System.out.println("Invalid position");;
            return;
        }

        Node current = head;
        for (int i = 1; i <= position && current.next != null ; i++) {
            current = current.next;
        }

        if (current.next == null) {
            System.out.println("Its the last node");
            return;
        }
        Node temp = current.next.next;
        current.next.next = null;
        current.next = temp;
        System.out.println(current.next.data + " deleted");
    }

    void printList() {
        Node current = head;
        while (current!= null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Choose the operation: ");
            System.out.println("1. Insert node at front");
            System.out.println("2. Insert node at rear");
            System.out.println("3. Insert node so list is in ascending order");
            System.out.println("4. Remove node at front");
            System.out.println("5. Remove node before specified position [ Counting starts from 0 ]");
            System.out.println("6. Remove node after specified position [ Counting starts from 0 ]");
            System.out.println("7. Display List");
            System.out.println("8. Exit");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the value to be inserted: ");
                    int frontValue = scanner.nextInt();
                    list.insertAtStart(frontValue);
                    break;
                case 2:
                    System.out.print("Enter the value to be inserted: ");
                    int rearValue = scanner.nextInt();
                    list.insertAtEnd(rearValue);
                    break;
                case 3:
                    System.out.print("Enter the value to be inserted: ");
                    int sortedValue = scanner.nextInt();
                    list.insertInSortedOrder(sortedValue);
                    break;
                case 4:
                    list.deleteAtStart();
                    break;
                case 5:
                    System.out.print("Enter the value to be inserted: ");
                    int beforeValue = scanner.nextInt();
                    list.deleteNodeBeforeSpecifiedPosition(beforeValue);
                    break;
                case 6:
                    System.out.print("Enter the value to be inserted: ");
                    int afterValue = scanner.nextInt();
                    list.deleteNodeAfterSpecifiedPosition(afterValue);
                case 7:
                    list.printList();
                    break;
                case 8:
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }
    }
}