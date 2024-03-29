import java.util.Scanner;

class Node{
    int data;
    Node left;
    Node right;

    Node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class BinarySearchTree {
    Node root;

    BinarySearchTree() {
        this.root = null;
    }

    public void insert(int data) {
        root = insertNodeRecursive(root, data);
    }

    private Node insertNodeRecursive(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }
        if (data < node.data) {
            node.left = insertNodeRecursive(node.left, data);
        } else if (data > node.data) {
            node.right = insertNodeRecursive(node.right, data);
        } else {
            System.out.println("Its a duplicate value");
        }
        return node;
    }

    public void traversal() {
        inorderTraversalRecursive(root);
    }

    private void inorderTraversalRecursive(Node node) {
        if (node != null) {
            inorderTraversalRecursive(node.left);
            System.out.print(node.data + " ");
            inorderTraversalRecursive(node.right);

        }
    }

    public boolean search(int data) {
        return searchNodeRecursive(root, data);
    }

    private boolean searchNodeRecursive(Node node, int data) {
        if (node == null) {
            return false;
        }
        if (node.data == data) {
            return true;
        }
        return data < node.data
            ? searchNodeRecursive(node.left, data) 
            : searchNodeRecursive(node.right, data);
    }

    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("Choose the operation: ");
            System.out.println("1. Insert a value");
            System.out.println("2. Search a value");
            System.out.println("3. Traversal");
            System.out.println("4. Exit");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the value to be inserted: ");
                    int frontValue = scanner.nextInt();
                    tree.insert(frontValue);
                    break;
                case 2:
                    System.out.print("Enter the value : ");
                    int searchValue = scanner.nextInt();
                    if (tree.search(searchValue)) {
                        System.out.println("Value Found");
                    } else {
                        System.out.println("Value Not found");
                    }
                    break;
                case 3:
                    tree.traversal();
                    System.out.println();
                    break;
                case 4:
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }
    }
}
