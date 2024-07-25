#include <windows.h> // Memanggil library windows API
#include <GL/glut.h> // Memanggil library glut untuk menjalankan openGL
#include <cmath> // Memanggil library math atau untuk perhitungan matematika

#ifndef M_PI
#define M_PI 3.14159265358979323846 // Definisikan nilai (pi) untuk garis di lingkaran bola
#endif

GLfloat posisi = 0.0f; // Mengatur posisi openGL
int gerak = 15.0f; // Mengatur gerak gambar

// Inisialisasi OpenGL
void initGL() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Mengubah warna latar belakang dengan warna abu-abu
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // Setup pencahayaan
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = { 0.0, 0.0, 5.0, 1.0 };
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

// Menggambar garis bola
void garisBola() {
    glColor3d(0.0, 0.0, 0.0); // Warna hitam untuk garis
    int numCircles = 10; // Jumlah garis horizontal dan vertikal
    double radius = 1.0;

    // Menggambar garis vertikal
    glBegin(GL_LINES);
    for (int i = 0; i < numCircles; ++i) {
        double angle = i * 2.0 * M_PI / numCircles;
        for (double lat = -M_PI / 2; lat <= M_PI / 2; lat += M_PI / 20) {
            double x1 = radius * cos(lat) * cos(angle);
            double y1 = radius * sin(lat);
            double z1 = radius * cos(lat) * sin(angle);
            double x2 = radius * cos(lat + M_PI / 20) * cos(angle);
            double y2 = radius * sin(lat + M_PI / 20);
            double z2 = radius * cos(lat + M_PI / 20) * sin(angle);
            glVertex3d(x1, y1, z1);
            glVertex3d(x2, y2, z2);
        }
    }
    glEnd();

    // Menggambar garis horizontal
    glBegin(GL_LINES);
    for (int i = 0; i < numCircles; ++i) {
        double angle = i * 2.0 * M_PI / numCircles;
        for (double lat = -M_PI / 2; lat < M_PI / 2; lat += M_PI / 20) {
            double x1 = radius * cos(lat) * cos(angle);
            double y1 = radius * sin(lat);
            double z1 = radius * cos(lat) * sin(angle);
            double x2 = radius * cos(lat + M_PI / 20) * cos(angle);
            double y2 = radius * sin(lat + M_PI / 20);
            double z2 = radius * cos(lat + M_PI / 20) * sin(angle);
            glVertex3d(x1, y1, z1);
            glVertex3d(x2, y2, z2);
        }
    }
    glEnd();
}

// Menampilkan teks 2D dengan outline
void judul(float x, float y, void* font, const char* string) {
    glColor3d(0.0, 0.0, 0.0); // Outline hitam
    glRasterPos2f(x - 1, y - 1);
    while (*string) {
        glutBitmapCharacter(font, *string++);
    }

    glColor3d(1.0, 1.0, 1.0); // Teks putih
    glRasterPos2f(x, y);
    string -= strlen(string);
    while (*string) {
        glutBitmapCharacter(font, *string++);
    }
}

// Menampilkan teks 2D dengan outline
void footer(float x, float y, float z, void* font, const char* string) {
    glColor3d(0.0, 0.0, 0.0); // Outline hitam
    glRasterPos3f(x - 0.1f, y - 0.1f, z);
    while (*string) {
        glutBitmapCharacter(font, *string++);
    }

    glColor3d(1.0, 1.0, 1.0); // Teks putih
    glRasterPos3f(x, y, z);
    string -= strlen(string);
    while (*string) {
        glutBitmapCharacter(font, *string++);
    }
}

// Menggambar segitiga
void segitiga() {
    glBegin(GL_TRIANGLES);
    // Warna bagian kanan hijau
    glColor3d(0.0, 1.0, 0.0);
    glVertex3d(0.0, 1.0, 0.0);
    glVertex3d(-1.0, -1.0, 1.0);
    glVertex3d(1.0, -1.0, 1.0);
    // Warna bagian belakang biru
    glColor3d(0.0, 0.0, 1.0);
    glVertex3d(0.0, 1.0, 0.0);
    glVertex3d(1.0, -1.0, 1.0);
    glVertex3d(1.0, -1.0, -1.0);
    // Warna bagian kiri kuning
    glColor3d(1.0, 1.0, 0.0);
    glVertex3d(0.0, 1.0, 0.0);
    glVertex3d(1.0, -1.0, -1.0);
    glVertex3d(-1.0, -1.0, -1.0);
    // Warna bagian depan merah
    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(0.0, 1.0, 0.0);
    glVertex3d(-1.0, -1.0, -1.0);
    glVertex3d(-1.0, -1.0, 1.0);
    // Warna bagian bawah orange
    glColor3d(1.0, 0.5, 0.0);
    glVertex3d(-1.0, -1.0, 1.0);
    glVertex3d(1.0, -1.0, 1.0);
    glVertex3d(1.0, -1.0, -1.0);
    glVertex3d(1.0, -1.0, -1.0);
    glVertex3d(-1.0, -1.0, -1.0);
    glVertex3d(-1.0, -1.0, 1.0);
    glEnd();
}

