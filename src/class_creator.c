#include "class_creator.h"

char buffer = '\0';

cJSON *add_name(cJSON *object){
    char name[MAX_NAME_LEN] = {'\0'};

    printf("Enter new class name: ");
    scanf("%[^\n]%*c", name);
    return cJSON_AddObjectToObject(object, name);
}

void add_hit_dice(cJSON *object){
    unsigned int value;

    printf("Enter hit point dice value: ");
    scanf("%u", &value);
    scanf("%c", &buffer);

    cJSON_AddNumberToObject(object, "Hit Point Dice", value);
}

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

void add_proficiencies(cJSON *object){
    cJSON *proficencies = cJSON_AddObjectToObject(object, "Proficencies");

    printf("\n\nAdd poficiences\n");
    add_armor_proficencies(proficencies);
    add_weapon_proficencies(proficencies);
    add_tool_proficencies(proficencies);
    add_SavingThrows_proficencies(proficencies);
    add_skill_proficencies(proficencies);
}

void add_list(cJSON *array){

    cJSON *list = cJSON_CreateObject();
    cJSON_AddItemToArray(array, list);
    char string[MAX_INPUT_LEN] = {'\0'};

    bool variability = ask_YN("Dose this list have varaiti?");

    cJSON_AddBoolToObject(list, "Choice", variability);
    cJSON *values = cJSON_AddArrayToObject(list, "Values");

    while (1){
        if (!scanf("%[^\n]%*c", string)){
            scanf("%c", &buffer);
        }

        if(string[0] == '0'){
            return;
        }
    cJSON *item = cJSON_CreateString(string);
    cJSON_AddItemToArray(values, item);
    }
}

void add_equipment(cJSON *object){
    printf("\n\nAdd equipment to class.\n");
    
    cJSON *equipment = cJSON_AddArrayToObject(object, "Equipment");

    add_list(equipment);
    printf("\n");
    while(ask_YN("Add new position?")){
        add_list(equipment);
        printf("\n");
    }
}

cJSON *add_class(cJSON *object){
    cJSON *class = add_name(object);

    add_hit_dice(class);
    add_proficiencies(class);
    add_equipment(class);

    return class;
}
