/*
 Created by Elchairoy Meir on 17/11/2021.
 Definition of table, column a cell structs.
*/

#define MAX_COLUMN_NAME_LEN 100
#define MAX_TABLE_NAME_LEN 100

typedef enum {Character,Integer,Double,String}Type; /* All the possible types of data in each column/cell. */

/* The struct of cells: */
typedef struct
{
    Type type;
    unsigned long index; /* The index of the cell in the initial column (after the column goes through changes that
                        might not be the number of the cell in the column). */
    union {
        char char_value;
        int int_value;
        double double_value;
        char *string_value;
    }value /* The value of the cell (can be several types). */;
}cell;

/* The struct of columns: */
typedef struct
{
    Type type;
    char name[MAX_COLUMN_NAME_LEN]; /* The name of the column. */
    unsigned long number_of_cells; /* The number of cells in the column. */
    void *cells_list; /* The linked list contains the cells in the column. */
    unsigned NOT_NULL :1; /* NEED AN EXPLANATION */
    unsigned UNIQUE :1; /* NEED AN EXPLANATION */
    unsigned PRIMARY_KEY :1; /* NEED AN EXPLANATION */
    unsigned FOREIGN_KEY :1; /* NEED AN EXPLANATION */
}column;

/* The struct of tables: */
typedef struct
{
    char name[MAX_TABLE_NAME_LEN]; /* The name of the table. */
    unsigned long number_of_columns; /* The number of columns in the column. */
    void *columns_list; /* The linked list contains the columns in the column. */
}table;
