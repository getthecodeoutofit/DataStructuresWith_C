#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *lchild, *rchild;
};

void searchloc(int item);
void insert();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
void delete();
void case1(int item, struct node *par, struct node *loc);
void case2(int item, struct node *par, struct node *loc);
void case3(int item, struct node *par, struct node *loc);

struct node *root = NULL;
struct node *par = NULL;
struct node *loc = NULL;

void searchloc(int item) {
    struct node *temppar = NULL, *temploc = NULL;
    loc = NULL;
    par = NULL;

    if (root == NULL) {
        par = NULL;
        loc = NULL;
        return;
    }

    temploc = root;
    while (temploc != NULL) {
        if (item < temploc->data) {
            temppar = temploc;
            temploc = temploc->lchild;
        } else if (item > temploc->data) {
            temppar = temploc;
            temploc = temploc->rchild;
        } else if (temploc->data == item) {
            par = temppar;
            loc = temploc;
            return;
        }
    }

    loc = temploc;
    par = temppar;
}

void insert() {
    int item;
    printf("Enter the item to insert: ");
    scanf("%d", &item);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->data = item;

    if (root == NULL) {
        root = newnode;
        return;
    }

    searchloc(item);

    if (item > loc->data) {
        loc->rchild = newnode;
    } else if (item < loc->data) {
        loc->lchild = newnode;
    }
}

void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d\t", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->lchild);
    printf("%d\t", root->data);
    inorder(root->rchild);
}

void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\t", root->data);
}

void case1(int item, struct node *par, struct node *loc) {
    struct node *temp1, *temp2;
    temp2 = loc->rchild;
    temp1 = temp2->lchild;

    if (par == NULL) {
        root = temp2;
        struct node *trav = temp2;
        while (trav->lchild != NULL) {
            trav = trav->lchild;
        }
        trav->lchild = temp1;
    } else {
        struct node *trav = temp2;
        if (par->lchild == loc) {
            par->lchild = temp2;
            while (trav->lchild != NULL) {
                trav = trav->lchild;
            }
            trav->lchild = temp1;
        } else if (par->rchild == loc) {
            par->rchild = temp2;
            struct node *trav = temp2;
            while (trav->lchild != NULL) {
                trav = trav->lchild;
            }
            trav->lchild = temp1;
        }
    }

    free(loc);
}

void case2(int item, struct node *par, struct node *loc) {
    // Implement case 2 logic here
}

void case3(int item, struct node *par, struct node *loc) {
    // Implement case 3 logic here
}

void delete() {
    int item;
    printf("Enter the item to delete: ");
    scanf("%d", &item);

    searchloc(item);

    if (par == NULL && loc == root) {
        if (root->lchild != NULL && root->rchild != NULL) {
            case1(item, par, loc);
        } else if (root->lchild == NULL && root->rchild == NULL) {
            case3(item, par, loc);
        } else {
            case2(item, par, loc);
        }
    } else if ((par == NULL && loc == NULL) || (par != NULL && loc == NULL)) {
        printf("No item to delete.\n");
        return;
    } else if (par != NULL && loc != NULL) {
        if (loc->rchild == NULL && loc->lchild == NULL) {
            case3(item, par, loc);
        } else if (loc->lchild != NULL && loc->rchild == NULL) {
            case1(item, par, loc);
        } else {
            case2(item, par, loc);
        }
    }
}

int main() {
    bool a = true;
    int choice;

    printf("1 - Insert element\n");
    printf("2 - Preorder Traversal\n");
    printf("3 - Inorder Traversal\n");
    printf("4 - Postorder Traversal\n");
    printf("5 - Delete by element\n");
    printf("6 - Search Element\n");
    printf("7 - Exit\n");

    while (a) {
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                preorder(root);
                printf("\n");
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                delete();
                break;
            case 6:
                printf("Enter the item to search: ");
                int item;
                scanf("%d", &item);
                searchloc(item);
                break;
            case 7:
                a = false;
                break;
        }
    }

    return 0;
}
