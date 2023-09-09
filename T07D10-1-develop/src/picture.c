#include <stdio.h>
#define N 15
#define M 13

void transform(int buf[N][M], int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void make_foliage(int **picture, int *tree_foliage);
void make_trunk(int **picture, int *tree_trunk, int m);
void reset_picture(int **picture, int n, int m);
void output(int **matrix, int m, int n);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(picture_data, picture, N, M);

    make_picture(picture, N, M);

    output(picture, N, M);
    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);
    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][(m - 1) / 2] = frame_h[i];
        picture[i][m - 1] = frame_h[i];
    }

    make_foliage(picture, tree_foliage);
    make_trunk(picture, tree_trunk, m);

    for (int i = 1; i < 7; i++) {
        for (int j = (m - 1) / 2 + 1, k = 0; j < m - 1 && k < 5; j++, k++) {
            picture[i][j] = sun_data[i - 1][k];
        }
    }

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[(m + 1) / 2][i] = frame_w[i];
        picture[m + 1][i] = frame_w[i];
    }
}

void make_foliage(int **picture, int *tree_foliage) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            picture[3 + i][2 + j] = tree_foliage[j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            picture[2 + j][3 + i] = tree_foliage[j];
        }
    }
}

void make_trunk(int **picture, int *tree_trunk, int m) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            picture[6 + j][3 + i] = tree_trunk[j];
        }
    }

    for (int j = 0; j < 4; j++) {
        picture[(m + 1) / 2 + 3][2 + j] = tree_trunk[j];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int buf[N][M], int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = *buf + i * m;
    }
}

void output(int **picture, int m, int n) {
    for (int i = 0; i < m; i++) {
        int j = 0;
        for (; j < n - 1; j++) printf("%d ", picture[i][j]);
        printf("%d", picture[i][j]);

        if (i != m - 1) printf("\n");
    }
}
