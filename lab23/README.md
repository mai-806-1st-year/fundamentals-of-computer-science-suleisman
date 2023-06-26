# Отчет по лабораторной работе №25-26 по курсу "Фундументальня информатика" 
<b>Студент группы:</b> <ins>М80-108Б-22 Шелаев Серафим Ильич, номер по списку 23</ins>  
<b>Контакты e mail:</b> <ins>serafimshelaev@mail.ru</ins>  
<b>Работа выполнена:</b> «27» <ins>июня</ins> <ins>2023</ins> г.
<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>3 (удовлетворительно)</ins>

<b>Отчет сдан</b> «27» <ins>июня</ins> <ins>2022</ins> г., <b>итоговая оценка</b>3 <ins> (удовлетворительно)</ins>                                                          

<b>Подпись преподавателя:</b> ________________
## 1. Тема
Динамические структуры данных. Обработка деревьев.    
## 2. Цель работы
Научиться работать с деревьями.  
## 3. Задание (вариант № 23)
Составить программу на языке СИ для построения и обработки упорядоченного двоичного дерева, содержащего узлы типа float. Основные функции работы с деревьями реализовать в виде универсальных процедур или функций. После того, как дерево создано, его обработка должна производиться в режиме текстового меню со следующими действиями.

- добавление нового узла

- текстовая визуализация дерева

- удаление узла   

- поиск числа вершин двоичного дерева
 
