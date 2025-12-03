#include <cJSON.h>

#define MAX_NAME_LEN 16

char buffer = '\0';


/* Добавление имени расы */
void add_name(cJSON *object){
	char name[MAX_NAME_LEN] = {'\0'};

	printf("Enter new race name: ");
	if (scanf("%[^\n]%*c", name)){
		scanf("%c", buffer);
		printf("No empty names allowed!\n");
		printf("Enter new class name: ");
	}

	return cJSON_AddObjectToObject(object, name);
}





/* Добавление объекта, содержащего расу
 * Заполнение информации о расе */
cJSON *add_race(cJSON *object){
	cJSON *race = add_name(object);

	
}