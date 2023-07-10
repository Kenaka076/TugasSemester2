#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool kondisi_kosong() {
return front == -1 && rear == -1;
}

bool kondisi_penuh() {
return (rear + 1) % MAX_SIZE == front;  
}


void Enqueue() {
	if (kondisi_penuh()) {
		cout << "Queue sudah penuh" << endl;
		return;
	}
	
int val;
	cout << "Masukkan nilai yang ditambahkan: ";
	cin >> val;
		if (kondisi_kosong()) front = 0;
			rear = (rear + 1) % MAX_SIZE;
			queue[rear] = val;
			cout << "Nilai " << val << " berhasil ditambahkan ke dalam queue" << endl;
		}

void Dequeue() {
	if (kondisi_kosong()) {
		cout << "Queue kosong" << endl;
		return;
	}
	
	
int val = queue[front];
	if (front == rear) front = rear = -1;
		else front = (front + 1) % MAX_SIZE;
		cout << "Nilai " << val << " berhasil dihapus dari queue" << endl;
	}


void display() {
	if (kondisi_kosong()) {
		cout << "Tidak terdapat elemen pada queue" << endl;
		return;
		}
		
	cout << "Data elemen pada queue : " << endl;
	
int id = front;
	while (id != rear) {
		cout << id - front + 1 << "." << queue[id] << endl;
		id = (id + 1) % MAX_SIZE;
		}
		
cout << id - front + 1 << "." << queue[id] << endl;
}

int main() {
int menu;

	do	{

		display();
		cout << "Menu:" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Cek kondisi queue" << endl;
		cout << "0. Keluar" << endl;
		cout << "Pilih menu: ";
		cin >> menu;
		switch (menu) {
				
				case 1:
				Enqueue();
				break;
				
				case 2:
				Dequeue();
				break;
				
				case 3:
				if (kondisi_kosong()) {
				cout << "Queue kosong" << endl;
				}
				else if (kondisi_penuh()) {
				cout << "Queue penuh dengan " << MAX_SIZE << " elemen" << endl;
				}
				else {
				cout << "Jumlah elemen pada queue: " << (rear - front + MAX_SIZE) % MAX_SIZE + 1 << endl;
				}
				break;
				
				case 0:
				cout << "Berhasil Keluar Dari Program !" << endl;
				break;
			
			 
				default:
				cout << "Pilihan tidak tersedia" << endl;
				break;
			  	}
				cout << endl;
				} 
				while (menu != 0);
				
				return 0;
			}
