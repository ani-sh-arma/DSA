import java.util.Scanner;

public class QueueImplementation {
    public static void main(String[] args) {
        Queue queue = new Queue(10);
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Choose the operation: ");
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the value to be inserted: ");
                    int value = scanner.nextInt();
                    queue.enqueue(value);
                    break;
                case 2:
                    int dequeuedValue = queue.dequeue();
                    if (dequeuedValue != -1) {
                        System.out.println("Dequeued value: " + dequeuedValue);
                    }
                    break;
                case 3:
                    queue.display();
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

class Queue {
    private int[] queue;
    private int front;
    private int rear;
    private int size;
    private int maxSize;

    public Queue(int size) {
        this.queue = new int[size];
        this.front = -1;
        this.rear = -1;
        this.size = 0;
        this.maxSize = size;
    }

    void enqueue(int value) {
        if (size == maxSize) {
            System.out.println("Overflow");
            return;
        }

        if (rear == maxSize - 1) {
            rear = 0; // Wrap around to the beginning of the queue
        } else {
            rear++;
        }

        queue[rear] = value;
        if (front == -1) {
            front = 0; // Set the front index when the queue was initially empty
        }
        size++;
        System.out.println("Value inserted successfully");
    }

    int dequeue() {
        if (size == 0) {
            System.out.println("Underflow");
            return -1;
        }

        int dequeuedValue = queue[front];

        if (front == maxSize - 1) {
            front = 0; // Wrap around to the beginning of the queue
        } else {
            front++;
        }

        size--;
        return dequeuedValue;
    }

    void display() {
        if (size == 0) {
            System.out.println("Queue is empty");
            return;
        }

        int i = front;
        for (int j = 0; j < size; j++) {
            System.out.print(queue[i] + " ");
            i = (i + 1) % maxSize; // Wrap around if i reaches the end of the queue
        }
        System.out.println();
    }
}