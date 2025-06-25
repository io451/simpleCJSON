#include "sJS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if (sJSON_MAJOR_VERSION != 0 || sJSON_MINOR_VERSION != 1 || sJSON_PATCH_VERION != 0)
    #error sJSON.c and sJSON.h have a different versions. Please get a correct version of sJSON
#endif


#ifdef __cplusplus
    #error sJSON support only C language.
#endif

int sJSGetNumberValue(const char *filename, const char *block, const char *value)
{
    if (!filename || !block || !value) return -1;

    FILE *f = fopen(filename,"rb");

    if(!f)
    {
        printf("[sJSON] Unable to open %s, file do not exist or filepath is wrong\n",filename);
        return -1;
    }

    fseek(f,0,SEEK_END);
    long filesize = ftell(f);
    rewind(f);

    char *buffer = malloc(filesize + 1);
    if(!buffer)
    {
        return -1;
    }

    size_t read = fread(buffer,sizeof(char),filesize,f);
    if(read != filesize) {free(buffer); fclose(f); return -1;}
    buffer[filesize] = '\0';
    fclose(f);

    cJSON *root = cJSON_Parse(buffer);
    free(buffer);

    if(!root)
    {
        return -1;
    }

    cJSON *item = cJSON_GetObjectItem(root,block);
    
    if(!item || !cJSON_IsObject(item))
    {
        cJSON_Delete(root);
        return -1;
    }

    cJSON *res = cJSON_GetObjectItem(item,value);

    if(!res || !cJSON_IsNumber(res))
    {
        cJSON_Delete(root);
        return -1;
    }

    int result = (int)cJSON_GetNumberValue(res);
    
    cJSON_Delete(root);
    return result;
}

char *sJSGetString(const char *filename, const char *block, const char *value)
{
    if(!filename || !block || !value) return NULL;

    FILE *f = fopen(filename,"rb");

    if(!f)
    {
        printf("Не удалось открыть файл\n");
        return NULL;
    }

    fseek(f,0,SEEK_END);
    long filesize = ftell(f);
    rewind(f);

    char *buffer = malloc(filesize + 1);
    if(!buffer)
    {
        printf("Не удалось выделить память\n");
        return NULL;
    }

    size_t read = fread(buffer,sizeof(char),filesize,f);
    if(read != filesize) {printf("Не удалось прочитать файл\n");free(buffer); fclose(f); return NULL;}
    buffer[filesize] = '\0';
    fclose(f);

    cJSON *root = cJSON_Parse(buffer);
    free(buffer);

    if(!root)
    {
        printf("Не удалось пропарсить файл\n");
        return NULL;
    }

    cJSON *item = cJSON_GetObjectItem(root,block);

    if(!item || !cJSON_IsObject(item))
    {
        printf("Не удалось получить объект\n");
        cJSON_Delete(root);
        return NULL;
    }

    cJSON *res = cJSON_GetObjectItem(item,value);

    if(!res || !cJSON_IsString(res))
    {
        printf("Не удалось получить значение\n");
        cJSON_Delete(root);
        return NULL;
    }
    
    char *result = strdup(cJSON_GetStringValue(res));

    cJSON_Delete(root);

    return result;
}

double sJSGetDoubleValue(const char *filename, const char *block, const char *value)
{
    if (!filename || !block || !value) return -1;
    FILE *f = fopen(filename,"rb");

    if(!f)
    {
        printf("[sJSON] Unable to open %s, file do not exist or filepath is wrong\n",filename);
        return -1;
    }

    fseek(f,0,SEEK_END);
    long filesize = ftell(f);
    rewind(f);

    char *buffer = malloc(filesize + 1);
    if(!buffer)
    {
        return -1;
    }

    size_t read = fread(buffer,sizeof(char),filesize,f);
    if(read != filesize) {free(buffer); fclose(f); return -1;}
    buffer[filesize] = '\0';
    fclose(f);

    cJSON *root = cJSON_Parse(buffer);
    free(buffer);

    if(!root)
    {
        return -1;
    }

    cJSON *item = cJSON_GetObjectItem(root,block);
    
    if(!item || !cJSON_IsObject(item))
    {
        cJSON_Delete(root);
        return -1;
    }

    cJSON *res = cJSON_GetObjectItem(item,value);

    if(!res || !cJSON_IsNumber(res))
    {
        cJSON_Delete(root);
        return -1;
    }

    double result = (double)cJSON_GetNumberValue(res);
    
    cJSON_Delete(root);
    return result;
}