## 4. Оборудование:
ноутбук  Asus Vivobook 15(1920x1080, Intel Core i5 2.4 ГГц, RAM 16 ГБ, SSD 512 ГБ, Windows 11 Home)
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11<br/> 
<b>Компилятор:</b> GNU Compiler Collection<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0<br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Двоичное дерево поиска было реализовано с помощью динамических структур. Каждая вершина представляла собой структуру, содержащую значение узла и указатели на родителя, левого и правого детей      
 
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
tree.c  
```c
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

typedef struct TreeNode TreeNode;

struct TreeNode {
    TreeNode *parent, *left, *right;
    int value;
};

void treeClear(Tree * const tree) {
    TreeNode *node = tree->root;
    TreeNode *root = tree->root;
    while (root->left != NULL || root->right != NULL) {
        if (node->left != NULL)
            node = node->left;
        else if (node->right != NULL)
            node = node->right;
        else {
            if (node->parent->left == node) {
                node = node->parent;
                free(node->left);
                node->left = NULL;
                --tree->size;
            }
            else if (node->parent->right == node) {
                node = node->parent;
                free(node->right);
                node->right = NULL;
                --tree->size;
            }
        }
    }
    free(root);
    tree->root = NULL;
    --tree->size;
}

bool treeContains(const Tree * const tree, const int value) {
    TreeNode *node = tree->root;
    while (node != NULL) {
        if (node->value > value)
            node = node->left;
        else if (node->value < value)
            node = node->right;
        else
            return true;
    }
    return false;
}

void treeCreate(Tree * const tree) {
    tree->root = NULL;
    tree->size = 0;
}

int treeErase(Tree * const tree, const int value) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
            break;
    }
    if (node == NULL)
        return EINVAL;

    assert(node->value == value);
    if (node->left != NULL && node->right != NULL) {
        int * const value = &node->value;
        ptr = &node->right;
        node = node->right;
        while (node->left != NULL) {
            ptr = &node->left;
            node = node->left;
        }
        *value = node->value;
    }
    if (node->left != NULL) {
        assert(node->right == NULL);
        *ptr = node->left;
        node->left->parent = node->parent;
    } else if (node->right != NULL) {
        assert(node->left == NULL);
        *ptr = node->right;
        node->right->parent = node->parent;
    } else
        *ptr = NULL;
    free(node);
    --tree->size;
}

int treeInsert(Tree * const tree, const int value) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
            return EINVAL;
    }
    *ptr = malloc(sizeof(TreeNode));
    if (*ptr == NULL)
        return errno;
    ++tree->size;
    (*ptr)->parent = node;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
    (*ptr)->value = value;
    return 0;
}

bool treeIsEmpty(const Tree * const tree) {
    return tree->size == 0;
}

size_t treeSize(const Tree * const tree) {
    return tree->size;
}

void treeDestroy(Tree * const tree) {
    treeClear(tree);
}

void nodePrint(TreeNode * node, size_t depth) {

    for (size_t i = 0; i < depth; ++i)
        printf(" ");
    printf("%d\n", node->value);
    if (node->left != NULL)
        nodePrint(node->left, depth + 1);
    if (node->right != NULL)
        nodePrint(node->right, depth + 1);

}

void treePrint(Tree * const tree) {
    bool check = treeIsEmpty(tree);
    if (check)
        printf("Tree is empty\n");
    else
        nodePrint(tree->root, 0);

}

void Number_of_Vertices(Tree* tree) {
    int k=0;
    
    TreeNode* node = tree->root;

    TreeNode* last = NULL;
    while (node != NULL) {
        if (last == node->parent) {
            if (node->right != NULL) {
                last = node;
                node = node->right;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->right) {
            ++k;

            if (node->left!= NULL) {
                last = node;
                node = node->left;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->left) {
            last = node;
            node = node->parent;
        }
    }
    printf("%d", k);
    printf("\n");
}

void treePreorder(Tree* tree) {
    size_t size = treeSize(tree), i = 0;
    TreeNode* stack[size];
    stack[0] = NULL;
    TreeNode *root = tree->root;
    TreeNode *node;

    if (root == NULL)
        return;

    stack[i] = root;
    while (stack[0] != NULL) {
        node = stack[i];
        stack[i] = NULL;
        --i;
        printf("%d ", node->value);
        if (node->right != NULL){
            ++i;
            stack[i] = node->right;
        }
        if (node->left != NULL) {
            ++i;
            stack[i] = node->left;
        }
    }
    printf("\n");
}

void treeInorder(Tree* tree) {
    TreeNode* node = tree->root;

    TreeNode* last = NULL;
    while (node != NULL) {
        if (last == node->parent) {
            if (node->left != NULL) {
                last = node;
                node = node->left;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->left) {
            printf("%d ", node->value);

            if (node->right != NULL) {
                last = node;
                node = node->right;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->right) {
            last = node;
            node = node->parent;
        }
    }
    printf("\n");
}

void treePostorder(Tree* tree) {
    TreeNode* node = tree->root;

    TreeNode* last = NULL;
    while (node != NULL) {
        if (last == node->parent) {
            if (node->right != NULL) {
                last = node;
                node = node->right;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->right) {
            printf("%d ", node->value);

            if (node->left!= NULL) {
                last = node;
                node = node->left;
                continue;
            }
            else
                last = NULL;
        }
        if (last == node->left) {
            last = node;
            node = node->parent;
        }
    }
    printf("\n");
}

```
main.c 
```c
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
```
tree.h  
```c
#ifndef TREE_H
#define TREE_H


#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

typedef struct TreeNode TreeNode;

typedef struct {
    TreeNode *root;
    size_t size;
} Tree;

void treeClear(Tree *tree);

bool treeContains(const Tree *tree, int value);

void treeCreate(Tree *tree);

int treeErase(Tree * const tree, int value);

int treeInsert(Tree * const tree, int value);

int treeGet(const Tree *tree, size_t index, int *value);

int treeSet(Tree *tree, size_t index, int value);

size_t treeSize(const Tree *tree);

void treeDestroy(Tree *tree);

void treePrint(Tree *tree);

void treePrint();

void Number_of_Vertices(Tree *tree);

void treePreorder(Tree *tree);

void treeInorder(Tree *tree);

void treePostorder(Tree *tree);

#endif //TREE_H
```
## 8. Протокол  
```
serafim@serafim-VirtualBox:~/programs/lab23$ make
gcc -c main.c -o main.o 
gcc    -c -o tree.o tree.c
gcc main.o tree.o -o lab23 
serafim@serafim-VirtualBox:~/programs/lab23$ ./lab23
0 - create tree
1 - add node
2 - print tree
3 - delete node
4 - Number_of_Vertices
5 - preorder
6 - inorder
7 - postorder
8 - treeClear
9 - end program
0
1
enter value
2
1
enter value
3
1
enter value
1
2
2
 1
 3
4
3

```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 27.06.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Защита с Coderforces:  
<b>[Контест (Div. 2)](https://codeforces.com/contest/1810/submission/199989384)</b>   
  
## 11. Выводы
Были изучены динамические структуры данных. Была составлена программа на языке Си для обработки двоичного дерева  
   
Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________


