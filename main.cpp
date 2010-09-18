#include <iostream>
#include "tabelas.h"
#include "banco.h"

int main(int argc, char* argv[])
{
	bd::Banco::getInstance().registerTable(new base::Alunos());
	base::Aluno a(0, 0, "Hugo");
	bd::Banco::getInstance().save("alunos", &a);
}