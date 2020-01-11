#include <stdio.h>

#include <stdlib.h> 




int runLengthCompressWOAppend(char* data_ptr[], int data_size){
	if (data_size == 0) return 0;  

	int nomCount;  // the occurrence of a number/value
	
	char* dest=(char*)malloc(sizeof(char)*(2*data_size));	// creating array of double size original,
															// if all numbers are different in original array compression 
															//would generate a double sized array 
	
	int newIndex=0;
	
	// traversing the original array 
	for(int i=0; i<data_size; i++){
		
		char temp=(*data_ptr)[i]; // occurrence of new number copied from original array
		
		
		// counting number of occurrences of the new number 
		nomCount=1;
		while(i+1<data_size && temp==(*data_ptr)[i+1]){
			nomCount++;
			i++;
		}
		
		
		dest[newIndex]=nomCount;			// saving the count and value
		dest[newIndex+1]=temp;
		newIndex+=2;
		
	}
	free(*data_ptr);		// freeing and reassigning pointers
	*data_ptr=dest;
	return newIndex;
}

int runLengthDecompressWOAppend(char* data_ptr[], int data_size){
	int newSize=0;		// calculating the data size of the to be decompressed Array
	
	for(int i=0; i<data_size;i+=2){
		newSize+=(*data_ptr)[i];
	}
 
	
    char* temp = (char*)malloc(newSize*sizeof(char));
	char *tempLocation=temp;
	for(int i=0; i<data_size;i+=2){
		int count=(*data_ptr)[i];			// reading the count of that certain number
		
		int counter=0;
		while(counter<count){			// writing the number withs its occurrences into the new array
			*temp=(*data_ptr)[i+1];
			counter++;
			temp++;
		}

		
	}
	  
	free(*data_ptr);		// freeing and reassigning pointers
	*data_ptr = tempLocation;
	return newSize;
	
	
}


void printArr(char data_ptr[], int data_size) {

  for (int i = 0; i < data_size; i++) 

    printf("%hhx ", data_ptr[i]);

  printf("\n");

}

int main() {

  // printf() displays the string inside quotation

  char data_ptr_original[] = { 0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64, 

                      0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,

                      0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09 };

  int data_size = 24;

  char* data_ptr = (char*)malloc(sizeof(char)*data_size);

  for(int i=0;i<data_size;i++) data_ptr[i] = data_ptr_original[i];



  printArr(data_ptr, data_size);

  

  data_size = runLengthCompressWOAppend(&data_ptr, data_size);

  printArr(data_ptr, data_size);

  printf("Compress Size: %d\n", data_size);



  data_size = runLengthDecompressWOAppend(&data_ptr, data_size);

  printArr(data_ptr, data_size);

  printf("Decompress Size: %d\n", data_size);



  printf("End\n");

  return 0;

}

