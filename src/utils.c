#include "utils.h"

void slow_print(const char *str, float time){
    unsigned const int len = strlen(str);
    unsigned int delay = (time*1000/len);
    
    for (int i = 0; i < len; i++){
        _sleep(delay);
        printf("%c", str[i]);
    }
    printf("\n");
}
