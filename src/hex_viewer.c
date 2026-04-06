#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	
	// initial check for number of arguments provided
	if (argc != 2){
		printf("usage: %s <file>\n", argv[0]);
		return 1;
	}
	
	// open the file with the filename argument provided 
	FILE *file = fopen(argv[1], "rb");
	
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}
	
	// buffer 16 characters
	unsigned char buffer[16];
	size_t bytes_read;
	unsigned int offset =0;
	
	while ((bytes_read = fread(buffer,1,16,file)) > 0){
		printf("%08x  ", offset);		
		for (size_t i = 0; i < bytes_read;i++){
			printf("%02x ", buffer[i]);
		}
		
		// pad missing bytes
		for (size_t i = bytes_read; i < 16; i++) {
			printf("   ");
		}
		
		printf(" |");

        for (size_t i = 0; i < bytes_read; i++) {
            if (isprint(buffer[i])) {
                printf("%c", buffer[i]);
            } else {
				printf(".");
			}
		}
		printf("|\n");
		offset += bytes_read;
	}
	

	
	fclose(file);
	return 0;
}