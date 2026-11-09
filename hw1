#include <stdio.h>

int main() {
    int L, M;
    printf("Enter L (<= 18) and M (<= 20): ");
    if (scanf("%d %d", &L, &M) != 2) {
        printf("Input error!\n");
        return 1;
    }

    // Проверка ограничений из условия задачи
    if (L > 18 || M > 20 || L <= 0 || M <= 0) {
        printf("Error: L <= 18 and M <= 20\n");
        return 1;
    }

    char Z[18][20];
    
    // Эталонный массив латинских гласных в верхнем регистре
    char vowels[] = {'A', 'E', 'I', 'O', 'U', 'Y'};
    int vowels_count = 6;
    
    // Массив флагов: 0 - буква не встретилась, 1 - встретилась
    int met[6] = {0}; 

    printf("Enter matrix elements (%d characters):\n", L * M);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            // Пробел перед %c заставляет scanf пропускать пробелы и переносы строк
            scanf(" %c", &Z[i][j]);
            
            char current_char = Z[i][j];
            
            // Ручной перевод строчной латинской буквы в прописную (регистронезависимость)
            if (current_char >= 'a' && current_char <= 'z') {
                current_char = current_char - ('a' - 'A'); // Сдвиг по таблице ASCII
            }
            
            // Проверяем, является ли символ одной из гласных
            for (int k = 0; k < vowels_count; k++) {
                if (current_char == vowels[k]) {
                    met[k] = 1; 
                    break;
                }
            }
        }
    }

    // 1. Вывод исходной матрицы
    printf("\n--- Initial matrix Z ---\n");
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c ", Z[i][j]);
        }
        printf("\n");
    }

    // 2. Формирование одномерного массива из невстретившихся гласных
    char result[6];
    int result_size = 0;

    for (int k = 0; k < vowels_count; k++) {
        if (met[k] == 0) { 
            result[result_size] = vowels[k];
            result_size++;
        }
    }

    // 3. Вывод полученного массива
    printf("\n--- Result array (vowels not found) ---\n");
    if (result_size == 0) {
        printf("All vowels are present in the matrix.\n");
    } else {
        for (int i = 0; i < result_size; i++) {
            printf("%c ", result[i]);
        }
        printf("\n");
    }

    return 0;
}
