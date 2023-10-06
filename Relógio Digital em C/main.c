#include <stdio.h>
#include <time.h>
#include <unistd.h>

void clear_screen() {
    printf("\033[2J\033[H"); // Limpa a tela
}

void print_clock(int hours, int minutes, int seconds, int screen_width) {
    int padding = (screen_width - 8) / 2; // Calcula o espaço à esquerda para centralizar
    printf("\033[1;32m"); // Define a cor para verde brilhante
    printf("%*s%02d:%02d:%02d\r", padding, "", hours, minutes, seconds);
    printf("\033[0m"); // Reseta as configurações de cor
    fflush(stdout);
}

int get_screen_width() {
    return 80; // Ajuste para o tamanho da tela do seu terminal
}

int main() {
    int screen_width = get_screen_width();

    while (1) {
        time_t t;
        struct tm* info;
        t = time(NULL);
        info = localtime(&t);
        clear_screen();
        print_clock(info->tm_hour, info->tm_min, info->tm_sec, screen_width);
        sleep(1);
    }
    return 0;
}
