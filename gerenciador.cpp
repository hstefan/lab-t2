#include "gerenciador.h"
#include "banco.h"
#include "dados.h"
#include <iostream>
#include <string>

namespace gerenc
{
	Gerenciador::Gerenciador()
		: alunos(), cursos()
	{
		bd::Banco::getInstance().registerTable(&alunos);
		bd::Banco::getInstance().registerTable(&cursos);
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

	void Gerenciador::menu_alunos()
	{
		std::cout << "1 - Cadastrar" << std::endl << "2 - Remover" << std::endl <<"3 - Alterar" <<
			std::endl << "4 - Listar" << std::endl << "5 - Voltar" << std::endl << "> ";

		char op;
		std::cin >> op;
		std::cout << std::endl;
		switch(op)
		{
		case '1':
			cadastra_aluno();
			break;
		case '2':
			remove_aluno();
			break;
		case '3':
			altera_aluno();
			break;
		case '4':
			lista_alunos();
			break;
		case '5':
			menu_inicial();
			break;
		default:
			std::cout << "Opcao invalida" << std::endl;
			menu_alunos();
			break;
		}
	}

	void Gerenciador::menu_cursos()
	{
		std::cout << "1 - Cadastrar" << std::endl << "2 - Remover" << std::endl <<"3 - Alterar" << std::endl <<
			"4 - Listar" << std::endl << "5 - Voltar" << std::endl << "> ";

		char op;
		std::cin >> op;
		std::cout << std::endl;
		switch(op)
		{
		case '1':
			cadastra_curso();
			break;
		case '2':
			remove_curso();
			break;
		case '3':
			altera_curso();
			break;
		case '4':
			lista_cursos();
			break;
		case '5':
			break;
		default:
			std::cout << "Opcao invalida" << std::endl;
			menu_alunos();
			break;
		}
	}

	void Gerenciador::menu_disciplinas()
	{
	}

	void Gerenciador::menu_professores()
	{
	}
	
	void Gerenciador::menu_turmas()
	{
	}

	void Gerenciador::cadastra_aluno()
	{
		unsigned int matricula;
		std::string nome, codigo;
		std::cout << "Nome: ";
		std::cin.get();
		std::getline(std::cin, nome);
		std::cout << "Matricula: ";
		std::cin >> matricula;
		std::cout << "Codigo do curso: ";
		std::cin >> codigo;
		const base::Curso* curso = cursos.getCurso(codigo);

		if(curso == 0)
		{
			std::cout << "Curso inexistente, abortando operacao." << std::endl;
		}

		base::Aluno(curso, matricula, nome).save();
		menu_alunos();
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
		menu_alunos();
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
			switch (op)
			{
			case 1:
				std::cout << "Novo nome: ";
				std::cin.get();
				std::getline(std::cin, nome);
				aluno->setNome(nome);
				break;
			case 2:
				std::cout << "Nova Matricula: ";
				std::cin >> matricula;
				aluno->setMatricula(matricula);
				break;
			case 3:
				std::cout << "Lista cursos? (s/n)" << std::endl << "> ";
				std::cin >> op;
				if(op == 's' || op == 'S')
					lista_cursos();
				std::cout << "Codigo do curso: " << std::endl;
				std::cin.get();
				std::getline(std::cin, codigo);
				aluno->setCurso(cursos.getCurso(codigo));
				break;
			default:
				std::cout << "Opcao invalida" << std::endl;
			}
		}
		else
			std::cout << "Aluno nao encontrado" << std::endl;
		menu_alunos();
	}

	void Gerenciador::lista_alunos()
	{
		for(base::Alunos::AlunoIter it = alunos.begin(); it != alunos.end(); it++)
			std::cout << (*it).getMatricula()  << "\t" << (*it).getNome() << std::endl;
		menu_alunos();
	}

	void Gerenciador::cadastra_curso()
	{
		std::string cod, nome;
		std::cout << "Codigo: ";
		std::cin.get();
		std::getline(std::cin, cod);
		std::cout << "Nome: ";
		std::cin.get();
		std::getline(std::cin, nome);
		base::Curso(cod, nome).save();
	}

	void Gerenciador::remove_curso()
	{
		std::cout << "Listar cursos? (s/n)" << std::endl;
		char op;
		std::cin >> op;
		if(op == 's' || op == 'n')
			lista_cursos();
		std::cout << "Codigo: ";
		std::string codigo;
		std::cin.get();
		std::getline(std::cin, codigo);
		base::Curso* curso = cursos.getCurso(codigo);
		if(curso != 0)
			curso->erase();
		else
			std::cout << "Curso nao encontrado" << std::endl;
	}

	void Gerenciador::altera_curso()
	{
		std::cout << "Listar cursos? (s/n)" << std::endl;
		char op;
		std::cin >> op;
		if(op == 's' || op == 'n')
			lista_cursos();
		std::cout << "Codigo: " << std::endl;
		std::string cod;
		std::cin.get();
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
				std::cin.get();
				std::getline(std::cin, cod);
				curso->setCodigo(cod);
				break;
			case '2':
				std::cout << "Novo nome: ";
				std::cin.get();
				std::getline(std::cin, cod);
				curso->setNome(cod);
				break;
			default:
				std::cout << "Opcao invalida" << std::endl;
			}
		}
		else
			std::cout << "Curso nao encontrado" << std::endl;
		menu_cursos();
	}

	void Gerenciador::lista_cursos()
	{
		for(base::Cursos::CursoIter it = cursos.begin(); it != cursos.end(); it++)
			std::cout << (*it).getCodigo() << "\t" << (*it).getNome() << std::endl;
		menu_cursos();
	}
}