/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:55:20 by ingrid            #+#    #+#             */
/*   Updated: 2025/09/10 12:58:17 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	printf("=== TESTE GET_NEXT_LINE - PRIMEIRA CHAMADA ===\n");

// 	// Abre o arquivo
// 	printf("1. Tentando abrir 'text.txt'...\n");
// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("❌ Erro ao abrir o arquivo 'text.txt'\n");
// 		printf("Certifique-se que o arquivo existe no mesmo diretório!\n");
// 		return (1);
// 	}
// 	printf("✅ Arquivo aberto com sucesso! (fd = %d)\n", fd);

// 	// Chama get_next_line pela primeira vez
// 	printf("\n2. Chamando get_next_line(fd)...\n");
// 	line = get_next_line(fd);

// 	// Verifica resultado
// 	if (line)
// 	{
// 		printf("✅ Linha lida com sucesso!\n");
// 		printf("📄 Conteúdo: '%s'", line);
// 		if (line[0] != '\0' && line[ft_strlen(line) - 1] != '\n')
// 			printf(" (sem \\n no final)");
// 		printf("\n");
// 		printf("📏 Tamanho: %zu caracteres\n", ft_strlen(line));
// 		free(line);
// 		printf("🧹 Memória liberada\n");
// 	}
// 	else
// 	{
// 		printf("❌ get_next_line retornou NULL\n");
// 		printf("Possíveis causas:\n");
// 		printf("- Arquivo vazio\n");
// 		printf("- Erro de leitura\n");
// 		printf("- Problema na implementação\n");
// 	}

// 	close(fd);
// 	printf("\n3. Arquivo fechado. Teste concluído!\n");
// 	return (0);
// }

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("text.txt", O_RDONLY);
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line%d: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
