#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 16 // Defina um limite para o número de threads

typedef struct /// armazena os dados que serão passados pras threads
{
    int (*A)[100]; // Ajuste para uma matriz estática
    int (*B)[100]; // Ajuste para uma matriz estática
    int linha_inicio;
    int linha_fim;
    int m;
    int n;
} ThreadData;

void* transpor_matriz_thread(void* arg) 
{
    ThreadData* data = (ThreadData*)arg; /// faz cast de um ponteiro generico para threadData 
    /// loop pelas linhas da transposta
    for (int i = data->linha_inicio; i < data->linha_fim; i++) {
        for (int j = 0; j < data->n; j++) {
            data->B[i][j] = data->A[j][i];
        }
    }
    return NULL;
}

int main(void) {
    int n, m, i, j, num_threads;

    printf("\nDigite o valor de n e m para sua matriz NxM respectivamente: \n");
    scanf("%d %d", &n, &m);
    
    printf("\nDigite o numero de threads a serem utilizadas: \n");
    scanf("%d", &num_threads);
    
    if (num_threads > MAX_THREADS) ///inibe o numero de threads passar  o limite já declarado
    {
        num_threads = MAX_THREADS;
    }

    int matriz1[100][100]; // Usando uma matriz estática
    int matriz2[100][100]; // Usando uma matriz estática
    srand(time(NULL)); /// inicializa a função randomica

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            matriz1[i][j] = rand() % 100; // Números entre 0 e 99
        }
    }

    // Imprimindo a matriz original
    printf("\nMatriz 1 %dx%d:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%3d ", matriz1[i][j]);
        }
        printf("\n");
    }

    pthread_t threads[MAX_THREADS];  ///Array para armazenar os identificadores de thread
    ThreadData t_args[MAX_THREADS]; /// Array de structs para passar para passar dados para cada thread

    int linhas_por_thread = m / num_threads;
    int extra = m % num_threads;
    int inicio = 0;

    ///CRIA AS THREADS
    for (i = 0; i < num_threads; i++) {
        int fim = inicio + linhas_por_thread + (i < extra ? 1 : 0); ///Distribui as sobras entre as primeiras threads
        t_args[i] = (ThreadData){matriz1, matriz2, inicio, fim, m, n}; /// preenche os dados que serao enviados para as threads
        pthread_create(&threads[i], NULL, transpor_matriz_thread, &t_args[i]); /// Cria a thread e passa os dados
        inicio = fim; /// atualiza o inicio para proxima thread
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL); /// Espera a thread terminar
    }


    printf("\nMatriz 2: %dx%d:\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", matriz2[i][j]);
        }
        printf("\n");
    }

    return 0;
}