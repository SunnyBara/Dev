#include "data.h"
#include "game.h"
#include "print.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>

// angle of rotation for the camera direction
double angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f;
float z = 0.0f;
float y = 36.0f;
int X;
int Y;
char stop = 'Y';
s_cell *listcell;
s_rules *rules;

//======================== Dossier Print.c===============================

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}
int search(int sx, int sy)
{
    s_cell *tmp;
    tmp = listcell;
    printf("search %d %d \n", sx, sy);
    while (tmp->X != sx || tmp->Y != sy)
    {
        tmp = tmp->next;
    }
    printf("find %d %d , state = %d\n", tmp->X, tmp->Y, tmp->state);
    return (tmp->state);
}
int gameHG(int cx, int cy)
{
    int cpt = 0;
    cpt = cpt + search(cx + 1, cy);
    cpt = cpt + search(cx + 1, cy + 1);
    cpt = cpt + search(cx, cy + 1);
    return (cpt);
}
int gameHD(int cx, int cy)
{
    int cpt = 0;
    cpt = cpt + search(cx + 1, cy);
    cpt = cpt + search(cx + 1, cy - 1);
    cpt = cpt + search(cx, cy - 1);
    return (cpt);
}

int gameBG(int cx, int cy)
{
    int cpt = 0;
    cpt = cpt + search(cx - 1, cy);
    cpt = cpt + search(cx - 1, cy + 1);
    cpt = cpt + search(cx, cy + 1);
    return (cpt);
}

int gameBD(int cx, int cy)
{
    int cpt = 0;
    cpt = cpt + search(cx - 1, cy);
    cpt = cpt + search(cx - 1, cy - 1);
    cpt = cpt + search(cx, cy - 1);
    return (cpt);
}

int gameLH(int cx, int cy)
{
    int cpt = 0;
    cpt = cpt + search(cx, cy - 1);
    cpt = cpt + search(cx, cy + 1);
    cpt = cpt + search(cx + 1, cy - 1);
    cpt = cpt + search(cx + 1, cy);
    cpt = cpt + search(cx + 1, cy + 1);
    return (cpt);
}
int gameLB(int cx, int cy)
{

    int cpt = 0;
    cpt = cpt + search(cx - 1, cy - 1);
    cpt = cpt + search(cx - 1, cy);
    cpt = cpt + search(cx - 1, cy + 1);
    cpt = cpt + search(cx, cy - 1);
    cpt = cpt + search(cx, cy + 1);
    return (cpt);
}

int gameCG(int cx, int cy)
{
    int cpt = 0;
    cpt = cpt + search(cx - 1, cy);
    cpt = cpt + search(cx - 1, cy + 1);
    cpt = cpt + search(cx, cy + 1);
    cpt = cpt + search(cx + 1, cy);
    cpt = cpt + search(cx + 1, cy + 1);
    return (cpt);
}

int gameCD(int cx, int cy)
{

    int cpt = 0;
    cpt = cpt + search(cx - 1, cy - 1);
    cpt = cpt + search(cx - 1, cy);
    cpt = cpt + search(cx, cy - 1);
    cpt = cpt + search(cx + 1, cy - 1);
    cpt = cpt + search(cx + 1, cy);
    return (cpt);
}

int gameint(int cx, int cy)
{
    int cpt = 0;
    cpt = cpt + search(cx - 1, cy - 1);
    cpt = cpt + search(cx - 1, cy);
    cpt = cpt + search(cx - 1, cy + 1);
    cpt = cpt + search(cx, cy - 1);
    cpt = cpt + search(cx, cy + 1);
    cpt = cpt + search(cx + 1, cy - 1);
    cpt = cpt + search(cx + 1, cy);
    cpt = cpt + search(cx + 1, cy + 1);
    return (cpt);
}

int gameext(int gX, int gY)
{
    int cpt = 0;
    if (gX == 0)
    {
        if (gY == 0)
        {
            cpt = gameHG(gX, gY);
        }
        else if (gY == Y - 1)
        {
            cpt = gameHD(gX, gY);
        }
        else
        {
            cpt = gameLH(gX, gY);
        }
    }
    else if (gX == X - 1)
    {
        if (gY == 0)
        {
            cpt = gameBG(gX, gY);
        }
        else if (gY == Y - 1)
        {
            cpt = gameBD(gX, gY);
        }
        else
        {
            cpt = gameLB(gX, gY);
        }
    }
    else if (gY == 0)
    {
        cpt = gameCG(gX, gY);
    }
    else if (gY == Y - 1)
    {
        cpt = gameCD(gX, gY);
    }
    return (cpt);
}

void findejeu(void)
{
    printf("la situation est statique ! Fin de partie \n");
    stop = 'Y';
    return;
}

