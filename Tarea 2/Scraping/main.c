#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void raspadoweb(char content[]);
int FTag(char content[], char tag[], int posi);
int FProducto(char content[], char producto[], int posi);
int String(char content[], char SubString[], int posi);
int Info(char contenido[], int pos);
char * Leer(char nombreArchivo[]);

int main()
{
	char * content = Leer("todo.txt");
	raspadoweb(content);
	free(content);
	return 0;
}

char * Leer(char nombreArchivo[])
{
	int TArchivo;
	FILE * todo ;
	char * content;

	todo = fopen("todo.txt", "rt");
fflush(stdin);
	if (todo == NULL)
		return NULL;

	fseek(todo, 0, SEEK_END);
	TArchivo = ftell(todo);
	fseek(todo, 0, SEEK_SET);

	content = malloc((TArchivo + 1) * sizeof(char));

	fread(content, sizeof(char), TArchivo, todo);
	fclose(todo);
	content[TArchivo] = '\0';

	return content;
};

void raspadoweb(char content[])
{
	int i = 0, count = 0;
	char tagProducto[] = "class=\"product-name\">";
	char tagPrecio[] = "class=\"price\"";
	char producto[] = "CAMINADORA CX-7";

	while ((i = FTag(content, tagProducto, i)))
	{
		if (FProducto(content, producto, i))
		{
			printf("\n%d) ", ++count);
			Info(content, i);
			i = FTag(content, tagPrecio, i);
			Info(content, i);
		}
	}
}

int FTag(char content[], char tag[], int posi)
{
	while (content[posi] != '\0')
	{
		if (SubStr(content, tag, posi))
		{
			posi += strlen(tag);
			while (content[posi++] != '>');
			return (posi);
		}
		posi++;
	}
	return 0;
}

int FProducto(char content[], char producto[], int posi) {

	while (content[posi] != '\0' && content[posi] != '\n')
		if (SubStr(content, producto, posi++))
			return 1;

	return 0;
}

int Info(char content[], int posi)
{
	while (content[posi] != '\0' && content[posi] != '<')
		printf("%c", content[posi++]);

	printf("\n");
	return posi;
}

int SubStr(char content[], char SubString[], int posi)
{
	int i;

	for (i = 0; content[i + posi] != '\0' && content[i + posi] != '\n'; i++)
		if (SubString[i] != content[i + posi])
			break;

	return (SubString[i] == '\0');
}
