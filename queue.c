#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int front = -1, rear = -1, inp_array[SIZE];
void enqueue();
void dequeue();
void show();
int main()
{
    int choice;
    while (1)
    {
        printf("\nPerform operations on the queue:");
        printf("\n1.Enqueue the element\n2.Dequeue the element\n3.Show\n4.Size\n5.Max \n6.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
                switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
            case 4:
                printf("\nSize of the queue: %d\n", size());
                break;
            case 5:
                printf("\nMax Element: %d\n", findMax());
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!!");
        }
    }
}
void enqueue()
{
    int x;
    if (rear == SIZE - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added to the queue: ");
        scanf("%d", &x);
        if (front == -1)
            front = 0;
        rear = rear + 1;
        inp_array[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nDequeued element: %d", inp_array[front]);
        front = front + 1;
    }
}
void show()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty!!");
    }
    else
    {
        printf("\nElements present in the queue: \n");
        for (int i = front; i <= rear; i++)
            printf("%d\n", inp_array[i]);
    }
}

int size() {
    if (front == -1 || front > rear) {
        return 0;
    } else {
        return rear - front + 1;
    }
}

int findMax(){
     if (front == -1 || front > rear) {
        printf("\nQueue is empty!!");
        return 0;
    }
    int max = inp_array[front];
    for (int i = front + 1; i <= rear; i++) {
        if (inp_array[i] > max) {
            max = inp_array[i];
        }
    }
    return max;
}