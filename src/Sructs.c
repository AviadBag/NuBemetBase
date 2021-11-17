/*
 Created by Elchairoy Meir on 17/11/2021.
 Definition of table, column a cell structs.
*/

#define MAX_COLUMN_NAME_LEN 30
#define MAX_TABLE_NAME_LEN 30

enum types {character = 0,integer,string};

typedef union
{
    struct
    {
        enum types type;
        unsigned index;
        char value;
    } char_cell;

    struct
    {
        enum types type;
        unsigned index;
        int value;
    } int_cell;

    struct
    {
        enum types type;
        unsigned index;
        char *value;
    } string_cell;
}cell;

typedef struct
{
    enum types type;
    char name[MAX_COLUMN_NAME_LEN];
    unsigned number_of_cells;
    void *cells_list;
}column;

typedef struct
{
    char name[MAX_TABLE_NAME_LEN];
    unsigned number_of_columns;
    void *columns_list;
}table;
