#ifndef __CLASSS_CREATOR_H
#define __CLASSS_CREATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cJSON.h>

#define MAX_NAME_LEN 16
#define MAX_DESCRIPTION_LEN 2048
#define MAX_INPUT_LEN 64

/* Добваление имени и создание объекта, в котором хранится класс */
cJSON *add_name(cJSON *object);

/* Добавление кости хитов */
void add_hit_dice(cJSON *object);

/* Функция, задающая вопрос, на который принимается ответ "Да" или "Нет"
 * Возвращает 0 или 1 в зависимости от ответа ползователя. По умолчанию возвращает 0 */
bool ask_YN(char *message);


/* Блок добавления различных владений */
/*-------------------------------------------*/

/* Владение бронёй */
void add_armor_proficencies(cJSON *object);

/* Владение оружием */
void add_weapon_proficencies(cJSON *object);

/* Владение инструментами */
void add_tool_proficencies(cJSON *object);

/* Владение спасбросками */
void add_SavingThrows_proficencies(cJSON *object);

/* Владение навыками */
void add_skill_proficencies(cJSON *object);

/* Добавление всех владений к объекту персонажа */
void add_proficiencies(cJSON *object);
/*-------------------------------------------*/


/*-------------------------------------------*/
/* функция добаления одной позиции выбра снаряжения */
void add_list(cJSON *array);


/* Функция добавления снаряжения, которое получает класс по умолчанию */
void add_equipment(cJSON *object);
/*-------------------------------------------*/


/* Добавление объекта, содержащего класс.
 * Заполнение информации о классе */
cJSON *add_class(cJSON *object);

#endif
