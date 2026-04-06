#include <stdio.h>

int main(int argc, char *argv[]){
	
	// initial check for number of arguments provided
	if (argc != 2){
		printf("usage: %s <file>\n", argv[0]);
		return 1;
	}
	
	// open the file with the filename argument provided 
	FILE *file = fopen(argv[1], "rb");
	
	if (file == NULL) {
		printf("Could not open file.\n");
		return 1;
	}
	
	// buffer 16 characters
	unsigned char buffer[16];
	size_t bytes_read;
	
	while ((bytes_read = fread(buffer,1,16,file)) > 0){
		printf("read %zu bytes\n", bytes_read);

		for (size_t i = 0; i < bytes_read;i++){
			printf("%02x ", buffer[i]);
		}
	}
	
	printf("\n");
	
	fclose(file);
	return 0;
}