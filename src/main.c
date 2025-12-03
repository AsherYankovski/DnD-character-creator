#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cJSON/cJSON.h>


/*typedef struct characteristic{
	char *name;
	int value;
	int mod;
} characteristic;
*/

void end_programm(const char *message){
	printf("Unfortunately prgramm was aborted: %s\n", message);
	exit(1);
}


const char *write_json_to_file(const char *json_str, const char *name){
	unsigned int n = strlen(name) + 5;
	
	char file_name[n];
	sprintf(file_name, "%s.json", name);

	FILE *file = fopen(file_name, "w");
	if (file == NULL){
		end_programm("unable to open this file");
	}

	printf("\nPrinting json data to file %s...\n", file_name);
	fputs(json_str, file);
	fclose(file);
	return json_str;
}


void write_characteristics(cJSON *file/*, unsigned int nums[6]*/){
	cJSON *characteristics = cJSON_CreateArray();
	char *names[6] = {"STR", "DEX", "CON", "INT", "WIS", "CHA"};
	cJSON_AddItemToObject(file, "Characteristics", characteristics);

	for (int i = 0; i < 6; i++){
		cJSON *blank = cJSON_CreateObject();
		int n = 0;

		printf("Wright %s value: ", names[i]);
		scanf("%d", &n);

		cJSON_AddNumberToObject(blank, names[i], n);

		cJSON_AddItemToArray(characteristics, blank);
	}
}


int main(){
	cJSON *json = cJSON_CreateObject();

	write_characteristics(json/*, chars*/);
	write_json_to_file(cJSON_Print(json), "data");

	cJSON_Delete(json);
	return 0;
}
