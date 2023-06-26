#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main() {

    Tree tree;

    printf(
                "0 - Create tree\n"
                "1 - Add node\n"
                "2 - Print tree\n"
                "3 - Delete node\n"
                "4 - Number_of_Vertices\n"
                "5 - Preorder\n"
                "6 - Inorder\n"
                "7 - Postorder\n"
                "8 - TreeClear\n"
                "9 - End program\n"
               );

    while (1) {

        int key;
        scanf("%d", &key);

        if (key == 0)
            treeCreate(&tree);
        else if (key == 1) {
            printf("enter value\n");
            int val;
            scanf("%d", &val);
            treeInsert(&tree, val);
        }
        else if (key == 2)
            treePrint(&tree);
        else if (key == 3) {
            printf("enter value\n");
            int val2;
            scanf("%d", &val2);
            treeErase(&tree, val2);
        }
        else if (key == 4)
            Number_of_Vertices(&tree);
        else if (key == 9) {
            treeClear(&tree);
            break;
        }
        else if (key == 5)
            treePreorder(&tree);
        else if (key == 6)
            treeInorder(&tree);
        else if (key == 7)
            treePostorder(&tree);
         else if (key == 8)
            treeClear(&tree);
    }

    return 0;
}