// Menggambar kubus kotak
void kotak() {
    // Warna-warna untuk kubus kotak
    const GLfloat warna[6][3] = {
        {1.0, 0.0, 0.0}, // Merah
        {0.0, 1.0, 0.0}, // Hijau
        {0.0, 0.0, 1.0}, // Biru
        {1.0, 1.0, 0.0}, // Kuning
        {1.0, 0.5, 0.0}, // Oranye
        {1.0, 1.0, 1.0}  // Putih
    };

    glBegin(GL_QUADS);

    // Depan - Merah
    glColor3d(warna[0][0], warna[0][1], warna[0][2]);
    glVertex3d(-1.0, -1.0, 1.0);
    glVertex3d(1.0, -1.0, 1.0);
    glVertex3d(1.0, 1.0, 1.0);
    glVertex3d(-1.0, 1.0, 1.0);

    // Belakang - Hijau
    glColor3d(warna[1][0], warna[1][1], warna[1][2]);
    glVertex3d(-1.0, -1.0, -1.0);
    glVertex3d(-1.0, 1.0, -1.0);
    glVertex3d(1.0, 1.0, -1.0);
    glVertex3d(1.0, -1.0, -1.0);

    // Atas - Kuning
    glColor3d(warna[3][0], warna[3][1], warna[3][2]);
    glVertex3d(-1.0, 1.0, -1.0);
    glVertex3d(-1.0, 1.0, 1.0);
    glVertex3d(1.0, 1.0, 1.0);
    glVertex3d(1.0, 1.0, -1.0);

    // Bawah - Putih
    glColor3d(warna[5][0], warna[5][1], warna[5][2]);
    glVertex3d(-1.0, -1.0, -1.0);
    glVertex3d(1.0, -1.0, -1.0);
    glVertex3d(1.0, -1.0, 1.0);
    glVertex3d(-1.0, -1.0, 1.0);

    // Kanan - Oranye
    glColor3d(warna[4][0], warna[4][1], warna[4][2]);
    glVertex3d(1.0, -1.0, -1.0);
    glVertex3d(1.0, 1.0, -1.0);
    glVertex3d(1.0, 1.0, 1.0);
    glVertex3d(1.0, -1.0, 1.0);

    // Kiri - Biru
    glColor3d(warna[2][0], warna[2][1], warna[2][2]);
    glVertex3d(-1.0, -1.0, -1.0);
    glVertex3d(-1.0, -1.0, 1.0);
    glVertex3d(-1.0, 1.0, 1.0);
    glVertex3d(-1.0, 1.0, -1.0);

    glEnd();

    // Menambahkan garis-garis untuk membagi setiap sisi (opsional)
    glColor3d(0.0, 0.0, 0.0); // Hitam untuk garis

    glBegin(GL_LINES);
    // Garis vertikal
    for (int i = -1; i <= 1; i += 2) {
        glVertex3d(i, -1.0, 1.0);
        glVertex3d(i, 1.0, 1.0);

        glVertex3d(i, -1.0, -1.0);
        glVertex3d(i, 1.0, -1.0);

        glVertex3d(1.0, i, -1.0);
        glVertex3d(-1.0, i, -1.0);

        glVertex3d(1.0, i, 1.0);
        glVertex3d(-1.0, i, 1.0);
    }
    glEnd();
}

// Fungsi untuk menampilkan objek
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // Menggambar piramida
    glLoadIdentity();
    glTranslatef(0.5f, 0.0f, -7.0f);
    glRotatef(posisi, 1.0f, 1.0f, 0.0f);
    segitiga();

    // Menggambar bola basket
    glLoadIdentity();
    glTranslatef(3.0f, 0.0f, -7.0f);
    glRotatef(posisi, 1.0f, 1.0f, 0.0f);
    glColor3d(1.0, 0.5, 0.0);
    glutSolidSphere(1.0, 50, 50);
    garisBola();

    // Menggambar kubus kotak
    glLoadIdentity();
    glTranslatef(-3.0f, 0.0f, -8.0f);
    glRotatef(posisi, 1.0f, 1.0f, 0.0f);
    kotak();

    // Menggambar tulisan Judul
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    judul(310, 560, GLUT_BITMAP_TIMES_ROMAN_24, "UAS GRAFIKA KOMPUTER");
    judul(330, 530, GLUT_BITMAP_TIMES_ROMAN_24, "(3D Geometri openGL)");
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    // Menggambar tulisan footer
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    footer(530, 30, 0, GLUT_BITMAP_HELVETICA_18, "By Flying Cat From Universitas Siber Asia");
    footer(30, 90, 0, GLUT_BITMAP_HELVETICA_18, "Kelompok UAS:");
    footer(30, 70, 0, GLUT_BITMAP_HELVETICA_18, "1. Achmad Dwi Prasetyo");
    footer(30, 50, 0, GLUT_BITMAP_HELVETICA_18, "2. Jovita Kusuma");
    footer(30, 30, 0, GLUT_BITMAP_HELVETICA_18, "3. Ilham Bagas Saputra");
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glutSwapBuffers();

    posisi += 0.2f;
}

// Fungsi timer
void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc((int)gerak, timer, 0);
}

// Fungsi untuk mengubah ukuran jendela
void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1140, 760); // Mengatur ukuran frame
    glutInitWindowPosition(50, 50); // Mengatur posisi frame
    glutCreateWindow("UAS Grafika Komputer 3D Geometri"); // Memberi nama untuk frame
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