void replacelist(s_cell *listcell, s_cell *newlist)
{
    s_cell *tmp;
    s_cell *save;
    tmp = listcell;
    int cpt = 0;
    while (tmp != NULL && newlist != NULL)
    {
        if (tmp->state != newlist->state)
        {
            cpt = cpt + 1;
        }
        tmp->state = newlist->state;
        save = newlist;
        newlist = newlist->next;
        tmp = tmp->next;
        free(save);
    }
    if (cpt == 0)
    {
        findejeu();
    }
    return;
}
s_cell *freelist(s_cell *oldliste)
{
    s_cell *save;
    s_cell *tmp;
    tmp = oldliste;
    while (tmp != NULL)
    {
        save = tmp;
        tmp = tmp->next;
        free(save);
    }
    return (NULL);
}
s_cell *reshaplist(int lX, int lY, s_cell *oldlist, s_cell *newlist)
{
    s_cell *tmp;
    s_cell *tmpload;
    freelist(oldlist);
    s_cell *loadliste;
    loadliste = malloc(sizeof(s_cell));
    fillcell(lX, lY, loadliste);
    tmpload = loadliste;
    tmp = newlist;
    while (tmp != NULL && tmpload != NULL)
    {
        tmpload->state = tmp->state;
        tmp = tmp->next;
        tmpload = tmpload->next;
    }
    return (loadliste);
}

void switchcell(int a, int b)
{
    s_cell *tmp;
    tmp = listcell;
    while (tmp != NULL && (tmp->X != b || tmp->Y != a))
    {
        tmp = tmp->next;
    }
    if (tmp != NULL && tmp->state == 0)
    {
        tmp->state = 1;
    }
    else if (tmp != NULL && tmp->state == 1)
    {
        tmp->state = 0;
    }
    return;
}

void drawgame(void)
{

    int SIZE = 100;
    int i = 0;

    // draw table;

    while (i <= X * 10)
    {
        glColor3f(1.0f, 0.5f, 0.5f);
        glBegin(GL_LINES);
        glVertex3f(0, 0, i);
        glVertex3f(Y * 10, 0, i);
        glEnd();
        i = i + 10;
    }
    i = 0;
    while (i <= Y * 10)
    {
        glBegin(GL_LINES);
        glVertex3f(i, 0, 0);
        glVertex3f(i, 0, X * 10);
        glEnd();
        i = i + 10;
    }
    // Draw cell
    s_cell *tmp = listcell;
    while (tmp != NULL)
    {
        if (tmp->state == 1)
        {
            glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 10);
            glVertex3f((tmp->Y) * 10 + 10, 0, (tmp->X) * 10 + 0);
            glVertex3f((tmp->Y) * 10 + 0, 0, (tmp->X) * 10 + 0);
            glEnd();
        }
        tmp = tmp->next;
    }
}

void displayf(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // Set the camera
    gluLookAt(x, y, z,
              x + lx, 1.0f, z + lz,
              0.0f, 1.0f, 0.0f);
    //   if (X != 0 && Y != 0)
    //   {
    drawgame();
    //   }

    glutSwapBuffers();
}
void fillrules(void)
{
    int i = 1;
    s_rules *tmp = rules;
    while (i < 9)
    {
        s_rules *newrules;
        newrules = malloc(sizeof(s_rules));
        newrules->number = i;
        if (i == 2)
        {
            newrules->type = 1;
        }
        else if (i == 3)
        {
            newrules->type = 2;
        }
        else
        {
            newrules->type = 0;
        }
        tmp->next = newrules;
        tmp = tmp->next;
        i++;
    }
}
void fillcell(int X, int Y, s_cell *list)
{
    s_cell *tmp;
    tmp = list;
    tmp->X = 0;
    tmp->Y = 0;
    int i = 0;
    int j = 1;
    while (i < X)
    {

        while (j < Y)
        {
            s_cell *newcell;
            newcell = malloc(sizeof(s_cell));
            newcell->X = i;
            newcell->Y = j;
            tmp->next = newcell;
            tmp = tmp->next;
            j++;
        }
        i++;
        j = 0;
    }
}

