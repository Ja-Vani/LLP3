//
// Created by Ja_Vani on 13.03.2023.
//

#ifndef LLP3_JSON_TREE_H
#define LLP3_JSON_TREE_H

#include <json-c/json.h>
#include "Lab2/request_tree.h"

#define MAX_SIZE 1024

json_object *tree_to_json(request_tree *tree);

#endif //LLP3_JSON_TREE_H
