#include<iostream>
#include<iomanip>

using namespace std;

typedef struct customer{
       char ID;
       int Arrival_Time;
       int Service_Time;
       struct customer* next;
}Customer;


// Global �ܼƫŧi 
Customer *newnode, *ptr, *first;


// ��l�� 
void init(){
       first = (Customer *)malloc(sizeof(Customer));
       ptr = first;
}

void isFull(){
}

//�P�_Queue�O���O�Ū� 
bool isEmpty(){
          if(first->next==NULL) return 1;
          else return 0;
}

//�s�WQueue���s���� 
void enqueue(char id, int arrival_time, int service_time){
        newnode = (Customer *)malloc(sizeof(Customer));
        newnode->ID = id;
        newnode->Arrival_Time = arrival_time;
        newnode->Service_Time = service_time;
        newnode->next = NULL;
        ptr->next = newnode;
        ptr = newnode;
}

//�R���̫e�������� 
Customer* dequeue(Customer* leave){           
        Customer* temp;
        temp = leave;
        first->next = leave->next;
        leave = leave->next;
        free(temp);
        if(!isEmpty()){
            return leave;
        }
        else
            return NULL;
}

float Run(){
     int time = 0;
     int count; //�H�� 
     int sum; //Waiting Time ���[�` 
     Customer* Teller;
     Teller = first->next; // Teller �A�ȲĤ@�ӤH 
     
     if(Teller!=NULL){
         time = Teller->Arrival_Time + Teller->Service_Time;
         Teller = dequeue(Teller);
         sum = 0;
         count = 1;
     }
     else return 0;
     
     while(Teller!=NULL){
         sum += time - Teller->Arrival_Time;
         time += Teller->Service_Time;
         count++;
         Teller = dequeue(Teller);
     }
     
     return (float)sum / count;
     
}

void Show(float num){
     cout << setprecision(2) << "Average Waiting Time = " << num << endl;
}

int main(){
    init();
    FILE *op;
    fopen_s (&op, "input.txt" , "r");
	if (op == NULL)
	{
		cout << "Error: failed to open input.txt" << endl;
		system("pause");
		return 0;
	}

    char id;
    int arrival_time;
    int service_time;
    float average_waiting_time;
    
    //���J��Ƭ� 3 ���� Ū�J��� 
    while(fscanf_s(op, "%c %d %d\n", &id, 1, &arrival_time, &service_time)==3){
          enqueue(id, arrival_time, service_time);
          printf("%c %d %d\n", id, arrival_time, service_time);
    };
    
    //�]�{�� 
    average_waiting_time = Run();
    
    //Show�XWaiting_time���T�� 
    Show(average_waiting_time);
    
    fclose(op);
    system("pause");
}
