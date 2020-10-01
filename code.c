#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *prev;
struct node *link;
}aa;
aa *head,*p;
int i;

int begin();
void end();
void middle();
void insert();
int length();
void print();
void nstart();
void nend();
void searchk();
void searchi();
void deletek();
void deletei();
void deletelist();


int main(){
int m,a,n;
do{printf("\n0.Make linked list.\n1.Insert an element at beginning of the list.\n2.Insert an element at the end of the list.\n");
printf("3.Insert an element at a particular index position of the list.\n4.Delete an element from the list given the key.\n");
printf("5.Delete an element from the list given the index of the node.\n6.Search an element from the list given the key.\n");
printf("7.Delete the linked list.\n8.Search an element from the list given the index of the node.\n");
printf("9.Get the nth node of the list.\n10.Get the nth node from the end of the list.\n11.Count the number of nodes of the list.\n");
printf("12.Get the middle element of the list.\n13.Print the list.\n  -1 to exit\n");
scanf("%d",&n);
if(n==0){
    aa *temp=NULL;
    printf("enter no. of elements\n");
    scanf("%d",&m);
for(i=0;i<m;i++){
    temp=(aa*)malloc(sizeof(aa));
    printf("enter data\n");
    scanf("%d",&(temp->data));
    temp->link=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        p=head;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=temp;
        temp->prev=p;
    }
}
}

if(n==1){
    begin();
}
if(n==2){
    end();
}
if(n==3){
    insert();
}
if(n==4){
    deletek();
}
if(n==5){
    deletei();
}
if(n==6){
    searchk();
}
if(n==7){
    deletelist();
}
if(n==8){
    searchi();
}
if(n==9){
    nstart();
}
if(n==10){
    nend();
}
if(n==11){
    a=length();
    printf("%d\n",a);
}
if(n==12){
    middle();
}
if(n==13){
    print();
}
if(n==14){
    reverse();
}

}while(n!=-1);
return 0;
}
int begin(){
    aa *temp;
    aa *p=head;
    temp=(aa*)malloc(sizeof(aa));
    printf("enter element\n");
    scanf("%d",&(temp->data));
    temp->link=p;
    p->prev=temp;
    head=temp;
    return head;
}

void end(){
    aa *temp;
    if(length()==0){
        begin();
    }
    else{
    temp=(aa*)malloc(sizeof(aa));
    temp->link=NULL;
    printf("enter element\n");
    scanf("%d",&(temp->data));
    p=head;

    while(p->link!=NULL){
        p=p->link;
    }
        p->link=temp;
        temp->prev=p;
}
}

void insert(){
    int v;
    aa *temp,*q;
    temp=(aa*)malloc(sizeof(aa));
    printf("place of element\n");
    scanf("%d",&v);
    if(v==1){
        begin();
    }
    else{
    printf("enter element\n");
    scanf("%d",&(temp->data));
    p=head;
    for(i=0;i<v-2;i++){
        p=p->link;
    }
    q=p->link;
    temp->link=q;
    temp->prev=p;
    p->link=temp;
}
}
void deletek(){
    int o=0,k,c=length();
    aa *p=head,*t;
    aa *q=head;
    printf("enter the key\n");
    scanf("%d",&k);
    while(p->data!=k){
        p=p->link;
        o+=1;
        if(o>c){
            break;
        }
    }
    p=head;
    if(o==0){
        q=p->link;
        head=q;
        q->prev=NULL;
        free(p);
    }
    if(o<c-1 && o>0){
    while(o)
    {q=p;
    p=p->link;
    o--;}
    t=q->link;
    p=p->link;
    q->link=p;
    p->prev=q;
    free(t);
    }
    if(o==c-1){
    while(p->link!=NULL){
        p=p->link;
    }
    q=p;
    p=p->prev;
    p->link=NULL;
    free(q);
}
}

void deletei(){
int a,c=length(),o=0;
aa *p=head,*t;
aa *q=head;
printf("enter the index\n");
scanf("%d",&a);
if(a<=c)
    {
    if(a==1){
        q=p;
        head=p->link;
        p=p->link;
        p->prev=NULL;
        free(q);
}
if(a==c){
    while(p->link!=NULL){
        p=p->link;
    }
    q=p;
    p=p->prev;
    p->link=NULL;
    free(q);
}
else{
   while(a>1)
    {q=p;
    p=p->link;
    a--;}
    t=q->link;
    p=p->link;
    q->link=p;
    p->prev=q;
    free(t);
}
}
}


void deletelist()
{
   aa *current = head;
   aa *link;

   while (current != NULL)
   {
       link = current->link;
       free(current);
       current = link;
   }
    head = NULL;
}

void nstart(){
int k;
p=head;
printf("enter node no.\n");
scanf("%d",&k);
for(i=0;i<k-1;i++){
    p=p->link;
}
printf("\n%d\n",p->data);
}

void middle(){
aa *p=head;
int x=(length())/2;
while(x){
    p=p->link;
    x--;
    }
printf("\n%d\n",p->data);
}

void searchi(){
int k,c=length();
p=head;
printf("enter index\n");
scanf("%d",&k);
if(k>c){
    printf("error\n");
}
else{
for(i=0;i<k-1;i++){
    p=p->link;
}
printf("\n%d\n",p->data);
}
}

void searchk(){
int k,count=0,b=0,c=length();
p=head;
printf("enter key\n");
scanf("%d",&k);
while(b!=c){
    if(k==p->data){
        printf("\npresent\n");
        count+=1;
        break;
    }
    b+=1;
    p=p->link;
}
if(!count){
    printf("\nnot present\n");
}
}

void nend(){
int k,m,c=length();
p=head;
printf("enter node no.\n");
scanf("%d",&k);
m=c-k;
for(i=0;i<m;i++){
    p=p->link;
}
printf("\n%d\n",p->data);
}

int length(){
    int count=0;
    p=head;
    while(p!=NULL){
        count++;
        p=p->link;
    }
    return count;
}

void print(){
    p=head;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->link;
}
}
