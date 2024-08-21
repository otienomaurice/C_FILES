#include <stdio.h>
#include <stdlib.h>
#define SIZE 100	
//#ifdef EXIT_FAILURE 
//#undef EXIT_FAILURE 
//#endif
//#define EXIT_FAILURE 1 //((void *) 0)
int main(){
		char buffer[SIZE];
	FILE *gcc_vstring;
	FILE *gcc_v;
	gcc_v = popen("gcc -v", "r");
	if(gcc_v == NULL){
		perror("gcc -v script failure");
		return EXIT_FAILURE;
	}
gcc_vstring = fopen("gcc_v.txt","w");
while(fgets(buffer,SIZE,gcc_v) != NULL)
 fputs(buffer,gcc_vstring);
 fclose(gcc_v);
 fclose(gcc_vstring);
 pclose(gcc_v);
return 0;
}