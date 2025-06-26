#include "sJS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
#if (sJSON_MAJOR_VERSION != 0 || sJSON_MINOR_VERSION != 1 || sJSON_PATCH_VERION != 0)
    #error sJSON.c and sJSON.h have a different versions. Please get a correct version of sJSON
#endif


#ifdef __cplusplus
    #error sJSON support only C language.
#endif

int sJSGetNumberValue(const char *filename, const char *block, const char *value)
{
    if (!filename || !block || !value) return -1;
=======
int sJSGetNumberValue(const char *filename, const char *object, const char *value)
{
    if (!filename || !object || !value) return -1;
>>>>>>> 483b1fa (A few improvemets and 3 new functions)

    FILE *f = fopen(filename,"rb");

    if(!f)
    {
<<<<<<< HEAD
        printf("[sJSON] Unable to open %s, file do not exist or filepath is wrong\n",filename);
=======
        perror("sJSGetNumberValue: Unable to open a file. File do not exist or filepath is wrong\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        return -1;
    }

    fseek(f,0,SEEK_END);
    long filesize = ftell(f);
    rewind(f);

    char *buffer = malloc(filesize + 1);
    if(!buffer)
    {
<<<<<<< HEAD
=======
        perror("sJSGetNumberValue: Failed to malloc the memory for buffer\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        return -1;
    }

    size_t read = fread(buffer,sizeof(char),filesize,f);
<<<<<<< HEAD
    if(read != filesize) {free(buffer); fclose(f); return -1;}
=======
    if(read != filesize) 
    {
        free(buffer); 
        fclose(f); 
        return -1;
    }
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
    buffer[filesize] = '\0';
    fclose(f);

    cJSON *root = cJSON_Parse(buffer);
    free(buffer);

    if(!root)
    {
<<<<<<< HEAD
        return -1;
    }

    cJSON *item = cJSON_GetObjectItem(root,block);
    
    if(!item || !cJSON_IsObject(item))
    {
=======
        perror("sJSGetNumberValue: Failed to parse JSON\n");
        return -1;
    }

    cJSON *item = cJSON_GetObjectItem(root,object);
    
    if(!item || !cJSON_IsObject(item))
    {
        perror("sJSGetNumberValue: Object do not exist or incorrect\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        cJSON_Delete(root);
        return -1;
    }

    cJSON *res = cJSON_GetObjectItem(item,value);

    if(!res || !cJSON_IsNumber(res))
    {
<<<<<<< HEAD
=======
        
        perror("sJSGetNumberValue: Value do not exist, or not a number, or incorrect\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        cJSON_Delete(root);
        return -1;
    }

    int result = (int)cJSON_GetNumberValue(res);
    
    cJSON_Delete(root);
    return result;
}

<<<<<<< HEAD
char *sJSGetString(const char *filename, const char *block, const char *value)
{
    if(!filename || !block || !value) return NULL;
=======
char *sJSGetStringValue(const char *filename, const char *object, const char *value)
{
    if(!filename || !object || !value) return NULL;
>>>>>>> 483b1fa (A few improvemets and 3 new functions)

    FILE *f = fopen(filename,"rb");

    if(!f)
    {
<<<<<<< HEAD
        printf("Не удалось открыть файл\n");
=======
        perror("sJSGetStringValue: Unable to open a file. File do not exist or filepath is wrong\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        return NULL;
    }

    fseek(f,0,SEEK_END);
    long filesize = ftell(f);
    rewind(f);

    char *buffer = malloc(filesize + 1);
    if(!buffer)
    {
<<<<<<< HEAD
        printf("Не удалось выделить память\n");
=======
        perror("sJSGetStringValue: Failed to malloc the memory for buffer\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        return NULL;
    }

    size_t read = fread(buffer,sizeof(char),filesize,f);
<<<<<<< HEAD
    if(read != filesize) {printf("Не удалось прочитать файл\n");free(buffer); fclose(f); return NULL;}
=======
    if(read != filesize) 
    {
        perror("sJSGetStringValue: Failed to read file\n");
        free(buffer); 
        fclose(f); 
        return NULL;
    }
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
    buffer[filesize] = '\0';
    fclose(f);

    cJSON *root = cJSON_Parse(buffer);
    free(buffer);

    if(!root)
    {
<<<<<<< HEAD
        printf("Не удалось пропарсить файл\n");
        return NULL;
    }

    cJSON *item = cJSON_GetObjectItem(root,block);

    if(!item || !cJSON_IsObject(item))
    {
        printf("Не удалось получить объект\n");
=======
        perror("sJSGetStringValue: Failed to parse JSON\n");
        return NULL;
    }

    cJSON *item = cJSON_GetObjectItem(root,object);

    if(!item || !cJSON_IsObject(item))
    {
        perror("sJSGetStringValue: Object do not exist or incorrect\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        cJSON_Delete(root);
        return NULL;
    }

    cJSON *res = cJSON_GetObjectItem(item,value);

    if(!res || !cJSON_IsString(res))
    {
<<<<<<< HEAD
        printf("Не удалось получить значение\n");
=======
        perror("sJSGetStringValue: Value do not exist, or not a string, or incorrect\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        cJSON_Delete(root);
        return NULL;
    }
    
    char *result = strdup(cJSON_GetStringValue(res));

    cJSON_Delete(root);

    return result;
}

<<<<<<< HEAD
double sJSGetDoubleValue(const char *filename, const char *block, const char *value)
{
    if (!filename || !block || !value) return -1;
=======
double sJSGetDoubleValue(const char *filename, const char *object, const char *value)
{
    if (!filename || !object || !value) return -1;
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
    FILE *f = fopen(filename,"rb");

    if(!f)
    {
<<<<<<< HEAD
        printf("[sJSON] Unable to open %s, file do not exist or filepath is wrong\n",filename);
=======
        perror("sJSGetDoubleValue: Unable to open a file\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        return -1;
    }

    fseek(f,0,SEEK_END);
    long filesize = ftell(f);
    rewind(f);

    char *buffer = malloc(filesize + 1);
    if(!buffer)
    {
<<<<<<< HEAD
=======
        perror("sJSGetDoubleValue: Failed to malloc a memory for buffers\n");
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
        return -1;
    }

    size_t read = fread(buffer,sizeof(char),filesize,f);
<<<<<<< HEAD
    if(read != filesize) {free(buffer); fclose(f); return -1;}
=======
    if(read != filesize) 
    {
        perror("sJSGetDoubleValue: Failed to read a file\n");
        free(buffer); 
        fclose(f); 
        return -1;
    }
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
    buffer[filesize] = '\0';
    fclose(f);

    cJSON *root = cJSON_Parse(buffer);
    free(buffer);

    if(!root)
    {
        return -1;
    }

<<<<<<< HEAD
    cJSON *item = cJSON_GetObjectItem(root,block);
=======
    cJSON *item = cJSON_GetObjectItem(root,object);
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
    
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
<<<<<<< HEAD
=======
}

cJSON *sJSParseJSON(const char *filename)
{
    if(!filename) return NULL;

    FILE *f = fopen(filename,"rb");

    if(!f)
    {
        perror("sJSParseJSON: Unable to open a file. File do not exist or filepath is wrong\n");
        return -1;
    }

    fseek(f,0,SEEK_END);
    long filesize = ftell(f);
    rewind(f);

    char *buffer = malloc(filesize + 1);
    if(!buffer)
    {
        perror("sJSParseJSON: Failed to malloc the memory for buffer\n");
        return -1;
    }

    size_t read = fread(buffer,sizeof(char),filesize,f);
    if(read != filesize) 
    {
        perror("sJSParseJSON: Failed to read a file\n");
        free(buffer); 
        fclose(f); 
        return -1;
    }
    buffer[filesize] = '\0';
    fclose(f);

    cJSON *root = cJSON_Parse(buffer);
    free(buffer);
    return root;
}


int sJSGetNumber(cJSON *root, const char *object, const char *value)
{
    if (!root)
    {
        perror("sJSGetNumber: cJSON is not parsed (cJSON is NULL) \n");
        return -1;
    }
    cJSON *item = cJSON_GetObjectItem(root,object);
    
    if(!item || !cJSON_IsObject(item))
    {
        perror("sJSGetNumber: Object do not exist or incorrect\n");
        cJSON_Delete(root);
        return -1;
    }

    cJSON *res = cJSON_GetObjectItem(item,value);

    if(!res || !cJSON_IsNumber(res))
    {
        
        perror("sJSGetNumber: Value do not exist, or not a number, or incorrect\n");
        cJSON_Delete(root);
        return -1;
    }

    int result = (int)cJSON_GetNumberValue(res);
    
    cJSON_Delete(root);
    return result;
}

char *sJSGetString(cJSON *root, const char *object, const char *value)
{
    if (!root)
    {
        perror("sJSGetString: cJSON is not parsed (cJSON is NULL) \n");
        return -1;
    }

    cJSON *item = cJSON_GetObjectItem(root,object);

    if(!item || !cJSON_IsObject(item))
    {
        perror("sJSGetString: Object do not exist or incorrect\n");
        cJSON_Delete(root);
        return NULL;
    }

    cJSON *res = cJSON_GetObjectItem(item,value);

    if(!res || !cJSON_IsString(res))
    {
        perror("sJSGetString: Value do not exist, or not a string, or incorrect\n");
        cJSON_Delete(root);
        return NULL;
    }
    
    char *result = strdup(cJSON_GetStringValue(res));

    cJSON_Delete(root);

    return result;
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
}