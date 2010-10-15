#include "gerenciador.h"
#include "banco.h"
#include "dados.h"
#include <iostream>
#include <string>

namespace gerenc
{
	Gerenciador::Gerenciador()
		: alunos(), cursos(), professores(), disciplinas(), turmas(), notas()
	{
		bd::Banco::getInstance().registerTable(&alunos);
		bd::Banco::getInstance().registerTable(&cursos);
		bd::Banco::getInstance().registerTable(&professores);
		bd::Banco::getInstance().registerTable(&disciplinas);
		bd::Banco::getInstance().registerTable(&turmas);
		bd::Banco::getInstance().registerTable(&notas);
	}

	void Gerenciador::menu_inicial()
	{
		std::cout << "Digite o numero da opcao que deseja operar" << std::endl;
		std::cout << "1 - Alunos" << std::endl << "2 - Cursos" << std::endl << "3 - Disciplinas" 
			<< std::endl << "4 - Professores" << std::endl << "5 - Turmas" << std::endl << "6 - Sair" << std::endl;
		std::cout << "> ";
		char op;
		std::cin >> op;
		std::cout << std::endl;
		switch (op)
		{
		case '1':
			menu_alunos();
			break;
		case '2':
			menu_cursos();
			break;
		case '3':
			menu_disciplinas();
			break;
		case '4':
			menu_professores();
			break;
		case '5':
			menu_turmas();
			break;
		case '6':
			return;
			break;
		default:
			std::cout << "Opcao invalida" << std::endl;
			menu_inicial();
			break;
		}
	}

	void Gerenciador::menu_alunos(bool print_menu)
	{
		if(print_menu)
		{
			std::cout << "1 - Cadastrar" << std::endl << "2 - Remover" << std::endl <<"3 - Alterar" <<
				std::endl << "4 - Listar" << std::endl << "5 - Voltar" << std::endl;
		}
		std::cout << "> ";

		char op;
		std::cin >> op;
		std::cout << std::endl;
		switch(op)
		{
		case '1':
			cadastra_aluno();
			menu_alunos(false);
			break;
		case '2':
			remove_aluno();
			menu_alunos(false);
			break;
		case '3':
			altera_aluno();
			menu_alunos(false);
			break;
		case '4':
			lista_alunos();
			menu_alunos(false);
			break;
		case '5':
			menu_inicial();
			break;
		default:
			std::cout << "Opcao invalida" << std::endl;
			menu_alunos(false);
			break;
		}
	}

	void Gerenciador::menu_cursos(bool print_menu)
	{
		if(print_menu)
		{
			std::cout << "1 - Cadastrar" << std::endl << "2 - Remover" << std::endl <<"3 - Alterar" << std::endl <<
				"4 - Listar" << std::endl << "5 - Voltar" << std::endl;
		}
		std::cout << "> ";
		char op;
		std::cin >> op;
		std::cout << std::endl;
		switch(op)
		{
		case '1':
			cadastra_curso();
			menu_cursos(false);
			break;
		case '2':
			remove_curso();
			menu_cursos(false);
			break;
		case '3':
			altera_curso();
			menu_cursos(false);
			break;
		case '4':
			lista_cursos();
			menu_cursos(false);
			break;
		case '5':
			menu_inicial();
			break;
		default:
			std::cout << "Opcao invalida" << std::endl;
			menu_cursos(false);
			break;
		}
	}

	void Gerenciador::menu_disciplinas(bool print_menu)
	{
		if(print_menu)
		{
			std::cout << "1 - Cadastrar" << std::endl << "2 - Remover" << std::endl <<"3 - Alterar" << std::endl <<
				"4 - Listar" << std::endl << "5 - Voltar" << std::endl;

		}
		std::cout << "> ";
		char op;
		std::cin >> op;
		switch(op)
		{
		case '1':
			cadastra_disciplina();
			menu_disciplinas(false);
			break;
		case '2':
			remove_disciplina();
			menu_disciplinas(false);
			break;
		case '3':
			altera_disciplina();
			menu_disciplinas(false);
			break;
		case '4':
			lista_disciplinas();
			menu_disciplinas(false);
			break;
		case '5':
			menu_inicial();
			break;
		default:
			std::cout << "Opcao invalida." << std::endl;
			menu_disciplinas(false);
		}
	}

