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
		bd::Banco::getInstance().registerTable(&professores);
		bd::Banco::getInstance().registerTable(&disciplinas);
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
			break;
		case '2':
			remove_disciplina();
			break;
		case '3':
			altera_disciplina();
			break;
		case '4':
			lista_disciplinas();
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
			break;
		case '2':
			remove_professor();
			break;
		case '3':
			altera_professor();
			break;
		case '4':
			lista_professores();
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
	}

	void Gerenciador::cadastra_aluno()
	{
		std::cin.get();
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
		}

		base::Aluno(curso, matricula, nome).save();
		menu_alunos(false);
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
		menu_alunos(false);
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
			std::cin.get();
			switch (op)
			{
			case 1:
				std::cout << "Novo nome: ";				
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
				std::getline(std::cin, codigo);
				aluno->setCurso(cursos.getCurso(codigo));
				break;
			default:
				std::cout << "Opcao invalida" << std::endl;
			}
		}
		else
			std::cout << "Aluno nao encontrado" << std::endl;
		menu_alunos(false);
	}

	void Gerenciador::lista_alunos()
	{
		for(base::Alunos::AlunoIter it = alunos.begin(); it != alunos.end(); it++)
			std::cout << (*it).getMatricula()  << "\t" << (*it).getNome() << std::endl;
		menu_alunos(false);
	}

	void Gerenciador::cadastra_curso()
	{
		std::string cod, nome;
		std::cout << "Codigo: ";
		std::cin.get();
		std::getline(std::cin, cod);
		std::cout << "Nome: ";
		std::getline(std::cin, nome);
		base::Curso(cod, nome).save();
		menu_cursos(false);
	}

	void Gerenciador::remove_curso()
	{
		std::cout << "Codigo: ";
		std::string codigo;
		std::cin.get();
		std::getline(std::cin, codigo);
		base::Curso* curso = cursos.getCurso(codigo);
		if(curso != 0)
			curso->erase();
		else
			std::cout << "Curso nao encontrado" << std::endl;
		menu_cursos(false);
	}

	void Gerenciador::altera_curso()
	{
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
		menu_cursos(false);
	}

	void Gerenciador::lista_cursos()
	{
		for(base::Cursos::CursoIter it = cursos.begin(); it != cursos.end(); it++)
			std::cout << (*it).getCodigo() << "\t" << (*it).getNome() << std::endl;
		menu_cursos(false);
	}

	void Gerenciador::cadastra_professor()
	{
		std::string nome, siape, titulacao, area;
		std::cout << "Nome: ";
		std::cin.get();
		std::getline(std::cin, nome);
		std::cout << "Siape: ";
		std::getline(std::cin, siape);
		std::cout << "Titulacao: ";
		std::getline(std::cin, titulacao);
		std::cout << "Area: ";
		std::getline(std::cin, area);
		base::Professor(siape, nome, area, titulacao).save();
		menu_professores(false);
	}

	void Gerenciador::remove_professor()
	{
		std::cout << "Siape: ";
		std::string siape;
		std::cin.get();
		std::getline(std::cin, siape);
		base::Professor* prof = professores.getProfessor(siape);
		if(prof != 0)
			prof->erase();
		else
			std::cout << "Professor nao encontrado." << std::endl;
		menu_professores(false);
	}

	void Gerenciador::altera_professor()
	{
		std::cin.get();
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
			std::cin.get();
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
		menu_professores(false);
	}

	void Gerenciador::lista_professores()
	{
		for(base::Professores::ProfIter it = professores.begin(); it != professores.end(); it++)
		{
			std::cout << (*it).getSiape() << "\t" << (*it).getNome() << "\t" << (*it).getTitulacao() 
				<< "\t" << (*it).getArea() << std::endl;
		}
		menu_professores(false);
	}
	
	void Gerenciador::cadastra_disciplina()
	{
		std::cin.get();
		std::string cod_disc, cod_curso, nome;
		std::cout << "Codigo da disciplina: ";
		std::getline(std::cin, cod_disc);
		std::cout << "Listar cursos existentes? (s/n) " ;
		char op;
		std::cin >> op;
		if(op == 's' || op == 'S')
			lista_cursos();
		std::cin.get();
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
		menu_disciplinas(false);
	}

	void Gerenciador::altera_disciplina()
	{
		std::cin.clear();
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
		std::cin.clear();
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
			std::cin.clear();
			std::cout << "Novo curso (codigo): ";
			std::getline(std::cin, cod_disc);
			base::Curso* c = cursos.getCurso(cod_disc);
			if(c != 0)
				disc->setCurso(c);
			else
				std::cout << "Curso nao encontrado, nao foi realizada nenhuma alteracao." << std::endl;
			break;
		case '4':
			std::cout << "Nova carga horaria: ";
			unsigned int carga;
			std::cin >> carga;
			std::cin.clear();
			disc->setCarga(carga);
			break;
		case '5':
			std::cout << "1 - Remover" << std::endl << "2 - Adcionar" << "3 - Voltar" << std::endl;
			menu_disc:
			std::cout << "> ";
			std::cin >> op;
			std::cin.clear();
			std::cout << "Codigo da disciplina: " << std::endl;
			std::getline(std::cin, cod_disc);
			base::Disciplina* req = disciplinas.getDisciplina(cod_disc, disc->getCurso().getCodigo());
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
		std::cin.clear();
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
		menu_disciplinas();
	}

	void Gerenciador::lista_disciplinas()
	{
		for(base::Disciplinas::DisciplinaIter it = disciplinas.begin(); it != disciplinas.end(); it++)
			std::cout << (*it).getCodigo() << "\t" << (*it).getNome() << "\t" << (*it).getCarga() << "\t" << (*it).getCurso().getNome() << std::endl;
		menu_disciplinas();
	}
}