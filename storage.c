#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "sticky.h"

int storage_init(void) {
    struct stat st = {0};
    if (stat(DB_DIR, &st) == -1) {
        if (mkdir(DB_DIR, 0700) == -1) {
            perror("mkdir failed");
            return -1;
        }
    }
    return 0;
}

static void get_filepath(const char *title, char *path, size_t max_len) {
    snprintf(path, max_len, "%s/%s.txt", DB_DIR, title);
}

int note_create(const char *title, const char *text) {
    char path[128];
    get_filepath(title, path, sizeof(path));
    
    FILE *f = fopen(path, "w");
    if (!f) return -1;
    
    fprintf(f, "%s", text);
    fclose(f);
    return 0;
}

int note_read(const char *title, Note *out_note) {
    char path[128];
    get_filepath(title, path, sizeof(path));
    
    FILE *f = fopen(path, "r");
    if (!f) return -1;
    
    strncpy(out_note->title, title, MAX_TITLE_LEN - 1);
    out_note->title[MAX_TITLE_LEN - 1] = '\0';
    
    size_t bytes_read = fread(out_note->text, 1, MAX_TEXT_LEN - 1, f);
    out_note->text[bytes_read] = '\0';
    
    fclose(f);
    return 0;
}

int note_update(const char *title, const char *new_text) {
    // В простом случае перезапись файла = обновление
    return note_create(title, new_text);
}

int note_remove(const char *title) {
    char path[128];
    get_filepath(title, path, sizeof(path));
    return remove(path);
}