int mergename(char *head, char *tails, char *receiver)
{
    int i = 0;
    int j = 0;
    int cr = 0;
    while ((head[i] != '\n' && head[i] != '\0') && j < 30 && i < 31)
    {
        if (head[i] != ' ')
        {
            if (head[i] == '.')
            {
                i = 31;
            }
            else
            {
                receiver[j] = head[i];
                j++;
            }
        }
        i++;
    }
    i = 0;
    while (tails[i] != '\0' && j < 30)
    {
        if (tails[i] != '\n')
        {
            receiver[j] = tails[i];
            j++;
        }
        i++;
    }
    if (j == 30)
    {
        printf("Trops de caractères!\n le fichier ne sera pas creer\n");
        cr = 1;
    }
    return (cr);
}
void writinfile(s_cell *liste)
{
    int cr;
    FILE *file;
    FILE *check;
    char *name;
    char *extend = ".txt";
    name = malloc(26 * sizeof(char));
    printf("Entrer le nom d'un fichier\n 25 charactère max\n");
    fgets(name, 26, stdin);
    char filename[30] = {0};
    cr = mergename(name, extend, filename);
    if (cr == 0)
    {

        check = fopen(filename, "r+");
        if (check != NULL)
        {
            printf("Dossier  déjà existant , le remplacer  OUI/NON ?\n");
            fclose(check);
            char *reponse;
            reponse = malloc(4 * sizeof(char));
            fgets(reponse, 4, stdin);
            if (reponse[0] == 'n' || reponse[0] == 'N')
            {
                printf("Re");
                writinfile(liste);
                return;
            }
            else
            {
                file = fopen(filename, "w+");
            }
        }
        else
        {
            file = fopen(filename, "w");
            printf("fichier %s créé \n", filename);
        }
        s_cell *tmp;
        tmp = liste;
        char cX = X + '0';
        char cY = Y + '0';
        fputc(cX, file);
        fputc(cY, file);
        fputc('\n', file);
        int i = 0;
        int j = 0;
        while (i < X)
        {
            while (j < Y)
            {
                fputc(tmp->state + '0', file);
                tmp = tmp->next;
                j++;
            }
            fputc('\n', file);
            i++;
            j = 0;
        }
        fclose(file);
    }
    return;
}
s_cell *loadfile(s_cell *liste)
{
    FILE *load;
    char filename[30] = {0};
    char *get;
    int cr;
    char *extend = ".txt";
    get = malloc(30 * sizeof(char));
    printf("Entrer le nom du fichier à ouvrir\n");
    fgets(get, 30, stdin);
    cr = mergename(get, extend, filename);
    load = fopen(filename, "r");
    if (load == NULL)
    {
        printf("Le fichier %s  n'existe pas\n", filename);
        return (liste);
    }
    char c;
    int size[2];
    int i = 0;
    while (i < 2)
    {
        c = fgetc(load);
        size[i] = c - '0';
        i++;
    }
    i = 0;
    s_cell *loadlist;
    loadlist = malloc(sizeof(s_cell));
    fillcell(size[0], size[1], loadlist);
    s_cell *tmp;
    tmp = loadlist;
    while (tmp != NULL && i < ((size[0] + 1) * size[1]))
    {
        c = fgetc(load);
        if (c != '\n')
        {
            tmp->state = c - '0';
            tmp = tmp->next;
        }
        i++;
    }
    fclose(load);
    X = size[0];
    Y = size[1];
    liste = reshaplist(X, Y, liste, loadlist);
    return (liste);
}
void *game(void *arg)
{
    while (stop == 'N')
    {
        s_cell *listgam;
        s_cell *tmpnewlist;
        s_cell *newlist;
        newlist = malloc(sizeof(s_cell));
        fillcell(X, Y, newlist);
        s_rules *tmp;
        int cpt;
        listgam = listcell;
        tmpnewlist = newlist;
        while (listgam != NULL)
        {
            cpt = 0;
            if (listgam->X == 0 || listgam->X == X - 1 || listgam->Y == 0 || listgam->Y == Y - 1)
            {
                cpt = gameext(listgam->X, listgam->Y);
            }
            else
            {
                cpt = gameint(listgam->X, listgam->Y);
            }
            tmp = rules;
            while (tmp->number != cpt)
            {
                tmp = tmp->next;
            }
            if (tmp->type == 2)
            {
                tmpnewlist->state = 1;
            }
            else if (tmp->type == 1)
            {
                tmpnewlist->state = listgam->state;
            }
            else if (tmp->type == 0)
            {
                tmpnewlist->state = 0;
            }
            listgam = listgam->next;
            tmpnewlist = tmpnewlist->next;
        }
        replacelist(listcell, newlist);
        glutDisplayFunc(displayf);
        sleep(1);
    }
}
void resetallrules(void)
{
    s_rules *tmp;
    tmp = rules;
    int i = 0;
    while (i < 9)
    {
        if (i == 2)
        {
            tmp->type = 1;
        }
        else if (i == 3)
        {
            tmp->type = 2;
        }
        else
        {
            tmp->type = 0;
        }
        tmp = tmp->next;
    }
    return;
}
void checkrules(void)
{
    printf("règles présentes \n");
    printf("Voisins  || règle \n");
    s_rules *tmp;
    tmp = rules;
    while (tmp != NULL)
    {
        printf(" %d %d\n", tmp->number, tmp->type);
        tmp = tmp->next;
    }
}
void addrules(int type, int number)
{
    s_rules *tmp;
    tmp = rules;
    while (tmp->number != number)
    {
        tmp = tmp->next;
    }
    tmp->type = type;
    return;
}

