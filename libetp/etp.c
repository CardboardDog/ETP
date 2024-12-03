/*

    LIB ETP (c) 2024 EN
    VERSION 1.0
    THIS FILE IS UNDER THE MIT LICENSE
    https://github.com/CardboardDog/ETP/blob/main/LICENSE

*/

#include<etp.h>

etp_base* etp_create_base(){
    return (etp_base*)malloc(sizeof(etp_base));
}

etp_result etp_load(etp_base* dst, FILE* file){
    if(!file)
        return ETP_NULL;

    unsigned char header[7];
    fgets(header,7,file);

    if(strncmp(header,"etp",3)!=0)
        return ETP_WRONG_FORMAT;
    if(!header[3]==ETP_VERSION)
        return ETP_UNSUPPORTED;

    if((!header[4])|(!header[5])){
        dst->w = 0;
        dst->h = 0;
        return ETP_EMPTY;
    }

    dst->w = header[4];
    dst->h = header[5];

    dst->p = calloc(header[4]*header[5]*4,sizeof(char));

    fseek(file,6,SEEK_SET);
    fread(dst->p,sizeof(char),header[4]*header[5]*4,file);

    return ETP_LOADED;
}

etp_result etp_loads(etp_base* dst, const char* file){
    FILE* f_file = fopen(file,"r");
    etp_result ret = etp_load(dst,f_file);
    if(f_file)
        fclose(f_file);
    return ret;
}

void etp_print_error(etp_result error){
    if(error == ETP_WRONG_FORMAT)
        printf("file is not an etp");
    if(error == ETP_EMPTY)
        printf("file has a width or height of null");
    if(error == ETP_UNSUPPORTED)
        printf("file is an unsupported version");
    if(error == ETP_LOADED)
        printf("file loaded successfully");
    if(error == ETP_BAD)
        printf("dst pointer is invalid");
    if(error == ETP_NULL)
        printf("file is invalid");
}

void etp_free(etp_base* ptr){
    if(ptr){
        if(ptr->p)
            free(ptr->p);
        free(ptr);
    }
    ptr = (etp_base*)NULL;
}