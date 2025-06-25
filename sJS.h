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
#define sJSON_MINOR_VERSION 1
#define sJSON_PATCH_VERSION 0

/**
 * @brief Automaticly open a file, read JSON data and return a specific number value from JSON string in object
 * 
 * Note: Do not use this function with FOR or WHILE loops. For loop operations use sJSGetNumber
 * 
 * @param filename  path to JSON file
 * @param block  JSON object which contain a value string
 * @param value  specific string in object which contain a number value
 * 
 * @return integer number from value string, or -1 on failure
 */
int sJSGetNumberValue(const char *filename, const char *block, const char *value);


/**
 * @brief Automaticly open a file, read JSON data and return a specific number value as double from JSON string in object
 * 
 * Note: Do not use this function with FOR or WHILE loops. For loop operations use sJSGetNumber
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
char *sJSGetString(const char *filename, const char *block, const char *value);


#endif



