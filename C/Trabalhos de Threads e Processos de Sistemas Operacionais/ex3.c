#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int n;
    printf("Digite um valor n: ");
    scanf("%d", &n);

    pid_t pid, me, parent, x, y;
    int status;
    
    pid = fork();

    me = getpid();
    parent = getppid();

    for (int i = 0; i < n; i++) {
        pid = fork();

        if (pid == 0) {
            // Código do filho
            printf("Sou o filho %d, PID = %d, PPID = %d\n", i, getpid(), getppid());
            x = getpid();
            while(x != 1){
                if(x%2 == 0)
                {
                    x = x/2;
                    printf(" Valor resultante da Conjectura de Collatz: %d referente ao Filho %d \n", x, i); ///par
                }
                else
                {
                    x = 3*x + 1;
                    printf(" Valor resultante da Conjectura de Collatz: %d referente ao Filho %d \n", x, i); ///impar 
                }
            return 0; // filho termina aqui
        }
        // O pai continua no loop
    }

    // O pai espera todos os filhos
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("Todos os filhos terminaram\n");


    ///n é referente a quantidade de processos criados e x é o valor da centena e da dezena do processo
    


        printf("%d\n", me);
    }
}
    