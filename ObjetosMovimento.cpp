#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define largura_janela 800
#define altura_janela 800
#define PI 3.14159265358979323846

GLfloat triangulo_rotacao = 0;
GLfloat triangulo_escala = 1;
GLfloat triangulo_trans_h = 0;
GLfloat triangulo_trans_v = 0;

GLfloat retangulo_rotacao = 0;
GLfloat retangulo_escala = 1;
GLfloat retangulo_trans_h = 0;
GLfloat retangulo_trans_v = 0;

GLfloat quadrado_rotacao = 0;
GLfloat quadrado_escala = 1;
GLfloat quadrado_trans_h = 0; 
GLfloat quadrado_trans_v = 0;

int opcao = 0;

void display();
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char key, GLint x, GLint y);
void especiais(GLint letra, GLint x, GLint y);
void desenharTriangulo();
void desenharRetangulo();
void desenharQuadrado();

GLint main(GLint argc, char** argv)
{
    glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

    //glutFullScreen();  // full screen
    glutInitWindowSize(largura_janela, altura_janela);  // tamanho da janela
    glutInitWindowPosition(10, 300); // posicao inicial da janela
    glutCreateWindow("Exercício movimentar objetos");   /// cria a janela
    
    glutReshapeFunc(tela);
    glutDisplayFunc(display);
    glutKeyboardFunc(&keyboard);
    glutSpecialFunc(&especiais);
    glutMainLoop();

    return EXIT_SUCCESS;
}

void tela(GLsizei w, GLsizei h) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, largura_janela, 0, altura_janela);

    glMatrixMode(GL_MODELVIEW);
}

void especiais(GLint tecla, GLint x, GLint y) {

    if (tecla == GLUT_KEY_PAGE_UP) {
        if (opcao == 1) {
            triangulo_rotacao += 0.25;
        }
        else if (opcao == 2) {
            retangulo_rotacao += 0.25;
        }
        else if (opcao == 3) {
            quadrado_rotacao += 0.25;
        }
    }
    else if (tecla == GLUT_KEY_PAGE_DOWN) {
        if (opcao == 1) {
            triangulo_rotacao -= 0.25;
        }
        else if (opcao == 2) {
            retangulo_rotacao -= 0.25;
        }
        else if (opcao == 3) {
            quadrado_rotacao -= 0.25;
        }
    }
    else if (tecla == GLUT_KEY_UP) {
        if (opcao == 1) {
            triangulo_trans_v += 0.25;
        }
        else if (opcao == 2) {
            retangulo_trans_v += 0.25;
        }
        else if (opcao == 3) {
            quadrado_trans_v += 0.25;
        }
    }
    else if (tecla == GLUT_KEY_DOWN) {
        if (opcao == 1) {
            triangulo_trans_v -= 0.25;
        }
        else if (opcao == 2) {
            retangulo_trans_v -= 0.25;
        }
        else if (opcao == 3) {
            quadrado_trans_v -= 0.25;
        }
    }
    else if (tecla == GLUT_KEY_RIGHT) {
        if (opcao == 1) {
            triangulo_trans_h += 0.25;
        }
        else if (opcao == 2) {
            retangulo_trans_h += 0.25;
        }
        else if (opcao == 3) {
            quadrado_trans_h += 0.25;
        }
    }
    else if (tecla == GLUT_KEY_LEFT) {
        if (opcao == 1) {
            triangulo_trans_h -= 0.25;
        }
        else if (opcao == 2) {
            retangulo_trans_h -= 0.25;
        }
        else if (opcao == 3) {
            quadrado_trans_h -= 0.25;
        }
    }
    glutPostRedisplay();
}

void keyboard(unsigned char tecla, GLint x, GLint y)
{
    printf("%c", tecla);

    if (tecla == '+') {
        if (opcao == 1) {
            triangulo_escala += 0.25;
        }
        else if (opcao == 2) {
            retangulo_escala += 0.25;
        }
        else if (opcao == 3) {
            quadrado_escala += 0.25;
        }
    }
    else if (tecla == '-') {
        if (opcao == 1) {
            triangulo_escala -= 0.25;
        }
        else if (opcao == 2) {
            retangulo_escala -= 0.25;
        }
        else if (opcao == 3) {
            quadrado_escala -= 0.25;
        }
    }

    else if (tecla == '1') {
        opcao = 1;
    }
    else if (tecla == '2') {
        opcao = 2;
    }
    else if (tecla == '3') {
        opcao = 3;
    }

    glutPostRedisplay();
}

void desenharTriangulo() {
    glScalef(2.0f, 2.0f, 2.0f);
    glBegin(GL_TRIANGLES);
    glColor3ub(231, 76, 60);
    glVertex2f(-150, 0);
    glVertex2f(0, 0);
    glVertex2f(-75, 100);
    glEnd();
}

void desenharRetangulo() {
    glScalef(2.0f, 2.0f, 2.0f);
    glTranslatef(0.0f, -50.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(41, 128, 185);
    glVertex2f(0, 120);
    glVertex2f(30, 120);
    glVertex2f(30, 180);
    glVertex2f(0, 180);
    glEnd();
}

void desenharQuadrado() {
    glTranslatef(50.0f, 0.0f, 0.0f);
    glScalef(2.0f, 2.0f, 2.0f);
    glBegin(GL_QUADS);
    glColor3ub(142, 68, 173);
    glVertex2f(30, 30);
    glVertex2f(60, 30);
    glVertex2f(60, 60);
    glVertex2f(30, 60);
    glEnd();
}


void display()
{
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glClearColor(0.17f, 0.24f, 0.31f, 1);  // cor do fundo
    glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo
    glTranslatef(largura_janela / 2, altura_janela / 2, 0.0f);
    glViewport(0, 0, largura_janela, altura_janela);

    glPushMatrix();
        glScalef(triangulo_escala, triangulo_escala, 0);
        glTranslatef(triangulo_trans_h, triangulo_trans_v, 0);
        glRotated(triangulo_rotacao, 0, 0, 1);
        desenharTriangulo();
    glPopMatrix();

    glPushMatrix();
        glScalef(retangulo_escala, retangulo_escala, 0);
        glTranslatef(retangulo_trans_h, retangulo_trans_v, 0);
        glRotated(retangulo_rotacao, 0, 0, 1);
        desenharRetangulo();
    glPopMatrix();

    glPushMatrix();
        glScalef(quadrado_escala, quadrado_escala, 0);
        glTranslatef(quadrado_trans_h, quadrado_trans_v, 0);
        glRotated(quadrado_rotacao, 0, 0, 1);
        desenharQuadrado();
    glPopMatrix();


    glFlush(); // executa o desenho
}