	void Gerenciador::menu_professores(bool print_menu)
	{
		if(print_menu)
		{
			std::cout << "1 - Cadastrar" << std::endl << "2 - Remover" << std::endl <<"3 - Alterar" << std::endl <<
				"4 - Listar" << std::endl << "5 - Voltar" << std::endl;
		}
		std::cout << "> ";
		char op;
		std::cin >> op;
		std::cout << std::endl;
		switch(op)
		{
		case '1':
			cadastra_professor();
			menu_professores(false);
			break;
		case '2':
			remove_professor();
			menu_professores(false);
			break;
		case '3':
			altera_professor();
			menu_professores(false);
			break;
		case '4':
			lista_professores();
			menu_professores(false);
			break;
		case '5':
			menu_inicial();
			break;
		default:
			std::cout << "Opcao invalida" << std::endl;
			menu_professores(false);
			break;
		}
	}
	
	void Gerenciador::menu_turmas(bool print_menu)
	{
		if(print_menu)
		{ 
			std::cout << "1 - Cadastrar" << std::endl << "2 - Remover" << std::endl << "3 - Alterar"
				<< std::endl << "4 - Voltar" << std::endl;
		}
		std::cout << "> ";
		std::cin.sync();
		char op;
		std::cin >> op;
		std::cin.sync();
		switch(op)
		{
		case '1':
			cadastra_turma();
			menu_turmas(false);
			break;
		case '2':
			remove_turma();
			menu_turmas(false);
			break;
		case '3':
			altera_turma();
			menu_turmas(false);
			break;
		case '4':
			menu_inicial();
			break;
		default:
			std::cout << "Opcao invalida." << std::endl;
			menu_turmas(false);
			break;
		}
	}
	
	void Gerenciador::remove_turma()
	{
		std::string cod_cu, cod_tu;
		std::cin.sync();
		std::cout << "Codigo do curso: ";
		std::getline(std::cin, cod_cu);
		std::cout << "Codigo da turma: ";
		std::getline(std::cin, cod_tu);
		base::Turma* t = turmas.getTurma(cod_cu, cod_tu);
		if(t == 0)
			t->erase();
		else
			std::cout << "Turma nao encontrada, abortando operacao." << std::endl;
	}

	void Gerenciador::cadastra_turma()
	{
		std::cin.sync();
		std::cout << "Lista cursos? (s/n) ";
		char op;
		std::cin >> op;
		if(op == 's' || op == 'S')
			lista_cursos();
		std::cin.sync();
		std::cout << "Codigo do curso: ";
		std::string cod;
		std::getline(std::cin, cod);
		base::Curso* c = cursos.getCurso(cod);
		if(c != 0)
		{
			std::cout << "Codigo da disciplina: ";
			std::getline(std::cin, cod);
			base::Turma t(c, cod);
			t.save();
			std::cout << "Turma criada com sucesso." << std::endl <<
				"Para adcinar professores e alunos a turma acesse o menu 'alterar'" << std::endl;
		}
		else
			std::cout << "Curso nao encontrado." << std::endl;
	}

	void Gerenciador::altera_turma()
	{
		std::cout << "Codigo da turma: ";
		std::cin.sync();
		std::string cod_t, cod_c;
		std::getline(std::cin, cod_t);
		std::cout << "Codigo do curso: ";
		std::cin.sync();
		std::getline(std::cin, cod_c);
		base::Turma* turma = turmas.getTurma(cod_c, cod_t);
		if(turma == 0)
		{
			std::cout << "Turma nao encontrada, abortando." << std::endl;
			return;
		}
		std::cout << "1 - Adcionar aluno" << std::endl;
		std::cout << "2 - Remover aluno" << std::endl;
		std::cout << "3 - Adcionar professor" << std::endl;
		std::cout << "4 - Remover Professor" << std::endl;
		std::cout << "5 - Voltar" << std::endl;
		char op;
		std::cin.sync();
		std::cin >> op;
		unsigned int mat;
		std::string util;
		base::Aluno* aluno;
		base::Professor* prof;
		switch(op)
		{
		case '1':
		case '2':
			std::cout << "Matricula: ";
			std::cin.sync();
			std::cin >> mat;
			aluno = alunos.getAluno(mat);
			if(aluno != 0)
			{
				if(op == '1')
					turma->adcionaAluno(aluno);
				else
					turma->removerAluno(aluno);
			}
			break;
		case '3':
		case '4':
			std::cout << "Siape: ";
			std::cin.sync();
			std::getline(std::cin, util);
			prof = professores.getProfessor(util);
			if(prof != 0)
			{
				if(op == '3')
					turma->adcionaProfessor(prof);
				else 
					turma->removerProfessor(prof);
			}
			break;
		case '5':
			menu_turmas(false);
			break;
		default:
			std::cout << "Opcao invalida, abortando." << std::endl;
			menu_turmas(false);
			break;
		}
	}

