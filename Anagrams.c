#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info{
    char* data;
    struct info* next;
};

void addHash(char word[],info** array,int size);
int getHash(char word[],int size);
bool checkAnagram(char a[100],char b[100]);

int main(){
    FILE* ptrInputFile = fopen("input.txt","r");
    FILE* ptrQueryFile = fopen("query.txt","r");
    FILE* ptrOutputFile = fopen("anagram.txt","w");

    int size;
    scanf("%d",&size);

    struct info* array[size];
    for (int i = 0; i < size; i++) {
        array[i] = NULL;
    }
    
    char buff[100];
    while(fscanf(ptrInputFile,"%s",buff)!=EOF){
        addHash(buff,array,size);
    }

    char queryString[100];
    while(fscanf(ptrQueryFile,"%s",queryString)!=EOF){
        int hashValue = getHash(queryString,size);
        struct info* temp = (struct info*)malloc(sizeof(struct info));
        temp = array[hashValue];
        while(temp!=NULL){
            if(checkAnagram(queryString,temp->data)){
                fprintf(ptrOutputFile,"%s ",temp->data);
            } 
            temp = temp->next;
        }
        fprintf(ptrOutputFile,"\n");
    }
    fclose(ptrInputFile);
    fclose(ptrOutputFile);
    fclose(ptrQueryFile);

    return 0;
}

void addHash(char word[100],info** array,int size){
    int x = getHash(word,size);
    
    struct info* newHead = (struct info*)malloc(sizeof(struct info));

    // Allocate memory for the data field
    newHead->data = (char*)malloc(100 * sizeof(char));
    // Copy the word into the data field
    strcpy(newHead->data, word);

    newHead->next = NULL;
    newHead->next = array[x];
    array[x] = newHead; 
}

int getHash(char word[],int size){
    int sum = 0;
    for(int i=0;i<strlen(word);i++){
        int asciiValue = word[i];
        sum = sum + asciiValue;
    }

    return sum%size;
}

bool checkAnagram(char a[100],char b[100]){
    if (strlen(a) != strlen(b)) {
        return false;
    }

    int i = 0;
    int freq_a[26] = {0};
    int freq_b[26] = {0};
    // storing frequency of each character in freq arrays of two different strings.
    for (i = 0; a[i] && b[i]; i++) {
        freq_a[a[i] - 97]++;
        freq_b[b[i] - 97]++;
    }
    // if the number of occurrences of all characters is same return true else, returns false.
    for (i = 0; i < 26; i++) {
        if (freq_a[i] != freq_b[i]) {
            return false;
        }
    }

    return true;
}