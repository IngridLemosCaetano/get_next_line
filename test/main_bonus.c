/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:09:25 by ingrid            #+#    #+#             */
/*   Updated: 2025/09/11 16:01:34 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../functions/get_next_line_bonus.h"

int main(void)
{
	int fd1, fd2, fd3;
	char *line;

	printf("=== TESTE GET_NEXT_LINE BONUS ===\n");
	printf("Lendo de 3 arquivos simultaneamente\n\n");

	// Abrir múltiplos arquivos
	fd1 = open("bonus_arquivo1.txt", O_RDONLY);
	fd2 = open("bonus_arquivo2.txt", O_RDONLY);
	fd3 = open("bonus_arquivo3.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("Erro ao abrir arquivos\n");
		return (1);
	}

	printf("Arquivos abertos: fd1=%d, fd2=%d, fd3=%d\n\n", fd1, fd2, fd3);

	// Leitura intercalada - demonstra que cada fd mantém seu estado
	printf("--- Lendo linha por linha de cada arquivo ---\n");

	// Primeira linha de cada arquivo
	printf("\n Primeira linha de arquivo1.txt:\n");
	line = get_next_line(fd1);
	if (line) {
		printf("  %s", line);
		free(line);
	}

	printf(" Primeira linha de arquivo2.txt:\n");
	line = get_next_line(fd2);
	if (line) {
		printf("  %s", line);
		free(line);
	}

	printf(" Primeira linha de arquivo3.txt:\n");
	line = get_next_line(fd3);
	if (line) {
		printf("  %s", line);
		free(line);
	}

	// Segunda linha de cada arquivo
	printf("\n Segunda linha de arquivo1.txt:\n");
	line = get_next_line(fd1);
	if (line) {
		printf("  %s", line);
		free(line);
	}

	printf(" Segunda linha de arquivo2.txt:\n");
	line = get_next_line(fd2);
	if (line) {
		printf("  %s", line);
		free(line);
	}

	printf(" Segunda linha de arquivo3.txt:\n");
	line = get_next_line(fd3);
	if (line) {
		printf("  %s", line);
		free(line);
	}

	// Demonstra que o estado é mantido independentemente
	printf("\n--- Voltando para arquivo1.txt (terceira linha) ---\n");
		line = get_next_line(fd1);
	if (line) {
		printf("  %s", line);
		free(line);
	} else {
		printf("  Fim do arquivo1.txt\n");
	}

	// Teste com arquivo inválido
	printf("\n--- Teste com fd inválido ---\n");
	line = get_next_line(-1);
	printf("get_next_line(-1): %s\n", line ? line : "NULL (correto)");

	line = get_next_line(9999);
	printf("get_next_line(9999): %s\n", line ? line : "NULL (correto)");

	close(fd1);
	close(fd2);
	close(fd3);

	printf("\n✅ Teste concluído!\n");
	return (0);
}
