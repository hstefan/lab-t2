#ifndef HUGO_GERENCIADOR_H__
#define HUGO_GERENCIADOR_H__

#include "tabelas.h"

namespace gerenc
{
	class Gerenciador
	{
	public:
		Gerenciador();
		void menu_inicial();
	
	protected:
		void cadastra_turma();
		void cadastra_aluno();
		void cadastra_professor();
		void cadastra_curso();
		void cadastra_disciplina();

		void remove_turma();
		void remove_aluno();
		void remove_professor();
		void remove_curso();
		void remove_disciplina();

		void altera_aluno();
		void altera_curso();

		void lista_alunos();
		void lista_cursos();
	
		void menu_turmas();
		void menu_alunos();
		void menu_professores();
		void menu_cursos();
		void menu_disciplinas();

	
	private:
		base::Alunos alunos;
		base::Cursos cursos;
	};
}

#endif