	void Gerenciador::cadastra_aluno()
	{
		std::cin.sync();
		unsigned int matricula;
		std::string nome, codigo;
		std::cout << "Nome: ";
		std::getline(std::cin, nome);
		std::cout << "Matricula: ";
		std::cin >> matricula;
		std::cout << "Codigo do curso: ";
		std::cin >> codigo;
		const base::Curso* curso = cursos.getCurso(codigo);

		if(curso == 0)
		{
			std::cout << "Curso inexistente, abortando operacao." << std::endl;
			menu_alunos(false);
		}
		base::Aluno(curso, matricula, nome).save();
	}

	void Gerenciador::remove_aluno()
	{
		std::cout << "Matricula: ";
		unsigned int mat;
		std::cin >> mat;
		base::Aluno* aluno = alunos.getAluno(mat);
		if(aluno != 0)
		{
			aluno->erase();
			std::cout << "Aluno removido com sucesso!" << std::endl;
			std::cout << "Matricula: " << aluno->getMatricula() << std::endl << "Nome: "
				<< aluno->getNome() << std::endl;
		}
		else
			std::cout << "Aluno nao encontrado" << std::endl;
	}

	void Gerenciador::altera_aluno()
	{
		std::cout << "Matricula: ";
		unsigned int mat;
		std::cin >> mat;
		base::Aluno* aluno = alunos.getAluno(mat);
		std::string codigo;
		if(aluno != 0)
		{
			std::cout << "1 - Alterar Matricula" << std::endl << "2 - Alterar Nome" << std::endl << "3 - Altera Curso" << std::endl <<  "> ";
			char op;
			std::cin >> op;
			std::string nome;
			unsigned int matricula;
			std::cin.sync();
			switch (op)
			{
			case '2':
				std::cout << "Novo nome: ";				
				std::getline(std::cin, nome);
				aluno->setNome(nome);
				break;
			case '1':
				std::cout << "Nova Matricula: ";
				std::cin >> matricula;
				aluno->setMatricula(matricula);
				break;
			case '3':
				std::cout << "Lista cursos? (s/n)" << std::endl << "> ";
				std::cin >> op;
				if(op == 's' || op == 'S')
					lista_cursos();
				std::cout << "Codigo do curso: " << std::endl;
				std::getline(std::cin, codigo);
				aluno->setCurso(cursos.getCurso(codigo));
				break;
			default:
				std::cout << "Opcao invalida" << std::endl;
			}
		}
		else
			std::cout << "Aluno nao encontrado" << std::endl;
	}

	void Gerenciador::lista_alunos()
	{
		for(base::Alunos::AlunoIter it = alunos.begin(); it != alunos.end(); it++)
			std::cout << (*it) << std::endl;
	}

	void Gerenciador::cadastra_curso()
	{
		std::string cod, nome;
		std::cout << "Codigo: ";
		std::cin.sync();
		std::getline(std::cin, cod);
		std::cout << "Nome: ";
		std::getline(std::cin, nome);
		base::Curso(cod, nome).save();
	}

	void Gerenciador::remove_curso()
	{
		std::cout << "Codigo: ";
		std::string codigo;
		std::cin.sync();
		std::getline(std::cin, codigo);
		base::Curso* curso = cursos.getCurso(codigo);
		if(curso != 0)
			curso->erase();
		else
			std::cout << "Curso nao encontrado" << std::endl;
	}

	void Gerenciador::altera_curso()
	{
		std::cout << "Codigo: " << std::endl;
		std::string cod;
		std::cin.sync();
		std::getline(std::cin, cod);
		base::Curso* curso = cursos.getCurso(cod);
		if(curso != 0)
		{
			std::cout << "1 - Alterar codigo" << std::endl << "2 - Alterar nome" << std::endl;
			char op;
			std::cin >> op;
			switch (op)
			{
			case '1':
				std::cout << "Novo codigo: ";
				std::cin.sync();
				std::getline(std::cin, cod);
				curso->setCodigo(cod);
				break;
			case '2':
				std::cout << "Novo nome: ";
				std::cin.sync();
				std::getline(std::cin, cod);
				curso->setNome(cod);
				break;
			default:
				std::cout << "Opcao invalida" << std::endl;
			}
		}
		else
			std::cout << "Curso nao encontrado" << std::endl;
	}

	void Gerenciador::lista_cursos()
	{
		for(base::Cursos::CursoIter it = cursos.begin(); it != cursos.end(); it++)
			std::cout << (*it) << std::endl;
	}

