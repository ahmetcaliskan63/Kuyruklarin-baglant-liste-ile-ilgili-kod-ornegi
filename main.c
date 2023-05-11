#include <stdio.h>
#include <stdlib.h>

// Kuyru�un d���m yap�s� node(yaprak) dir.
struct Node {
    int data;//veriyi int olarak tan�mlad�m.
    struct Node* next;
};

// Kuyruk s�n�f� fonkusyonu tan�mlad�m.
struct Queue {
    struct Node *front, *rear;
};

// Kuyruk olu�turma fonksiyonu a�a��da verilmi�tir.
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

/* Kuyru�a eleman ekleme fonksiyonu enqueue dir ve a�a��daki
 kod par�as�nda uygulanm��t�r.*/
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

/* Kuyruktan eleman silme fonksiyonu dequeuedir.ve a�a��daki
 kod par�as�nda uygulanm��t�r.*/
void dequeue(struct Queue* q) {
    if (q->front == NULL)
        return;

    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Kuyruktaki elemanlar� ekrana yazd�rma fonksiyonu.
void display(struct Queue* q) {
    if (q->front == NULL)
        return;

    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Ana fonksiyon yukarda tan�mlad���m�z fonkusyonlar� burada �a��r�yoruz.
//switch case ile i�lemler se�iliyor.
// do while d�ng�s� ile birden fazla i�lem d�nd�r�r.
int main() {
    struct Queue* q = createQueue();
    int choice, value;

    do {
        printf("\nKuyruk veri yapisi programi istediginiz islemi secin\n");
        printf("1. Eleman Ekleme\n");
        printf("2. Eleman Silme\n");
        printf("3. Elemanlari Goster\n");
        printf("0. Cikis\n");
        printf("Secim: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklenecek elemani girin: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                printf("Kuyruktaki elemanlar: ");
                display(q);
                break;

            case 0:
                printf("Program sonlandiriliyor...\n");
                break;

            default:
                printf("Gecersiz secim!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
