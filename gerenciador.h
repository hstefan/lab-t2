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
		void altera_professor();
		void altera_turma();
		void altera_disciplina();

		void lista_alunos();
		void lista_cursos();
		void lista_professores();
		void lista_turmas();
		void lista_disciplinas();
	
		void menu_turmas(bool print_menu = true);
		void menu_alunos(bool print_menu = true);
		void menu_professores(bool print_menu = true);
		void menu_cursos(bool print_menu = true);
		void menu_disciplinas(bool print_menu = true);

	
	private:
		base::Alunos alunos;
		base::Cursos cursos;
		base::Professores professores;
		base::Disciplinas disciplinas;
	};
}

#endif