	void Gerenciador::cadastra_professor()
	{
		std::string nome, siape, titulacao, area;
		std::cout << "Nome: ";
		std::cin.sync();
		std::getline(std::cin, nome);
		std::cout << "Siape: ";
		std::getline(std::cin, siape);
		std::cout << "Titulacao: ";
		std::getline(std::cin, titulacao);
		std::cout << "Area: ";
		std::getline(std::cin, area);
		base::Professor(siape, nome, area, titulacao).save();
	}

	void Gerenciador::remove_professor()
	{
		std::cout << "Siape: ";
		std::string siape;
		std::cin.sync();
		std::getline(std::cin, siape);
		base::Professor* prof = professores.getProfessor(siape);
		if(prof != 0)
			prof->erase();
		else
			std::cout << "Professor nao encontrado." << std::endl;
	}

	void Gerenciador::altera_professor()
	{
		std::cin.sync();
		std::cout << "Siape: ";
		std::string siape;
		std::getline(std::cin, siape);
		base::Professor* prof = professores.getProfessor(siape);
		if(prof != 0)
		{
			std::cout << "1 - Nome" << std::endl << "2 - Siape" << std::endl <<
				"3 - Titulacao" << std::endl << "4 - Area" << std::endl;
			std::cout << "> ";
			char op;
			std::cin >> op;
			std::cin.sync();
			switch(op)
			{
			case '1':
				std::cout << "Novo nome: ";
				std::getline(std::cin, siape);
				prof->setNome(siape);
				break;
			case '2':
				std::cout << "Novo siape: ";
				std::getline(std::cin, siape);
				prof->setSiape(siape);
				break;
			case '3':
				std::cout << "Nova titulacao: ";
				std::getline(std::cin, siape);
				prof->setTitulacao(siape);
				break;
			case '4':
				std::cout << "Nova area: ";
				std::getline(std::cin, siape);
				prof->setArea(siape);
				break;
			default:
				std::cout << "Opcao invalida." << std::endl;
			}
		}
		else
			std::cout << "Professor nao encontrado." << std::endl;
	}

	void Gerenciador::lista_professores()
	{
		for(base::Professores::ProfIter it = professores.begin(); it != professores.end(); it++)
			std::cout << (*it) << std::endl;
	}
	
	void Gerenciador::cadastra_disciplina()
	{
		std::cin.sync();
		std::string cod_disc, cod_curso, nome;
		std::cout << "Codigo da disciplina: ";
		std::getline(std::cin, cod_disc);
		std::cout << "Listar cursos existentes? (s/n) " ;
		char op;
		std::cin >> op;
		if(op == 's' || op == 'S')
			lista_cursos();
		std::cin.sync();
		std::cout << "Codigo do curso: ";
		std::getline(std::cin, cod_curso);
		base::Curso* c = cursos.getCurso(cod_curso);
		if(c == 0)
		{
			std::cout << "Curso nao encontrado, abortando." << std::endl;
			menu_disciplinas(false);
			return;
		}
		std::cout << "Nome da disciplina: ";
		std::getline(std::cin, nome);
		unsigned int carga;
		std::cout << "Carga horaria: ";
		std::cin >> carga;

		base::Disciplina(cod_disc, c, nome, carga).save();
		std::cout << "Por padrao, turmas sao criadas sem nenhum requisito, caso deseje adcionar algum utilize a operacao 'Alterar Disciplina'" 
			<< std::endl;
	}

