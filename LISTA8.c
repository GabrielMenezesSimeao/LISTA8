#include <stdio.h>
#include <time.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int dias_de_vida(Data nasc) {
    struct tm data_nasc = {0};
    data_nasc.tm_mday = nasc.dia;
    data_nasc.tm_mon = nasc.mes - 1; 
    data_nasc.tm_year = nasc.ano - 1900; 

    time_t agora = time(NULL);
    struct tm *data_atual = localtime(&agora);

    time_t nascimento = mktime(&data_nasc);
    time_t hoje = mktime(data_atual);

    double diferenca = difftime(hoje, nascimento);

    return (int)(diferenca / (60 * 60 * 24));
}

int main() {
    Data nascimento;

    printf("Digite sua data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &nascimento.dia, &nascimento.mes, &nascimento.ano);

    int dias = dias_de_vida(nascimento);
    printf("Dias de vida: %d\n", dias);
    
    return 0;
}
