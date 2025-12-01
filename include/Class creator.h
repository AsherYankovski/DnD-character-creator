#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

#define NAME_MAX_LEN 16
#define MAX_INPUT_LEN 64

char buffer = '\0';

/* Добваление имени и создание объекта, в котором хранится класс */
cJSON *add_name(cJSON *object){
	char name[NAME_MAX_LEN] = {'\0'};

	printf("Enter new class name: ");
	scanf("%[^\n]%*c", name);
	return cJSON_AddObjectToObject(object, name);
}

/* Добавление кости хитов */
void add_hit_dice(cJSON *object){
	unsigned int value;

	printf("Enter hit point dice value: ");
	scanf("%u", &value);
	scanf("%c", &buffer);

	cJSON_AddNumberToObject(object, "Hit Point Dice", value);
}

/* Функция, задающая вопрос, на который принимается ответ "Да" или "Нет"
 * Возвращает 0 или 1 в зависимости от ответа ползователя. По умолчанию возвращает 0 */
bool ask_YN(char *message){
	while(1){
		char input[8] = {'\0'};
		char choice = 'N';

		printf("%s y\\N ", message);
		scanf("%[^\n]%*c", input);

		if (input[0] == '\0'){
			scanf("%c", &buffer);
		}else{
			choice = input[0];
		}

		if(choice == 'Y' || choice == 'y'){
			return 1;
		}else if(choice == 'N' || choice == 'n'){
			return 0;
		}
	
		printf("Try again\n");
	}
}


/* Блок добавления различных владений */
/*-------------------------------------------*/
/* Владение бронёй */
void add_armor_proficencies(cJSON *object){
	printf("\nAdd armor proficencies\n");

	cJSON *armor = cJSON_AddObjectToObject(object, "Armor");
	char string[MAX_INPUT_LEN] = {'\0'};

/* Блок кода, отвечающий за наличие выбора
	bool variability = ask_YN("Dose armor proficencies variability?");
	cJSON_AddBoolToObject(armor, "Choice", variability);
	if (variability){
		unsigned int variants = 0;
		printf("How many proficency variants player should choose? ");
		scanf("%u", &variants);
		scanf("%c", &buffer);
		cJSON_AddNumberToObject(armor, "Number of variants", variants);
	}
*/

	cJSON *array = cJSON_AddArrayToObject(armor, "Values");

	printf("Enter armor proficencies.\n");
	printf("Every proficency shuld place from new line, end of list mark as string from 0.\n");
	bool scan = scanf("%[^\n]%*c", string);

	while (string[0] != '0'){	
		if (scan){
			cJSON *strobject = cJSON_CreateString(string);
			cJSON_AddItemToArray(array, strobject);
		}else{
			printf("No such armor bro...\n");
			scanf("%c", &buffer);
		}
		scan = scanf("%[^\n]%*c", string);
	}

}

/* Владение оружием */
void add_weapon_proficencies(cJSON *object){
	printf("\nAdd weapoon proficencies\n");

	cJSON *weapoon = cJSON_AddObjectToObject(object, "Weapoon");
	char string[MAX_INPUT_LEN] = {'\0'};

/* Блок кода, отвечающий за наличие выбора
	bool variability = ask_YN("Dose weapoon proficencies variability?");
	cJSON_AddBoolToObject(weapoon, "Choice", variability);
	if (variability){
		unsigned int variants = 0;
		printf("How many proficency variants player should choose? ");
		scanf("%u", &variants);
		scanf("%c", &buffer);
		cJSON_AddNumberToObject(weapoon, "Number of variants", variants);
	}
*/

	cJSON *array = cJSON_AddArrayToObject(weapoon, "Values");

	printf("Enter weapoon proficencies.\n");
	printf("Every proficency shuld place from new line, end of list mark as string from 0.\n");
	bool scan = scanf("%[^\n]%*c", string);

	while (string[0] != '0'){	
		if (scan){
			cJSON *strobject = cJSON_CreateString(string);
			cJSON_AddItemToArray(array, strobject);
		}else{
			printf("No such type bro...\n");
			scanf("%c", &buffer);
		}
		scan = scanf("%[^\n]%*c", string);
	}

}

/* Владение инструментами */
void add_tool_proficencies(cJSON *object){
	printf("\nAdd tools proficencies\n");

	cJSON *tool = cJSON_AddObjectToObject(object, "Tools");
	char string[MAX_INPUT_LEN] = {'\0'};

	bool variability = ask_YN("Dose tool proficencies variability?");
	cJSON_AddBoolToObject(tool, "Choice", variability);
	if (variability){
		unsigned int variants = 0;
		printf("How many proficency variants player should choose? ");
		scanf("%u", &variants);
		scanf("%c", &buffer);
		cJSON_AddNumberToObject(tool, "Number of variants", variants);
	}

	cJSON *array = cJSON_AddArrayToObject(tool, "Values");

	printf("Enter tool proficencies.\n");
	printf("Every proficency shuld place from new line, end of list mark as string from 0.\n");
	bool scan = scanf("%[^\n]%*c", string);

	while (string[0] != '0'){	
		if (scan){
			cJSON *strobject = cJSON_CreateString(string);
			cJSON_AddItemToArray(array, strobject);
		}else{
			printf("No such tool bro...\n");
			scanf("%c", &buffer);
		}
		scan = scanf("%[^\n]%*c", string);
	}

}