	void Gerenciador::altera_disciplina()
	{
		std::cin.sync();
		std::string cod_disc, cod_curso;
		std::cout << "Codigo da disciplina: ";
		std::getline(std::cin, cod_disc);
		std::cout << "Codigo do curso: ";
		std::getline(std::cin, cod_curso);
		base::Disciplina* disc = disciplinas.getDisciplina(cod_disc, cod_curso);
		if(disc == 0)
		{
			std::cout << "Disciplina nao encontrada :(" << std::endl;
			return;
		}

		std::cout << "1 - Alterar codigo" << std::endl << "2 - Alterar nome" << std::endl << "3 - Alterar curso" << std::endl
			<< "4 - Alterar carga horaria" << std::endl << "5 - Alterar requisitos" << std::endl << "> ";
		char op;
		std::cin >> op;
		std::cin.sync();
		base::Curso* c = 0;
		base::Disciplina* req = 0;
		switch(op)
		{
		case '1':
			std::cout << "Novo codigo: ";
			std::getline(std::cin, cod_disc);
			disc->setCodigo(cod_disc);
			break;
		case '2':
			std::cout << "Novo nome: ";
			std::getline(std::cin, cod_disc);
			disc->setNome(cod_disc);
			break;
		case '3':
			std::cout << "Listar cursos antes? (s/n)" << std::endl;
			std::cin >> op;
			if(op == 's' || op == 'S')
				lista_cursos();
			std::cin.sync();
			std::cout << "Novo curso (codigo): ";
			std::getline(std::cin, cod_disc);
			c = cursos.getCurso(cod_disc);
			if(c != 0)
				disc->setCurso(c);
			else
				std::cout << "Curso nao encontrado, nao foi realizada nenhuma alteracao." << std::endl;
			break;
		case '4':
			std::cout << "Nova carga horaria: ";
			unsigned int carga;
			std::cin >> carga;
			std::cin.sync();
			disc->setCarga(carga);
			break;
		case '5':
			std::cout << "1 - Remover" << std::endl << "2 - Adcionar" << "3 - Voltar" << std::endl;
			menu_disc:
			std::cout << "> ";
			std::cin >> op;
			std::cin.sync();
			std::cout << "Codigo da disciplina: " << std::endl;
			std::getline(std::cin, cod_disc);
			req = disciplinas.getDisciplina(cod_disc, disc->getCurso().getCodigo());
			if(req == 0)
			{
				std::cout << "Disciplina nao encontrada :|" << std::endl;
				goto menu_disc;
			}

			switch(op)
			{
			case '1':
				disc->adcionaRequisito(req);
				break;
			case '2':
				break;
			case '3':
				disc->removeRequisito(req);
				menu_disciplinas();
				break;
			default:
				std::cout << "Opcao invalida." << std::endl;
				goto menu_disc;
				break;
			}
			break;
		default:
			std::cout << "Opcao invalida" << std::endl;
			break;
		}
		menu_disciplinas();
	}

	void Gerenciador::remove_disciplina()
	{
		std::cin.sync();
		std::string cod_curso, cod_disc;
		std::cout << "Digite o codigo do curso: ";
		std::getline(std::cin, cod_curso);
		std::cout << "Digite o codigo da disciplina: ";
		std::getline(std::cin, cod_disc);
		base::Disciplina* disc = disciplinas.getDisciplina(cod_disc, cod_curso);
		if(disc != 0)
			disc->erase();
		else
		{
			std::cout << "Disciplina nao entrada." << std::endl;
			remove_disciplina();
		}
	}

	void Gerenciador::lista_disciplinas()
	{
		for(base::Disciplinas::DisciplinaIter it = disciplinas.begin(); it != disciplinas.end(); it++)
			std::cout << (*it) << std::endl;
	}

	void Gerenciador::busca_aluno()
	{
		std::cout << "Digite a matricula: ";
		unsigned int mat;
		std::cin >> mat;
		base::Aluno* a = alunos.getAluno(mat);
		if(a == 0)
			std::cout << "Aluno nao encontrado :(" << std::endl;
		else
			std::cout << *a << std::endl;
	}

	void Gerenciador::busca_curso()
	{
		std::cout << "Digite o codigo do curso: ";
		std::string cod;
		std::cin.sync();
		std::getline(std::cin, cod);
		base::Curso* c = cursos.getCurso(cod);
		if(c == 0)
			std::cout << "Curso nao encontrado :(" << std::endl;
		else
			std::cout << *c << std::endl;
	}

	void Gerenciador::busca_disciplina()
	{
		std::cout << "Digite o codigo da disciplina: ";
		std::string cod_d, cod_c;
		std::cin.sync();
		std::getline(std::cin, cod_d);
		std::cout << "Digite o codigo do curso: ";
		std::cin.sync();
		std::getline(std::cin, cod_c);
		base::Disciplina* d = disciplinas.getDisciplina(cod_d, cod_c);
		if(d == 0)
			std::cout << "Disciplina nao encontrada :(" << std::endl;
		else
			std::cout << *d << std::endl;
	}

	void Gerenciador::busca_professor()
	{
		std::cout << "Digite o siape do professor: ";
		std::string cod;
		std::cin.sync();
		std::getline(std::cin, cod);
		base::Professor* c = professores.getProfessor(cod);
		if(c == 0)
			std::cout << "Professor nao encontrado :(" << std::endl;
		else
			std::cout << *c << std::endl;
	}

	void Gerenciador::busca_turma()
	{
		std::cout << "Digite o codigo da turma: ";
		std::string cod_t, cod_c;
		std::cin.sync();
		std::getline(std::cin, cod_t);
		std::cin.sync();
		std::cout << "Digite o codigo do curso: ";
		std::getline(std::cin, cod_c);
		base::Turma* t = turmas.getTurma(cod_c, cod_t);
		if(t == 0)
			std::cout << "Turma nao encontrada :(" << std::endl;
		else
			std::cout << *t << std::endl;
	}
} 