void menurules(void)
{
    char l[2];
    lire(l, 2);
    if (l[0] == '1')
    {
        int i = 0;
        int k;
        char m[2];
        printf("combien de règles voulez vous modifier ?\n");
        lire(m, 2);
        k = m[0] - '0';
        char c[2];
        while (i < k)
        {

            printf("entrer le nombre de voisin néessaire pour appliquer la regle\n choisir entre 0 et 8\n");
            lire(c, 2);
            int nombre = c[0] - '0';
            if (nombre < 0 || nombre > 8)
            {
                printf("numéro hors range\n");
            }
            else
            {
                printf("entrer le type de règle : \n 0 = mourir 1 = stable 2 = naissance \n");
                lire(c, 2);
                int type = c[0] - '0';
                if (type < 0 || type > 2)
                {
                    printf("numéro hors range\n");
                }
                else
                {
                    addrules(type, nombre);
                    i++;
                }
            }
            checkrules();
        }
    }
    else if (l[0] == '2')
    {
        checkrules();
    }
    else if (l[0] == '3')
    {
        printf("reset de toutes les règles\n");
        resetallrules();
    }
    else if (l[0] == '4')
    {
        printf("exit\n");
        return;
    }
    else
    {
        printf("réponse non comprise\n");
    }
    printf("retour menu\n");
    menurules();
}

void processNormalKeys(unsigned char key, int xi, int yi)
{
    switch (key)
    {
    case 'q':
        x += 1;
        break;

    case 'd':
        x -= 1;
        break;

    case 'z':
        z += 1;
        break;

    case 's':
        z -= 1;
        break;
    case 'r':
        pthread_t gam;
        stop = 'N';
        pthread_create(&gam, NULL, game, NULL);
        break;
    case 'c':
        writinfile(listcell);
        break;
    case 'v':
        listcell = loadfile(listcell);
        break;
    case 'p':
        stop = 'Y';
        break;
    case 't':
        printf("Que voulez vous faire?\n1 : add rules\n2 : check rules\n3 : reset rule\n4 : sortir du menu\n");
        menurules();
        break;
    }
}

void processSpecialKeys(int key, int xx, int yy)
{

    float fraction = 0.1f;

    switch (key)
    {
    case GLUT_KEY_UP:
        y -= 1;
        break;
    case GLUT_KEY_DOWN:
        y += 1;
        break;
    }
}
void processMouse(int button, int state, int a, int b)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
    {
        switch (state)
        {
        case GLUT_DOWN:
            printf("mouse x =%d mouse y = %d zoom = %f\n", a, b, y);
            float k;
            int l;
            float n;
            int p;
            float g;
            k = a / (3600 / y);
            p = 3600 / y;
            n = ((x - 1 / ((1 / y) * (2.46866671))) / 10);
            g = (a / (3600 / y) + ((x - 1 / ((1 / y) * (2.5152887))) / 10));
            l = (b / (3600 / y) + ((z - 1 / ((1 / y) * (2.46866671))) / 10));
            //
            p = g;
            printf(" k = %f, n = %f , l = %d g = %f p=%d\n", k, n, l, g, p);

            switchcell(g, l);
            break;
        }
    }
    case GLUT_RIGHT_BUTTON:
    {
        switch (state)
        {
        case GLUT_DOWN:
            printf("camera x = %f camera z = %f zoom y = %f\n", x, z, y);
            break;
        }
    }
    }
}
void reshape(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;
    float ratio = 1.0 * w / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45, ratio, 1, 1000);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

int printgame(int argc, char **argv, s_cell *list, int line, int column)
{
    X = line;
    Y = column;
    listcell = list;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(100, 100);
    int win = glutCreateWindow("Cell Game");
    glutDisplayFunc(displayf);
    glutReshapeFunc(reshape);
    glutIdleFunc(displayf);
    glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(processNormalKeys);
    glutMouseFunc(processMouse);
    // OpenGL init
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 1;
}
///=======================GAME======================/////////////////////

//=========================dossier game.c =====================

//==================== dossier main ==============================
int main(int argc, char **argv)
{
    X = 45;
    Y = 45;
    listcell = malloc(sizeof(s_cell));
    rules = malloc(sizeof(s_rules));
    rules->number = 0;
    rules->type = 0;
    fillrules();
    fillcell(X, Y, listcell);
    printgame(argc, argv, listcell, X, Y);
    return 0;
}