/* Владение спасбросками */
void add_SavingThrows_proficencies(cJSON *object){
	printf("\nAdd saving throws proficencies\n");

	cJSON *SavingThrows = cJSON_AddObjectToObject(object, "Saving throws");
	char string[MAX_INPUT_LEN] = {'\0'};

/* Блок кода, отвечающий за наличие выбора
	bool variability = ask_YN("Dose saving throws proficencies variability?");
	cJSON_AddBoolToObject(Saving throws, "Choice", variability);
	if (variability){
		unsigned int variants = 0;
		printf("How many proficency variants player should choose? ");
		scanf("%u", &variants);
		scanf("%c", &buffer);
		cJSON_AddNumberToObject(SavingThrows, "Number of variants", variants);
	}
*/

	cJSON *array = cJSON_AddArrayToObject(SavingThrows, "Values");

	printf("Enter saving throw proficencies.\n");
	printf("Every proficency shuld place from new line, end of list mark as string from 0.\n");
	bool scan = scanf("%[^\n]%*c", string);

	while (string[0] != '0'){	
		if (scan){
			cJSON *strobject = cJSON_CreateString(string);
			cJSON_AddItemToArray(array, strobject);
		}else{
			printf("No such throw bro...\n");
			scanf("%c", &buffer);
		}
		scan = scanf("%[^\n]%*c", string);
	}
}

/* Владение навыками */
void add_skill_proficencies(cJSON *object){
	printf("\nAdd skills proficencies\n");

	cJSON *skill = cJSON_AddObjectToObject(object, "Skills");
	char string[MAX_INPUT_LEN] = {'\0'};

	bool variability = ask_YN("Dose skill proficencies have variability?");
	cJSON_AddBoolToObject(skill, "Choice", variability);
	if (variability){
		unsigned int variants = 0;
		printf("How many proficency variants player should choose? ");
		scanf("%u", &variants);
		scanf("%c", &buffer);
		cJSON_AddNumberToObject(skill, "Number of variants", variants);
	}

	cJSON *array = cJSON_AddArrayToObject(skill, "Values");

	printf("Enter skill proficencies.\n");
	printf("Every proficency shuld place from new line, end of list mark as string from 0.\n");
	bool scan = scanf("%[^\n]%*c", string);

	while (string[0] != '0'){	
		if (scan){
			cJSON *strobject = cJSON_CreateString(string);
			cJSON_AddItemToArray(array, strobject);
		}else{
			printf("No such skill bro...\n");
			scanf("%c", &buffer);
		}
		scan = scanf("%[^\n]%*c", string);
	}
}

/* Добавление всех владений к объекту персонажа */
void add_proficiencies(cJSON *object){
	cJSON *proficencies = cJSON_AddObjectToObject(object, "Proficencies");

	printf("\n\nAdd poficiences\n");
	add_armor_proficencies(proficencies);
	add_weapon_proficencies(proficencies);
	add_tool_proficencies(proficencies);
	add_SavingThrows_proficencies(proficencies);
	add_skill_proficencies(proficencies);
}
/*-------------------------------------------*/


/*-------------------------------------------*/
/* Функция добаления .элемента позиции */
bool add_item(cJSON *array){
	printf("Write item name\n");
	char string[MAX_INPUT_LEN*2 + 3] = {'\0'};
	char name[MAX_INPUT_LEN] = {'\0'};

	scanf("%[^\n]%*c", name);

	bool expl = ask_YN("Add comment?");
	if (expl){
		char comment[MAX_INPUT_LEN] = {'\0'};

		scanf("%[^\n]%*c", comment);
		sprintf(string, "%s (%s)", name, comment);
	}else{
		sprintf(string, "%s", name);
	}

	cJSON *item = cJSON_CreateString(string);
	cJSON_AddItemToArray(array, item);
}


/* функция добаления одной позиции выбра снаряжения */
void add_position(cJSON *array){
	printf("Add equipment position to eqiupment list.\n");
	cJSON *position = cJSON_CreateObject();
	cJSON_AddItemToArray(array, position);

	bool variability = ask_YN("Dose this position have variability?");
	cJSON_AddBoolToObject(position, "Choice", variability);

	cJSON *values = cJSON_AddArrayToObject(position, "Values");

	add_item(values);
	while(ask_YN("Add new item?")){
		add_item(values);
	}
}


/* Функция добавления снаряжения, которое получает класс по умолчанию */
void add_equipment(cJSON *object){
	printf("\n\nAdd equipment to class.\n");
	
	cJSON *equipment = cJSON_AddArrayToObject(object, "Equipment");

	add_position(equipment);
	while(ask_YN("Add new position?")){
		add_position(equipment);
	}
}
/*-------------------------------------------*/


/* Добавление объекта, содержащего класс.
 * Заполнение информации о классе */
cJSON *add_class(cJSON *object){
	cJSON *class = add_name(object);

	add_hit_dice(class);
	add_proficiencies(class);
	add_equipment(class);

	return class;
}