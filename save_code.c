#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>

int ends_with_c(const char *filename) {
    int len = (int)strlen(filename);
    return (len > 2 && filename[len - 2] == '.' && filename[len - 1] == 'c');
}

int process_dir(const char *dirpath, FILE *outf, const char *outname, const char *selfname) {
    DIR *d = opendir(dirpath);
    if (!d) return -1;
    struct dirent *e;
    char path[PATH_MAX];
    while ((e = readdir(d)) != NULL) {
        if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0)
            continue;

        int n = snprintf(path, sizeof(path), "%s/%s", dirpath, e->d_name);
        if (n < 0 || n >= (int)sizeof(path))
            continue;

        /* avoid including the output file itself or this source file */
        if (strcmp(e->d_name, outname) == 0 || strcmp(path, outname) == 0 || strcmp(e->d_name, selfname) == 0)
            continue;

        struct stat st;
        if (stat(path, &st) != 0)
            continue;

            if (S_ISDIR(st.st_mode)) {
            process_dir(path, outf, outname, selfname);
        } else if (S_ISREG(st.st_mode) && ends_with_c(e->d_name)) {
            fprintf(outf, "\n======================================== %s ========================================\n\n", path);
            FILE *f = fopen(path, "r");
            if (!f) {
                fprintf(outf, "// <cannot open> %s\n\n", path);
                continue;
            }
            int ch;
            while ((ch = fgetc(f)) != EOF) {
                fputc(ch, outf);
            }
            fprintf(outf, "\n\n");
            fclose(f);
        }
    }
    closedir(d);
    return 0;
}

int main(int argc, char **argv) {
    const char *out_name = "save_code.txt";
    if (argc > 1 && argv[1][0] != '\0') out_name = argv[1];

    FILE *out = fopen(out_name, "w");
    if (!out) {
        perror("Cannot open output file");
        return 1;
    }

    /* determine this source file base name so we don't include it */
    const char *self = __FILE__;
    const char *b1 = strrchr(self, '/');
    if (!b1) b1 = strrchr(self, '\\');
    if (b1) self = b1 + 1;

    process_dir(".", out, out_name, self);

    fclose(out);
    printf("Wrote combined source to '%s'\n", out_name);
    return 0;
}
