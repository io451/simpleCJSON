/*
Simple JSON

Based on cJSON for reading JSON data.

Free for anything

Author: https://github.com/io451
*/
#ifndef sJSON_H
#define sJSON_H

#ifndef cJSON__h
#include "cJSON.h"
#endif


#define sJSON_MAJOR_VERISON 0
<<<<<<< HEAD
#define sJSON_MINOR_VERSION 1
#define sJSON_PATCH_VERSION 0

/**
 * @brief Automaticly open a file, read JSON data and return a specific number value from JSON string in object
 * 
 * Note: Do not use this function with FOR or WHILE loops. For loop operations use sJSGetNumber
=======
#define sJSON_MINOR_VERSION 0
#define sJSON_PATCH_VERSION 2

/**
 * @brief Automaticly open a file, read JSON data and 
 * return a specific integer number from JSON string in object
 * 
 * @note Do not use this function with FOR or WHILE loops. For loop operations use sJSGetNumber
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
 * 
 * @param filename  path to JSON file
 * @param block  JSON object which contain a value string
 * @param value  specific string in object which contain a number value
 * 
 * @return integer number from value string, or -1 on failure
 */
int sJSGetNumberValue(const char *filename, const char *block, const char *value);


/**
<<<<<<< HEAD
 * @brief Automaticly open a file, read JSON data and return a specific number value as double from JSON string in object
 * 
 * Note: Do not use this function with FOR or WHILE loops. For loop operations use sJSGetNumber
=======
 * @brief Automaticly open a file, read JSON data and return a double number 
 * from JSON string in object
 * 
 * @note Do not use this function with FOR or WHILE loops. For loop operations use sJSGetNumber
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
 * 
 * @param filename  path to JSON file
 * @param block  JSON object which contain a value string
 * @param value  specific string in object which contain a number value
 * 
 * @return integer number from value string, or -1 on failure
 */
double sJSGetDoubleValue(const char *filename, const char *block, const char *value);


/**
 * @brief Automaticly open a file, read JSON data and return a specific string from JSON string in object
 * 
 * Note: Do not use this function with FOR or WHILE loops. For loop operations use sJSGetString
 * 
 * @param filename  path to JSON file
 * @param block  JSON object which contain a value string
 * @param value  specific string in object which contain a number value
 * 
 * @return char *  from JSON string, or NULL on failure
 */
<<<<<<< HEAD
char *sJSGetString(const char *filename, const char *block, const char *value);


=======
char *sJSGetStringValue(const char *filename, const char *block, const char *value);


/**
 * @brief Opens a file, and parse JSON data in cJSON struct
 * 
 * You can use this function for more specific operations.
 * 
 * @param filename JSON file to parse
 * 
 * @return cJSON struct or NULL on failure
 */
cJSON *sJSParseJSON(const char *filename);


/**
 * @brief Alternative to sJSGetNumberValue.
 * 
 * sJSGetNumber gets a number value from cJSON object, you can use
 * this function in FOR and WHILE loops, because sJSGetNumber do not 
 * opens a file.
 * 
 * @param root cJSON struct with parsed file, you can use
 * @param object a JSON object to parse
 * @param value a JSON string to get integer
 * 
 * @return integer number or -1 on failure
 * 
 * 
 * @note You can use sJSParseJSON to get cJSON struct
 */
int sJSGetNumber(cJSON *root, const char *object, const char *value);


/**
 * @brief Alternative to sJSGetStringValue.
 * 
 * sJSGetString gets a string value from cJSON object, you can use
 * this function in FOR and WHILE loops, because sJSGetString do not 
 * opens a file.
 * 
 * @param root cJSON struct with parsed file, you can use
 * @param object a JSON object to parse
 * @param value a JSON string to get integer
 * 
 * @return string or NULL on failure
 * 
 * 
 * @note You can use sJSParseJSON to get cJSON struct
 */
char *sJSGetString(cJSON *root, const char *object, const char *value);
>>>>>>> 483b1fa (A few improvemets and 3 new functions)
#endif



