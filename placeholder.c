#include <unistd.h>
#include <signal.h>
//gcc -o placeholder placeholder.c
volatile sig_atomic_t running = 1;

void handle_signal(int sig) {
    running = 0;
}

int main() {
    // 设置信号处理
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    // 主循环
    while (running) {
        pause();  // 暂停执行直到收到信号
    }

    return 0;
}